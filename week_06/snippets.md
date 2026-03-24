# Code snippets - 24.03.2026

## Snippet 1

```c++
class A
{
public:
	A() { std::cout << "A() "; }
	
	~A() { std::cout << "~A() "; }
};

class B
{
public:
	B() { std::cout << "B() "; }

	~B() { std::cout << "~B() "; }
};

class X
{
	A a;
	B b;

public:
	X() : a(), b() 
	{ std::cout << "X() "; }

	~X() { std::cout << "~X() "; }
};

int main()
{
	X x;
}
```

## Snippet 2

```c++
class Student {
private:
    char* _name = nullptr;

public:
    Student(const char* name) {
        _name = new char[std::strlen(name) + 1];
        std::strcpy(_name, name);
    }

    ~Student() {
        if (_name != nullptr)
            delete[] _name;
    }
};

int main() {
    Student s1("Ivan");
    Student s2 = s1;   
}
```

## Snippet 3

```c++
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#pragma warning (disable : 4996)

class Student {
private:
    char* _name = nullptr;

    void copyFrom(const Student& other) {
        _name = new char[strlen(other._name) + 1];
        std::strcpy(_name, other._name);
    }

    void free() {
        if (_name != nullptr)
            delete[] _name;
    }

public:
    Student(const char* name) {
        _name = new char[std::strlen(name) + 1];
        std::strcpy(_name, name);
    }

    Student(const Student& other) {
        copyFrom(other);
    }

    Student& operator=(const Student& other)
    {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    void setName(const char* name)
    {
        if (_name)
            delete[] _name;
        _name = new char[std::strlen(name) + 1];
        std::strcpy(_name, name);
    }

    void printName() const
    {   
        std::cout << _name << '\n';
    }

    ~Student() {
        free();
    }
};

int main() {
    Student s1("Ivan");
    Student s2 = s1;   
    s2.setName("Petio");

    s1.printName();
    s2.printName();
}
```

## Snippet 4

```c++
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#pragma warning (disable : 4996)

class A
{
	int* _a;
public:

	A(size_t size) 
	{
		_a = new int[size] {0};
	}

	A(const A& other) = delete;
	A& operator=(const A& other) = delete;

	~A()
	{
		delete _a;
	}
};

int main() {

}
```

## Snippet 5

```c++
#include <iostream>

class A {
public:
    A() { std::cout << "Constructor\n"; }
    A(const A&) { std::cout << "Copy constructor\n"; }
};

A create() {
    return A();
}

int main() {
    A obj = create();
}
```

## Snippet 6

```c++
#include <iostream>

class X {
public:
    X() { std::cout << "default\n"; }
    X(const X&) { std::cout << "copy\n"; }
    X& operator=(const X&) {
        std::cout << "assign\n";
        return *this;
    }
};

int main() {
    X a;      
    X b = a;  
    X c;      
    c = a;    
}
```

## Snippet 7

Въпрос: Къде е memory leak-а?

```c++
#include <iostream>

class Leak {
private:
    int* data;

public:
    Leak() {
        data = new int[10];
    }

    Leak(const Leak& other) {
        data = new int[10];
        for (int i = 0; i < 10; i++) {
            data[i] = other.data[i];
        }
    }

    Leak& operator=(const Leak& other) {
        data = new int[10];
        for (int i = 0; i < 10; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    ~Leak() {
        delete[] data;
    }
};
```