# Code snippets - 07.04.2026

## Snippet 1 

Как се интерпретира изразът `a + b + c`?

```cpp
#include <iostream>

class Test
{
    int x;
public:
    Test(int x = 0) : x(x) {}

    Test operator+(const Test& other) const
    {
        std::cout << "operator+\n";
        return Test(x + other.x);
    }
};

int main()
{
    Test a(1), b(2), c(3);
    Test result = a + b + c;
}
```

## Snippet 2

Какво ще бъде изведено на стандартния изход?

```cpp
#include <iostream>

class Counter
{
    int x;
public:
    Counter(int x = 0) : x(x) {}

    Counter& operator++()
    {
        std::cout << "prefix\n";
        ++x;
        return *this;
    }

    Counter operator++(int)
    {
        std::cout << "postfix\n";
        Counter temp = *this;
        x++;
        return temp;
    }

    void print() const { std::cout << x << '\n'; }
};

int main()
{
    Counter c(5);

    (++c).print();
    (c++).print();
    c.print();
}
```

## Snippet 3

Липсва ли нещо в следващия snippet?

```cpp
#include <iostream>

class A
{
    int data[3] = {1, 2, 3};
public:
    int& operator[](int i)
    {
        return data[i];
    }
};

int main()
{
    const A a;
    std::cout << a[0];
}
```

## Snippet 4

Има ли грешка в следващия snippet?

```cpp
class A
{
    int x;
public:
    A(int x) : x(x) {}

    A& operator+(const A& other)
    {
        return A(x + other.x);
    }
};
```

## Snippet 5

Какво ще бъде изведено на стандартния изход?

```cpp
#include <iostream>

class A
{
    int* data;
public:
    A()
    {
        data = new int(5);
    }

    A(A&& other)
    {
        data = other.data;
        other.data = nullptr;
    }

    void print()
    {
        std::cout << *data << '\n';
    }
};

int main()
{
    A a;
    A b(std::move(a));

    a.print();
}
```