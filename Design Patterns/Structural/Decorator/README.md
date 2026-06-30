# Decorator Pattern

## Intent

Attach additional responsibilities to an object dynamically without modifying its existing code.

The Decorator Pattern provides a flexible alternative to subclassing for extending an object's behavior.

---

## Motivation

Imagine a coffee shop.

A customer starts with a simple coffee and may optionally add:

- Milk
- Sugar
- Chocolate
- Caramel

Without the Decorator Pattern, you would need a separate class for every possible combination:

- Coffee
- MilkCoffee
- SugarCoffee
- MilkSugarCoffee
- ChocolateCoffee
- MilkChocolateCoffee
- ...

As the number of toppings grows, the number of subclasses grows exponentially.

With the Decorator Pattern, each topping becomes a separate decorator that wraps the coffee object and adds its own behavior.

---

## When to Use

- When responsibilities need to be added dynamically at runtime.
- When subclassing would lead to an explosion of classes.
- When multiple optional features can be combined independently.
- When following the Open/Closed Principle (extending behavior without modifying existing classes).

### Examples

- Coffee customization.
- Pizza toppings.
- GUI widgets (Borders, Scrollbars, Shadows).
- Logging.
- Compression.
- Encryption.
- Caching.
- Input/Output Streams.

---

## UML Diagram

```mermaid
classDiagram

class Component {
    <<interface>>
    +operation()
}

class ConcreteComponent {
    +operation()
}

class Decorator {
    <<abstract>>
    -component : Component
    +operation()
}

class ConcreteDecoratorA {
    +operation()
}

class ConcreteDecoratorB {
    +operation()
}

Component <|.. ConcreteComponent
Component <|.. Decorator

Decorator o--> Component

Decorator <|-- ConcreteDecoratorA
Decorator <|-- ConcreteDecoratorB

class Client {
    +main()
}

Client --> Component : uses
```

---

## Implementation

### Naive Version

```cpp
class Coffee {
public:
    virtual std::string description() const = 0;
    virtual double cost() const = 0;
};

class SimpleCoffee : public Coffee { };

class MilkCoffee : public Coffee { };

class SugarCoffee : public Coffee { };

class MilkSugarCoffee : public Coffee { };

class ChocolateCoffee : public Coffee { };

class MilkChocolateCoffee : public Coffee { };

class SugarChocolateCoffee : public Coffee { };

class MilkSugarChocolateCoffee : public Coffee { };
```

### Problems

- Subclass explosion.
- Difficult to maintain.
- Code duplication.
- Features cannot be combined dynamically.
- Violates the Open/Closed Principle whenever new combinations require new subclasses.

---

### Decorator Pattern Version

#### Component

```cpp
class Coffee {
public:
    virtual ~Coffee() = default;

    virtual std::string description() const = 0;
    virtual double cost() const = 0;
};
```

---

#### Concrete Component

```cpp
class SimpleCoffee : public Coffee {
public:
    std::string description() const override {
        return "Coffee";
    }

    double cost() const override {
        return 50;
    }
};
```

---

#### Decorator

```cpp
class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> coffee;

public:
    explicit CoffeeDecorator(std::unique_ptr<Coffee> c)
        : coffee(std::move(c))
    {}
};
```

---

#### Concrete Decorators

```cpp
class MilkDecorator : public CoffeeDecorator {
public:
    explicit MilkDecorator(std::unique_ptr<Coffee> c)
        : CoffeeDecorator(std::move(c))
    {}

    std::string description() const override {
        return coffee->description() + " + Milk";
    }

    double cost() const override {
        return coffee->cost() + 20;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    explicit SugarDecorator(std::unique_ptr<Coffee> c)
        : CoffeeDecorator(std::move(c))
    {}

    std::string description() const override {
        return coffee->description() + " + Sugar";
    }

    double cost() const override {
        return coffee->cost() + 10;
    }
};
```

---

#### Client Code

```cpp
int main() {

    std::unique_ptr<Coffee> coffee =
        std::make_unique<SimpleCoffee>();

    coffee = std::make_unique<MilkDecorator>(std::move(coffee));
    coffee = std::make_unique<SugarDecorator>(std::move(coffee));

    std::cout << coffee->description() << '\n';
    std::cout << coffee->cost() << '\n';
}
```

---

## How It Works

Each decorator:

- **IS-A** `Coffee` (Inheritance)
- **HAS-A** `Coffee` (Composition)

Example:

```
SugarDecorator
        │
        ▼
MilkDecorator
        │
        ▼
SimpleCoffee
```

Calling

```cpp
coffee->cost();
```

results in:

```
SugarDecorator::cost()
        ↓
MilkDecorator::cost()
        ↓
SimpleCoffee::cost()
```

which evaluates to

```
50
↓
70
↓
80
```

---

## Participants

### Component

Defines the common interface for both concrete objects and decorators.

### Concrete Component

The original object whose behavior can be extended.

### Decorator

Maintains a reference to a component and forwards requests.

### Concrete Decorator

Adds new responsibilities before or after forwarding the request to the wrapped component.

### Client

Creates the component and decorates it with one or more decorators.

---

## Advantages

- Eliminates subclass explosion.
- Supports the Open/Closed Principle.
- Features can be added dynamically.
- Promotes composition over inheritance.
- Individual decorators have a single responsibility.
- Decorators can be combined in any order.

---

## Disadvantages

- Creates many small objects.
- Can be harder to debug because behavior is spread across wrappers.
- Order of decorators may affect behavior.
- Object structure becomes more complex.

---

## Decorator vs Inheritance

| Inheritance | Decorator |
|-------------|-----------|
| Adds behavior at compile time | Adds behavior at runtime |
| Requires many subclasses | Requires one decorator per feature |
| Difficult to combine features | Features can be composed freely |
| Less flexible | Highly flexible |

---

## Real-World Examples

- Coffee customization.
- Pizza toppings.
- Java I/O Streams.
- Logging decorators.
- Compression pipelines.
- Encryption layers.
- GUI widgets (Border, Shadow, Scrollbar).
- HTTP middleware.
- Caching wrappers.

---

## Summary

- **Category:** Structural Pattern
- **Intent:** Add responsibilities dynamically without modifying the original object.
- **Core Idea:** Wrap an object inside another object implementing the same interface.
- **Relationships:**
  - Decorator **IS-A** Component.
  - Decorator **HAS-A** Component.
- **Best For:** Optional, combinable features that should be added dynamically.