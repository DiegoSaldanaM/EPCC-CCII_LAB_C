#include <iostream>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<>altura_rand(1.60, 1.90);
uniform_int_distribution<>edad_rand(10, 30);

struct jugdor{
	string nombre{};
	int edad{};
	double talla{};
};

int main(){
	const int tam = 5;
	jugdor* jug = new jugdor[tam];

	jug[0].nombre = "Luis";
	jug[1].nombre = "Juan";
	jug[2].nombre = "Carlos";
	jug[3].nombre = "Diego";
	jug[4].nombre = "Javier";

	for (int i = 0; i < tam; i++){
		jug[i].edad = edad_rand(gen);
		jug[i].talla = altura_rand(gen);
	}

	cout << "Los menores de 20 años y mas altos que 1.70 son: " << endl;
	bool ninguno = false;

	for (int i = 0; i < tam; i++){
		if (jug[i].talla > 1.70 && jug[i].edad < 20){
			cout << jug[i].nombre << " : " << jug[i].talla << " - " << jug[i].edad << endl;
			ninguno = true;
		}
	}

	if (ninguno == false){
        cout << "No hay ningún jugador." << endl;
    }

	delete[] jug;
}