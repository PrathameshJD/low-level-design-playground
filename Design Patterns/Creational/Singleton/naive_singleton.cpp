#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    // private constructor
    Singleton() {
        std::cout << "Singleton Constructor\n";
    }

public:
    // delete copy operations
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton(); // lazy initialization
        }
        return instance;
    }

    void show() {
        std::cout << "Naive Singleton Working\n";
    }
};

// initialize static member
Singleton* Singleton::instance = nullptr;


int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->show();

    std::cout << (s1 == s2) << std::endl;
}