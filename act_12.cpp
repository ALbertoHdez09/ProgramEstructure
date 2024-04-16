#include <iostream>
#include <vector>
#include <limits> // Para usar numeric_limits

using namespace std;

// Función recursiva para resolver las Torres de Hanoi
// Mueve 'n' discos desde el poste 'origen' al poste 'destino' usando 'auxiliar' como auxiliar
void hanoi(int n, char origen, char destino, char auxiliar, int& movimientos) {
    if (n == 1) {
        // Caso base: mover un solo disco de 'origen' a 'destino'
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        movimientos++;
    } else {
        // Mover n-1 discos de 'origen' a 'auxiliar' usando 'destino' como auxiliar
        hanoi(n - 1, origen, auxiliar, destino, movimientos);

        // Mover el disco más grande de 'origen' a 'destino'
        cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
        movimientos++;

        // Mover n-1 discos de 'auxiliar' a 'destino' usando 'origen' como auxiliar
        hanoi(n - 1, auxiliar, destino, origen, movimientos);
    }
}

// Función para validar y procesar un movimiento ingresado por el usuario
bool procesarMovimiento(char origen, char destino, vector<char>& postes) {
    // Verificar que los postes origen y destino sean válidos
    if (origen < 'A' || origen > 'C' || destino < 'A' || destino > 'C') {
        cout << "Postes inválidos. Deben ser A, B o C." << endl;
        return false;
    }

    // Obtener el índice de los postes en el vector
    int indiceOrigen = origen - 'A';
    int indiceDestino = destino - 'A';

    // Verificar que los postes origen y destino sean diferentes
    if (indiceOrigen == indiceDestino) {
        cout << "El poste de origen y destino deben ser diferentes." << endl;
        return false;
    }

    // Verificar que el poste origen contenga al menos un disco
    if (postes[indiceOrigen] == 0) {
        cout << "El poste de origen está vacío." << endl;
        return false;
    }

    // Verificar que el disco a mover sea más pequeño que el disco en el poste destino
    if (postes[indiceDestino] != 0 && postes[indiceOrigen] > postes[indiceDestino]) {
        cout << "No se puede mover un disco sobre uno más pequeño." << endl;
        return false;
    }

    // El movimiento es válido, actualizar el arreglo de postes
    postes[indiceDestino] = postes[indiceOrigen];
    postes[indiceOrigen] = 0;

    return true;
}

// Función para imprimir el estado actual de los postes
void imprimirPostes(const vector<char>& postes) {
    cout << "Estado actual de los postes:" << endl;
    for (char poste = 'A'; poste <= 'C'; ++poste) {
        cout << poste << ": ";
        char disco = postes[poste - 'A'];
        if (disco == 0) {
            cout << " ";
        } else {
            for (char d = '1'; d <= disco; ++d) {
                cout << d;
            }
        }
        cout << endl;
    }
}

int main() {
    int numDiscos;

    cout << "Ingrese el número de discos (entre 3 y 8): ";
    cin >> numDiscos;

    if (numDiscos < 3 || numDiscos > 8) {
        cout << "Número de discos fuera del rango permitido (3-8)." << endl;
        return 1;
    }

    vector<char> postes(3, 0); // Inicializar los postes A, B, C con 0 discos

    // Colocar los discos en el poste A (poste inicial)
    for (int i = numDiscos; i >= 1; --i) {
        postes[0] = i;
    }

    int movimientos = 0;

    // Llamada inicial a la función hanoi para mostrar la solución óptima
    hanoi(numDiscos, 'A', 'C', 'B', movimientos);

    cout << "Solución completa. Ahora puede jugar!" << endl;
    imprimirPostes(postes);

    char origen, destino;

    // Bucle principal para permitir al usuario jugar
    while (postes[2] != numDiscos) { // Mientras todos los discos no estén en el poste C
        cout << "Ingrese el poste de origen y destino (Ejemplo: A C): ";
        cin >> origen >> destino;

        // Limpiar el buffer de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Procesar el movimiento ingresado por el usuario
        if (procesarMovimiento(origen, destino, postes)) {
            ++movimientos;
            imprimirPostes(postes);
        }
    }

    cout << "¡Felicidades! Ha completado las Torres de Hanoi en " << movimientos << " movimientos." << endl;

    return 0;
}
