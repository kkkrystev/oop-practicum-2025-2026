# Задачи - 31.03.2026

## Задача 1 - MyString 

*Live coding. Реализация на copy и move семантики*

*Пълна реализация на задачата ще намерите [тук](https://github.com/kkkrystev/oop-practicum-2025-2026/tree/main/week_08/tasks_solutions/task-01_mystring).*

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