#include <iostream>
#include "Asistente.h"
using namespace std;

//Asistente Basico
Asistente::Asistente(string nombre){
    this -> tipo = "Basico";
    this -> nombre = nombre;
    this -> edad = -1;
}

//Asistente en Linea
Asistente::Asistente(string nombre, string nickname){
    this -> tipo = "Online";
    this -> nombre = nombre;
    this -> nickname = nickname;
    this -> edad = -1;
}

//Trabajador Empresa
Asistente::Asistente(string nombre, string ocupacion, string empresa){
    this -> tipo = "T_Empresa";
    this -> nombre = nombre;
    this -> ocupacion = ocupacion;
    this -> empresa = empresa;
    this -> edad = -1;
}

//Trabajador Docente
Asistente::Asistente(string nombre, int edad, string ocupacion, string est_Educativo){
    this -> tipo = "T_Docente";
    this -> nombre = nombre;
    this -> edad = edad;
    this -> ocupacion = ocupacion;
    this -> est_Educativo = est_Educativo;
}

//Estudiante
Asistente::Asistente(string nombre, string est_Educativo, int semestre){
    this -> tipo = "Estudiante";
    this -> nombre = nombre;
    this -> est_Educativo = est_Educativo;
    this -> semestre = semestre;
    this -> edad = -1;
}

string Asistente::getTipo(){return tipo;}
string Asistente::getNombre(){return nombre;}
string Asistente::getNickname(){return nickname;}
string Asistente::getOcupacion(){return ocupacion;}
string Asistente::getEmpresa(){return empresa;}
string Asistente::getEstablecimiento(){return est_Educativo;}
int Asistente::getEdad(){return edad;}
int Asistente::getSemestre(){return semestre;}

void Asistente::setEdad(int edad){
    this -> edad = edad;
}

Asistente::~Asistente(){}