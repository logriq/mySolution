#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Matrix.h"

int Matrix::countObjects = 0;

Matrix::Matrix(size_t rows, size_t cols) : m_pdata(new int* [rows]), m_rows(rows), m_cols(cols)
{
    for (int i = 0; i < m_rows; i++)
    {
        m_pdata[i] = new int[m_cols];
        for (int j = 0; j < m_cols; j++)
            m_pdata[i][j] = 0;
    }
    countObjects++;
}

Matrix::Matrix(size_t rows, size_t cols, int value) : Matrix(rows, cols)
{
    FillByValue(value);
}

Matrix::Matrix(const Matrix& other) : m_pdata(new int* [other.m_rows]), m_rows(other.m_rows), m_cols(other.m_cols)
{
    for (int i = 0; i < m_rows; i++)
    {
        m_pdata[i] = new int[m_cols];
        for (int j = 0; j < m_cols; j++)
        {
            m_pdata[i][j] = other.m_pdata[i][j];
        }
    }
    countObjects++;
}

Matrix::Matrix(Matrix&& other) : m_rows(other.m_rows), m_cols(other.m_cols), m_pdata(other.m_pdata)
{
    std::cout << "move constructor\n";
    other.m_rows = 0;
    other.m_cols = 0;
    other.m_pdata = nullptr;
}

Matrix::~Matrix()
{
    Destroy();
    countObjects--;
}

int Matrix::GetElement(size_t row, size_t col) const
{
    return m_pdata[row][col];
}

size_t Matrix::GetRowsCount() const
{
    return m_rows;
}

size_t Matrix::GetColsCount() const
{
    return m_cols;
}

void Matrix::FillByRandom()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            m_pdata[i][j] = rand() % (m_rows * m_cols - 1) + 1;
        }
    }
}

void Matrix::FillByValue(int value)
{
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            m_pdata[i][j] = value;
        }
    }
}

Matrix Matrix::Transponse(bool& bres)
{
    Matrix result(m_cols, m_rows);
    for (int i = 0; i < result.m_rows; ++i)
    {
        for (int j = 0; j < result.m_cols; ++j)
        {
            result.m_pdata[i][j] = m_pdata[j][i];
        }
    }
    bres = true;
    return result;
}

void Matrix::Print()
{
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            std::cout << m_pdata[i][j] << "       ";
        }
        std::cout << '\n';
    }
}

Matrix Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        Destroy();
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_pdata = new int* [other.m_rows];
        for (int i = 0; i < m_rows; i++)
        {
            m_pdata[i] = new int[other.m_cols];
            for (int j = 0; j < m_cols; j++)
            {
                m_pdata[i][j] = other.m_pdata[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator = (Matrix&& other)
{
    if (this != &other)
    {
        Destroy();
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_pdata = other.m_pdata;
        other.m_rows = 0;
        other.m_cols = 0;
        other.m_pdata = nullptr;
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix result(m_rows, m_cols);
    if (m_rows != other.m_rows || m_cols != other.m_cols)
    {
        std::cout << "Cannot add matrices\n";
        return result;
    }
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            result.m_pdata[i][j] = m_pdata[i][j] + other.m_pdata[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    return *this + other * (-1);
}

Matrix Matrix::operator*(const int multiplier) const
{
    Matrix result(m_rows, m_cols);
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            result.m_pdata[i][j] = m_pdata[i][j] * multiplier;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    Matrix result(m_rows, other.m_cols);
    if (m_cols != other.m_rows)
    {
        std::cout << "Cannot multiply matrices\n";
        result.FillByValue(-1);
    }
    else
    {
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < other.m_cols; j++)
            {
                result.m_pdata[i][j] = 0;
                for (int k = 0; k < m_cols; k++)
                {
                    result.m_pdata[i][j] += m_pdata[i][k] * other.m_pdata[k][j];
                }
            }
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    if (m_rows != other.m_rows || m_cols != other.m_cols)
    {
        std::cout << "Cannot add matrices\n";
        return *this;
    }
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            m_pdata[i][j] = m_pdata[i][j] + other.m_pdata[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    if (m_rows != other.m_rows || m_cols != other.m_cols)
    {
        std::cout << "Cannot subtract matrices\n";
        return *this;
    }
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            m_pdata[i][j] = m_pdata[i][j] - other.m_pdata[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const int mult)
{
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_cols; ++j)
        {
            m_pdata[i][j] = m_pdata[i][j] * mult;
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    *this = *this * other;
    return *this;
}

Matrix Matrix::operator++()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_pdata[i][j]++;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix temp = *this;
    ++(*this);
    return temp;
}

Matrix Matrix::operator--()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_pdata[i][j]--;
        }
    }
    return *this;
}

Matrix Matrix::operator--(int)
{
    Matrix temp = *this;
    --(*this);
    return temp;
}

Matrix Matrix::operator-()
{
    return (*this) * (-1);
}

bool Matrix::operator==(const Matrix& other) const
{
    if (m_rows != other.m_rows || m_cols != other.m_cols)
        return false;
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            if (m_pdata[i][j] != other.m_pdata[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
    return !(*this == other);
}

bool Matrix::operator<(const Matrix& other) const
{
    return m_pdata[0][0] < other.m_pdata[0][0];
}

bool Matrix::operator>(const Matrix& other) const
{
    return other < *this;
}

bool Matrix::operator<=(const Matrix& other) const
{
    return (*this < other) || (*this == other);
}

bool Matrix::operator>=(const Matrix& other) const
{
    return (*this > other) || (*this == other);
}

int& Matrix::operator()(size_t row, size_t col)
{
    return m_pdata[row][col];
}

int* Matrix::operator[](size_t row)
{
    return m_pdata[row];
}

const int* Matrix::operator[](size_t row) const
{
    return m_pdata[row];
}

Matrix Matrix::createMatrix()
{
    Matrix temp(2, 2, 1);
    return temp;
}

void Matrix::Destroy()
{
    for (int i = 0; i < m_rows; ++i)
    {
        delete[] m_pdata[i];
        m_pdata[i] = nullptr;
    }
    delete[] m_pdata;
    m_pdata = nullptr;
}

Matrix operator*(double mult, const Matrix& other)
{
    return other * mult;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
    for (int i = 0; i < matrix.m_rows; ++i)
    {
        for (int j = 0; j < matrix.m_cols; ++j)
        {
            out << matrix.m_pdata[i][j] << "       ";
        }
        out << '\n';
    }
    return out;
}