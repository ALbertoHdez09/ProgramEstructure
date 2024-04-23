/***************
Alberto Guadalupe Hernandez Valencia
22/04/24
act.14
CuAltos
***************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <cstring>  // Para strchr

using namespace std;

// Array de palabras para el juego del ahorcado
string palabras[] = {"computadora", "programacion", "tecnologia", "universidad", "desarrollo",
                     "ingenieria", "inteligencia", "informatica", "algoritmo", "exito",
                     "aprendizaje", "estrategia", "creatividad", "sistema", "aplicacion",
                     "solucion", "interfaz", "redes", "hardware", "software"};

const int num_palabras = sizeof(palabras) / sizeof(palabras[0]);

// Función para elegir una palabra al azar
string elegirPalabraAleatoria() {
    srand(time(0));  // Inicializar la semilla aleatoria
    int indice = rand() % num_palabras;
    return palabras[indice];
}

// Función para mostrar la palabra oculta (mostrar letras adivinadas y guiones para las no adivinadas)
string mostrarPalabraOculta(const string& palabra, const string& letrasAdivinadas) {
    string palabraMostrada;
    for (char letra : palabra) {
        if (letrasAdivinadas.find(letra) != string::npos) {
            palabraMostrada += letra;  // Mostrar letra adivinada
        } else {
            palabraMostrada += '_';  // Mostrar guion para letra no adivinada
        }
        palabraMostrada += ' ';  // Espacio entre letras/guiones
    }
    return palabraMostrada;
}

int main() {
    string palabraSecreta;
    string letrasAdivinadas;
    int intentosMaximos = 7;
    int intentosRestantes;
    char opcion;

    cout << "¡Bienvenido al juego del ahorcado!" << endl;

    do {
        // Elegir una nueva palabra secreta
        palabraSecreta = elegirPalabraAleatoria();
        letrasAdivinadas = "";
        intentosRestantes = intentosMaximos;

        cout << "Adivina la palabra secreta. La palabra tiene " << palabraSecreta.length() << " letras." << endl;

        while (intentosRestantes > 0) {
            cout << "Intentos restantes: " << intentosRestantes << endl;
            cout << "Palabra: " << mostrarPalabraOculta(palabraSecreta, letrasAdivinadas) << endl;

            char letra;
            cout << "Ingresa una letra: ";
            cin >> letra;
            letra = tolower(letra);  // Convertir la letra ingresada a minúscula

            if (!isalpha(letra)) {
                cout << "Por favor, ingresa una letra valida." << endl;
                continue;  // Saltar la iteración si no es una letra
            }

            if (letrasAdivinadas.find(letra) != string::npos) {
                cout << "Ya has ingresado esta letra. Intenta con otra." << endl;
                continue;  // Saltar la iteración si la letra ya fue adivinada
            }

            letrasAdivinadas += letra;

            if (palabraSecreta.find(letra) == string::npos) {
                // La letra no está en la palabra secreta
                cout << "¡Incorrecto! La letra '" << letra << "' no está en la palabra." << endl;
                if (strchr("aeiou", letra) != nullptr) {
                    // Penalizar por elegir una vocal
                    intentosRestantes--;
                    cout << "¡Has elegido una vocal! Pierdes un intento." << endl;
                } else {
                    // Penalizar por letra incorrecta
                    intentosRestantes--;
                }
            } else {
                cout << "¡Correcto! La letra '" << letra << "' está en la palabra." << endl;
            }

            // Verificar si se adivinó la palabra completa
            if (mostrarPalabraOculta(palabraSecreta, letrasAdivinadas) == palabraSecreta) {
                cout << "¡Felicidades! Has adivinado la palabra secreta: " << palabraSecreta << endl;
                break;  // Salir del bucle si se adivinó la palabra completa
            }

            cout << endl;
        }

        if (intentosRestantes == 0) {
            cout << "¡Oh no! Te has quedado sin intentos. La palabra secreta era: " << palabraSecreta << endl;
        }

        // Mostrar menú de opciones después de cada juego
        cout << "¿Que deseas hacer a continuacion?" << endl;
        cout << "1. Intentar de nuevo" << endl;
        cout << "2. Elegir una nueva palabra" << endl;
        cout << "3. Mostrar la palabra secreta" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese el numero de la opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                break;  // Continuar con la siguiente partida
            case '2':
                cout << endl;
                break;  // Salir del bucle y elegir una nueva palabra
            case '3':
                cout << "La palabra secreta era: " << palabraSecreta << endl;
                break;
            case '4':
                cout << "Gracias por jugar. ¡Hasta luego!" << endl;
                return 0;  // Salir del programa
            default:
                cout << "Opcion invalida. Saliendo del juego." << endl;
                return 0;  // Salir del programa en caso de opción inválida
        }

    } while (opcion == '1');  // Repetir el juego si se elige intentar de nuevo

    return 0;
}
