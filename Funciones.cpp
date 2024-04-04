#include <iostream>
#include "Funciones.h"
#include "Evento.h"

using namespace std;
/*NOTAS de cambios que hice
    agregue el #include "Evento.h" (linea 3)
    agregue codigo(funcion Crearevento) de la linea 38 al 93
*/
Funciones::Funciones(int capacidad){
    this -> capacidad = capacidad;
    this -> cantidad = 0;
    this -> eventos = new Evento* [capacidad];
}

Evento** Funciones::getEventos(){return eventos;}
int Funciones::getCapacidad(){return capacidad;}
int Funciones::getCantidad(){return cantidad;}

void Funciones::printMenu(){
    cout << "-------Menu-------" << endl;
    cout << "[1] Crear eventos" << endl;
    cout << "[2] Registrar asistentes" << endl;
    cout << "[3] Consultar lista de asistentes" << endl;
    cout << "[4] Generar informe" << endl;
    cout << "[5] Salir" << endl;
    cout << "Opcion: ";
}
bool Funciones::Crearevento(){
    cout << "creacion de Evento" << endl;
    //preguntar por tipo
    printTipo();
    //elegir tipo
    string* data = new string;
    cin >> *data;   
    int* opcion = new int;
    *opcion =validarOpcion(*data);
    switch (*opcion){
        case 1:{
            //Publico
            cout<<"tema: "<<endl;
            cin >> *data;
            string temaP= *data; 
            cout<<"duracion: "<<endl;
            cin >> *data;
            int i = validarOpcion(*data);
            int duracionP= i;
            cout<<"ubicacion: "<<endl;
            cin >> *data;
            string ubicacionP= *data;
            cout<<"capacidad: "<<endl;
            cin >> *data;
            i = validarOpcion(*data);
            int capacidadP= i;
            Evento* eP=new Evento(temaP,duracionP,ubicacionP,capacidadP);
            
            //agregar a lista
            addEvento(eP);
            break;}
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
        default:
            cout << "-------Opcion Invalidad-------" << endl;
            break;
                    }
    return true;
}
int Funciones::validarOpcion(string data){
    try{
                int i = std::stoi(data);
                return i;
                }
                catch(std::invalid_argument const &e){
                    cout << "Ingrese un dato valido:";
                    cin >> data;
                    return validarOpcion(data);
                }
                catch(std::out_of_range const &e){
                    cout << "Ingrese un dato valido:";
                    cin >> data;
                    return validarOpcion(data);
                }
}
void Funciones::printTipo(){
    cout<<"1) Evento Publico"<< endl;
    cout<<"2) Evento Digital"<< endl;
    cout<<"3) Evento Corporativo"<< endl;
    cout<<"4) Evento Academico"<< endl;
    cout<<"5) Evento Privado"<< endl;
}
bool Funciones::addEvento(Evento* evento){
    if (cantidad < capacidad) {
        eventos[cantidad] = evento;
        cantidad++;
        return true;
    }
    return false;
}

Funciones::~Funciones(){cout << "Programa finalizado" << endl;}