#include<iostream>
#include<string>
#include<cmath>
#include<list>
#include<iomanip>
using namespace std;

struct Producto {
	string codigo;
	string nombre;
	float precio;
	int stock;
	bool estado;
};

typedef struct Producto* Tienda;
Tienda ingresar(string codigo_, string nombre_, float precio_, int stock_) {
	Tienda nuevo = new(struct Producto);
	nuevo->codigo = codigo_;
	nuevo->nombre = nombre_;
	nuevo->precio = precio_;
	nuevo->stock = stock_;
	nuevo->estado = true;
	return nuevo;
}

void ingresar_datos(Tienda& lista, string codigo_, string nombre_, float precio_, int stock_) {
	if (lista == NULL) {
		lista = ingresar(codigo_, nombre_, precio_, stock_);
	}
}

void imprimir(Tienda lista) {
	if (lista != NULL) {
		cout<<"-> Datos del producto <-"<<endl;
		cout<< "Código del producto: "<< lista->codigo<<endl;
		cout<< "Nombre del producto: "<< lista->nombre<<endl;
		cout<< "Precio del producto: "<< lista->precio<<endl;
		cout<< "Stock del producto: "<< lista->stock<<endl; 
		if (lista->estado) {
			cout<< "Disponibilidad: Si"<<endl;
		}
		else {
			cout<< "Disponibilidad: No"<<endl;
		}
		cout<<"  <-------------------->  "<<endl;
	}
}

void dar_alta(Tienda*& lista, int& moun) {
	moun = moun + 1;
	Tienda* lista2 = new Tienda[moun];
	for (int i = 0; i < moun; i++) {
		if (i == moun - 1) {
			lista2[i] = NULL;
		}
		else {
			lista2[i] = lista[i];
		}
	}
	cout<<endl;
	cout<< "  <-------------------->  " << endl;
	string code, name;
	float price;
	int stock;
	cout << "Código del producto: ";
	cin >> code; 
	cout << endl;
	cout << "Nombre del producto: ";
	cin >> name; 
	cout << endl;
	cout << "Precio del producto: ";
	cin >> price; 
	cout << endl;
	cout << "Stock del producto: ";
	cin >> stock; 
	cout << endl;
	ingresar_datos(lista2[moun - 1], code, name, price, stock);
	cout<<"  <-------------------->  "<<endl;
	lista = lista2;
	
}

void dar_baja(Tienda*& lista, int moun) {
	cout<<"  <-------------------->  "<<endl;
	for (int i = 0; i < moun; i++) {
		cout << left << setw(10) << i + 1;
		imprimir(lista[i]);
	}
	string op_2;
	cout << "Seleccionar el producto que desea dar de baja: ";
	cin >> op_2;
	int num = stoi(op_2);
	if (num <= moun && 0 < num) {
		num = num - 1;
		lista[num]->estado = false;
		lista[num]->stock = 0;
		cout<<"  <-------------------->  "<<endl;
		imprimir(lista[num]);
	}
	else {
		cout << "<Error al verificar>" << endl;
	}
}

void buscar_code(Tienda* lista, string code, int moun) {
	int cont = 0;
	for (int i = 0; i < moun; i++) {
		if (lista[i]->codigo == code) {
			cont++;
			cout << left << setw(10) << i + 1;
			imprimir(lista[i]);
		}
	}
	if (cont == 0) {
		cout << "<Producto no encontrado>" << endl;
	}
	cout << "<Error al verificar>" << endl;
	cout << endl;
}

void buscar_name(Tienda* lista, string name, int moun) {
	int cont = 0;
	for (int i = 0; i < moun; i++) {
		if (lista[i]->nombre == name) {
			cont++;
			cout << left << setw(10) << i + 1;
			imprimir(lista[i]);
		}
	}
	if (cont == 0) {
		cout << "<Producto no encontrado>" << endl;
	}
	cout << "<Error al verificar>" << endl;
	cout << endl;
}

