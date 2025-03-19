// RAII (Resource Acquisition Is Initialization) - ідіома керування ресурсами
// Прив'язує життєвий цикл ресурсу до об'єкта, запобігаючи витокам

#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>

// Клас, що демонструє RAII для динамічної пам'яті
class RAII_Memory {
    int* data; // Вказівник на динамічно виділену пам'ять
public:
    RAII_Memory(int value) : data(new int(value)) {
        std::cout << "Resource acquired (memory)" << std::endl;
    }

    ~RAII_Memory() {
        delete data; // Звільнення пам'яті при знищенні об'єкта
        std::cout << "Resource released (memory)" << std::endl;
    }

    int get() const { return *data; }
};

// Клас, що демонструє RAII для роботи з файлами
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
        file.close(); // Автоматичне закриття файлу
        std::cout << "Resource released (file)" << std::endl;
    }

    void write(const std::string& text) { file << text; }
};

// RAII у багатопотоковому програмуванні
void thread_safe_function() {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx); // Захист критичної секції
    std::cout << "Thread-safe operation" << std::endl;
}

int main() {
    // Використання RAII для динамічної пам'яті
    RAII_Memory obj(42);
    std::cout << "Stored value: " << obj.get() << std::endl;

    // Використання RAII для файлів
    RAII_File file("example.txt");
    file.write("Hello, RAII!");

    // Використання RAII для синхронізації потоків
    thread_safe_function();

    // Умні вказівники як частина RAII
    std::unique_ptr<int> smartPtr = std::make_unique<int>(100);
    std::cout << "Smart pointer value: " << *smartPtr << std::endl;

    return 0;
}