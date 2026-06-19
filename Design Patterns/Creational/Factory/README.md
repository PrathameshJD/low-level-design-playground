# Factory Design Pattern

## Intent

The Factory Design Pattern provides a way to create objects without exposing the instantiation logic to the client.

Instead of using `new` directly, object creation is delegated to factory classes.

---

## Motivation

In real-world applications, object creation often depends on conditions.

For example:
- Different types of vehicles
- Different UI components
- Different payment methods

If handled directly in client code, it leads to:
- Tight coupling
- Large `if-else` or `switch` blocks
- Poor scalability

The Factory Pattern solves this by centralizing object creation and decoupling it from usage.

---

## Factory Pattern Forms

This repository demonstrates the evolution of the Factory Pattern in C++ through three levels:

---

### 1 Simple Factory

- One factory class handles all object creation
- Uses `if-else` or `switch`
- Easy to understand and implement
- Not a GoF design pattern (but widely used)

📁 Location:
Factory/Single/

---

### 2 Factory Method Pattern

- Defines an interface for object creation
- Subclasses decide which object to create
- Follows Open/Closed Principle
- More flexible than Simple Factory

📁 Location:
Factory/Factory/

---

### 3 Abstract Factory Pattern

- Creates families of related objects
- Ensures compatibility between created objects
- Highest level of abstraction in factory patterns

📁 Location:
Factory/Abstract/

---

## Learning Progression

This module is designed as a step-by-step learning path:

Simple Factory  
      ↓  
Factory Method  
      ↓  
Abstract Factory  

Each level increases:
- Abstraction
- Flexibility
- Scalability

---

## Key Benefits

- Removes direct dependency on concrete classes
- Centralizes object creation logic
- Improves maintainability
- Supports Open/Closed Principle
- Enables runtime flexibility

---

## Trade-offs

- More classes introduced
- Slight increase in complexity
- Requires proper design understanding

---

## Goal

To understand how object creation evolves from:

Hardcoded logic → Centralized factory → Polymorphic factories → Family-based factories