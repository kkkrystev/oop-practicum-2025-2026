# Snippets - 19.05.2026

## Snippet 01

Какво ще бъде изведено на стандартния изход?
```cpp
#include <print>
#include <stdexcept>

int divide(int a, int b) {
	std::print("Dividing...");
    if (b == 0)
        throw std::runtime_error("Division by zero!");
    return a / b;
}

int main() {
	int divisionResult;
    try {
        divisionResult = divide(10, 2);
        std::print("Success: Result is {}\n", divisionResult);

		divisionResult = divide(10, 0);
        std::print("Success: Result is {}\n", divisionResult);
    }
    catch (const std::exception& e) {
        std::print("Failure: {}\n", e.what());
    }
	std::print("Final valid result is {}\n", divisionResult);
}
```
## Snippet 02

Какво ще бъде изведено на стандартния изход?
```cpp
#include <print>
#include <stdexcept>

class A {
public:
    A() { std::print("A()\n"); }
    ~A() { std::print("~A()\n"); }
};

class B {
public:
    B() {
        std::print("B()\n");
        throw std::runtime_error("B() failed");
    }
    ~B() { std::print("~B()\n"); }
};

class C {
    A a;
    B b;
public:
    C() { std::print("C()\n"); }
    ~C() { std::print("~C()\n"); }
};

int main() {
    try {
        C c;
    }
    catch (const std::exception& e) {
        std::print("{}\n", e.what());
    }
}
```
## Snippet 03

Какво ще бъде изведено на стандартния изход? Има ли проблем с програмата? Как бихме го поправили?
```cpp
#include <print>
#include <stdexcept>

class Base {
public:
    Base() { std::print("Base()\n"); }
    ~Base() { std::print("~Base()\n"); }
};

class Derived : public Base {
public:
	Derived() { std::print("Derived()\n"); }
    ~Derived() {
        std::print("~Derived()\n");
        throw std::runtime_error("Error in destructor!");
    }
};

int main() {
    try {
        Derived d;
    }
    catch (const std::exception& e) {
        std::print("{}\n", e.what());
    }
}
```
## Snippet 04

Какво ще бъде изведено на стандартния изход?
```cpp
#include <print>
#include <stdexcept>

void foo() { throw std::runtime_error("runtime error"); }

void bar() {
    try {
        foo();
    }
    catch (std::exception e) {
        std::print("caught in bar\n");
        throw e;
    }
}

int main() {
    try {
        bar();
    }
    catch (const std::runtime_error& e) {
        std::print("runtime_error\n");
    }
    catch (const std::exception& e) {
        std::print("exception\n");
    }
}
```
## Snippet 05

Какъв е проблемът със следния код? Как бихме го поправили?
```cpp
#include <print>
#include <stdexcept>

class A {
    int* ptr1;
    int* ptr2;
public:
    A() {
        ptr1 = new int[10];
        std::print("ptr1 allocated\n");

        ptr2 = new int[1000000000000]; // 1 trillion
        std::print("ptr2 allocated\n");
    }
    ~A() {
        delete[] ptr1;
        delete[] ptr2;
    }
};

int main() {
    try {
        A a;
    }
    catch (...) {
        std::print("allocation failed\n");
    }
}
```
## Snippet 06

Опишете последователността от събития, които се случват по време на изпълнение на следния код.
```cpp
#include <print>
#include <stdexcept>

void foo() noexcept{
    std::print("foo\n");
    throw std::runtime_error("error");
}

int main() {
    try {
        foo();
    }
    catch (...) {
        std::print("caught\n");
    }
}
```