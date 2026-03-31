# Code snippets - 31.03.2026

## Snippet 1

```c++
#include <iostream>

int& f() 
{
    static int value = 10;
    return value;
}

int main() 
{
    f() = 5;
}
```

## Snippet 2

Има ли грешка в следния snippet? Ако има, какво бихте редактирали, за да работи коректно.

```c++
#include <iostream>

void f(int& value)
{
    std::cout << value << std::endl;
}

int main() 
{   
    int var = 10;
    f(var);
    f(10);
}
```

## Snippet 3

Има ли некоректни извиквания на функция? Кои са те?

```c++
#include <iostream>

void f(int a) { std::cout << "f()\n"; }

void g(int& a) { std::cout << "g(&)\n"; }

void h(int&& a) { std::cout << "h(&&)\n"; }

void j(const int& a) { std::cout << "j(const&)\n"; }

int main()
{
    int x = 10;

    f(x);
    f(10);
    f(std::move(x));

    g(x);
    g(10);
    g(std::move(x));

    h(x);
    h(10);
    h(std::move(x));

    j(x);           
    j(10);
    j(std::move(x));
}
```

## Snippet 4

Какво ще бъде изведено на стандартния изход?

```c++

void printString(const std::string& s) 
{
    std::cout << "[lvalue] " << s << std::endl;
}

void printString(std::string&& s)
{
    std::cout << "[rvalue] " << s << std::endl;
}

int main()
{
    std::string s1 = "I <3";
    std::string s2 = "OOP";
    std::string s3 = s1 + " " + s2;

    printString(s3);
    printStirng(s1 + " " + s2);
}
```

## Snippet 5

```c++
#include <iostream>

class A {
	int *x;

public:
	A() {
		this->x = new int(10);
		std::cout << "A()" << std::endl;
	}

	~A() {
		if (!x) delete x;
		std::cout << "~A()" << std::endl;
	}

	void incrementX() {
		(*x)++;
	}

	void printX() {
		std::cout << x << std::endl;
	}
};

int main() {
	A a1;
	{
		A a2;
		a1 = a2;
	}
	a1.incrementX();
	a1.printX();
}
```

### Snippet(s) 6

```c++
#include <iostream>

struct C {
	bool x;

	C() { std::cout << "C()\n"; }

	C(const C& other) { std::cout << "copy C()\n"; }

	C& operator=(const C& other) 
    {
		std::cout << "C::op=" << std::endl;
		return *this;
	}

	~C() { std::cout << "~C\n"; }
};

C foo(bool b) 
{
	if (b) {
		C c1;
		c1.x = 0;
		return c1;
	}
	else {
		C c2;
		c2.x = 1;
		return c2;
	}
}

C bar(bool b) 
{
	C c1, c2;
	if (b) 
		return c1;
	return c2;
}

C baz() 
{
	return C();
}

int main() {
	C c1 = foo(true);

	C c2 = bar(false);

	C c3 = baz();

	C c4;
	c4 = baz();

    C c5(baz());
}
```
