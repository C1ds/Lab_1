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
Evento::Evento(string tema, int duracion, string ubicacion, int capacidad, bool registroRequerido){
    this -> tipo = "Publico";
    this -> cantidad = 0;
    this -> tema = tema;
    this -> duracion = duracion;
    this -> ubicacion = ubicacion;
    this -> capacidad = capacidad;
    this -> registroRequerido = registroRequerido;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Digital
Evento::Evento(string tema, int duracion, int capacidad, string plataformaTransmision, bool accesoGratuito){
    this -> tipo = "Digital";
    this -> cantidad = 0;
    this -> tema = tema;
    this -> duracion = duracion;
    this -> capacidad = capacidad;
    this -> plataformaTransmision = plataformaTransmision;
    this -> accesoGratuito = accesoGratuito;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Corporativo
Evento::Evento(string tema, int duracion, string ubicacion, int capacidad, string departamentoResponsable, string empresa){
    this -> tipo = "Corporativo";
    this -> cantidad = 0;
    this -> tema = tema;
    this -> duracion = duracion;
    this -> ubicacion = ubicacion;
    this -> capacidad = capacidad;
    this -> departamentoResponsable = departamentoResponsable;
    this -> empresa = empresa;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Academico
Evento::Evento(string tema, int duracion, string ubicacion, int capacidad, string universidad, bool certificadoDisponible){
    this -> tipo = "Academico";
    this -> cantidad = 0;
    this -> tema = tema;
    this -> duracion = duracion;
    this -> ubicacion = ubicacion;
    this -> capacidad = capacidad;
    this -> universidad = universidad;
    this -> certificadoDisponible = certificadoDisponible;
    this -> asistentes = new Asistente* [capacidad];
}
//Evento Privado
Evento::Evento(int duracion, string ubicacion, int capacidad){
    this -> tipo = "Privado";
    this -> cantidad = 0;
    this -> tema = "Tema Privado";
    this -> duracion = duracion;
    this -> ubicacion = ubicacion;
    this -> capacidad = capacidad;
    this -> asistentes = new Asistente* [capacidad];
}

string Evento::getTipo(){return tipo;}
string Evento::getTema(){return tema;}
string Evento::getUbicacion(){return ubicacion;}
string Evento::getPlataformaTransmision(){return plataformaTransmision;}
string Evento::getDepartamentoResponsable(){return departamentoResponsable;}
string Evento::getEmpresa(){return empresa;}
string Evento::getUniversidad(){return universidad;}
int Evento::getCapacidad(){return capacidad;}
int Evento::getCantidad(){return cantidad;}
int Evento::getDuracion(){return duracion;}
bool Evento::getRegistroRequerido(){return registroRequerido;}
bool Evento::getAccesoGratuito(){return accesoGratuito;}
bool Evento::getCertificadoDisponible(){return certificadoDisponible;}

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