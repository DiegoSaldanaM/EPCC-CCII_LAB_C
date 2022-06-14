#include <iostream>
#include <cstdlib>
#include "list.h"
#include "list.cpp"

using namespace std;

int main(){
	Lista<int> lista_1;
	Lista<int> lista_2;
	int elem;
	int tam=1000;
	int posicion;
	int op;
	
	//cout << "Indique el tamaño de la lista enlazada: " << endl;
	//cin >> tam;
	
	lista_1.elementos_random(tam);
	
	//cout << "La lista inicial es: " << endl;
	//lista_1.imprimir();
	
	cout << "Ordenando elementos de forma ascendente. " << endl;
	lista_1.orden_ascendete();
	//lista_1.imprimir();

	cout << "Ordenando elementos de forma descendente. " << endl;
	lista_1.orden_descendente();
	//lista_1.imprimir();

	return 0;	
}