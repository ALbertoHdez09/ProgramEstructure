#include <iostream>

using namespace std;

// Función para generar la serie Fibonacci con un ciclo for
void fibonacciFor(int valorLimite) {
    int a = 0, b = 1, c;
    cout << "Serie Fibonacci utilizando ciclo for:" << endl;
    cout << a << " ";
    for (; b <= valorLimite;) {
        cout << b << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// Función para generar la serie Fibonacci con un ciclo while
void fibonacciWhile(int valorLimite) {
    int a = 0, b = 1, c;
    cout << "Serie Fibonacci utilizando ciclo while:" << endl;
    cout << a << " ";
    while (b <= valorLimite) {
        cout << b << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// Función para generar la serie Fibonacci con un ciclo do-while
void fibonacciDoWhile(int valorLimite) {
    int a = 0, b = 1, c;
    cout << "Serie Fibonacci utilizando ciclo do-while:" << endl;
    cout << a << " ";
    do {
        cout << b << " ";
        c = a + b;
        a = b;
        b = c;
    } while (b <= valorLimite);
    cout << endl;
}

int main() {
    int valorLimite;
    char opcion;

    // Bucle principal que permite al usuario ejecutar el programa varias veces
    do {
        // Se solicita al usuario un valor límite para la serie Fibonacci
        cout << "Ingrese un valor limite para la serie Fibonacci: ";
        cin >> valorLimite;

        // Se le pide al usuario que elija con qué ciclo desea trabajar
        cout << "Elija con qué ciclo desea trabajar: " << endl;
        cout << "a) Ciclo for" << endl;
        cout << "b) Ciclo while" << endl;
        cout << "c) Ciclo do-while" << endl;
        cout << "d) Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        // Se utiliza un switch para ejecutar la función correspondiente según la opción seleccionada
        switch (opcion) {
            case 'a':
                fibonacciFor(valorLimite);
                break;
            case 'b':
                fibonacciWhile(valorLimite);
                break;
            case 'c':
                fibonacciDoWhile(valorLimite);
                break;
            case 'd':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }

    } while (opcion != 'd'); // El bucle se repite mientras el usuario no elija salir del programa

    return 0;
}
