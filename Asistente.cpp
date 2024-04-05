#include <iostream>
#include "Asistente.h"
using namespace std;

//Asistente Basico
Asistente::Asistente(string nombre, int edad){
    this -> tipo = "Basico";
    this -> nombre = nombre;
    this -> edad = edad;
}
//Asistente en Linea
Asistente::Asistente(string nombre, string nickname){
    this -> tipo = "Online";
    this -> nombre = nombre;
    this -> nickname = nickname;
}
//Trabajador Empresa
Asistente::Asistente(string nombre, int edad, string ocupacion, string empresa){
    this -> tipo = "T_Empresa";
    this -> nombre = nombre;
    this -> edad = edad;
    this -> ocupacion = ocupacion;
    this -> empresa = empresa;
}
//Trabajador Docente
Asistente::Asistente(string nombre, string ocupacion, string universidad){
    this -> tipo = "T_Docente";
    this -> nombre = nombre;
    this -> ocupacion = ocupacion;
    this -> universidad = universidad;
}
//Estudiante
Asistente::Asistente(string nombre, string carrera, string universidad, int semestre){
    this -> tipo = "Estudiante";
    this -> nombre = nombre;
    this -> carrera = carrera;
    this -> universidad = universidad;
    this -> semestre = semestre;
}

string Asistente::getTipo(){return tipo;}
string Asistente::getNombre(){return nombre;}
string Asistente::getNickname(){return nickname;}
string Asistente::getOcupacion(){return ocupacion;}
string Asistente::getEmpresa(){return empresa;}
string Asistente::getCarrera(){return carrera;}
string Asistente::getUniversidad(){return universidad;}
int Asistente::getEdad(){return edad;}
int Asistente::getSemestre(){return semestre;}

void Asistente::setEdad(int edad){
    this -> edad = edad;
}

Asistente::~Asistente(){}