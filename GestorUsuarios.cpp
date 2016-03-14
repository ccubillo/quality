/* 
 * File:   GestorUsuarios.cpp
 * Author: Carolina y Maria
 * 
 * Created on 14 de noviembre de 2015, 13:06
 */

#include "GestorUsuarios.h"
#include <iostream>
#include "CheckClave.h"
#include "ExistingUser.h"
#include "PasswordNotAccepted.h"
#include "UserNotFound.h"
/**
 * User manager constructor
 */
GestorUsuarios::GestorUsuarios() {
}
/**
 * User manager copy constructor
 * @param orig a copy managed
 */
GestorUsuarios::GestorUsuarios(GestorUsuarios& orig) {
    this->usuarios = orig.usuarios;
    //Al hacer la copia de usuarios la direccion de memoria cambia y por eso busco los conectados en los usuarios copiados para obtener su nueva dir. de memoria
    std::map<string, Usuario*, less<string> >::iterator it;
    it=orig.conectados.begin();
    while(it!=orig.conectados.end())
    {   
        string id=it->first;
        this->conectados.insert(std::pair<string, Usuario*>(id, &buscaUsuario(id)));
        it++;
    }
    
}
/**
 * User manager destructor
 */
GestorUsuarios::~GestorUsuarios() {
}
/**
 * User manager operator=
 * define operator =
 * @param g a user manager
 * @return
 */
GestorUsuarios& GestorUsuarios::operator=(GestorUsuarios &g)
{
    this->conectados.clear();
    this->usuarios.clear();
    
    this->usuarios = g.usuarios;
    std::map<string, Usuario*, less<string> >::const_iterator it;
    it=g.conectados.begin();
    while(g.conectados.begin()!=g.conectados.end())
    {   
        string id=it->first;
        this->conectados.insert(std::pair<string, Usuario*>(id, &buscaUsuario(id)));
        it++;
    }
    return *this;
}
/**
 * CheckKey function
 * check is the key is correct
 * @param clave password of user
 * @return a boolean value
 */
bool GestorUsuarios::compruebaClave(string &clave) {
    CheckClave c; 
    bool valida = false;
    switch (c.check(clave)) {
        case 0:
            valida = true;
            break;
        default: throw password_not_accepted();
        break;
    }
    return valida;
}
/**
 * To register user
 * @param u user
 */
void GestorUsuarios::altaUsuario(Usuario &u) {
    std::map<string, Usuario, less<string> >::iterator it;
    it = usuarios.find(u.getId());
    if (it != usuarios.end()) {
        throw existing_user();
//        cout << "Usuario existente" << endl;
    } else {
        string s = u.getClave();
        if (compruebaClave(s)) {
            usuarios.insert(std::pair<string, Usuario>(u.getId(), u));
//            cout << "Introducido correctamente" << endl;
        } else throw password_not_accepted(); 
    }
}
/**
 * to unsubscribe a user
 * @param id of the user
 */
void GestorUsuarios::bajaUsuario(string &id) {
	//Primero comprobar que esta conectado y luego llamar a desconexion.
	//Si no siempre salta la excepci��n de que no est�� encontrado porque no est�� conectado.
    std::map<string, Usuario, less<string> >::iterator it;
    it = usuarios.find(id);
    if (it != usuarios.end()) {
        desconexion(id);
        usuarios.erase(it);
//        cout << "Usuario eliminado" << endl;
    } else {
//        cout << "usuario no existente" << endl;
        throw user_not_found();
    }
}
/**
 * To change password
 * @param id of the user
 * @param clave key of the user
 */
void GestorUsuarios::cambiaClave(string &id, string &clave) {
    if (compruebaClave(clave)) {
        std::map<string, Usuario, less<string> >::iterator it;
        it = usuarios.find(id);
        if (it != usuarios.end()) {
            it->second.setClave(clave);
//            cout << "Clave modificada correctamente" << endl;
        } else {
//            cout << "Usuario no encontrado" << endl;
            throw user_not_found();
        }
    } else {
//        cout << "contrase��a no valida" << endl;
        throw password_not_accepted();
    }
}
/**
 * To find a user
 * @param id of the user
 * @return user found
 */
Usuario& GestorUsuarios::buscaUsuario(string &id) {
    std::map<string, Usuario, less<string> >::iterator it;
    it = usuarios.find(id);
    if (it != usuarios.end()) {
//        cout << "Usuario encontrado" << endl;
        return it->second;
    } else {
//        cout << "Usuario no encontrado" << endl;
        throw user_not_found();
    }
}
/**
 * To connect a user
 * @param id of the user
 * @param clave key of the user
 */
void GestorUsuarios::conexion(string &id, string &clave) {
    std::map<string, Usuario, less<string> >::iterator i;
    i = usuarios.find(id);
    if (i != usuarios.end()) {
        if (estaConectado(id)) {
//            cout << "usuario ya conectado" << endl;
            throw existing_user();
        } else {
            if (compruebaClave(clave)) {
                conectados.insert(std::pair<string, Usuario*>(id, &buscaUsuario(id)));
//                cout << "usuario conectado " << endl;
            } else {
//                cout << "clave no valida" << endl;
                throw password_not_accepted();
            }
        }
    } else {
//        cout << "usuario no existente" << endl;
        throw user_not_found();
    }
}
/**
 * To disconnect a user
 * @param id of the user
 */
void GestorUsuarios::desconexion(string &id) {
    std::map<string, Usuario*, less<string> >::iterator it;
    it = conectados.find(id);
    if (it != conectados.end()) {
        conectados.erase(it);
    } else {
        throw user_not_found();
    }
}
/**
 * To check if a user is connect
 * @param id of the user
 * @return a boolean value (true if connect or false is not)
 */
bool GestorUsuarios::estaConectado(string &id) {
    std::map<string, Usuario*, less<string> >::iterator it;
    it = conectados.find(id);
    return it!=conectados.end();
}
/**
 * Show users connect
 * @return a set of users
 */
set<string> GestorUsuarios::usuariosConectados() {
    std::map<string, Usuario*, less<string> >::iterator it = conectados.begin();
    set<string> u;
    while(it != conectados.end()){
        u.insert(it->first);
        it++;
    }
    return u;
}

//void GestorUsuarios::muestra() {
//    cout << "Total usuarios " << usuarios.size() << endl;
//    std::map<string, Usuario, less<string> >::iterator it;
//    for (it = usuarios.begin(); it != usuarios.end(); it++) {
//        cout << "string e id: " << it->first << " clave: " << it->second.getClave()
//                << " nombre: " << it->second.getNombre() << endl;
//        cout << endl;
//    }
//
//}
//void GestorUsuarios::muestraConectados(std::map<string, Usuario*, less<string> > conectados) {
//    cout << "Total conectados " << conectados.size() << endl;
//    std::map<string, Usuario*, less<string> >::iterator it;
//    
//    for (it = conectados.begin(); it != conectados.end(); it++) {
//        cout << "string e id: " << it->first  << " clave: " << it->second->getClave()
//                << " nombre: " << it->second->getNombre() << endl;
//        cout << endl;
//    }
//
//}
