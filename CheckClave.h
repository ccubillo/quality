/* 
 * File:   CheckClave.h
 * Author: Carolina y María
 *
 * Created on 13 de noviembre de 2015, 17:57
 */

#ifndef CHECKCLAVE_H
#define	CHECKCLAVE_H
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <cctype>
using namespace std;
/**
 * CheckKey class
 */
class CheckClave {
private:
    set<string> arbol;///<tree compounds of words
public:

    CheckClave();
    CheckClave(CheckClave& orig);
    virtual ~CheckClave();
    CheckClave& operator=(CheckClave &c);
    int check(string &s);


};

#endif	/* CHECKCLAVE_H */

