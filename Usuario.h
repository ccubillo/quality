/**
 * @brief Header of Usuario.
 * @author: Carolina y Maria
 * @since 1.0
 */

#ifndef USUARIO_H
#define	USUARIO_H
#include <string>

using namespace std;

/**
 * @brief class representing an user, with an unique id, name and password. The user can change it password and name.
 * 		  In addition the user can consult it identifier, password and name.
 */
class Usuario {
private:
    string id;  ///< id of the user (unique).

    string clave;  ///< password of the user.

    string nombre;  ///< name of the user.

public:
    Usuario();
    Usuario(string new_id, string new_clave, string new_nombre);
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    string getId();
    string getClave();
    string getNombre();
    void setClave(string &clave);
    string toString();
    void setNombre(string &nombre);
    void setId(string &id);
};

#endif	/* USUARIO_H */

