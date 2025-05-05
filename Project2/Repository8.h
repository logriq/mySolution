template <typename T>
class Repository8 {
private:
    T data[8];
public:
    Repository8() {
        for (int i = 0; i < 8; i++) {
            data[i] = T();
        }
    }
    void set(int index, T value) {
        if (index >= 0 && index < 8) {
            data[index] = value;
        }
    }
    T get(int index) {
        if (index >= 0 && index < 8) {
            return data[index];
        }
        return T();
    }
};

template <>
class Repository8<bool> {
private:
    unsigned char data;
public:
    Repository8() : data(0) {}
    void set(int index, bool value) {
        if (index >= 0 && index < 8) {
            if (value) {
                data |= (1 << index);
            }
            else {
                data &= ~(1 << index);
            }
        }
    }
    bool get(int index) {
        if (index >= 0 && index < 8) {
            return (data >> index) & 1;
        }
        return false;
    }
};