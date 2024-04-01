#include <iostream>
#include "Evento.h"
using namespace std;

/*Evento Test
Evento::Evento(string tipo, string tema, int capacidad){
    this -> tipo = tipo;
    this -> tema = tema;
    this -> ubicacion = nullptr;
    this -> duracion = 0;
    this -> capacidad = capacidad;
    this -> cantidad = 0;
    this -> asistentes = new Asistente* [capacidad];
}*/

//Evento Publico
Evento::Evento(string tema, int duracion, string ubicacion, int capacidad){
    this -> tipo = "Publico";
    this -> cantidad = 0;
    this -> tema = tema;
    this -> duracion = duracion;
    this -> ubicacion = ubicacion;
    this -> capacidad = capacidad;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Digital
Evento::Evento(string tema, int capacidad, int duracion){
    this -> tipo = "Digital";
    this -> cantidad = 0;
    this -> tema = tema;
    this -> capacidad = capacidad;
    this -> duracion = duracion;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Corporativo
Evento::Evento(string tema, string ubicacion, int capacidad, int duracion){
    this -> tipo = "Corporativo";
    this -> cantidad = 0;
    this -> tema = tema;
    this -> ubicacion = ubicacion;
    this -> capacidad = capacidad;
    this -> duracion = duracion;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Academico
Evento::Evento(int capacidad, int duracion, string tema, string ubicacion){
    this -> tipo = "Academico";
    this -> cantidad = 0;
    this -> capacidad = capacidad;
    this -> duracion = duracion;
    this -> tema = tema;
    this -> ubicacion = ubicacion;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Privado
Evento::Evento(int capacidad, string ubicacion, int duracion){
    this -> tipo = "Privado";
    this -> cantidad = 0;
    this -> capacidad = capacidad;
    this -> ubicacion = ubicacion;
    this -> duracion = duracion;
    this -> asistentes = new Asistente* [capacidad];
}

string Evento::getTipo(){return tipo;}
string Evento::getTema(){return tema;}
string Evento::getUbicacion(){return ubicacion;}
int Evento::getCapacidad(){return capacidad;}
int Evento::getCantidad(){return cantidad;}
int Evento::getDuracion(){return duracion;}

void Evento::setUbicacion(string ubicacion){
    this -> ubicacion = ubicacion;
}
void Evento::setDuracion(int duracion){
    this -> duracion = duracion;
}

bool Evento::addAsistente(Asistente* asistente){
    if (cantidad < capacidad) {
        asistentes[cantidad] = asistente;
        cantidad++;
        return true;
    }
    return false;
}

Evento::~Evento(){}