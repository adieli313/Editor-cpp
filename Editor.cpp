/*Adiel Itzhak 313485286*/
/*Inbar Dahari 205561582*/
#include "Editor.h"
#include <iostream>
using namespace std;

Editor::Editor(){
    doc = new Document();
}

code Editor::code_num(string input){
    if (input == "p") return code::printLine;
    if (input == "n") return code::printNumLine;
    if (input == "%p") return code::printAllLines;
    if (input == "a")return code::appendText;
    if (input == "i") return code::insertBeforeLine;
    if (input == "c") return code::changeCurrentLine;
    if (input == "d") return code::deleteCurrent;
    if (input.at(0) == '/') return code::search;
    if (input.at(0) == 's') return code::replace;
    if (input == "Q") return code::quit;
    int number;
    std::istringstream iss (input);
    iss >> number;
    if (number > 0) {
        doc->setCurrentLine(number);
        return code ::setCurrentLine;
    }
    else return code::def;
}
void Editor::loop(){
    while(1) {
        string input;
        cin >> input;
            switch (code_num(input)) {
                case code::printLine: {
                    doc->Document::printLine();
                    break;
                }

                case code::printNumLine: {
                    doc->Document::printNumLine();
                    break;
                }

                case code::printAllLines: {
                    doc->Document::printAllLines();
                    break;
                }

                case code::appendText: {
                    doc->Document::appendText();
                    break;
                }

                case code::insertBeforeLine: {
                    doc->Document::insertBeforeLine();
                    break;
                }

                case code::changeCurrentLine: {
                    doc->Document::changeCurrentLine();
                    break;
                }

                case code::deleteCurrent: {
                    doc->Document::deleteCurrent();
                    break;
                }
                case code::search: {
                    doc->Document::search(input.substr(1,input.size()));
                    break;
                }
                case code::replace: {
                    doc->Document::replace(input.substr(2,input.size()));
                    break;
                }

                case code::quit : {
                    doc->Document::quit();
                    break;
                }



            }
    }

}


