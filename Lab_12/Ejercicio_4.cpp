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

bool comparar(cola*& C_1, cola*& C_2)
{
	int aux1{}, aux2{};

	aux1 = C_1->obtener_prim_elem();
	C_1->borrar_elem();
	C_1->insertar_elemento(aux1);

	aux2 = C_2->obtener_prim_elem();
	C_2->borrar_elem();
	C_2->insertar_elemento(aux2);

	if (aux1 > aux2){
        return true;
    }	
	return false;
}

int main(){
    int num;
    bool a;
    cola* hom = new cola();
    cola* muj = new cola();

    for(int i=0; i<3; i++){
        cout<<"Ingrese una edad para las mujeres: ";
        cin>>num;
        muj->insertar_elemento(num);
    }
    for(int i=0; i<2; i++){
        cout<<"Ingrese una edad para los hombres: ";
        cin>>num;
        hom->insertar_elemento(num);
    }

    cout<<"Indique la cantidad de iteraciones a realizar: ";
    cin>>num;

    for (int i=0; i<num; i++){
		if (comparar(hom,muj)){
            a = true;
        }	
		else{
            a = false;
        }
	}

    if(a==true){
        cout<<"Los hombres son mayores despues de " <<num<< " iteraciones."<<endl;
    }
    else{
        cout<<"Las mujeres son mayores despues de " <<num<< " iteraciones."<<endl;
    }
	return 0;
}
