# Snippets - 26.05.2026

## Snippet 01

Какво ще бъде изведено на стандартния изход?

```cpp
#include <iostream>

struct Animal {
    virtual void sayName() const { std::cout << "Base class\n"; }
};

struct Dog : Animal {
    void sayName() const override { std::cout << "Dog\n"; }
};

struct Huskey : Dog {
    void sayName() const override { std::cout << "Huskey\n"; }
};

struct Cat : Animal {
    void sayName() const override { std::cout << "Cat\n"; }
};

struct Mouse : Animal {};

int main() {
    Animal** animals = new Animal*[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Mouse();
    animals[3] = new Huskey();

    animals[0]->sayName();
    animals[1]->sayName();
    animals[2]->sayName();
    animals[3]->sayName();

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    delete[] animals;
}
```
## Snippet 02

Какво ще бъде изведено на стандартния изход?

```cpp
#include <iostream>

class A {
    int x;
};

class B : public A {
    int y;

    virtual void f() {}
};

class C : public A {
public:
    virtual void g() {}
};

class D : public B {
    int y;
};

int main() {
    std::cout << "sizeof(A): " << sizeof(A) << '\n';
    std::cout << "sizeof(B): " << sizeof(B) << '\n';
    std::cout << "sizeof(C): " << sizeof(C) << '\n';
    std::cout << "sizeof(D): " << sizeof(D) << '\n';
}
```
## Snippet 03

Какво ще бъде изведено на стандартния изход? Има ли проблем със следния snippet? Как бихте го поправили?

```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal sound\n";
    }
    ~Animal() {
        std::cout << "~Animal()\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof\n";
    }
    ~Dog() {
        std::cout << "~Dog()\n";
    }
};

int main() {
    Animal* ptr = new Dog();

    ptr->speak();

    delete ptr;
}
```
## Snippet 04

Какво ще бъде изведено на стандартния изход?

```cpp
#include <iostream>

class Base {
public:
    Base() {
        print();
    }

    virtual void print() {
        std::cout << "Base\n";
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived\n";
    }
};

int main() {
    Derived d;
}
```
## Snippet 05

Какво ще бъде изведено на стандартния изход?

```cpp
#include <iostream>

class Base {
public:
    virtual void print(int x = 1) {
        std::cout << "Base\n";
        std::cout << x << '\n';
    }
};

class Derived : public Base {
public:
    void print(int x = 2) override {
        std::cout << "Derived\n";
        std::cout << x << '\n';
    }
};

int main() {
    Base* ptr = new Derived();

    ptr->print();

    delete ptr;
}
```
## Snippet 06

Има ли проблем със следния snippet?

```cpp
#include <iostream>

class Base {
public:
    virtual void print(int x) = 0;
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived\n";
    }
};

int main() {
    Base b;
}
```
