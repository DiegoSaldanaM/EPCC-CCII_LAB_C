#include <iostream>
using namespace std;

class nodo{
public:
	friend class cola;
	nodo(int num);
	~nodo();
private:
	nodo* sig;
	int num;
};

class cola{
public:
	cola();
	~cola();
	void insertar_elemento(int dato);
	bool vacio();
	int tam_col();
	const void imprimir();
    void borrar_elem();
    int obtener_prim_elem();  
	bool buscar_elemento(int dato);
private:
	nodo* cabeza;
	nodo* C_cola;
};

nodo::nodo(int num){
	this->sig = NULL;
	this->num = num;
}
nodo::~nodo(){
}

cola::cola(){
    cabeza = NULL;
    C_cola = NULL;
}

cola::~cola(){
}

void cola::insertar_elemento(int dato){
    nodo* nodo_nuevo = new nodo(dato);
    if (cabeza == NULL && C_cola == NULL){
        cabeza = nodo_nuevo;
        C_cola = cabeza;
    }
    else{
        nodo* aux = cabeza;
        while (aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nodo_nuevo;
        C_cola = aux->sig;
    }
}

const void cola::imprimir(){
    nodo* aux = cabeza;
    while (aux != NULL){
        cout << aux->num;
        if (aux->sig != NULL){
            cout << "->";
        }
        aux = aux->sig;
    }
    cout << "\n";
}

bool cola::vacio(){
    if (cabeza == NULL && C_cola == NULL){
        return true;
    }
    return false;
}

int cola::tam_col(){
    int tam = 0;
    nodo* aux = cabeza;
    while (aux != NULL){
        tam++;
        aux = aux->sig;
    }
    return tam;
}

void cola::borrar_elem()
{
    nodo* aux = cabeza;
    cabeza = cabeza->sig;
    delete aux;
}

int cola::obtener_prim_elem(){
    return cabeza->num;
}


bool cola::buscar_elemento(int dato){
    nodo* aux = cabeza;
    while (aux != NULL){
        if (aux->num == dato){
            return true; 
        }      
        aux = aux->sig;
    }
    return false;
}

int main(){
    int num;
    string opc;
	cola* C_1 = new cola();

    cout<<"Ingrese un elemento: ";
    cin>>num;
    C_1->insertar_elemento(num);

    while(true){
        cout<<"¿Desea seguir ingresando elementos? (1 -> si / 2 -> no): "; 
        cin>>opc;
        if(opc=="1"){
            cout<<"Ingrese un elemento: ";
            cin>>num;
            C_1->insertar_elemento(num);
        }
        else if(opc=="2"){
            C_1->imprimir();
            break;
        }
    }

    cout<<"Eliminando un elemento: "<<endl;
    C_1->borrar_elem();
    C_1->imprimir();

    cout<<"Ingrese un elemento a buscar: ";
    cin>>num;
    if (C_1->buscar_elemento(num)){
        cout<<"Elemento encontrado.";
    }
	else{
        cout<<"Elemento no encontrado.";
    }

	delete C_1;
	return 0;
}
