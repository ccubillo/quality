/* 
 * File:   GestorUsuarios.h
 * Author: Carolina y María
 *
 * Created on 14 de noviembre de 2015, 13:06
 */

#ifndef GESTORUSUARIOS_H
#define	GESTORUSUARIOS_H
#include "Usuario.h"
#include <map>
#include <set>
using namespace std;

class GestorUsuarios {
private:
    std::map<string,Usuario,less<string> > usuarios;
    std::map<string,Usuario*,less<string> > conectados;
    
public:
    GestorUsuarios();
    GestorUsuarios(GestorUsuarios& orig);
    virtual ~GestorUsuarios();
    GestorUsuarios& operator=(GestorUsuarios &g);
    void altaUsuario(Usuario &u);
    void bajaUsuario(string &id);
    void cambiaClave(string &id, string &clave);
    Usuario& buscaUsuario(string &id);
    void conexion(string &id, string &clave);
    void desconexion(string &id);
    bool estaConectado(string &id);
    set<string> usuariosConectados();
    bool compruebaClave(string &clave);
    //void muestra();
    // void muestraConectados(std::map<string,Usuario*,less<string> > conectados);
};

#endif	/* GESTORUSUARIOS_H */

