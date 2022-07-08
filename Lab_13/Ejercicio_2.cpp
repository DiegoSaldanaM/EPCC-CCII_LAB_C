#include <iostream>
using namespace std;

struct alumno{
	string nombre{};
	char grupo{};
	double nota_1{};
	double nota_2{};
	double nota_3{};
	double nota_final{};
};

bool aprobado(const alumno&);
void imprimir_alumno(const alumno&);
double nota(const alumno&);

int main(){
	int tam{};
	double auxa{};
	string aux;
	char auxb{};
	cout<<"Ingrese el número de compañeros: "; 
    cin>>tam;
	alumno* alum = new alumno[tam];

	for (int i = 0; i < tam; i++){
		cout << "Ingrese el nombre del alumno " << i + 1 << ": "; cin >> aux;
		alum[i].nombre = aux;
		cout << "Ingrese el grupo del alumno " << i + 1 << ": "; cin >> auxb;
		alum[i].grupo = auxb;
		cout << "Ingrese la nota 1 del alumno " << i + 1 << ": "; cin >> auxa;
		alum[i].nota_1 = auxa;
		cout << "Ingrese la nota 2 del alumno " << i + 1 << ": "; cin >> auxa;
		alum[i].nota_2 = auxa;
		cout << "Ingrese la nota 3 del alumno " << i + 1 << ": "; cin >> auxa;
		alum[i].nota_3 = auxa;
		cout << "Ingrese la nota del proyecto final del alumno " << i + 1 << ": "; cin >> auxa;
		alum[i].nota_final = auxa;
	}

	bool apro = false;

	cout<<"Los aprobados son: "<<endl;
	for (int i = 0; i < tam; i++){
		if (aprobado(alum[i])){
			imprimir_alumno(alum[i]);
			apro = true;
		}
	}

	if (apro == false){
        cout << "No hay aprobados." << endl;
    }
	delete[] alum;
}


bool aprobado(const alumno& a1){
	if ((a1.nota_1 * 0.15) + (a1.nota_2 * 0.20) + (a1.nota_3 * 0.25) + (a1.nota_final * 0.40) < 10.5){
        return false;
    }
	return true;
}

void imprimir_alumno(const alumno& a1){
	cout << "Nombre: " << a1.nombre <<endl<<"Nota 1: " << a1.nota_1 <<endl<<" Nota 2: " << a1.nota_2 <<endl<<" Nota 3: " << a1.nota_3 <<endl<<" Nota Proyecto: " << a1.nota_final << endl;
	cout << "Su promedio es: " << nota(a1) << endl;
}

double nota(const alumno& a1){
	return (a1.nota_1 * 0.15) + (a1.nota_2 * 0.20) + (a1.nota_3 * 0.25) + (a1.nota_final * 0.40);
}