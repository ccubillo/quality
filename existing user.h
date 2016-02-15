/* 
 * File:   existing user.h
 * Author: Carolina y María
 *
 * Created on 18 de noviembre de 2015, 18:05
 */

#ifndef EXISTING_USER_H
#define	EXISTING_USER_H
#include <exception>
using namespace std;

class existing_user: public exception{
public:
    virtual const char* what() const throw(){
        return "Usuario existente";
    }
    virtual ~existing_user() throw(){}
};

#endif	/* EXISTING_USER_H */

