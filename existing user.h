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
/**
 * Existing user exception
 */
class existing_user: public exception{
public:
	/**
	 * A exception
	 * Show the exception when user already exists in the system
	 * @return
	 */
    virtual const char* what() const throw(){
        return "Usuario existente";
    }
    virtual ~existing_user() throw(){}
};

#endif	/* EXISTING_USER_H */

