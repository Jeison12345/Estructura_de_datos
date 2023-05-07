#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Vuelo{
    string numeroVuelo;
    string origen;
    string destino;
    string matriculaAvion;
    string nombrePiloto;
    string horaVuelo;
    string fechaVuelo;
    int estado;
};

struct Nodo{
    Vuelo dato;
    Nodo *sig;
};

struct Pasajero{
    string numeroVuelo;
    string cedula;
    string nombre;
    string telefono;
    int estado;
};

struct NodoPasajero{
    Pasajero dato;
    NodoPasajero *sig;
};

Vuelo datosVuelo(Vuelo vuelo){
    cout << "Ingrese el numero de vuelo: ";
    cin >> vuelo.numeroVuelo;
    cout << "Ingrese el origen: ";
    cin >> vuelo.origen;
    cout << "Ingrese el destino: ";
    cin >> vuelo.destino;
    cout << "Ingrese la matricula del avion: ";
    cin >> vuelo.matriculaAvion;
    cout << "Ingrese el nombre del piloto: ";
    cin >> vuelo.nombrePiloto;
    cout << "Ingrese la hora del vuelo: ";
    cin >> vuelo.horaVuelo;
    cout << "Ingrese la fecha del vuelo: ";
    cin >> vuelo.fechaVuelo;
    cout << "Ingrese el estado: ";
    cin >> vuelo.estado;

    ofstream archivo("vuelos.txt", ios::app);
    archivo << vuelo.numeroVuelo << " " << vuelo.origen << " " << vuelo.destino << " " << vuelo.matriculaAvion << " " << vuelo.nombrePiloto << " " << vuelo.horaVuelo << " " << vuelo.fechaVuelo << " " << vuelo.estado << endl;
    archivo.close();
    return vuelo;
}

Pasajero datosPasajero(Pasajero pasajero){
    cout << "Ingrese el numero de vuelo: ";
    cin >> pasajero.numeroVuelo;
    cout << "Ingrese la cedula: ";
    cin >> pasajero.cedula;
    cout << "Ingrese el nombre: ";
    cin >> pasajero.nombre;
    cout << "Ingrese el telefono: ";
    cin >> pasajero.telefono;
    cout << "Ingrese el estado: ";
    cin >> pasajero.estado;

    return pasajero;
}

bool existePasajero(NodoPasajero *lista, Pasajero pasajero){
    NodoPasajero *actual = lista;
    while(actual != NULL){
        if(actual->dato.numeroVuelo == pasajero.numeroVuelo && actual->dato.cedula == pasajero.cedula){
            return true;
        }
        actual = actual->sig;
    }
    return false;
}

