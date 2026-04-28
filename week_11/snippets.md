# Snippets - 28.04.2026

## 1. Какво ще изведе конзолата?

```cpp
template<class T = int>
class Pair
{
    T _one;
    T _two;

public:

    Pair(T one, T two) : _one(one), _two(two) { std::cout << "other\n"; }
    Pair(int one, int two) : _one(one), _two(two) { std::cout << "int\n"; }
};

int main()
{
    Pair<double> p1(1, 2);
    Pair<double> p2(1.1, 2);
    Pair<double> p3(1.1, 2.2);
}
```

Отговор:
int
other
other

---

## 2. TypeList

```cpp
template <class... Types>
class TypeList
{
public:
    size_t size() const
    {
        return sizeof...(Types);
    }

    template <typename T>
    bool contains() const
    {
        return (std::is_same_v<T, Types> || ...);
    }

    void printTypes() const
    {
        ((std::cout << typeid(Types).name() << '\n'), ...);
    }
};

int main()
{
    TypeList<int, int, double> tl;
    std::cout << tl.contains<int>() << '\n';
    std::cout << tl.contains<bool>() << '\n';
    std::cout << tl.contains<const int>() << '\n';
    std::cout << tl.contains<10>() << '\n';   // template <auto... Values>
    tl.printTypes();
}
```

Забележка: contains<10>() няма да се компилира.

---

## 3. tuple пример

```cpp
    std::tuple<int, double, std::string> t(5, 3.14, "hello");
    std::cout << std::get<0>(t) << "\n"; // 5
    std::cout << std::get<1>(t) << "\n"; // 3.14
    std::cout << std::get<2>(t) << "\n"; // hello
```

---

## 4. tuple грешки

```cpp
int main()
{
    std::tuple<int> a1(10, 2);
    std::tuple<int, bool> a2(10, 2);
    std::tuple<int, double> a3(10, 2);
    std::tuple<int, double, std::string> a4(10, 2);
    std::tuple<int, double, std::string> a5(10, "BA", "AB");
}
```

---

## 5. make_tuple vs tie

```cpp
template <typename T>
void print(T x)
{
    std::get<0>(x) = 100;
}

int main()
{
    int a = 5;

    auto t1 = std::make_tuple(a);
    auto t2 = std::tie(a);

    print(t1);
    std::cout << a << " ";

    print(t2);
    std::cout << a << "\n";
}
```

---

## 6. tuple от references

```cpp
int main()
{
    int a = 1;
    int b = 2;

    std::tuple<int&, int&> t(a, b);

    std::get<0>(t) = 10;
    std::get<1>(t) = std::get<0>(t);

    std::cout << a << " " << b << "\n";
}
```

---

## 7. tuple_cat

```cpp
int main()
{
    auto t1 = std::make_tuple(1, 2.5);
    auto t2 = std::make_tuple(std::string("abc"), 'Z');

    auto result = std::tuple_cat(t1, t2);

    std::cout << std::get<0>(result) << " ";
    std::cout << std::get<1>(result) << " ";
    std::cout << std::get<2>(result) << " ";
    std::cout << std::get<3>(result) << "\n";
}
```