#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para imprimir un conjunto
template<typename T>
void imprimirConjunto(const vector<T>& conjunto) {
    cout << "{ ";
    for (const auto& elemento : conjunto) {
        cout << elemento << " ";
    }
    cout << "}" << endl;
}

// Función para insertar valores en un conjunto
template<typename T>
void insertarElemento(vector<T>& conjunto) {
    T valor;
    cout << "Ingrese el elemento a insertar: ";
    cin >> valor;
    conjunto.push_back(valor);
}

// Función para borrar un elemento de un conjunto
template<typename T>
void borrarElemento(vector<T>& conjunto) {
    T valor;
    cout << "Ingrese el elemento a borrar: ";
    cin >> valor;
    auto it = find(conjunto.begin(), conjunto.end(), valor);
    if (it != conjunto.end()) {
        conjunto.erase(it);
        cout << "Elemento borrado exitosamente." << endl;
    } else {
        cout << "Elemento no encontrado en el conjunto." << endl;
    }
}

// Función para vaciar un conjunto
template<typename T>
void vaciarConjunto(vector<T>& conjunto) {
    conjunto.clear();
    cout << "Conjunto vaciado exitosamente." << endl;
}

// Función para realizar la unión de dos conjuntos
template<typename T>
vector<T> unionConjuntos(const vector<T>& conjunto1, const vector<T>& conjunto2) {
    vector<T> union_resultado = conjunto1;
    for (const auto& elemento : conjunto2) {
        if (find(union_resultado.begin(), union_resultado.end(), elemento) == union_resultado.end()) {
            union_resultado.push_back(elemento);
        }
    }
    return union_resultado;
}

// Función para realizar la intersección de dos conjuntos
template<typename T>
vector<T> interseccionConjuntos(const vector<T>& conjunto1, const vector<T>& conjunto2) {
    vector<T> interseccion_resultado;
    for (const auto& elemento : conjunto1) {
        if (find(conjunto2.begin(), conjunto2.end(), elemento) != conjunto2.end()) {
            interseccion_resultado.push_back(elemento);
        }
    }
    return interseccion_resultado;
}

// Función para realizar la diferencia de dos conjuntos
template<typename T>
vector<T> diferenciaConjuntos(const vector<T>& conjunto1, const vector<T>& conjunto2) {
    vector<T> diferencia_resultado;
    for (const auto& elemento : conjunto1) {
        if (find(conjunto2.begin(), conjunto2.end(), elemento) == conjunto2.end()) {
            diferencia_resultado.push_back(elemento);
        }
    }
    return diferencia_resultado;
}

int main() {
    vector<int> conjunto1, conjunto2;
    int opcion;

    do {
        cout << "\nOperaciones con conjuntos:" << endl;
        cout << "1. Insertar elemento en conjunto 1" << endl;
        cout << "2. Insertar elemento en conjunto 2" << endl;
        cout << "3. Borrar elemento de conjunto 1" << endl;
        cout << "4. Borrar elemento de conjunto 2" << endl;
        cout << "5. Vaciar conjunto 1" << endl;
        cout << "6. Vaciar conjunto 2" << endl;
        cout << "7. Unión de conjuntos" << endl;
        cout << "8. Intersección de conjuntos" << endl;
        cout << "9. Diferencia de conjuntos" << endl;
        cout << "10. Complemento de conjunto 1 respecto a conjunto 2" << endl;
        cout << "11. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarElemento(conjunto1);
                break;
            case 2:
                insertarElemento(conjunto2);
                break;
            case 3:
                borrarElemento(conjunto1);
                break;
            case 4:
                borrarElemento(conjunto2);
                break;
            case 5:
                vaciarConjunto(conjunto1);
                break;
            case 6:
                vaciarConjunto(conjunto2);
                break;
            case 7: {
                vector<int> union_resultado = unionConjuntos(conjunto1, conjunto2);
                cout << "Unión de conjuntos: ";
                imprimirConjunto(union_resultado);
                break;
            }
            case 8: {
                vector<int> interseccion_resultado = interseccionConjuntos(conjunto1, conjunto2);
                cout << "Intersección de conjuntos: ";
                imprimirConjunto(interseccion_resultado);
                break;
            }
            case 9: {
                vector<int> diferencia_resultado = diferenciaConjuntos(conjunto1, conjunto2);
                cout << "Diferencia de conjuntos (conjunto1 - conjunto2): ";
                imprimirConjunto(diferencia_resultado);
                break;
            }
            case 10: {
                vector<int> complemento_resultado = diferenciaConjuntos(conjunto2, conjunto1);
                cout << "Complemento de conjunto 1 respecto a conjunto 2: ";
                imprimirConjunto(complemento_resultado);
                break;
            }
            case 11:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 11);

    return 0;
}