void adicionarVuelo(Nodo *&lista, Vuelo vuelo){
    Nodo *nuevo = new Nodo();
    nuevo->dato = vuelo;
    Nodo *aux1 = lista;
    Nodo *aux2 = NULL;
    bool encontrado = false;
    while((aux1 != NULL) && (aux1->dato.numeroVuelo <= vuelo.numeroVuelo)){
        if (aux1->dato.numeroVuelo == vuelo.numeroVuelo) {
            // Ya existe un vuelo con el mismo número de vuelo, actualizar la información de vuelo
            aux1->dato = vuelo;
            encontrado = true;
            break;
        }
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if (!encontrado) {
        if(lista == aux1){
            lista = nuevo;
        }else{
            aux2->sig = nuevo;
        }
        nuevo->sig = aux1;
    }
}

void adicionarPasajero(NodoPasajero *&lista, Pasajero pasajero){
    if(existePasajero(lista, pasajero)){
        cout << "El pasajero ya existe." << endl;
        return;
    }
    NodoPasajero *nuevo = new NodoPasajero();
    nuevo->dato = pasajero;
    NodoPasajero *aux1 = lista;
    NodoPasajero *aux2;
    while((aux1 != NULL) && (aux1->dato.numeroVuelo < pasajero.numeroVuelo)){
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if(lista == aux1){
        lista = nuevo;
    }else{
        aux2->sig = nuevo;
    }
    nuevo->sig = aux1;

    ofstream archivo("pasajeros.txt", ios::app);
    archivo << pasajero.numeroVuelo << " " << pasajero.cedula << " " << pasajero.nombre << " " << pasajero.telefono << " " << pasajero.estado << endl;
    archivo.close();
}

void mostrarVuelos(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        cout << "Numero de vuelo: " << actual->dato.numeroVuelo << endl;
        cout << "Origen: " << actual->dato.origen << endl;
        cout << "Destino: " << actual->dato.destino << endl;
        cout << "Matricula del avion: " << actual->dato.matriculaAvion << endl;
        cout << "Nombre del piloto: " << actual->dato.nombrePiloto << endl;
        cout << "Hora del vuelo: " << actual->dato.horaVuelo << endl;
        cout << "Fecha del vuelo: " << actual->dato.fechaVuelo << endl;
        cout << "Estado: " << actual->dato.estado << endl;
        actual = actual->sig;
    }
}

void mostrarPasajeros(NodoPasajero *lista){
    NodoPasajero *actual = new NodoPasajero();
    actual = lista;
    while(actual != NULL){
        cout << "Numero de vuelo: " << actual->dato.numeroVuelo << endl;
        cout << "Cedula: " << actual->dato.cedula << endl;
        cout << "Nombre: " << actual->dato.nombre << endl;
        cout << "Telefono: " << actual->dato.telefono << endl;
        cout << "Estado: " << actual->dato.estado << endl;
        actual = actual->sig;
    }
}

void mostrarPasajerosVuelo(NodoPasajero *lista, int estado){
    NodoPasajero *actual = new NodoPasajero();
    actual = lista;
    while(actual != NULL){
        if(actual->dato.estado == estado){
            cout << "Numero de vuelo: " << actual->dato.numeroVuelo << endl;
            cout << "Cedula: " << actual->dato.cedula << endl;
            cout << "Nombre: " << actual->dato.nombre << endl;
            cout << "Telefono: " << actual->dato.telefono << endl;
            cout << "Estado: " << actual->dato.estado << endl;
        }
        actual = actual->sig;
    }
}

void mostrarVuelosRealizados(Nodo *lista, int estado){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        if(actual->dato.estado == estado){
            cout << "Numero de vuelo: " << actual->dato.numeroVuelo << endl;
            cout << "Origen: " << actual->dato.origen << endl;
            cout << "Destino: " << actual->dato.destino << endl;
            cout << "Matricula del avion: " << actual->dato.matriculaAvion << endl;
            cout << "Nombre del piloto: " << actual->dato.nombrePiloto << endl;
            cout << "Hora del vuelo: " << actual->dato.horaVuelo << endl;
            cout << "Fecha del vuelo: " << actual->dato.fechaVuelo << endl;
            cout << "Estado: " << actual->dato.estado << endl << endl;
        }
        actual = actual->sig;
    }
}

void mostrarVuelosPasajero(NodoPasajero *lista, string cedula){
    NodoPasajero *actual = new NodoPasajero();
    actual = lista;
    while(actual != NULL){
        if(actual->dato.cedula == cedula){
            cout << "Numero de vuelo: " << actual->dato.numeroVuelo << endl;
            cout << "Cedula: " << actual->dato.cedula << endl;
            cout << "Nombre: " << actual->dato.nombre << endl;
            cout << "Telefono: " << actual->dato.telefono << endl;
            cout << "Estado: " << actual->dato.estado << endl << endl;
        }
        actual = actual->sig;
    }
}

void cambiarEstadoVuelo(Nodo *lista, string numeroVuelo, int estado){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        if(actual->dato.numeroVuelo == numeroVuelo){
            actual->dato.estado = estado;
        }
        actual = actual->sig;
    }
}

void cambiarEstadoPasajero(NodoPasajero *lista, string cedula, int estado){
    NodoPasajero *actual = new NodoPasajero();
    actual = lista;
    while(actual != NULL){
        if(actual->dato.cedula == cedula){
            actual->dato.estado = estado;
        }
        actual = actual->sig;
    }
}

