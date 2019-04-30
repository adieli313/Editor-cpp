/*Adiel Itzhak 313485286*/
/*Inbar Dahari 205561582*/
#include "Document.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Document::Document(){
    currLine = -1;
}

void Document::printLine(){
    if(isEmpty())return;
    cout << doc.at(currLine) <<endl;
    }

void Document::printNumLine(){
    if(isEmpty())return;
    cout << currLine+1 << "\t" << doc.at(currLine) <<endl;
}

void Document::printAllLines(){
    if(isEmpty())return;
    for (int i = 0; i < doc.size(); ++i) {
        cout << doc.at(i) << endl;
    }
}

void Document::setCurrentLine(int newCurr){
    currLine  =  newCurr-1;
    cout << doc.at(currLine) << endl;
}

void Document::appendText(){
    string text;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, text);
    while(text != "."){
        vector<string>::iterator it;
        it = doc.begin();
        currLine++;
        doc.insert(it + currLine, text);
        getline(cin, text);
    }
}

void Document::insertBeforeLine(){
    if(isEmpty())return;
    currLine--;
    appendText();
}

void Document::changeCurrentLine(){
    if(isEmpty())return;
    string text;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, text);
    deleteCurrent();
    while(text != "."){
        vector<string>::iterator it;
        it = doc.begin();
        currLine++;
        doc.insert(it + currLine, text);
        getline(cin, text);
    }

}

void Document::deleteCurrent(){
    doc.erase(doc.begin()+(currLine--));
}

void Document::search(string str){
    if(isEmpty())return;
    bool flag = true;
    int i = 0;
    for( i = currLine ; i < doc.size() ; i++ ){
        if(doc.at(i).find(str) != string::npos){
            cout << doc.at(i) <<endl;
            flag = false;
            currLine = i;
            break;
         }
    }
    if(flag){
        for(i = 0 ; i < currLine ; i++ ){
            if(doc.at(i).find(str) != string::npos){
                cout << doc.at(i) <<endl;
                currLine = i;
                break;
            }
        }
    }
}

void Document::replace(string str){
    str = str.substr(0,str.size()-1);
    if(isEmpty())return;
    string old , newStr;
    int sec = str.find("/");
    old = str.substr(0, sec);
    newStr = str.substr(sec + 1, str.size());
    int oldIndex = doc.at(currLine).find(old);
    if(oldIndex != string::npos)
    doc.at(currLine).replace(oldIndex, old.size(), newStr);
    else cerr << "old word not found." << endl;
}

void Document::quit(){
    exit(1);
}

bool Document::isEmpty(){
    if(currLine != -1)return false;
    else{
            cerr << "the document is empty." <<endl;
            return true;
    }
}