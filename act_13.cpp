/***************
Alberto Guadalupe Hernandez Valencia
15/04/24
act.13
CuAltos
***************/
#include <iostream>
#include <string>
#include <cctype> // Para funciones de caracteres

using namespace std;

// Función para contar vocales, consonantes y espacios
void contarCaracteres(const string& texto, int& vocales, int& consonantes, int& espacios) {
    vocales = 0;
    consonantes = 0;
    espacios = 0;

    for (char c : texto) {
        if (isalpha(c)) { // Si es una letra
            char lowerC = tolower(c); // Convertir a minúscula para comparación

            // Contar vocales (a, e, i, o, u)
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                vocales++;
            } else { // Si no es vocal, es consonante
                consonantes++;
            }
        } else if (isspace(c)) { // Si es un espacio
            espacios++;
        }
    }
}

// Función para verificar si una palabra o frase es palíndromo
bool esPalindromo(const string& texto) {
    int izquierda = 0;
    int derecha = texto.length() - 1;

    while (izquierda < derecha) {
        if (tolower(texto[izquierda]) != tolower(texto[derecha])) {
            return false; // No es palíndromo
        }
        izquierda++;
        derecha--;
    }
    return true; // Es palíndromo
}

int main() {
    string frase;
    cout << "Ingrese una palabra o frase: ";
    getline(cin, frase);

    // Contar vocales, consonantes y espacios
    int numVocales, numConsonantes, numEspacios;
    contarCaracteres(frase, numVocales, numConsonantes, numEspacios);

    cout << "Numero de vocales: " << numVocales << endl;
    cout << "Numero de consonantes: " << numConsonantes << endl;
    cout << "Numero de espacios: " << numEspacios << endl;

    // Verificar si es palíndromo
    if (esPalindromo(frase)) {
        cout << "La palabra/frase es un palindromo." << endl;
    } else {
        cout << "La palabra/frase NO es un palindromo." << endl;
    }

    // Convertir a mayúsculas y minúsculas
    string mayusculas = frase;
    string minusculas = frase;

    for (char& c : mayusculas) {
        c = toupper(c);
    }

    for (char& c : minusculas) {
        c = tolower(c);
    }

    cout << "En mayusculas: " << mayusculas << endl;
    cout << "En minusculas: " << minusculas << endl;

    // Concatenar con otra palabra o frase
    string otraFrase;
    cout << "Ingrese otra palabra o frase para concatenar: ";
    getline(cin, otraFrase);

    frase += " " + otraFrase;
    cout << "Frase concatenada: " << frase << endl;

    return 0;
}
