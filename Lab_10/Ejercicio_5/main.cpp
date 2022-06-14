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
	int posicion = 1;
	int op;
	
	cout << "Indique el tamaño de la lista enlazada: " << endl;
	cin >> tam;
	
	lista_1.elementos_random(tam);
	
	cout << "La lista inicial es: " << endl;
	lista_1.imprimir();
	
	cout << "Se eliminará el primer elemento de la lista: " << endl;
	lista_1.eliminar_nodo(posicion);
	lista_1.imprimir();

	
	return 0;	
}