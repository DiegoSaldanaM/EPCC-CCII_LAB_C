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
    void buscar(int n);
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

void pila::buscar(int n){
	nodo *reco = raiz;
	int cont = 1;
	int cont2 = 0;
	
	while(reco){
		if (reco->info == n) {
			cout << "El elemento ha sido encontrado en la posición: "<<cont<<endl;
			cont2++;
		}
		reco = reco->sig;
		cont++;
	}
	
	if (cont2 == 0){
		cout<<"Elemento no encontrado."<<endl;
	}
	cout<<endl;
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
        cout<<"No se eliminaran elementos de la pila."<<endl;
    }
    
    while(true){
        cout<<"¿Desea buscar elementos en la píla? (1 = si, 2 = no): ";
        cin>>opcion;
        if(opcion=="1"){
            cout<<"Indique el elemento que se desea buscar: ";
			cin>>num;
			Pila_1->buscar(num);
        }
        else if(opcion=="2"){
            break;
        }
    }
    

	delete Pila_1;
	return 0;
}