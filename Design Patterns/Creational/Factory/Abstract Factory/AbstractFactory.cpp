#include<iostream>
#include<memory>

using namespace std;

// Product A Interface
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};

// Product B Interface
class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() = default;
};

// Concrete Product A
class WindowsButton : public Button {
public:
    void render() override {
        std::cout << "Windows Button\n";
    }
};

// Concrete Product B
class WindowsCheckbox : public Checkbox {
public:
    void render() override {
        std::cout << "Windows Checkbox\n";
    }
};

// Concrete Product A
class MacButton : public Button {
public:
    void render() override {
        std::cout << "Mac Button\n";
    }
};

// Concrete Product B
class MacCheckbox : public Checkbox {
public:
    void render() override {
        std::cout << "Mac Checkbox\n";
    }
};

// Factory Interface
class GUIFactory {
public:

    virtual unique_ptr<Button> createButton() = 0;

    virtual unique_ptr<Checkbox> createCheckbox() = 0;

    virtual ~GUIFactory() = default;
};

// Concrete Factory
class WindowsFactory : public GUIFactory {
public:

    unique_ptr<Button> createButton() override {
        return make_unique<WindowsButton>();
    }

    unique_ptr<Checkbox> createCheckbox() override {
        return  make_unique<WindowsCheckbox>();
    }
};

// Concrete Factory
class MacFactory : public GUIFactory {
public:

    unique_ptr<Button> createButton() override {
        return make_unique<MacButton>();
    }

    unique_ptr<Checkbox> createCheckbox() override {
        return  make_unique<MacCheckbox>();
    }
};

// Client
int main(){

    unique_ptr<GUIFactory> factory;

    factory = make_unique<WindowsFactory>();
    factory->createButton()->render();
    factory->createCheckbox()->render();

    factory = make_unique<MacFactory>();
    factory->createButton()->render();
    factory->createCheckbox()->render();

    return 0;
}