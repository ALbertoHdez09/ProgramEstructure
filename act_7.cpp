#include <iostream>
#include <ctime> // Para generar números aleatorios
#include <cstdlib> // Para generar números aleatorios

using namespace std;

const int MAX_SIZE = 10; // Tamaño máximo de la matriz

// Función para imprimir una matriz
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para llenar una matriz con valores aleatorios
void fillMatrixRandom(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(0)); // Inicializar la semilla para números aleatorios

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 201 - 100; // Generar un número aleatorio entre -100 y 100
        }
    }
}

// Función para sumar dos matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Función para restar dos matrices
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Función para multiplicar dos matrices
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0; // Inicializar el elemento de la matriz resultante en 0
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int size;
    cout << "Ingrese el tamaño de las matrices (entre 2 y 10): ";
    cin >> size;

    if (size < 2 || size > 10) {
        cout << "Tamaño de matriz no valido. Debe estar entre 2 y 10." << endl;
        return 1;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    char option;
    cout << "¿Desea llenar las matrices con valores aleatorios? (S/N): ";
    cin >> option;

    if (option == 'S' || option == 's') {
        fillMatrixRandom(matrixA, size);
        fillMatrixRandom(matrixB, size);
    } else if (option == 'N' || option == 'n') {
        cout << "Ingrese los valores de la matriz A:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Ingrese el valor para la posicion (" << i << ", " << j << "): ";
                cin >> matrixA[i][j];
            }
        }

        cout << "Ingrese los valores de la matriz B:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Ingrese el valor para la posicion (" << i << ", " << j << "): ";
                cin >> matrixB[i][j];
            }
        }
    } else {
        cout << "Opcion no válida." << endl;
        return 1;
    }

    cout << "Matriz A:" << endl;
    printMatrix(matrixA, size);

    cout << "Matriz B:" << endl;
    printMatrix(matrixB, size);

    cout << "Seleccione la operacion a realizar:" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "Ingrese su opcion: ";
    cin >> option;

    switch(option) {
        case '1':
            addMatrices(matrixA, matrixB, result, size);
            cout << "Resultado de la suma:" << endl;
            printMatrix(result, size);
            break;
        case '2':
            subtractMatrices(matrixA, matrixB, result, size);
            cout << "Resultado de la resta:" << endl;
            printMatrix(result, size);
            break;
        case '3':
            multiplyMatrices(matrixA, matrixB, result, size);
            cout << "Resultado de la multiplicacion:" << endl;
            printMatrix(result, size);
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }

    return 0;
}
