#include "node.h"
#include "node.h"

template<typename T>
Nodo<T>::Nodo(){
	dato = NULL;
	siguiente = NULL;
}

template<typename T>
Nodo<T>::Nodo(T dato_){
	dato = dato_;
	siguiente = NULL;
}

template<typename T>
void Nodo<T>::borrar_todo(){
	if (siguiente)
		siguiente->borrar_todo();
	delete this;
}

template<typename T>
void Nodo<T>::imprimir(){
	cout << dato << "-> ";
}

template<typename T>
Nodo<T>::~Nodo() {}