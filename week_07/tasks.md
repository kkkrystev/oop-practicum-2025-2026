# Задачи - 31.03.2026

### *Общи указания*

- *Да не се допуска изтичане на памет*
- *Да се използват помощни функции: `copyFrom`, `moveFrom`, `free`, `resize`*
- *Да се спазва коректна move семантика*

## Задача 1

Да се реализира клас `Text`, който пази текст в динамична памет:

```cpp
char* data;
```

### Изисквания
Да се реализират:
- Default constructor
- Конструктор от C-string
- Destructor
- Copy constructor
- Copy assignment operator
- Move constructor
- Move assignment operator

### Методи
- `const char* c_str() const`
- `size_t size() const`
- `void print() const`

### Уточнения
- При копиране да се създава нов буфер и да се копира съдържанието
- При move да се прехвърля указателят без копиране
- Преместеният обект да остава във валидно състояние

## Задача 2 - Notebook

Да се реализира система за работа с бележки, състояща се от класовете `Note` и `Notebook`.

### Клас `Note`

Член-данни:
```cpp
unsigned id;
char* title;
char* content;
```

Изисквания:
- динамична памет за `title` и `content`
- Rule of Five
- статичен генератор на id
- запис и четене на един обект от двоичен файл

Методи:
- `setTitle`, `setContent`
- `getTitle`, `getContent`, `getId`
- `print`
- `saveToFile`, `readFromFile`

---

### Клас `Notebook`

Член-данни:
```cpp
char* name;
Note* notes;
size_t size;
size_t capacity;
```

Изисквания:
- Rule of Five
- динамичен масив от `Note`
- добавяне (copy и move), премахване и търсене по id
- запис и четене на целия обект от файл

Методи:
- `addNote(const Note&)`
- `addNote(Note&&)`
- `removeNoteById`
- `findById`
- `printAll`
- `saveToFile`
- `readFromFile`

## Задача 3 - Car dealership

Да се реализира система за управление на автокъща.

### Клас `Car`

Член-данни:
```cpp
unsigned id;
char* brand;
char* model;
unsigned year;
double price;
char** features;
size_t featuresCount;
```

Изисквания:
- динамична памет
- Rule of Five
- статичен генератор на id

Методи:
- `addFeature`, `removeFeature`, `hasFeature`
- `changePrice`
- `print`
- getter-и

---

### Клас `CarDealership`

Член-данни:
```cpp
char* name;
Car* cars;
size_t size;
size_t capacity;
```

Изисквания:
- Rule of Five
- динамичен масив от `Car`
- добавяне (copy и move)
- премахване и търсене по id

Методи:
- `addCar(const Car&)`
- `addCar(Car&&)`
- `removeCarById`
- `findCarById`
- `printAll`
- `printCarsByBrand`
- `getAveragePrice`
- `sellCar`