#include "SharedNote.h"
#include <algorithm>

static size_t cursor = 0;

SharedNote::SharedNote() : document(std::make_shared<Note>()) {}

SharedNote::SharedNote(std::shared_ptr<Note> document)
    : document(std::move(document))
{
    if (!this->document) 
    {
        return;
        //throw std::invalid_argument("SharedNote requires a valid Note instance.");
    }
}

void SharedNote::insert(const std::string& text)
{
    document->insert(cursor, text);
    cursor += text.size();
}

void SharedNote::erase(std::size_t count) 
{
    document->erase(cursor, count);
    cursor = std::min(cursor, document->size());
}

void SharedNote::moveLeft(std::size_t steps) 
{
    if (steps > cursor) 
    {
        cursor = 0;
        return;
    }

    cursor -= steps;
}

void SharedNote::moveRight(std::size_t steps)
{
    const std::size_t newCursor = cursor + steps;
    cursor = std::min(newCursor, document->size());
}

void SharedNote::undo() 
{
    document->undo();
    cursor = std::min(cursor, document->size());
}

void SharedNote::redo() 
{
    document->redo();
    cursor = std::min(cursor, document->size());
}

const char* SharedNote::c_str() const
{
    return document->c_str();
}

std::size_t SharedNote::getCursor() const 
{
    return cursor;
}

std::shared_ptr<Note> SharedNote::getDocument() const
{
    return document;
}
