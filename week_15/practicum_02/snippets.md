# Snippets - 29.05.2026
## Snippet 01

Какво ще се изведе на стандартния изход?

```cpp
#include <iostream>

class A {
    int x;
};

class B : public A {
    int y;
};

class C : public virtual A {
    int y;
};

class D : public virtual C {
    int z;
};

int main() {
    std::cout << "sizeof(A): " << sizeof(A) << '\n';
    std::cout << "sizeof(B): " << sizeof(B) << '\n';
    std::cout << "sizeof(C): " << sizeof(C) << '\n';
    std::cout << "sizeof(D): " << sizeof(D) << '\n';
}
```
## Snippet 02

Какво ще се изведе на стандартния изход?

```cpp
#include <print>

class A {
public:
    A(int x) {
        std::print("A({})\n", x);
    }
};

class B : virtual public A {
public:
    B() : A(1) {
        std::print("B()\n");
    }
};

class C : public B {
public:
    C() : A(2) {
        std::print("C()\n");
    }
};

int main() {
    C obj;
}
```
## Snippet 03

Какво ще се изведе на стандартния изход?

```cpp
#include <iostream>

class A {};

class B : public A {};

class C : virtual public A {};

void foo(A* ptr) {
    std::cout << "A ptr: " << ptr << '\n';
}

int main() {
    B b;
    C c;

    std::cout << "B ptr: " << &b << '\n';
    foo(&b);

    std::cout << "C ptr: " << &c << '\n';
    foo(&c);
}
```
## Snippet 04

Какво ще се изведе на стандартния изход?

```cpp
#include <print>

struct A {
    A(int x) { std::print("A({})\n", x); }
};

struct B {
    B(int x) { std::print("B({})\n", x); }
};

struct C : public A, public B {
    C() : B(2), A(1) {
        std::print("C()\n");
    }
};

int main() {
    C obj;
}
```
## Snippet 05

Какво ще се изведе на стандартния изход?

```cpp
#include <print>

struct A {
    int x = 10;
};

struct B : public A {};
struct C : public A {};

struct D : public B, public C {};

int main() {
    D obj;
	
	std::print("{}\n", obj.x);
	
    std::print("{}\n", obj.B::x);
    std::print("{}\n", obj.C::x);

    obj.B::x = 20;
    obj.C::x = 30;

    std::print("{}\n", obj.B::x);
    std::print("{}\n", obj.C::x);

    std::print("{}\n", obj.x);
}
```
## Snippet 06

Какво ще се изведе на стандартния изход?

```cpp
#include <print>

struct A {
    int x = 10;
};

struct B : virtual public A {};
struct C : virtual public A {};

struct D : public B, public C {};

int main() {
    D obj;

    std::print("{}\n", obj.x);

    obj.B::x = 20;
    std::print("{}\n", obj.C::x);

    obj.C::x = 30;
    std::print("{}\n", obj.B::x);

    std::print("{}\n", obj.x);
}
```
## Snippet 07

Какво ще се изведе на стандартния изход?

```cpp
#include <print>

struct A {
    A(int x) { std::print("A({})\n", x); }
};

struct B : virtual public A {
    B() : A(1) { std::print("B()\n"); }
};

struct C : virtual public A {
    C() : A(2) { std::print("C()\n"); }
};

struct D : public B, public C {
    D() : A(3), B(), C() { std::print("D()\n"); }
};

int main() {
    D obj;
}
```

## Snippet 08

Какво ще се изведе на стандартния изход?

```cpp
#include <print>

struct A {
    A(int x) { std::print("A({})\n", x); }
};

struct B : virtual public A {
    B() : A(1) { std::print("B()\n"); }
};

struct C : public A {
    C() : A(2) { std::print("C()\n"); }
};

struct D : public B, public C {
    D() : B::A(3), B(), C() { std::print("D()\n"); }
};

int main() {
    D obj;
}
```

## Snippet 09

Какво ще се изведе на стандартния изход? *Разиграйте няколко случая, като смените конструктора, който хвърля изключението.*

```cpp
#include <string>
#include <print>
#include <stdexcept>

struct MyError : std::runtime_error {
	MyError(const std::string& error_msg) : runtime_error(error_msg) {}
};

struct A {
	A() { std::print("A()\n"); }
	~A() { std::print("~A()\n"); }
};

struct B : virtual A {
	B() { 
		std::print("B()\n"); 
		throw MyError("Failed to construct B\n");
	}
	~B() { std::print("~B()\n"); }
};

struct C : virtual A{
	C() { std::print("C()\n"); }
	~C() { std::print("~C()\n"); }
};

struct D : B, C {
	D() { std::print("D()\n"); }
	~D() { std::print("~D()\n"); }
};

int main() {
	try {
		D d;
		std::print("Success!\n");
	}
	catch (const std::runtime_error& e) {
		std::print("{}", e.what());
	}
}
```
