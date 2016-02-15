/* 
 * File:   Usuario.h
 * Author: Carolina y María
 *
 * Created on 14 de noviembre de 2015, 12:47
 */

#ifndef USUARIO_H
#define	USUARIO_H
#include <string>
using namespace std;
class Usuario {
private:
    string id;
    string clave;
    string nombre;
public:
    Usuario();
    Usuario(string id, string clave, string nombre);
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

