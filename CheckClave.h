/**
 * @author: Carolina y Maria
 * @since 1.0
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
     const int PASSWORD_SIZE = 6;
public:

    CheckClave();
    CheckClave(CheckClave& orig);
    virtual ~CheckClave();
    CheckClave& operator=(CheckClave &c);
    int check(string &s);


};

#endif	/* CHECKCLAVE_H */

