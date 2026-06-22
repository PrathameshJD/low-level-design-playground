#include <iostream>

class Singleton {
private:
    // private constructor
    Singleton() {
        std::cout << "Singleton Constructor\n";
    }

public:
    // delete copy constructor and assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        static Singleton instance;  // created once, thread-safe in C++11+
        return instance;
    }

    void show() {
        std::cout << "Modern Singleton Working\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.show();

    std::cout << (&s1 == &s2) << std::endl;
}