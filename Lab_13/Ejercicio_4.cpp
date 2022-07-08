#include <iostream>
using namespace std;

struct empleado{
	string nombre{};
	char sexo{};
    int sueldo{};
};

int sueldo_men(empleado*&, int tam);
int sueldo_may(empleado*&, int tam);

int main(){
	const int tam = 3;
	empleado* emple = new empleado[tam];

	emple[0] = { "Diego",'M',2200 };
	emple[1] = { "Marco",'M',1800 };
	emple[2] = { "Luisa",'F',2500 };

	cout << "El menor sueldo es de: " << sueldo_men(emple, tam) << endl;
	cout << "El mayor sueldo es de: " << sueldo_may(emple, tam) << endl;

	delete[] emple;
}

int sueldo_may(empleado*& e1, int tam){
	int mayor = e1[0].sueldo;
	for (int i = 1; i < tam; i++){
		if (mayor < e1[i].sueldo){
            mayor = e1[i].sueldo;
        }		
	}
	return mayor;
}

int sueldo_men(empleado*& e1, int tam){
	int menor = e1[0].sueldo;
	for (int i = 1; i < tam; i++){
		if (menor > e1[i].sueldo){
            menor = e1[i].sueldo;
        }
	}
	return menor;
}