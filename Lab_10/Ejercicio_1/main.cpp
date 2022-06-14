#include <iostream>
#include <cstdlib>
#include "list.h"
#include "list.cpp"

using namespace std;

int main(){
	Lista<int> lista_1;
	Lista<int> lista_2;
	int elem;
	
	int tam;
	int posicion;
	
	cout << "Indique el tamaño de la lista enlazada: " << endl;
	cin >> tam;
	
	lista_1.elementos_random(tam);
	
	cout << "La lista inicial es: " << endl;
	lista_1.imprimir();
	
	cout << "Ingresar elemento en la ultima posición: " << endl;
	cin >> elem;
	lista_1.agregar_final(elem);
	lista_1.imprimir();
	
	return 0;	
}
