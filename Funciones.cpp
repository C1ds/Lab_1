#include <iostream>
#include "Funciones.h"
using namespace std;

Funciones::Funciones(int capacidad){
    this -> capacidad = capacidad;
    this -> cantidad = 0;
    this -> eventos = new Evento* [capacidad];
}

Evento** Funciones::getEventos(){return eventos;}
int Funciones::getCapacidad(){return capacidad;}
int Funciones::getCantidad(){return cantidad;}

int Funciones::validarOpcion(string data){
    if (data == "1"){return 1;}
    else if (data == "2"){return 2;}
    else if (data == "3"){return 3;}
    else if (data == "4"){return 4;}
    else if (data == "5"){return 5;}
    else {return -1;}
}

void Funciones::printMenu(){
    cout << "-------Menu-------" << endl;
    cout << "[1] Crear eventos" << endl;
    cout << "[2] Registrar asistentes" << endl;
    cout << "[3] Consultar lista de asistentes" << endl;
    cout << "[4] Generar informe" << endl;
    cout << "[5] Salir" << endl;
    cout << "Opcion: ";
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