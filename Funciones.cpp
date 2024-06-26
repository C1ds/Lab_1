#include <iostream>
#include <string>
#include "Funciones.h"
#include "Evento.h"
#include <fstream>
#include <sstream>
#include <vector>

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

void Funciones::listarAsistentes() {
    string* data = new string;
    cout << "[1] Listar asistentes de un evento" << endl;
    cout << "[2] Listar todos los asistentes por evento" << endl;
    cout << "Opcion: ";
    cin.ignore();
    getline(cin,*data);
    int i = validarOpcion(*data);

    if (cantidad == 0) {
        cout << "No hay eventos que listar" << endl;
        return;
    }

    switch (i){
    case 1: { //Asistentes de un Evento
            listarEventos();
            cout << "Opcion: ";
            cin >> *data;
            int i = validarOpcion(*data);
    
            for (int x = 0; x < cantidad; x++) {
                if ((i-1) == x) {
                    if (0 < eventos[x] -> getCantidad()) {
                        cout << "#############################" << endl;
                        cout << "[" << (x+1) << "] " << eventos[x] -> getTipo() << " - " << eventos[x] -> getTema() << endl;
                        cout << "#############################" << endl;
                        eventos[x] -> listarAsistentes();
                        return;
                    }
                }
            }

            break;}
    case 2: { //Asistentes de todos los Eventos
            for (int x = 0; x < cantidad; x++) {
                if (0 < eventos[x] -> getCantidad()) {
                    cout << "#############################" << endl;
                    cout << "[" << (x+1) << "] " << eventos[x] -> getTipo() << " - " << eventos[x] -> getTema() << endl;
                    cout << "#############################" << endl;
                    eventos[x] -> listarAsistentes();
                } 
            }
            break;}
    default:
        cout << "-------Opcion Invalidad-------" << endl;
        break;
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
    int i = validarOpcion(*data);
    Asistente* asistente;

    switch (i){
    case 1: { //Asistente Basico
        cout << "Nombre: ";
        cin.ignore();
        getline(cin,*data);
        string nombre = *data;

        cout << "Edad: ";
        cin >> *data;
        i = validarOpcion(*data);
        int edad = i;

        asistente  = new Asistente(nombre, edad);
        return asistente;
        break;}
    case 2: { //Asistente en Linea
        cout << "Nombre: ";
        cin.ignore();
        getline(cin,*data);
        string nombre = *data;

        cout << "Nickname: ";
        getline(cin,*data);
        string nickname = *data;

        asistente = new Asistente(nombre, nickname);
        return asistente;
        break;}
    case 3: { //Trabajador Empresa
        cout << "Nombre: ";
        cin.ignore();
        getline(cin,*data);
        string nombre = *data;

        cout << "Edad: ";
        cin >> *data;
        i = validarOpcion(*data);
        int edad = i;

        cout << "Ocupacion: ";
        cin.ignore();
        getline(cin,*data);
        string ocupacion = *data;

        cout << "Empresa: ";
        getline(cin,*data);
        string empresa = *data;

        asistente = new Asistente(nombre, edad, ocupacion, empresa);
        return asistente;
        break;}
    case 4: { //Trabajador Docente
        cout << "Nombre: ";
        cin.ignore();
        getline(cin,*data);
        string nombre = *data;

        cout << "Ocupacion: ";
        getline(cin,*data);
        string ocupacion = *data;

        cout << "Universidad: ";
        getline(cin,*data);
        string universidad = *data;

        asistente = new Asistente(nombre, ocupacion, universidad);
        return asistente;
        break;}
    case 5: { //Estudiante
        cout << "Nombre: ";
        cin.ignore();
        getline(cin,*data);
        string nombre = *data;

        cout << "Carrera: ";
        getline(cin,*data);
        string carrera = *data;

        cout << "Universidad: ";
        getline(cin,*data);
        string universidad = *data;

        cout << "Semestre: ";
        cin >> *data;
        i = validarOpcion(*data);
        int semestre = i;

        asistente = new Asistente(nombre, carrera, universidad, semestre);
        return asistente;
        break;}
    default:
        cout << "-------Opcion Invalidad-------" << endl;
        crearAsistente();
    }

    return asistente;
    }

bool Funciones::registrarAsist() {
    listarEventos();
    if (cantidad == 0) {return false;}
    
    string* data = new string;
    cout << "Opcion: ";
    cin >> *data;
    int i = validarOpcion(*data);
    
    for (int x = 0; x < cantidad; x++) {
        if ((i-1) == x) {
            if (eventos[x] -> getCantidad() < eventos[x] -> getCapacidad()) {
                //Agregar asistente
                Asistente* a = crearAsistente();
                eventos[x] -> addAsistente(a);
                return true;
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
void Funciones::leerArchivoEvento() {
    string nombreArchivo = "eventos.txt";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string parte;
        vector<string> partes;

        // mete las partes a un vector
        while (getline(ss, parte, ',')) {
            partes.push_back(parte);
        }
        Evento* e;
        if(partes[1]=="Publico"){
            e = new Evento(partes[2],validarOpcion(partes[3]),partes[4],validarOpcion(partes[5]), validarOpcion(partes[6]));
        } else if (partes[1]=="Digital"){
            e = new Evento(partes[2],validarOpcion(partes[3]),validarOpcion(partes[4]),partes[5],validarOpcion(partes[6]));
        }else if (partes[1]=="Corporativo"){
            e = new Evento(partes[2],validarOpcion(partes[3]),partes[4],validarOpcion(partes[5]),partes[6],partes[7]);
        }else if (partes[1]=="Academico"){
            e = new Evento(partes[2],validarOpcion(partes[3]),partes[4],validarOpcion(partes[5]),partes[6],validarBoolean(partes[7]));
        }else if (partes[1]=="Privado"){
            e = new Evento(validarOpcion(partes[2]),partes[3],validarOpcion(partes[4]));
        }
        addEvento(e);
        
       
    }

    archivo.close();
}
void Funciones::leerArchivoAsistentes(){
    string nombreArchivo = "asistentes.txt";
    ifstream archivo(nombreArchivo.c_str());
    string linea;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string parte;
        vector<string> partes;  
    while (getline(ss, parte, ',')) {
        partes.push_back(parte);
    }
    Asistente* a;
    if(partes[1]=="Basico"){
        a = new Asistente(partes[2],validarOpcion(partes[3]));
        
    }else if(partes[1]=="Online"){
        a = new Asistente(partes[2],partes[3]);
    }else if(partes[1]=="T_Empresa"){
        a = new Asistente(partes[2],validarOpcion(partes[3]),partes[4],partes[5]);
    }else if(partes[1]=="T_Docente"){
        a = new Asistente(partes[2],partes[3],partes[4]);
    }else if(partes[1]=="Estudiante"){
        a = new Asistente(partes[2],partes[3],partes[4],validarOpcion(partes[5]));
    }
    int index = validarOpcion(partes[0]);
    
    eventos[index] -> addAsistente(a);
    }
    archivo.close();
     }
void Funciones::escribirArchivo(){
    
    string archEvento = "eventos.txt";
    string archAsistent = "asistentes.txt";
    ofstream archivo;
    ofstream archivoAsistentes;
    archivo.open(archEvento.c_str(), fstream::out);
    archivoAsistentes.open(archAsistent.c_str(), fstream::out);
    if (cantidad < 1) {
        archivo << "No hay eventos registrados" << endl;
        return;
    }

    string tipo;
    for ( int i = 0; i < cantidad; i++){
        tipo = eventos[i] -> getTipo();
        cout << "#############################" << endl;
        
        if (tipo == "Publico") {
            archivo << i <<","<<eventos[i] -> getTipo() <<","<< eventos[i] -> getTema() <<","<< eventos[i] -> getDuracion() <<","<<eventos[i] -> getUbicacion() <<","<< eventos[i] -> getCapacidad()<<","<< eventos[i] -> getCantidad()  << endl;
            archivoAsistentes<<i<< eventos[i]-> getAsistentes();
            continue;
        }
        else if (tipo == "Digital") {
            archivo << i<<","<< eventos[i] -> getTipo() <<","<< eventos[i] -> getTema() <<","<< eventos[i] -> getDuracion() <<","<<eventos[i] -> getCapacidad() <<","<< eventos[i] -> getCantidad() << endl;
            archivoAsistentes<<i<< eventos[i]-> getAsistentes();
            continue;
        }
        else if (tipo == "Corporativo") {
            
            archivo << i<<","<< eventos[i] -> getTipo() <<","<< eventos[i] -> getTema() <<","<< eventos[i] -> getDuracion() <<","<<eventos[i] -> getUbicacion() <<","<< eventos[i] -> getCapacidad() <<","<< eventos[i] -> getDepartamentoResponsable()<<","<< eventos[i] -> getEmpresa()<< endl;
            archivoAsistentes<<i<< eventos[i]-> getAsistentes();
            continue;
            
        }
        else if (tipo == "Academico"){
            
            archivo << i<<","<< "Academico" <<","<< eventos[i] -> getTema() <<","<< eventos[i] -> getDuracion() <<","<<eventos[i] -> getUbicacion() <<","<< eventos[i] -> getCapacidad() <<","<< eventos[i] -> getUniversidad()<<","<<  eventos[i] -> getCertificadoDisponible() <<endl;
            archivoAsistentes<<i<< eventos[i]-> getAsistentes();
            continue;
            
            
            //archivo << "Certificado disponible: " << boolalpha << eventos[i] -> getCertificadoDisponible() << endl;
        }
        else if (tipo == "Privado") {
            
            archivo << i<<","<< eventos[i] -> getTipo() <<","<< eventos[i] -> getDuracion() <<","<< eventos[i] -> getUbicacion() <<","<<eventos[i] -> getCapacidad() <<endl;
            archivoAsistentes<<i<< eventos[i]-> getAsistentes();
            continue;
        }
        else {
            cout << "------Evento no Listado------" << endl;
        };
        
    }
    archivo.close();
    archivoAsistentes.close();
}
    
    //
    
    
    

    
    
    
    
    
    
    
    
    

     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
Funciones::~Funciones(){cout << "Programa finalizado" << endl;}