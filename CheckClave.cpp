/* 
 * File:   CheckClave.cpp
 * Author: Carolina y María
 * 
 * Created on 13 de noviembre de 2015, 17:57
 */

#include "CheckClave.h"
#include <fstream>
#include "file not found.h"
#include <iostream>
/**
* CheckKey constructor
* read the file lemario-espanol-utf8.txt and initialize tree
*/
CheckClave::CheckClave() {
    ifstream fichero;
    fichero.open("lemario-espanol-utf8.txt");
    if (fichero.good()) {
        string word;
        while (!fichero.eof()) {
            fichero >> word;
            arbol.insert(word);
        }
    } else {
        throw file_not_found();
    }

    fichero.close();
}
/**
* CheckKey copy constructor
* @param orig a checkKey
*/
CheckClave::CheckClave(CheckClave& orig) {
    this->arbol = orig.arbol;
}
/**
 * CheckKey destructor
 */
CheckClave::~CheckClave() {
    arbol.clear();
}
/**
 * Operator= CheckKey
 * define operator =
 * @param c a checkKey
 * @return a checkKey
 */
CheckClave& CheckClave::operator=(CheckClave &c) {
    this->arbol = c.arbol;
    return *this;
}
/**
 * Check function
 * check is the password is correct, if it is correct return 0
 * @param s a word
 * @return an integer (0 if key is correct)
 */
int CheckClave::check(string& s) {
    //Paso las mayusculas a minusculas
    transform(s.begin(), s.end(), s.begin(), ptr_fun<int, int>(tolower));
    set<string>::iterator i = arbol.begin();
    //Realizo el check
    string result;
    int contador = s.size();
    if (contador < 6) {
        return -1;
    } else if (arbol.find(s) != arbol.end()) {
        return -2;
    } else if ((i = arbol.lower_bound(s)) != arbol.end()) {
        if (i != arbol.begin()) {
            i--;
        }
        result = *i;
        if (s.find(result) != std::string::npos) { //Compruebo si s es una subcadena de result
            return -3;
        } else {
            return 0;
        }

    } else {
        return 0;
    }

}