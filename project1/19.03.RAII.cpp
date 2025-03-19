// RAII (Resource Acquisition Is Initialization) - ����� ��������� ���������
// ����'��� ������� ���� ������� �� ��'����, ���������� �������

#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>

// ����, �� ��������� RAII ��� �������� ���'��
class RAII_Memory {
    int* data; // �������� �� �������� ������� ���'���
public:
    RAII_Memory(int value) : data(new int(value)) {
        std::cout << "Resource acquired (memory)" << std::endl;
    }

    ~RAII_Memory() {
        delete data; // ��������� ���'�� ��� ������� ��'����
        std::cout << "Resource released (memory)" << std::endl;
    }

    int get() const { return *data; }
};

// ����, �� ��������� RAII ��� ������ � �������
class RAII_File {
    std::ofstream file;
public:
    RAII_File(const std::string& filename) : file(filename) {
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
        std::cout << "Resource acquired (file)" << std::endl;
    }

    ~RAII_File() {
        file.close(); // ����������� �������� �����
        std::cout << "Resource released (file)" << std::endl;
    }

    void write(const std::string& text) { file << text; }
};

// RAII � ���������������� ������������
void thread_safe_function() {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx); // ������ �������� ������
    std::cout << "Thread-safe operation" << std::endl;
}

int main() {
    // ������������ RAII ��� �������� ���'��
    RAII_Memory obj(42);
    std::cout << "Stored value: " << obj.get() << std::endl;

    // ������������ RAII ��� �����
    RAII_File file("example.txt");
    file.write("Hello, RAII!");

    // ������������ RAII ��� ������������ ������
    thread_safe_function();

    // ��� ��������� �� ������� RAII
    std::unique_ptr<int> smartPtr = std::make_unique<int>(100);
    std::cout << "Smart pointer value: " << *smartPtr << std::endl;

    return 0;
}