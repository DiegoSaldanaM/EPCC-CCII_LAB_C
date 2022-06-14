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
	int op;
	
	cout << "Indique el tamaño de la lista enlazada: " << endl;
	cin >> tam;
	int posicion=tam;
	
	lista_1.elementos_random(tam);
	
	cout << "La lista inicial es: " << endl;
	lista_1.imprimir();
	
	cout<<"Se eliminará el ultimo elemento: "<<endl;
	lista_1.eliminar_nodo(posicion);
	lista_1.imprimir();

	
	return 0;	
}