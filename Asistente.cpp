#include <iostream>
#include "Asistente.h"
using namespace std;

Asistente::Asistente(string tipo, string nombre){
    this -> tipo = tipo;
    this -> nombre = nombre;
    //this -> edad = -1;
}

string Asistente::getTipo(){return tipo;}