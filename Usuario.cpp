/* 
 * File:   Usuario.cpp
 * Author: Carolina y María
 * 
 * Created on 14 de noviembre de 2015, 12:47
 */
#include <sstream>
#include "Usuario.h"

Usuario::Usuario() {
    id = "null";
    clave = "null";
    nombre = "null";
}
Usuario::Usuario(string id, string clave, string nombre) {
    this->id = id;
    this->clave = clave;
    this->nombre = nombre;
}

Usuario::Usuario(const Usuario& orig) {
    id = orig.id;
    clave = orig.clave;
    nombre = orig.nombre;
}

Usuario::~Usuario() {
}

string Usuario::getId(){
    return this->id;
}

string Usuario::getClave(){
    return this->clave;
}

string Usuario::getNombre(){
    return this->nombre;
}
void Usuario::setClave(string &clave){
    this->clave = clave;
}
string Usuario::toString(){
    stringstream buffer;
    buffer << id <<", "<< clave <<", " << nombre;
    return buffer.str();
}

void Usuario::setNombre(string& nombre) {
    this->nombre = nombre;
}


void Usuario::setId(string& id) {
    this->id = id;
}