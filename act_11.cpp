/***************
Alberto Guadalupe Hernandez Valencia
19/03/24
act.11
CuAltos
***************/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para insertar un valor en el arreglo de manera ordenada
void insertar(int* arreglo[], int& tamano, int valor, int maxSize) {
    if (tamano >= maxSize) {
        cout << "El arreglo esta hasta aca mira hasta aca, osea llenito ." << endl;
        return;
    }

    // Verificar si el valor efectivamente en efecto ya está insertado
    for (int i = 0; i < tamano; ++i) {
        if (*arreglo[i] == valor) {
            cout << "El valor " << valor << " ya está en el arreglo." << endl;
            return;
        }
    }

    // Encontrar la posición donde insertar el nuevo valor
    int pos = 0;
    while (pos < tamano && *arreglo[pos] < valor) {
        ++pos;
    }

    // Desplazar los elementos para hacer espacio para el valor nuevesito de paquete
    for (int i = tamano; i > pos; --i) {
        arreglo[i] = arreglo[i - 1];
    }

    // Insertar el valor nuevesilo
    arreglo[pos] = new int(valor);
    ++tamano;
    cout << "Valor " << valor << " insertado correctamente." << endl;
}

// Función para mostrar el arreglo
void mostrar(int* arreglo[], int tamano) {
    if (tamano == 0) {
        cout << "El arreglo esta solo, solin, solito." << endl;
        return;
    }

    cout << "Arreglo actual:" << endl;
    for (int i = 0; i < tamano; ++i) {
        cout << *arreglo[i] << " ";
    }
    cout << endl;
}

// Función para llenar el arreglo con valores aleatoriamente aleatorios
void llenarAleatorio(int* arreglo[], int& tamano, int maxSize) {
    srand(time(nullptr));
    tamano = 0; // Reiniciar el tamaño del arreglo
    while (tamano < maxSize) {
        int valor = rand() % 100; // Generar valores aleatorios entre 0 y 99
        insertar(arreglo, tamano, valor, maxSize);
    }
}

// Función para barrer y trapear el arreglo
void borrarElemento(int* arreglo[], int& tamano, int valor) {
    for (int i = 0; i < tamano; ++i) {
        if (*arreglo[i] == valor) {
            delete arreglo[i];
            for (int j = i; j < tamano - 1; ++j) {
                arreglo[j] = arreglo[j + 1];
            }
            --tamano;
            cout << "Valor " << valor << " barrido de forma correctosa." << endl;
            return;
        }
    }
    cout << "El valor " << valor << " no se encuentra en el arreglo." << endl;
}

// Función para barrer y trapear todo el arreglo
void limpiarArreglo(int* arreglo[], int& tamano) {
    for (int i = 0; i < tamano; ++i) {
        delete arreglo[i];
    }
    tamano = 0;
    cout << "Arreglo barridito y trapeado correctamente ;)." << endl;
}

// Función para modificar un valor del arreglo
void modificarValor(int* arreglo[], int tamano, int pos, int nuevoValor) {
    if (pos < 0 || pos >= tamano) {
        cout << "Posición invalida." << endl;
        return;
    }
    delete arreglo[pos];
    arreglo[pos] = new int(nuevoValor);
    cout << "Cambio del valor en la posición " << pos << " patrocinado por fundacion televisa y televisa deportes :)." << endl;
}

// Función para establecer el tamaño del arreglo
int establecerTamanioArreglo() {
    int tamano;
    do {
        cout << "Ingrese el tamaño del arreglo (entre 1 y 50): ";
        cin >> tamano;
    } while (tamano < 1 || tamano > 50);
    return tamano;
}

int main() {
    int* arreglo[50];
    int tamano = 0; // Inicializar el tamaño del arreglo a 0
    int opcion;
    int maxSize;

    // Solicitar al usuario el tamaño del arreglo
    maxSize = establecerTamanioArreglo();

    do {
        cout << "\n1. Agregar numero al arreglo\n";
        cout << "2. Mostrar arreglo\n";
        cout << "3. Llenar arreglo con valores aleatorios\n";
        cout << "4. Borrar un elemento del arreglo\n";
        cout << "5. Limpiar todo el arreglo\n";
        cout << "6. Modificar un valor del arreglo\n";
        cout << "7. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                if (tamano >= maxSize) {
                    cout << "El arreglo está lleno." << endl;
                } else {
                    int valor;
                    cout << "Ingrese el valor a insertar: ";
                    cin >> valor;
                    insertar(arreglo, tamano, valor, maxSize);
                }
                break;
            case 2:
                mostrar(arreglo, tamano);
                break;
            case 3:
                llenarAleatorio(arreglo, tamano, maxSize);
                break;
            case 4:
                if (tamano == 0) {
                    cout << "El arreglo esta vacio." << endl;
                } else {
                    int valorBorrar;
                    cout << "Ingrese el valor a borrar: ";
                    cin >> valorBorrar;
                    borrarElemento(arreglo, tamano, valorBorrar);
                }
                break;
            case 5:
                limpiarArreglo(arreglo, tamano);
                break;
            case 6:
                if (tamano == 0) {
                    cout << "El arreglo esta vacio." << endl;
                } else {
                    int posicion, nuevoValor;
                    cout << "Ingrese la posición del valor que sale: ";
                    cin >> posicion;
                    cout << "Ingrese el valor que entra: ";
                    cin >> nuevoValor;
                    modificarValor(arreglo, tamano, posicion, nuevoValor);
                }
                break;
            case 7:
                cout << "Al rato paisa...\n";
                break;
            default:
                cout << "Opción inválida. Favor de leer e ingrese un número valido ;).\n";
        }

    } while (opcion != 7);

    // Liberar memoria
    limpiarArreglo(arreglo, tamano);

    return 0;
}
