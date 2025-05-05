#pragma once
#include <ostream>

class Matrix
{
public:
    Matrix(size_t rows = 2, size_t cols = 2);
    Matrix(size_t, size_t, int);
    Matrix(const Matrix&);
    Matrix(Matrix&&);
    ~Matrix();

    int GetElement(size_t, size_t) const;
    size_t GetRowsCount() const;
    size_t GetColsCount() const;

    void FillByRandom();
    void FillByValue(int);

    int& operator()(size_t, size_t);
    int* operator[](size_t row);
    const int* operator[](size_t row) const;

    Matrix Transponse(bool& bres);
    void Print();

    Matrix operator=(const Matrix&);
    Matrix& operator=(Matrix&&) noexcept;

    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const int) const;
    Matrix operator*(const Matrix&) const;

    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const int);
    Matrix& operator*=(const Matrix&);

    Matrix operator++();
    Matrix operator++(int);
    Matrix operator--();
    Matrix operator--(int);
    Matrix operator-();

    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;
    bool operator<(const Matrix&) const;
    bool operator>(const Matrix&) const;
    bool operator<=(const Matrix&) const;
    bool operator>=(const Matrix&) const;

    static Matrix createMatrix();

    friend Matrix operator*(double mult, const Matrix& other);
    friend std::ostream& operator<<(std::ostream&, const Matrix&);

private:
    void Destroy();
    static int countObjects;
    int** m_pdata;
    size_t m_rows;
    size_t m_cols;
};