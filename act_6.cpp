/*******************************************************
Nombre de la universidad: Universidad de Guadalajara
Centro universitario: Centro Universitario de los Altos
Carrera: Ingeniería en Computación
El trabajo: Actividad de programación 6
Nombre del maestro: Sergio Franco Casillas
Nombre propio: Alberto Guadalupe Hernández Valencia
Fecha: 20/feb/24
********************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main () {
 vector<int> numeros;
// declaramos las variables
   int opcion;
   int valor;
   int indice;
   int suma;
//Mostramos al usuario el menu de opciones

   do {
        cout<< "\nMenu:\n";
    cout<< "1.- Agregar un valor al vector\n";
    cout<< "2.- Mostrar lista de valores\n";
    cout<< "3.- Mostrar sumatoria de todos los elementos\n";
    cout<< "4.- Borrar elemento\n";
    cout<< "5.- Editar elemento\n";
    cout<< "6.- Vaciado de vector\n";
    cout<< "7.- Salir\n";
    cout<< "Seleccione una opcion: ";
    cin >> opcion;
//iniciamos con la primera opcion
    switch(opcion) {
case 1:// opcion para agregar numero al vector
    cout<<"ingrese el valor que quiere agregar al vector";
    cin>> valor;
    numeros.push_back(valor);//La función push_back() es un método de la clase vector en C++, y se utiliza para agregar un elemento al final del vector.
    break;
case 2://opcion para mostrar los valores de vector
    cout<< "lista de valores:\n";
    for(int i=0; i<numeros.size(); ++i) { //La función size() es un método de la clase vector en C++, y se utiliza para obtener el tamaño actual del vector, es decir, el número de elementos que contiene.
        cout<< "posicion " << i << ": "<< numeros[i]<< endl;
    }
    break;
case 3://opcion para imprimir al suma de los valores del vector
    suma=0;
    for(int i=0; i<numeros.size(); ++i) {
        suma += numeros[i];
    }
    cout<< "Sumatoria de todos los elementos: " << suma << endl;
    break;
case 4://opcion para borrar un valor del vector
    cout<< "Ingrese la posicion del elemento a borrar (0-9): ";
    cin>> indice;
    if(indice>=0 && indice <numeros.size()){
        numeros.erase(numeros.begin()+ indice); //La línea numeros.erase(numeros.begin() + indice) se utiliza para eliminar un elemento específico del vector numeros.
        }else{
        cout<< "posicion invalida" << endl;
        }
        break;
case 5://opcion  para editar los numerosdel vector
    cout<< "ingrese la posicion a editar (0-" << numeros.size() - 1 << "-): ";
    cin >> indice;
    if (indice >=0 && indice < numeros.size()){
        cout<< "ingrese el nuevo valor: ";
        cin>> valor;
        numeros[indice]= valor;
        cout<< "elemento editado exitosamente.\n";
    } else {
    cout<< "posicion invalida.\n";
    }
    break;//opcion para limpiar el vector
case 6:
    numeros.clear();
    cout<< "vector vaciado exitosamente.\n";
    break;
case 7://opcion para salir del menu de opciones
    cout<< "saliendo del programa... .\n";
    break;
default:
    cout<< "opcion invalida .\n";

    }
   } while (opcion !=7);
   return 0;
}
