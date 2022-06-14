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
	int op;
	
	cout << "Indique el tamaño de la lista enlazada: " << endl;
	cin >> tam;
	
	lista_1.elementos_random(tam);
	
	cout << "La lista inicial es: " << endl;
	lista_1.imprimir();
	
	while(true){
		cout<<"MENU: \n 1.-Ingresar elemento \n 2.-Exit"<<endl;
		cin>>op;
		if(op==1){
			cout << "Indicar el elemento a agregar: " << endl;
			cin >> elem;
			cout<<"Indicar la posición del elemento: " <<endl;
			cin >> posicion;
			lista_1.insertar(elem);
			lista_1.imprimir();
		}
		else{
			break;
		}
	}
	
	return 0;	
}