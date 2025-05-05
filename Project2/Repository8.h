template <typename T>
class Repository8 {
private:
    T data[8]; // Масив для 8 значень
public:
    Repository8() {
        for (int i = 0; i < 8; i++) {
            data[i] = T(); // Заповнюємо нулі
        }
    }
    void set(int index, T value) {
        if (index >= 0 && index < 8) {
            data[index] = value; // Записуємо значення
        }
    }
    T get(int index) {
        if (index >= 0 && index < 8) {
            return data[index]; // Повертаємо значення
        }
        return T(); // Повертаємо 0, якщо індекс поганий
    }
};

// Спеціалізація для bool
template <>
class Repository8<bool> {
private:
    unsigned char data; // Один байт для 8 бітів
public:
    Repository8() : data(0) {} // Ініціалізуємо байт нулем
    void set(int index, bool value) {
        if (index >= 0 && index < 8) {
            if (value) {
                data |= (1 << index); // Встановлюємо біт у 1
            }
            else {
                data &= ~(1 << index); // Встановлюємо біт у 0
            }
        }
    }
    bool get(int index) {
        if (index >= 0 && index < 8) {
            return (data >> index) & 1; // Повертаємо значення біта
        }
        return false; // Повертаємо false, якщо індекс поганий
    }
};