#include <string>
#include <vector>
#pragma once

class Note {
private:
    std::vector<std::string> states;
    std::size_t currentState;

    void discardRedoStates();
    void saveState(std::string newState);

public:
    Note();

    void insert(std::size_t pos, const std::string& text);
    void erase(std::size_t pos, std::size_t count);
    void append(const std::string& text);

    void undo();
    void redo();

    const char* c_str() const;
    const std::string& getText() const;
    std::size_t size() const;
};

