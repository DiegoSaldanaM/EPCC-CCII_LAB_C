#include <iostream>
using namespace std;

template <class Temp>

void operaciones(Temp num1, Temp num2){
	cout<<"La suma es: "<<num1+num2<<endl;
	cout<<"La resta es: "<<num1-num2<<endl;
	cout<<"La multiplicación es: "<<num1*num2<<endl;
	cout<<"La división es: "<<num1/num2<<endl;
}

int main(){
	int opc;
	cout<<"TIPO DE LOS DATOS"<<endl;
	cout<<"1. Enteros"<<endl;
	cout<<"2. Flotantes"<<endl;
	cout<<"Ingrese el número que corresponde al tipo de los datos a ingresar: ";
	cin>>opc;

	if(opc==1){
		int a,b;
		cout<<"Ingrese el primer número entero: ";
		cin>>a;
		cout<<"Ingrese el segundo número entero: ";
		cin>>b;
		operaciones<int>(a,b);
	}
	else if(opc==2){
		float a,b;
		cout<<"Ingrese el primer número flotante: ";
		cin>>a;
		cout<<"Ingrese el segundo número flotante: ";
		cin>>b;
		operaciones<float>(a,b);
	}
	else{
		cout<<"Valor no válido.";
	}
	return 0;
}
