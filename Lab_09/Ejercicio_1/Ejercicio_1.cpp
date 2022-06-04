#include <iostream>
using namespace std;

template <class Temp>

Temp retorno(Temp num1, Temp num2, Temp num3){
	Temp may, men;
	if(num1>num2 && num2>num3){
		may = num1;
		men = num3;
	}
	if(num1>num3 && num3>num2){
		may = num1;
		men = num2;
	}
	if(num2>num3 && num3>num1){
		may = num2;
		men = num1;
	}
	if(num2>num1 && num1>num3){
		may = num2;
		men = num3;
	}
	if(num3>num2 && num2>num1){
		may = num3;
		men = num1;
	}
	if(num3>num1 && num1>num2){
		may = num3;
		men = num2;
	}

	cout<<"El número mayor es: "<<may<<endl;
	cout<<"El número menor es: "<<men<<endl;
}

int main(){
	int ent1, ent2, ent3;
	float flo1, flo2, flo3;

	cout<<"Ingrese el primer valor entero: ";
	cin>>ent1;
	cout<<"Ingrese el segundo valor entero: ";
	cin>>ent2;
	cout<<"Ingrese el tercer valor entero: ";
	cin>>ent3;

	cout<<"Ingrese el primer valor flotante: ";
	cin>>flo1;
	cout<<"Ingrese el segundo valor flotante: ";
	cin>>flo2;
	cout<<"Ingrese el tercer valor flotante: ";
	cin>>flo3;

	cout<<"Valores enteros: "<<endl;
	retorno(ent1,ent2,ent3);
	cout<<"Valores flotantes: "<<endl;
	retorno(flo1,flo2,flo3);

	return 0;
}
