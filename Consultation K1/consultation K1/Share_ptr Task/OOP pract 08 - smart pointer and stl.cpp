#include "ChatRoom.h"
#include "Chatter.h"
#include "Note.h"
#include "SharedNote.h"

#include <iostream>
#include <memory>

int main() {
    //Note note;
    //note.append("Hello");
    //note.insert(5, " world");
    //note.erase(5, 1);
    //std::cout << "Note: " << note.c_str() << '\n';

    auto sharedDocument = std::make_shared<Note>();
    SharedNote userA(sharedDocument);
    SharedNote userB(sharedDocument);

    userA.insert("Hi ");
    userB.insert("Bye");

    std::cout << (*sharedDocument).c_str();




    //userA.insert("Shared");
    //userB.moveRight(6);
    //userB.insert(" note");

    //std::cout << "SharedNote content: " << userA.c_str() << '\n';
    //std::cout << "User A cursor: " << userA.getCursor() << '\n';
    //std::cout << "User B cursor: " << userB.getCursor() << '\n';

    //auto alice = std::make_shared<Chatter>("Alice");
    //auto bob = std::make_shared<Chatter>("Bob");
    //auto carol = std::make_shared<Chatter>("Carol");

    //ChatRoom room("oop-group");
    //room.addUser(alice);
    //room.addUser(bob);
    //room.addUser(carol);

    //room.sendMessage("Alice", "Hello everyone");
    //room.muteUser("Carol");
    //room.sendMessage("Bob", "Carol should not receive this one");

    //std::cout << "\nBob inbox:\n";
    //for (const std::string& message : bob->getMessages()) {
    //    std::cout << message << '\n';
    //}

    //std::cout << "\nCarol inbox:\n";
    //for (const std::string& message : carol->getMessages()) {
    //    std::cout << message << '\n';
    //}

    //return 0;
}
