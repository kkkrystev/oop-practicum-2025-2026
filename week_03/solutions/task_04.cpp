#include <iostream>
#include <cstring>

const int MAX_STR_LENGTH = 50;
const int MAX_BOOKS = 150;

enum class Genre {
    Fiction,
    Fantasy,
    Dystopian,
    Mystery,
    History,
    Unknown
};

const char* getGenreName(Genre g) {
    switch (g) {
    case Genre::Fiction:   return "Fiction";
    case Genre::Fantasy:   return "Fantasy";
    case Genre::Dystopian: return "Dystopian";
    case Genre::Mystery:   return "Mystery";
    case Genre::History:   return "History";
    default:               return "Unknown";
    }
}

class Book {
    char title[MAX_STR_LENGTH + 1];
    char author[MAX_STR_LENGTH + 1];
    Genre genre;
    int year;
    int pages;
    bool borrowed;

public:
    Book() : genre(Genre::Unknown), year(0), pages(0), borrowed(false) {
        title[0] = '\0';
        author[0] = '\0';
    }
    Book(const char* title, const char* author, Genre genre, int year, int pages)
        : genre(genre), year(year), pages(pages), borrowed(false) {

        strcpy_s(this->title, MAX_STR_LENGTH + 1, title);
        strcpy_s(this->author, MAX_STR_LENGTH + 1, author);
    }

    const char* getTitle() const { return title; }
    const char* getAuthor() const { return author; }
    int getPages() const { return pages; }
    bool isBorrowed() const { return borrowed; }
    Genre getGenre() const { return genre; }

    void setBorrowed(bool status) { borrowed = status; }

    void print() const {
        std::cout << "\"" << title << "\" by " << author
            << " [" << getGenreName(genre) << "], "
            << year << "y., " << pages << " pages. "
            << (borrowed ? "(Borrowed)" : "(Available)");
    }
};

class Library {
    char libraryName[MAX_STR_LENGTH + 1];
    Book books[MAX_BOOKS];
    int booksCount;

public:
    Library(const char* name) : booksCount(0) {
        strcpy_s(libraryName, MAX_STR_LENGTH + 1, name);
    }

    bool addBook(const Book& b) {
        if (booksCount >= MAX_BOOKS)
            return false;

        books[booksCount++] = b;
        return true;
    }

    bool removeBook(const char* title) {
        for (int i = 0; i < booksCount; i++) {
            if (strcmp(books[i].getTitle(), title) == 0) {
                for (int j = i; j < booksCount - 1; j++) {
                    books[j] = books[j + 1];
                }
                booksCount--;
                return true;
            }
        }
        return false;
    }

    bool borrowBook(const char* title) {
        for (int i = 0; i < booksCount; i++) {
            if (strcmp(books[i].getTitle(), title) == 0 && !books[i].isBorrowed()) {
                books[i].setBorrowed(true);
                return true;
            }
        }
        return false;
    }

    int countBooksByAuthor(const char* author) const {
        int count = 0;

        for (int i = 0; i < booksCount; i++) {
            if (strcmp(books[i].getAuthor(), author) == 0)
                count++;
        }

        return count;
    }

    void printLongestBook() const {
        if (booksCount == 0) {
            std::cout << "No books in library.";
            return;
        }

        int maxIdx = 0;

        for (int i = 1; i < booksCount; i++) {
            if (books[i].getPages() > books[maxIdx].getPages())
                maxIdx = i;
        }

        std::cout << "Longest book: ";
        books[maxIdx].print();
    }

    void printAllBooks() const {
        std::cout << "--- Library: " << libraryName << " ---\n";

        if (booksCount == 0) {
            std::cout << "No books in library.";
            return;
        }

        for (int i = 0; i < booksCount; i++) {
            books[i].print();
            std::cout << '\n';
        }
    }
};