#include <iostream>
#include "Evento.h"
#include<string>  
using namespace std;

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
string Evento::getAsistentes(){
    string listaDeAsistentes;
    for (int i = 0; i < cantidad; i++){
        string tipo = asistentes[i]->getTipo();
         if (tipo == "Basico") {
             int num = asistentes[i] ->getEdad();
            string str = to_string(num);
            listaDeAsistentes+=i+","+asistentes[i] ->getTipo()+","+asistentes[i] ->getNombre()+","+str+"\n";
        }
        else if (tipo == "Online") {
            listaDeAsistentes+=i+","+asistentes[i] ->getTipo()+","+asistentes[i] ->getNombre()+","+asistentes[i] ->getNickname()+"\n";
        }
        else if (tipo == "T_Empresa") {
            listaDeAsistentes+=i+","+asistentes[i] ->getTipo()+","+asistentes[i] ->getNombre()+","+to_string(asistentes[i] ->getEdad())+","+asistentes[i] ->getOcupacion()+","+asistentes[i] ->getEmpresa()+"\n";
        }
        else if (tipo == "T_Docente") {
            listaDeAsistentes+=i+","+asistentes[i] ->getTipo()+","+asistentes[i] ->getNombre()+","+asistentes[i] ->getOcupacion()+","+asistentes[i] ->getUniversidad()+"\n";
        }
        else if (tipo == "Estudiante") {
            listaDeAsistentes+=i+","+asistentes[i] ->getTipo()+","+asistentes[i] ->getNombre()+","+asistentes[i] ->getCarrera()+","+asistentes[i] ->getUniversidad()+","+to_string(asistentes[i] ->getSemestre())+"\n";
        }
    }
    return listaDeAsistentes;
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

void Evento::listarAsistentes() {
    if (cantidad == 0) {
        cout << "No hay asistentes registrados" << endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        string tipo = asistentes[i] -> getTipo();
        cout << "[" << (i+1) << "] Tipo asistente: " << tipo << endl; 
        cout << "[-] Nombre: " << asistentes[i] -> getNombre() << endl;

        if (tipo == "Basico") { //Asistente Basico
            cout << "[-] Edad: " << asistentes[i] -> getEdad() << endl;
            cout << "-----------------------------" << endl;
        }
        else if (tipo == "Online") { //Asistente en Linea
            cout << "[-] Nickname: " << asistentes[i] -> getNickname() << endl;
            cout << "-----------------------------" << endl;
        }
        else if (tipo == "T_Empresa") { //Trabajador Empresa
            cout << "[-] Edad: " << asistentes[i] -> getEdad() << endl;
            cout << "[-] Ocupacion: " << asistentes[i] -> getOcupacion() << endl;
            cout << "[-] Empresa: " << asistentes[i] -> getEmpresa() << endl;
            cout << "-----------------------------" << endl;
        }
        else if (tipo == "T_Docente") { //Trabajador Docente
            cout << "[-] Ocupacion: " << asistentes[i] -> getOcupacion() << endl;
            cout << "[-] Universidad: " << asistentes[i] -> getUniversidad() << endl;
            cout << "-----------------------------" << endl;
        }
        else if (tipo == "Estudiante") { //Estudiante
            cout << "[-] Carrera: " << asistentes[i] -> getCarrera() << endl;
            cout << "[-] Universidad: " << asistentes[i] -> getUniversidad() << endl;
            cout << "[-] Semestre Academico: " << asistentes[i] -> getSemestre() << endl;
            cout << "-----------------------------" << endl;
        }
        else {
            cout << "Tipo no registrado" << endl;
        }
    }
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