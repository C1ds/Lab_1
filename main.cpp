#include <iostream>
#include "Asistente.h"
#include "Evento.h"
#include "Funciones.h"

using namespace std;

int main() {
    string* data = new string;
    int* opcion = new int;
    Funciones* funciones = new Funciones(50);
    do {
        funciones -> printMenu();
        cin >> *data;

        *opcion = funciones -> validarOpcion(*data);
        
        switch (*opcion){
        case 1:break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
        default:
            cout << "-------Opcion Invalidad-------" << endl;
            break;
        }

    } while (*opcion != 5);

    delete data;
    delete opcion; 
    delete funciones;
    return 0;
}