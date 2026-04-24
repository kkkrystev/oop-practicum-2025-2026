#include "Note.h"
#include <cstddef>
#include <memory>
#include <string>
#pragma once

class SharedNote {
private:
    std::shared_ptr<Note> document;

public:
    SharedNote();
    explicit SharedNote(std::shared_ptr<Note> document);

    void insert(const std::string& text);
    void erase(std::size_t count);
    void moveLeft(std::size_t steps);
    void moveRight(std::size_t steps);
    void undo();
    void redo();

    const char* c_str() const;
    std::size_t getCursor() const;
    std::shared_ptr<Note> getDocument() const;
};

