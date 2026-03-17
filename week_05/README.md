# Практикум 05 - 17.03.2026

## Code snippets

### Snippet #1 

```c++
#include <iostream>

class A {
public:
    A() { std::cout << "A()\n"; }
    ~A() { std::cout << "~A()\n"; }
};

class B {
    A a;
public:
    B() { std::cout << "B()\n"; }
    B(int x) { std::cout << "B(" << x << ")\n"; }
    ~B() { std::cout << "~B()\n"; }
};

int main() {
    B* ptr = new B[2]{ 1 };
    B obj;
    delete[] ptr;
}
```

### Snippet #2

```c++
#include <iostream>

class X {
    int val;
public:
    explicit X(int v) : val(v) { std::cout << "X(" << val << ")\n"; }
    ~X() { std::cout << "~X(" << val << ")\n"; }
};

class Y {
    X x1;
    X x2;
public:
    Y() : x2(2), x1(1) { std::cout << "Y()\n"; }
    ~Y() { std::cout << "~Y()\n"; }
};

int main() {
    Y obj;
}
```

### Snippet #3

```c++
#include <iostream>

class Logger {
    mutable int count = 0;
public:
    void log() const { 
        count++; 
        std::cout << "Log #" << count << "\n"; }
};

class App {
    Logger l;
public:
    App() { std::cout << "App()\n"; }
    void run() const { l.log(); }
};

int main() {
    const App app;
    app.run();
    app.run();

    App arr[2];
    arr[0].run();
}
```

### Snippet #4

```c++
#include <iostream>

class Counter {
    static int count;
public:
    Counter() { 
        count++; 
        std::cout << "Counter(), count=" 
            << count << "\n"; 
    }
    ~Counter() { 
        count--; 
        std::cout << "~Counter(), count=" 
            << count << "\n"; 
    }
};

int Counter::count = 0;

int main() {
    Counter* arr = new Counter[3];
    Counter c;
    delete[] arr;
}
```

### Snippet #5

```c++
#include <iostream>

class A {
	int value;
public:
	A(int v = 5) : value(v) {
		std::cout << "A(" << v << ")" << std::endl;
	}
	~A() {
		std::cout << "~A(" << value << ")" << std::endl;
	}
};

int main() {
	A obj;
	A* ptr = new A(10);
	delete ptr;
}
```

### Snippet #6

```c++
class Engine {
public:
    Engine() { std::cout << "Engine()\n"; }
    ~Engine() { std::cout << "~Engine()\n"; }
};

class Car {
    Engine e;   
    Engine* e2; 
public:
    Car(Engine* ptr) : e2(ptr) { std::cout << "Car()\n"; }
    ~Car() { std::cout << "~Car()\n"; }
};

int main() {
    Engine eng;
    Car c(&eng);
}
```

### Snippet #7

```c++
#include <iostream>

class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}

	~A() {
		std::cout << "~A()" << std::endl;
	}
};

class B {
	A a;
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};

class C {
	A a;
	B b;
public:
	C() : b(), a() {
		std::cout << "C()" << std::endl;
	}
	~C() {
		std::cout << "~C()" << std::endl;
	}
};

int main() {
	C arr1[2];
	C* ptr = new C();
	return 0;
}
```

### Snippet #8

```c++
#include <iostream>

class A {
public:
    A() { std::cout << "A()\n"; }
    ~A() { std::cout << "~A()\n"; }
};

void f() {
    static A a;
    std::cout << "f()\n";
}

int main() {
    f();
    f();
}
```

### Snippet #9

```c++
#include <iostream>

class A {
public:
    A(int id) { std::cout << "A(" << id << ")\n"; }
    ~A() { std::cout << "~A()\n"; }
};

int main() {
    A a1(1);
    {
        A a2(2);
        A a3(3);
    }
    A a4(4);
}
```

### Snippet #10

```c++
#include <iostream>

class A {
    int& ref;
public:
    A(int& x) {
        ref = x;
        std::cout << "A()\n";
    }
};

int main() {
    int x = 10;
    A a(x);
}
```

## Live coding - FMICodes