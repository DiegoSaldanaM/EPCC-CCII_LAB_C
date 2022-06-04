#include <iostream>
using namespace std;

template <class T>

T ascendente(T *puntero, T ind_primer, T ind_ult){
	T aux;
	for(int i=0; i<5; i++){
		for(int j=0; j<4; j++){
			if(*(puntero+j)>*(puntero+j+1)){
				aux=*(puntero+j);
				*(puntero+j)=*(puntero+j+1);
				*(puntero+j+1)=aux;
			}
		}
	}
}

template <class T>

T descendente(T *puntero){
	for(int i=4; i>=0; i--){
		cout<<puntero[i]<<" ";
	}
	cout<<endl;
}

template <class T>

T imprimir(T *puntero){
	for (int i=0; i<5; i++){
		cout<<puntero[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int *enteros;
	enteros = new int[5];
	enteros[0]=5;
	enteros[1]=7;
	enteros[2]=2;
	enteros[3]=8;
	enteros[4]=6; 

	float *flotante;
	flotante = new float[5];
	flotante[0]=10.1;
	flotante[1]=8.4;
	flotante[2]=3.6;
	flotante[3]=4.4;
	flotante[4]=11.2;

	cout<<"Arreglo de enteros: "<<endl;
	cout<<"Arreglo de enteros de manera ascendente: "<<endl;
	ascendente(enteros,enteros[0],enteros[4]);
	imprimir(enteros);
	cout<<"Arreglo de enteros de manera descendente: "<<endl;
	descendente(enteros);

	cout<<"Arreglo de flotantes: "<<endl;
	cout<<"Arreglo de flotantes de manera ascendente: "<<endl;
	ascendente(flotante,flotante[0],flotante[4]);
	imprimir(flotante);
	cout<<"Arreglo de flotantes de manera descendente: "<<endl;
	descendente(flotante);

	return 0;
}
