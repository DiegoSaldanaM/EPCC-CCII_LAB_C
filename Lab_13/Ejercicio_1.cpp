#include <iostream>
using namespace std;

struct fecha{
	int dia{};
	int mes{};
	int anho{};
};

struct persona{
	string nombre{};
	string apellido{};
	fecha nacimiento{};
};

void imprimir_persona(const persona&);
void imprimir_fecha(const fecha&);
bool mes_cumple(const fecha&, const fecha&);

int main()
{
	int tam{}, auxn{};
	string aux{};
	cout<<"Ingrese el número de compañeros: "; cin >> tam;
	persona* comp = new persona[tam];

	for (int i = 0; i < tam; i++)
	{
		cout << "Ingrese el nombre de la persona " << i + 1 << ": "; cin >> aux;
		comp[i].nombre = aux;
		cout << "Ingrese el apellido de la persona " << i + 1 << ": "; cin >> aux;
		comp[i].apellido = aux;
		cout << "Ingrese el dia de nacimiento de la persona " << i + 1 << ": "; cin >> auxn;
		comp[i].nacimiento.dia = auxn;
		cout << "Ingrese el mes de nacimiento de la persona " << i + 1 << ": "; cin >> auxn;
		comp[i].nacimiento.mes = auxn;
		cout << "Ingrese el año de nacimiento de la persona " << i + 1 << ": "; cin >> auxn;
		comp[i].nacimiento.anho = auxn;
	}

	const fecha actual = { 27,06,2022 };
	bool cumple = false;

	cout << "Cumplen años: " << endl;
	for (int i = 0; i < tam; i++){
		if (mes_cumple(comp[i].nacimiento, actual)){
			imprimir_persona(comp[i]);
			cumple = true;
		}		
	}
	if (!cumple){
		cout << "Nadie cumple años." << endl;
	}

	delete[] comp;
}

void imprimir_persona(const persona& p1){
	cout << "El nombre de la persona es: " << p1.nombre << " " << p1.apellido << " " << "La fecha de nacimiento es: "; imprimir_fecha(p1.nacimiento);
}

void imprimir_fecha(const fecha& f1){
	cout << f1.dia << "/" << f1.mes << "/" << f1.anho << endl;
}

bool mes_cumple(const fecha& f1, const fecha& f2){
	if(f1.mes == f2.mes){
        return true;
    }
	return false;
}
