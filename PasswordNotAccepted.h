/**
 * @brief Header of PasswordNotAccepted.
 * @author: Carolina y Maria
 * @since 1.0
 */

#ifndef PASSWORD_NOT_ACCEPTED_H
#define	PASSWORD_NOT_ACCEPTED_H

#include <exception>

using namespace std;

/**
 * custom exception thrown when a password is not valid.
 * @brief Show password not accepted exception
 */
class password_not_accepted: public exception{
public:
    /**
     * shows the exception information when called.
     * In this case, the information is the string "Clave no valida".
     */
    virtual const char* what() const throw(){
        return "Clave no valida";
    }

    /**
     * exception destructor.
     * does nothing.
     */
    virtual ~password_not_accepted() throw(){}
};

#endif	/* PASSWORD_NOT_ACCEPTED_H */

