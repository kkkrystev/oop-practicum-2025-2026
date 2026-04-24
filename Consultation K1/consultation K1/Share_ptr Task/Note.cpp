#include "Note.h"

Note::Note() : states(1, ""), currentState(0) {}

void Note::discardRedoStates() 
{
    states.erase(states.begin() + static_cast<std::ptrdiff_t>(currentState) + 1, states.end());
}

void Note::saveState(std::string newState)
{
    discardRedoStates();
    states.push_back(std::move(newState));
    currentState = states.size() - 1;
}

void Note::insert(std::size_t pos, const std::string& text)
{
    const std::string& currentText = states[currentState];
    if (pos > currentText.size())
    {
        return;
        //throw std::out_of_range("Invalid insert position.");
    }

    std::string newText = currentText;
    newText.insert(pos, text);
    saveState(std::move(newText));
}

void Note::erase(std::size_t pos, std::size_t count)
{
    const std::string& currentText = states[currentState];
    if (pos > currentText.size())
    {
        return;
        //throw std::out_of_range("Invalid insert position.");
    }

    std::string newText = currentText;
    newText.erase(pos, count);
    saveState(std::move(newText));
}

void Note::append(const std::string& text) 
{
    insert(size(), text);
}

void Note::undo() {
    if (currentState > 0) 
    {
        --currentState;
    }
}

void Note::redo() {
    if (currentState + 1 < states.size())
    {
        ++currentState;
    }
}

const char* Note::c_str() const 
{
    return states[currentState].c_str();
}

const std::string& Note::getText() const
{
    return states[currentState];
}

std::size_t Note::size() const
{
    return states[currentState].size();
}
