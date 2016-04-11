/**
 * @brief Source code of Usuario.
 * @author: Carolina y Maria
 * @since 1.0
 */

#include <sstream>
#include "Usuario.h"

/**
 * user default constructor.
 * sets all variables class members to null.
 */
Usuario::Usuario(): id("null"), clave("null"), nombre("null") {
}

/**
 * user constructor with parameters.
 * set the variables with the values passed.
 * @param [in] id the user identifier (each user have an unique identifier).
 * @param [in] clave the user password (user need it to connect).
 * @param [in] nombre the name of the user.
 */
Usuario::Usuario(string new_id, string new_clave, string new_nombre): id(new_id), clave(new_clave), nombre(new_nombre) {
}

/**
 * user copy constructor.
 * @param [in] orig the original object to be copied.
 */
Usuario::Usuario(const Usuario& orig): id(orig.id), clave(orig.clave), nombre(orig.nombre) {
}

/**
 * user destructor.
 * does nothing for now.
 */
Usuario::~Usuario() {
}

/**
 * return the user id.
 * @return user id.
 */
string Usuario::getId(){
    return this->id;
}

/**
 * return the user password.
 * @return user password.
 */
string Usuario::getClave(){
    return this->clave;
}

/**
 * set the user password.
 * @param [in] clave the new password (to change password).
 */
void Usuario::setClave(string &clave){
    this->clave = clave;
}

/**
 * allow to print user information.
 * @return the string "user.id, user.password, user.name".
 */
string Usuario::toString(){
    stringstream buffer;
    buffer << id <<", "<< clave <<", " << nombre;
    return buffer.str();
}

/**
 * set the user name.
 * @param [in] nombre the new name (to register).
 */
void Usuario::setNombre(string& nombre) {
    this->nombre = nombre;
}

/**
 * set the user id.
 * @param [in] id the new id(program does it automatically).
 */
void Usuario::setId(string& id) {
    this->id = id;
}
