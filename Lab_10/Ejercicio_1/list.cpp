#include "list.h"
#include <ctime>
using namespace std;

template<typename T>
Lista<T>::Lista(){
	m_num_nodes = 0;
	m_head = NULL;
}

template<typename T>
void Lista<T>::agregar_final(T dato_){
	Nodo<T> *new_nodo = new Nodo<T> (dato_);
	Nodo<T> *temp = m_head;
	
	if (!m_head) {
		m_head = new_nodo;
	} else {
		while (temp->siguiente != NULL) {
			temp = temp->siguiente;
		}
		temp->siguiente = new_nodo;
	}
	m_num_nodes++;
}

template<typename T>
void Lista<T>::elementos_random(int tam){
	srand(time(NULL));
	for (int i = 0; i < tam; i++) {
		agregar_final(rand() % 100);
	}
}

template<typename T>
void Lista<T>::imprimir(){
	Nodo<T> *temp = m_head;
	if (!m_head) {
		cout << "Lista vacia: "<< endl;
	} else {
		while (temp) {
			temp->imprimir();
			if (!temp->siguiente) cout << "NULL";
			temp = temp->siguiente;
		}
	}
	cout << endl << endl;
}

template<typename T>
Lista<T>::~Lista() {}