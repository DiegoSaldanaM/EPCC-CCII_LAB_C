#include <iostream>
#include <string>
using namespace std;

template <class Temp>

class correo{
public:
	correo(Temp x){
		cout<<x;
	}
};

int main(){
	char name;
	string surname;
	cout<<"Ingresar la primera letra del nombre: ";
	cin>>name;
	cout<<"Ingresar el apellido´: ";
	cin>>surname;
	correo<char> nombre(name);
	correo<string> apellido(surname);
	correo<string> correo("@unsa.edu.pe");
	return 0;
}
