#include <iostream>
#include <string>
#include "Funciones.h"
#include "Evento.h"

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

void Funciones::printMenu(){
    cout << "-------Menu-------" << endl;
    cout << "[1] Crear eventos" << endl;
    cout << "[2] Registrar asistentes" << endl;
    cout << "[3] Consultar lista de asistentes" << endl;
    cout << "[4] Generar informe" << endl;
    cout << "[5] Salir" << endl;
    cout << "Opcion: ";
}

void Funciones::printTipo(){
    cout<<"[1] Evento Publico"<< endl;
    cout<<"[2] Evento Digital"<< endl;
    cout<<"[3] Evento Corporativo"<< endl;
    cout<<"[4] Evento Academico"<< endl;
    cout<<"[5] Evento Privado"<< endl;
    cout << "Opcion: ";
}

void Funciones::printAsistTipo(){
    cout<<"[1] Asistente Basico"<< endl;
    cout<<"[2] Asistente en Linea"<< endl;
    cout<<"[3] Trabajador Empresa"<< endl;
    cout<<"[4] Trabajador Docente"<< endl;
    cout<<"[5] Estudiante"<< endl;
    cout << "Opcion: ";
}

void Funciones::listarEventos(){
    if (cantidad < 1) {
        cout << "No hay eventos registrados" << endl;
        return;
    }

    cout << "Eventos disponibles:" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (eventos[i] -> getCantidad() < eventos[i] -> getCapacidad()) {
            cout << "[" << (i+1) << "] " << eventos[i] -> getTipo() << " - " << eventos[i] -> getTema() << endl;
            cout << "Capacidad: " << eventos[i] -> getCapacidad() << " - Inscritos: " << eventos[i] -> getCantidad() << endl;
        }
    }

}

void Funciones::printEventos(){
    if (cantidad < 1) {
        cout << "No hay eventos registrados" << endl;
        return;
    }

    string tipo;
    for ( int i = 0; i < cantidad; i++){
        tipo = eventos[i] -> getTipo();
        cout << "#############################" << endl;

        if (tipo == "Publico") {
            cout << "Tipo: " << eventos[i] -> getTipo() << endl;
            cout << "Tema: " << eventos[i] -> getTema() << endl;
            cout << "Duracion: " << eventos[i] -> getDuracion() << " minutos" << endl;
            cout << "Ubicacion: " << eventos[i] -> getUbicacion() << endl;
            cout << "Capacidad total: " << eventos[i] -> getCapacidad() << endl;
            cout << "Asistentes inscritos: " << eventos[i] -> getCantidad() << endl;
            cout << "Registro requerido: " << boolalpha << eventos[i] -> getRegistroRequerido() << endl;
            continue;
        }
        else if (tipo == "Digital") {
            cout << "Tipo: " << eventos[i] -> getTipo() << endl;
            cout << "Tema: " << eventos[i] -> getTema() << endl;
            cout << "Duracion: " << eventos[i] -> getDuracion() << " minutos" << endl;
            cout << "Capacidad total: " << eventos[i] -> getCapacidad() << endl;
            cout << "Asistentes inscritos: " << eventos[i] -> getCantidad() << endl;
            cout << "Plataforma transmision: " << eventos[i] -> getPlataformaTransmision() << endl;
            cout << "Acceso gratuito: " << boolalpha << eventos[i] -> getAccesoGratuito() << endl;
            continue;
        }
        else if (tipo == "Corporativo") {
            cout << "Tipo: " << eventos[i] -> getTipo() << endl;
            cout << "Tema: " << eventos[i] -> getTema() << endl;
            cout << "Duracion: " << eventos[i] -> getDuracion() << " minutos" << endl;
            cout << "Ubicacion: " << eventos[i] -> getUbicacion() << endl;
            cout << "Capacidad total: " << eventos[i] -> getCapacidad() << endl;
            cout << "Asistentes inscritos: " << eventos[i] -> getCantidad() << endl;
            cout << "Departamento responsable: " << eventos[i] -> getDepartamentoResponsable() << endl;
            cout << "Empresa: " << eventos[i] -> getEmpresa() << endl;
            continue;
        }
        else if (tipo == "Academico"){
            cout << "Tipo: " << eventos[i] -> getTipo() << endl;
            cout << "Tema: " << eventos[i] -> getTema() << endl;
            cout << "Duracion: " << eventos[i] -> getDuracion() << " minutos" << endl;
            cout << "Ubicacion: " << eventos[i] -> getUbicacion() << endl;
            cout << "Capacidad total: " << eventos[i] -> getCapacidad() << endl;
            cout << "Asistentes inscritos: " << eventos[i] -> getCantidad() << endl;
            cout << "Universidad: " << eventos[i] -> getUniversidad() << endl;
            cout << "Certificado disponible: " << boolalpha << eventos[i] -> getCertificadoDisponible() << endl;
            continue;
        }
        else if (tipo == "Privado") {
            cout << "Tipo: " << eventos[i] -> getTipo() << endl;
            cout << "Duracion: " << eventos[i] -> getDuracion() << " minutos" << endl;
            cout << "Ubicacion: " << eventos[i] -> getUbicacion() << endl;
            cout << "Capacidad total: " << eventos[i] -> getCapacidad() << endl;
            cout << "Asistentes inscritos: " << eventos[i] -> getCantidad() << endl;
            continue;
        }
        else {
            cout << "------Evento no Listado------" << endl;
        };
        
    }
    
}

