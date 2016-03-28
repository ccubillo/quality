/**
 * @author: Carolina y Maria
 * @since 1.0
 */

#include <cstdlib>
#include <iostream>
#include "CheckClave.h"
#include "Usuario.h"
#include "GestorUsuarios.h"
#include "FileNotFound.h"
#include "ExistingUser.h"
#include "PasswordNotAccepted.h"
#include "UserNotFound.h"

using namespace std;

int main(int argc, char** argv) {
    try {
        char n;
        GestorUsuarios g;
        //Menu programa
        do {
            cout << endl << "~~~~~~~~~~MENU~~~~~~~~~~" << endl;
            cout << "1 - Alta usuario" << endl;
            cout << "2 - Baja usuario" << endl;
            cout << "3 - Cambia clave" << endl;
            cout << "4 - Busca usuario" << endl;
            cout << "5 - Conectar usuario" << endl;
            cout << "6 - Desconectar usuario" << endl;
            cout << "7 - Buscar usuario conectado" << endl;
            cout << "8 - Listado de usuarios conectados" << endl;
            cout << "9 - Salir" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Opcion: ";
            cin >> n;

            string clave, nombre;
            Usuario u;
            set<string> arb;
            set<string>::iterator it;
            switch (n) {
                case '1':
                    cout << "Introduzca nombre:" << endl;
                    cin >> nombre;
                    cout << "Introduzca clave:" << endl;
                    cin >> clave;
                    u.setClave(clave);
                    u.setNombre(nombre);
                    u.setId(nombre);
                    try {
                        g.altaUsuario(u);
                    } catch (existing_user &ex) {
                        cout << "Fallo usuario ya existente";
                    } catch (password_not_accepted  &ex) {
                        cout << "Fallo clave no valida";
                    }
                    break;
                case '2':
                    cout << "Introduzca nombre:" << endl;
                    cin >> nombre;
                    try {
                        g.bajaUsuario(nombre);
                    } catch (user_not_found &ex) {
                        cout << "Usuario no encontrado";
                    }
                    break;
                case '3':
                    cout << "Introduzca nombre:" << endl;
                    cin >> nombre;
                    cout << "Introduzca nueva clave:" << endl;
                    cin >> clave;
                    try {
                        g.cambiaClave(nombre, clave);
                    } catch (user_not_found &ex) {
                        cout << "Usuario no encontrado";
                    } catch (password_not_accepted &ex) {
                        cout << "Fallo clave no valida";
                    }
                    break;
                case '4':
                    cout << "Introduzca nombre:" << endl;
                    cin >> nombre;
                    try{
                    cout << g.buscaUsuario(nombre).toString() << endl;
                    } catch (user_not_found &ex) {
                        cout << "Usuario no encontrado";
                    }
                    break;
                case '5':
                    cout << "Introduzca nombre:" << endl;
                    cin >> nombre;
                    cout << "Introduzca clave:" << endl;
                    cin >> clave;
                    try{
                    g.conexion(nombre, clave);
                    }catch (existing_user &ex) {
                        cout << "Fallo usuario ya existente";
                    } catch (password_not_accepted &ex) {
                        cout << "Fallo clave no valida";
                    } catch (user_not_found &ex) {
                        cout << "Usuario no encontrado";
                    }
                    break;
                case '6':
                    cout << "Introduzca nombre:" << endl;
                    cin >> nombre;
                    try{
                    g.desconexion(nombre);
                    } catch (user_not_found &ex) {
                        cout << "Usuario no encontrado";
                    }
                    break;
                case '7':
                    cout << "Introduzca nombre:" << endl;
                    cin >> nombre;
                    if (g.estaConectado(nombre)) {
                        cout << nombre << " esta conectado" << endl;
                    } else {
                        cout << nombre << " no esta conectado" << endl;
                    }
                    break;
                case '8':
                    arb = g.usuariosConectados();
                    if (arb.size() != 0) {
                        it = arb.begin();
                        while (it != arb.end()) {
                            cout << *it << endl;
                            ++it;
                        }
                    } else cout << "No hay usuarios conectados" << endl;
                    break;
            }

            system("pause");
            system("cls");
        } while ((n != '9'));
        //fin menu
    } catch (file_not_found &ex) {
        cout << "Fallo al cargar el diccionario de palabras, cerrando aplicacion";
        
    }

    return 0;
}

