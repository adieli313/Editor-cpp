/*Adiel Itzhak 313485286*/
/*Inbar Dahari 205561582*/
#pragma once
#ifndef EDITOR_EDITOR_H
#define EDITOR_EDITOR_H

#endif //EDITOR_EDITOR_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Document.h"
using namespace std;
// enum class to classify the commands.
enum class code {
    printLine,
    printNumLine,
    printAllLines,
    setCurrentLine,
    appendText,
    insertBeforeLine,
    changeCurrentLine,
    deleteCurrent,
    search,
    replace,
    quit,
    def
};

class Editor {
    //class members.
private:
    Document *doc;
    code code_num(string input);
    //class functions.
public:
    void loop();
    Editor();
};

