/*Adiel Itzhak 313485286*/
/*Inbar Dahari 205561582*/
#pragma once
#ifndef EDITOR_DOCUMENT_H
#define EDITOR_DOCUMENT_H

#endif //EDITOR_DOCUMENT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Document {

    //class members.

private:
    vector<string> doc;
    int currLine;

    //class functions.
public:
    Document();
    void printLine();
    void printNumLine();
    void printAllLines();
    void setCurrentLine(int newCurr);
    void appendText();
    void insertBeforeLine();
    void changeCurrentLine();
    void deleteCurrent();
    void search(string str);
    void replace(string str);
    bool isEmpty();
    void quit();
};