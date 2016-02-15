/* 
 * File:   user not found.h
 * Author: Carolina y María
 *
 * Created on 18 de noviembre de 2015, 18:08
 */

#ifndef USER_NOT_FOUND_H
#define	USER_NOT_FOUND_H
#include <exception>
using namespace std;

class user_not_found: public exception{
public:
    virtual const char* what() const throw(){
        return "Usuario no encontrado";
    }
    virtual ~user_not_found() throw(){}
};

#endif	/* USER_NOT_FOUND_H */

