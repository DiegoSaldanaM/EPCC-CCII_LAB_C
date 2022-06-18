#include <iostream>
using namespace std;

class pila{
private:
	class nodo {
	public:
		int info;
		nodo *sig;
	};
	
	nodo *raiz;
public:
	pila();
	~pila();
	void insertar(int n);
	void imprimir();
    int eliminar();
};

pila::pila(){
	raiz = NULL;
}

pila::~pila(){
	nodo *reco = raiz;
	nodo *bor;
	while (reco != NULL)
	{
		bor = reco;
		reco = reco->sig;
		delete bor;
	}
}

void pila::insertar(int n){
	nodo *nuevo;
	nuevo = new nodo();
	nuevo->info = n;
	if (raiz == NULL){
		raiz = nuevo;
		nuevo->sig = NULL;
	}
	else{
		nuevo->sig = raiz;
		raiz = nuevo;
	}
}

void pila::imprimir(){
	nodo *reco = raiz;
	while (reco != NULL){
		cout<<reco->info<< "-";
		reco = reco->sig;
	}
	cout<<"\n";
}

int pila::eliminar(){
	if (raiz != NULL){
		int informacion = raiz->info;
		nodo *bor = raiz;
		raiz = raiz->sig;
		delete bor;
		return informacion;
	}
	else{
		return -1;
	}
}


int main(){
	pila *Pila_1;
	Pila_1= new pila();
	string opcion;
	int num;

    cout<<"Ingrese el  número que desea insertar: ";
    cin>>num;
    Pila_1->insertar(num);
    while(true){
        cout<<"¿Desea seguir insertando datos? (1 = si, 2 = no): ";
        cin>>opcion;
        if(opcion=="1"){
            cout<<"Ingrese el  número que desea insertar: ";
            cin>>num;
            Pila_1->insertar(num);
        }
        else if(opcion=="2"){
            cout<<"Pila imprimida: "<<endl;
			Pila_1->imprimir();
			break;
		}
    }

    cout<<"¿Desea eliminar un elemento de la pila? (1 = si, 2 = no): ";
    cin>>opcion;
    if(opcion=="1"){
        cout<<"Elemento eliminado de la pila: "<< Pila_1->eliminar()<<endl;
        Pila_1->imprimir();
    }
    else if(opcion=="2"){
        cout<<"No se eliminaran elementos de la pila.";
    }

	delete Pila_1;
	return 0;
}