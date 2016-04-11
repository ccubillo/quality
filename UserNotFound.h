/**
 * @brief Header of UserNotFound.
 * @author: Carolina y Maria
 * @since 1.0
 */

#ifndef USER_NOT_FOUND_H
#define	USER_NOT_FOUND_H

#include <exception>

using namespace std;

/**
 * custom exception thrown in case of no user is found.
 * @brief Show user not found exception
 */
class user_not_found: public exception{
public:
    /**
     * shows the exception information when called.
     * In this case, the information is the string "Usuario no encontrado".
     */
    virtual const char* what() const throw(){
        return "Usuario no encontrado";
    }

    /**
     * exception destructor.
     * does nothing.
     */
    virtual ~user_not_found() throw(){}
};

#endif	/* USER_NOT_FOUND_H */

