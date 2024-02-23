#include <iostream>
using namespace std;
int main() {

//declaracion de arreglo
int arreglo [10];

//variables locales
int indice, valor, opcion, suma;

//iniciar arreglo con ceros
for(int i = 0; i <10; ++i) {
    arreglo [i]=0;
}

//ciclo principal
do{
    cout<< "\nMenu:\n";
    cout<< "1.- Agregar un valor al arreglo\n";
    cout<< "2.- Mostrar lista de valores\n";
    cout<< "3.- Mostrar sumatoria de todos los elementos\n";
    cout<< "4.- Borrar elemento\n";
    cout<< "5.- Editar elemento\n";
    cout<< "6.- Vaciado de arreglo\n";
    cout<< "7.- Salir\n";
    cout<< "Seleccione una opcion: ";
    cin >> opcion;

    switch(opcion){
case 1:
    cout<<"ingrese el valor que quiere agregar al arreglo";
    cin>>valor;
    cout<<"Ingrese la posicision donde desea agregar el valor (0-9)";
    cin>>indice;
    if (indice >= 0 && indice < 10) {
                    arreglo[indice] = valor;
                } else {
                    cout << "Posición inválida" << endl;
                }
                break;
case 2:
    cout<< "lista de valores \n";
    for(int i=0; i<10 ; ++i){
        cout<< "posicion "<< i << ": " << arreglo[i] << endl;
    }
    break;
case 3:
    suma=0;
    for(int i=0; i<10; ++i) {
        suma += arreglo[i];
    }
    cout<< "Sumatoria de todos los elementos: " << suma << endl;
    break;
case 4:
    cout<< "Ingrese la posicion del elemento a borrar (0-9): ";
    cin>> indice;
    if(indice>=0 && indice <10){
        arreglo[indice]=0;
        }else{
        cout<< "posicion invalida" << endl;
        }
        break;
case 5:
    cout << "Ingrese la posicion del elemento a editar: ";
    cin>> indice;
    if(indice=0 && indice ,10) {
        cout<< "ingrese el nuevo valor: ";
        cin>> valor;
        arreglo[indice] = valor;
    } else {
    cout<< "posicion invalida"<< endl;
    }
    break;
case 6:
    for(int i=0; i<10; ++i) {
        arreglo [i]=0;
    }
    cout<< "arreglo vaciado"<< endl;
    break;
case 7:
    cout<< "saliendo del programa"<< endl;
    break;
default:
    cout<< "opcion invalida"<< endl;
    }
} while (opcion != 7);

return 0;
}
