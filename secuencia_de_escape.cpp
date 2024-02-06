/* ****
*** ALBERTO GUADALUPE HERNANDEZ VALENCIA ***
*** 02/02/24 ***
*** CENTRO UNIVERSITARIO DE LOS ALTOS ***
*** 1.0.0 ***
*** CARACTERES ESPECIALES***
*** SERGIO FRANCO CASILLAS***
*** */
#include <iostream>
#include <iomanip> // Necesario para std::setprecision

int main() {
    // Cadena de control de tipo de salida: Entero
    int numero = 42;
    std::cout << "Numero: " << numero << std::endl;

    // Cadena de control de tipo de salida: Decimal
    double decimal = 3.14159;
    std::cout << "Decimal: " << decimal << std::endl;

    // Cadena de control de tipo de salida: Car�cter
    char caracter = 'A';
    std::cout << "Caracter: " << caracter << std::endl;

    // Cadena de control de tipo de salida: Cadena de texto
    std::string texto = "Hola, mundo!";
    std::cout << "Texto: " << texto << std::endl;

    // Cadena de control de tipo de salida: Booleano
    bool esVerdadero = true;
    std::cout << "Es verdadero: " << std::boolalpha << esVerdadero << std::endl;

    // Cadena de control de tipo de salida: Hexadecimal
    int numeroHexadecimal = 255;
    std::cout << "Numero en formato hexadecimal: " << std::hex << numeroHexadecimal << std::endl;

    // Caracter de escape: Nueva l�nea
    std::cout << "Esta l�nea est� en una nueva l�nea.\n";

    // Caracter de escape: Tabulaci�n
    std::cout << "Este texto est� separado\tcon una tabulaci�n.\n";

    // Caracter de escape: Retroceso
    std::cout << "Texto con retroceso:\b\b\b123\n";

    // Caracter de escape: Retorno de carro
    std::cout << "Este texto tiene un retorno de carro.\rReemplazado.\n";

    // Caracter de escape: Comilla simple
    std::cout << "Uso de comilla simple: '\''\n";

    // Caracter de escape: Barra invertida
    std::cout << "Uso de barra invertida: \\\n";

    return 0;
}