void menu(Nodo *listaVuelos, NodoPasajero *listaPasajeros, Vuelo vuelo, Pasajero pasajero){
    string cedula;
    string numeroVuelo;
    int estado;
    int opcion;
    int opcion2;
    do{
        system("clear");
        cout << "1. Agregar vuelo" << endl;
        cout << "2. Mostrar vuelos" << endl;
        cout << "3. Agregar pasajero" << endl;
        cout << "4. Mostrar pasajeros" << endl;
        cout << "5. Mostrar pasajeros de un vuelo realizado o programado" << endl;
        cout << "6. Mostrar vuelos realizados" << endl;
        cout << "7. Mostrar vuelos de un pasajero" << endl;
        cout << "8. Cambiar estado de un vuelo" << endl;
        cout << "9. Cambiar estado de un pasajero" << endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                datosVuelo(vuelo);
                adicionarVuelo(listaVuelos, vuelo);
                system("clear");
                break;
            case 2:
                mostrarVuelos(listaVuelos);
                cout << "Ingrese 1 para volver al menu" << endl;
                cin >> opcion2;
                if(opcion2 == 1){
                    system("clear");
                }
                break;
            case 3:
                datosPasajero(pasajero);
                adicionarPasajero(listaPasajeros, pasajero);
                system("clear");
                break;
            case 4:
                mostrarPasajeros(listaPasajeros);
                cout << "Ingrese 1 para volver al menu" << endl;
                cin >> opcion2;
                if(opcion2 == 1){
                    system("clear");
                }
                break;
            case 5:
                cout << "Ingrese el estado del vuelo: ";
                cin >> estado;
                mostrarPasajerosVuelo(listaPasajeros, estado);
                cout << "Ingrese 1 para volver al menu" << endl;
                cin >> opcion2;
                if(opcion2 == 1){
                    system("clear");
                }
                break;
            case 6:
                mostrarVuelosRealizados(listaVuelos, 1);
                cout << "Ingrese 1 para volver al menu" << endl;
                cin >> opcion2;
                if(opcion2 == 1){
                    system("clear");
                }
                break;
            case 7:
                cout << "Ingrese la cedula: ";
                cin >> cedula;
                mostrarVuelosPasajero(listaPasajeros, cedula);
                cout << "Ingrese 1 para volver al menu" << endl;
                cin >> opcion2;
                if(opcion2 == 1){
                    system("clear");
                }
                break;
            case 8:
                cout << "Ingrese el numero de vuelo: ";
                cin >> numeroVuelo;
                cout << "Ingrese el estado del vuelo: ";
                cin >> estado;
                cambiarEstadoVuelo(listaVuelos, numeroVuelo, estado);
                break;
            case 9:
                cout << "Ingrese la cedula: ";
                cin >> cedula;
                cout << "Ingrese el estado del pasajero: ";
                cin >> estado;
                cambiarEstadoPasajero(listaPasajeros, cedula, estado);
                break;
            case 10:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opcion != 10);
}

int main(){
    Nodo *listaVuelos = NULL;
    NodoPasajero *listaPasajeros = NULL;
    Vuelo vuelo;
    Pasajero pasajero;

    ifstream archivo("pasajeros.txt");
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){
        archivo >> pasajero.numeroVuelo >> pasajero.cedula >> pasajero.nombre >> pasajero.telefono >> pasajero.estado;
        adicionarPasajero(listaPasajeros, pasajero);
    }
    archivo.close();

    ifstream archivo2("vuelos.txt");
    if(archivo2.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo2.eof()){
        archivo2 >> vuelo.numeroVuelo >> vuelo.origen >> vuelo.destino >> vuelo.matriculaAvion >> vuelo.nombrePiloto >> vuelo.horaVuelo >> vuelo.fechaVuelo >> vuelo.estado;
        adicionarVuelo(listaVuelos, vuelo);
    }
    archivo2.close();

    menu(listaVuelos, listaPasajeros, vuelo, pasajero);

    return 0;
}