void busqueda(Tienda* lista, int moun) {
	string op_2;
	while (true) {
		cout<<"-> Busqueda del producto <-"<<endl;
		cout << "\t1. Busqueda por código"<<endl;
		cout << "\t2. Busqueda por nombre del producto"<<endl;
		cout << "\t3. Salir"<<endl;
		cin >> op_2;
		if (op_2 == "1") {
			string code;
			cout << "Código del producto: ";
			cin >> code;
			cout<<"  <-------------------->  "<<endl;
			buscar_code(lista, code, moun);
		}
		else if (op_2 == "2") {
			string name;
			cout << "Nombre del producto: ";
			cin >> name;
			cout<<"  <-------------------->  "<<endl;
			buscar_name(lista, name, moun);
		}
		else if (op_2 == "3") {
			break;
		}
		else {
			cout << "<Error al verificar>" << endl;
		}
	}
}

void modificar(Tienda*& lista, int moun) {
	cout<<"  <-------------------->  "<<endl;
	for (int i = 0; i < moun; i++) {
		cout << left << setw(10) << i + 1;
		imprimir(lista[i]);
	}
	string op_2;
	cout<<"-> Modificar producto <-"<<endl;
	cout << "Indicar el orden del producto a modificar: ";
	cin >> op_2;
	int num = stoi(op_2);
	if (num <= moun && 0 < num) {
		num = num - 1;
		cout<<"  <-------------------->  "<<endl;
		string code, name;
		float price;
		int stock;
		cout << "Código del producto: ";
		cin >> code; 
		cout << endl;
		cout << "Nombre del producto: ";
		cin >> name; 
		cout << endl;
		cout << "Precio del producto: ";
		cin >> price; 
		cout << endl;
		cout << "Stock del producto: ";
		cin >> stock; 
		cout << endl;
		lista[num]->codigo = code;
		lista[num]->nombre = name;
		lista[num]->precio = price;
		lista[num]->stock = stock;
		lista[num]->estado = true;
		cout<<"  <-------------------->  "<<endl;
		imprimir(lista[num]);
	}
	else {
		cout << "<Error al verificar>" << endl;
	}
}

void menu(Tienda*& lista, int& moun) {
	string op;
	while (true) {
		cout<<"-> Menú de inventario <-"<<endl;
		cout<<"1. Ingresar un producto nuevo"<<endl;
		cout<<"2. Dar de alta un producto nuevo"<<endl;
		cout<<"3. Dar de baja un producto nuevo"<<endl;
		cout<<"4. Buscar un producto"<<endl;
		cout<<"5. Modificar un producto"<<endl;
		cout<<"6. Salir"<<endl;
		cin >> op;
		if (op == "1") {
			for (int i = 0; i < moun; i++) {
				imprimir(lista[i]);
			}
			cout << endl;
		}
		else if (op == "2") {
			dar_alta(lista, moun);
			cout << endl;
			
		}
		else if (op == "3") {
			dar_baja(lista, moun);
			cout << endl;
		}
		else if (op == "4") {
			busqueda(lista, moun);
		}
		else if (op == "5") {
			modificar(lista, moun);
		}
		else if (op == "6") {
			break;
		}
		else {
			cout << "<Error al verificar>" << endl;
		}
	}
}

int main() {
	int moun=10;
	cout << endl;
	Tienda* lista = new Tienda[moun]; 
	for (int i = 0; i < moun; i++) {
		lista[i] = NULL;
	}
	cout<<"-> Datos de productos <-"<<endl;
	for (int i = 0; i < moun; i++) {
		string code, name;
		float price;
		int stock;
		cout << "Código del producto: ";
		cin >> code;
		cout << "Nombre del producto: ";
		cin >> name;
		cout << "Precio del producto: ";
		cin >> price;
		cout << "Stock del producto: ";
		cin >> stock;
		ingresar_datos(lista[i], code, name, price, stock);
		cout<<"  <-------------------->  "<<endl;
	}
	cout<<"  <-------------------->  "<<endl;
	for (int i = 0; i < moun; i++) {
		imprimir(lista[i]);
	}
	
	menu(lista, moun);
	delete[] lista;
	return 0;
}
