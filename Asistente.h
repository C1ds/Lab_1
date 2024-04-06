#pragma once
#include <iostream>
using namespace std;

class Asistente{
    private:
        string tipo, nombre, nickname, ocupacion, empresa, carrera, universidad;
        int edad, semestre;
    public:
        //Asistente Basico
        Asistente(string nombre, int edad);
        //Asistente en Linea
        Asistente(string nombre, string nickname);
        //Trabajador Empresa
        Asistente(string nombre, int edad, string ocupacion, string empresa);
        //Trabajador Docente
        Asistente(string nombre, string ocupacion, string universidad);
        //Estudiante
        Asistente(string nombre, string carrera, string universidad, int semestre);

        string getTipo();
        string getNombre();
        string getNickname();
        string getOcupacion();
        string getEmpresa();
        string getCarrera();
        string getUniversidad();
        int getEdad();
        int getSemestre();

        void setEdad(int edad);
        
        ~Asistente();
};