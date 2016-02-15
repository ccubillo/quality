/* 
 * File:   password not accepted.h
 * Author: Carolina y María
 *
 * Created on 18 de noviembre de 2015, 18:06
 */

#ifndef PASSWORD_NOT_ACCEPTED_H
#define	PASSWORD_NOT_ACCEPTED_H
#include <exception>
using namespace std;

class password_not_accepted: public exception{
public:
    virtual const char* what() const throw(){
        return "Clave no valida";
    }
    virtual ~password_not_accepted() throw(){}
};

#endif	/* PASSWORD_NOT_ACCEPTED_H */

