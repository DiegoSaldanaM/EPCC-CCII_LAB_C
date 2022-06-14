#include "list.h"
#include <ctime>
using namespace std;

template<typename T>
Lista<T>::Lista(){
	m_num_nodes = 0;
	m_head = NULL;
}

template<typename T>
void Lista<T>::agregar_inicio(T dato_){
	Nodo<T> *new_node = new Nodo<T> (dato_);
	Nodo<T> *temp = m_head;
	
	if (!m_head) {
		m_head = new_node;
	} else {
		new_node->siguiente = m_head;
		m_head = new_node;
		
		while (temp) {
			temp = temp->siguiente;
		}
	}
	m_num_nodes++;
}

template<typename T>
void Lista<T>::agregar_final(T dato_)
{
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
void Lista<T>::insertar(T dato_)
{
	Nodo<T> *new_node = new Nodo<T> (dato_);
	Nodo<T> *temp = m_head;
	
	if (!m_head) {
		m_head = new_node;
	} else {
		if (m_head->dato > dato_) {
			new_node->siguiente = m_head;
			m_head = new_node;
		} else {
			while ((temp->siguiente != NULL) && (temp->siguiente->dato < dato_)) {
				temp = temp->siguiente;
			}
			new_node->siguiente = temp->siguiente;
			temp->siguiente = new_node;
		}
	}
	m_num_nodes++;
}

template<typename T>
void Lista<T>::eliminar_nodo(int pos)
{
	Nodo<T> *temp = m_head;
	Nodo<T> *temp1 = temp->siguiente;
	
	if (pos < 1 || pos > m_num_nodes) {
		cout << "Fuera de rango " << endl;
	} else if (pos == 1) {
		m_head = temp->siguiente;
	} else {
		for (int i = 2; i <= pos; i++) {
			if (i == pos) {
				Nodo<T> *aux_node = temp1;
				temp->siguiente = temp1->siguiente;
				delete aux_node;
				m_num_nodes--;
			}
			temp = temp->siguiente;
			temp1 = temp1->siguiente;
		}
	}
}

template<typename T>
void Lista<T>::elementos_random(int tam){
	srand(time(NULL));
	for (int i = 0; i < tam; i++) {
		agregar_inicio(rand() % 100);
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