bool Funciones::validarBoolean(string data){
    try {
        int i = std::stoi(data);
        if (i == 1) {
            return true;
        }
        else if (i == 0) {
            return false;
        }
        else {
            cout << "Ingrese un dato valido (0|1): ";
            cin >> data;
            return validarBoolean(data);
        }
    }
    catch(std::invalid_argument const &e){
        cout << "Ingrese un dato valido (0|1): ";
        cin >> data;
        return validarBoolean(data);
        }
    catch(std::out_of_range const &e){
        cout << "Ingrese un dato valido (0|1): ";
        cin >> data;
        return validarBoolean(data);
        }

}

Asistente* Funciones::crearAsistente() {
    printAsistTipo();
    string* data = new string;
    cin >> *data;
    int* i = validarOpcion(*data);

    switch (*i){
    case 1: { //Asistente Basico
        break;}
    case 2: { //Asistente en Linea
        break;}
    case 3: { //Trabajador Empresa
        break;}
    case 4: { //Trabajador Docente
        break;}
    case 5: { //Estudiante
        break;}
    default:
        cout << "-------Opcion Invalidad-------" << endl;
        crearAsistente();
    }

    Asistente* a = new Asistente("test", 1);
    return a;
    }

bool Funciones::registrarAsist() {
    listarEventos();
    
    string* data = new string;
    cout << "Opcion: ";
    cin >> *data;
    int i = validarOpcion(*data);
    
    for (int x = 0; x < cantidad; x++) {
        if (i == x) {
            if (eventos[x] -> getCantidad() < eventos[x] -> getCapacidad()) {
                //Agregar asistente


            }
        }
    }
    return false;
}

bool Funciones::crearEvento(){
    cout << "------Creacion de Evento------" << endl;
    //preguntar por tipo
    printTipo();
    //elegir tipo
    string* data = new string;
    cin >> *data;   
    int* opcion = new int;
    *opcion = validarOpcion(*data);
    switch (*opcion){
        case 1:{//Evento Publico
            cout << "Tema: ";
            cin.ignore(); // Limpia el búfer
            getline(cin,*data);
            string tema = *data; 

            cout << "Duracion (en minutos): ";
            cin >> *data;
            int i = validarOpcion(*data);
            int duracion = i;

            cout << "Ubicacion: ";
            cin.ignore();
            getline(cin,*data);
            string ubicacion = *data;

            cout << "Capacidad: ";
            cin >> *data;
            i = validarOpcion(*data);
            int capacidad = i;

            cout << "Registro requerido (0|1): ";
            cin >> *data;
            bool registroR = validarBoolean(*data);
            
            Evento* eP = new Evento(tema,duracion,ubicacion,capacidad, registroR);
            addEvento(eP);
            break;}
        case 2:{//Evento Digital
            cout << "Tema: ";
            cin.ignore(); // Limpia el búfer
            getline(cin,*data);
            string tema = *data; 

            cout << "Duracion (en minutos): ";
            cin >> *data;
            int i = validarOpcion(*data);
            int duracion = i;

            cout << "Capacidad: ";
            cin >> *data;
            i = validarOpcion(*data);
            int capacidad = i;

            cout << "Plataforma de transmision: ";
            cin.ignore();
            getline(cin,*data);
            string plataforma = *data;

            cout << "Acceso gratuito (0|1): ";
            cin >> *data;
            bool accesoG = validarBoolean(*data);

            Evento* eD = new Evento(tema,duracion,capacidad,plataforma,accesoG);
            addEvento(eD);
            break;}
        case 3:{//Evento Corporativo
            cout << "Tema: ";
            cin.ignore(); // Limpia el búfer
            getline(cin,*data);
            string tema = *data; 

            cout << "Duracion (en minutos): ";
            cin >> *data;
            int i = validarOpcion(*data);
            int duracion = i;

            cout << "Ubicacion: ";
            cin.ignore();
            getline(cin,*data);
            string ubicacion = *data;

            cout << "Capacidad: ";
            cin >> *data;
            i = validarOpcion(*data);
            int capacidad = i;

            cout << "Departamento responsable: ";
            cin.ignore();
            getline(cin,*data);
            string departamentoR = *data;

            cout << "Empresa: ";
            getline(cin,*data);
            string empresa = *data;

            Evento* eC = new Evento(tema,duracion,ubicacion,capacidad,departamentoR,empresa);
            addEvento(eC);
            break;}
        case 4:{//Evento Academico
            cout << "Tema: ";
            cin.ignore(); // Limpia el búfer
            getline(cin,*data);
            string tema = *data; 

            cout << "Duracion (en minutos): ";
            cin >> *data;
            int i = validarOpcion(*data);
            int duracion = i;

            cout << "Ubicacion: ";
            cin.ignore();
            getline(cin,*data);
            string ubicacion = *data;

            cout << "Capacidad: ";
            cin >> *data;
            i = validarOpcion(*data);
            int capacidad = i;

            cout << "Universidad: ";
            cin.ignore();
            getline(cin,*data);
            string universidad = *data;

            cout << "Certificado disponible (0|1): ";
            cin >> *data;
            bool certificadoD = validarBoolean(*data);

            Evento* eA = new Evento(tema,duracion,ubicacion,capacidad,universidad,certificadoD);
            addEvento(eA);
            break;}
        case 5:{//Evento Privado
            cout << "Duracion (en minutos): ";
            cin >> *data;
            int i = validarOpcion(*data);
            int duracion = i;

            cout << "Ubicacion: ";
            cin.ignore();
            getline(cin,*data);
            string ubicacion = *data;

            cout << "Capacidad: ";
            cin >> *data;
            i = validarOpcion(*data);
            int capacidad = i;

            Evento* eP = new Evento(duracion,ubicacion,capacidad);
            addEvento(eP);
            break;}
        default:
            cout << "-------Opcion Invalidad-------" << endl;
            break;
    }
    return true;
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