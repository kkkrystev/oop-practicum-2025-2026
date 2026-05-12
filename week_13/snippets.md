# Snippets - 11.05.2026

## Snippet 01

Какво ще бъде изведено на стандартния изход?

```cpp
#include <print>

class Base {
public:
    Base() { std::print("Base()\n"); }
    ~Base() { std::print("~Base()\n"); }
};

class Derived : public Base {
public:
    Derived(int i) { std::print("Derived({})\n", i); }
    ~Derived() { std::print("~Derived()\n"); }
};

int main() {
    Derived obj(10);
}
```
## Snippet 02

Какво ще бъде изведено на стандартния изход?

```cpp
#include <print>

class A {
	int val = 0;
public:
	void set(int newVal) { val = newVal; }
	void foo() { std::print("{}\n", val); }
};

class B : public A {
	int val = 1;
public:
	void bar() { std::print("{}\n", val); }
};

int main() {
	B b;
	b.set(10);
	b.foo();
	b.bar();
}
```
## Snippet 03

Какво не е "както трябва" със следния код?

```cpp
#include <print>
#pragma warning (disable : 4996)

class Base {
	std::string str;
public:
	Base(const std::string& str) : str(str) {}
};

class Der : public Base {
	char* ptr;

	void copyFrom(const Der& other) {
		ptr = new char[std::strlen(other.ptr) + 1];
		std::strcpy(ptr, other.ptr);
	}
	void free() {
		delete ptr;
		ptr = nullptr;
	}

public:
	Der(const char* str1, const char* str2) {
		this->ptr = new char[std::strlen(str2) + 1];
		std::strcpy(this->ptr, str2);
	}
	Der(const Der& other) { 
		copyFrom(other); 
	}
	Der& operator=(const Der& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
	~Der() { free(); }
};

int main() {}
```
## Snippet 04

*Следващия code snippet ще използваме, за да разиграем няколко сценария с имплементацията на `Derived`.*

```cpp
#include <print>

class Base {
public:
    int val;

    Base(int val = 0) : val(val) { 
        std::print("Base({})\n", val); 
    }
    Base(const Base& other) : val(other.val) { 
        std::print("Base(other)\n"); 
    }
    ~Base() { std::print("~Base()\n"); }
};

class Derived : public Base {
public:
    int dval;

    Derived(int val, int dval) : Base(val), dval(dval) {
        std::print("Der({},{})\n", val, dval);
    }
    Derived(const Derived& other) : Base(other), dval(other.dval) {
        std::print("Der(other)\n");
    }
    ~Derived() { std::print("~Der()\n"); }
};

int main() {
    Derived d1(1, 2);
    Derived d2 = d1;
}
```
## Snippet 05

Кои опити за достъп до член-данните на клас `X` са валидни и кои водят до компилационна грешка?

```cpp
#include <print>

class X {
public:
    int publicVar = 1;
protected:
    int protectedVar = 2;
private:
    int privateVar = 3;
};

class A : public X {
public:
    void show() {
        std::print("{}\n", publicVar);      
        std::print("{}\n", protectedVar);   
        std::print("{}\n", privateVar);
    }
};

class B : protected X {
public:
    void show() {
        std::print("{}\n", publicVar);  
        std::print("{}\n", protectedVar); 
        std::print("{}\n", privateVar);
    }
};

class C : private X {
public:
    void show() {
        std::print("{}\n", publicVar);      
        std::print("{}\n", protectedVar); 
        std::print("{}\n", privateVar);
    }
};

class D : public B {
public:
    void show() {
        std::print("{}\n", publicVar);    
        std::print("{}\n", protectedVar); 
        std::print("{}\n", privateVar);
    }
};

class E : public C {
public:
    void show() {
        std::print("{}\n", publicVar);      
        std::print("{}\n", protectedVar);   
        std::print("{}\n", privateVar);
    }
};

int main() {
    A a;
    B b;
    C c;

    std::print("{}\n", a.publicVar);
    std::print("{}\n", a.protectedVar);  
    std::print("{}\n", b.publicVar);      
    std::print("{}\n", c.publicVar);      
}
```
## Snippet 06

Какво ще бъде изведено на стандартния изход?

```cpp
#include <print>

class Base {
public:
    int value = 0;
};

class Derived : public Base {
public:
    int value = 1;
};

void foo_by_value(Base b) {
    std::print("by value: {}\n", b.value);
}

void foo_by_ref(Base& b) {
    std::print("by ref: {}\n", b.value);
}

void foo_by_ptr(Base* b) {
    std::print("by ptr: {}\n", b->value);
}

int main() {
    Derived d;

    foo_by_value(d);
    foo_by_ref(d);
    foo_by_ptr(&d);
}
```

