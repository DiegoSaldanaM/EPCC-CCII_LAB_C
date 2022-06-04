#include <iostream>
using namespace std;

template <class T>

T num_menor(T array[5]){
	T min = array[0];
	for(int i=0; i<5; i++){
		if(array[i] <= min){
			min=array[i];
		}
	}
	return min;
}

template <class T>

T num_mayor(T array[5]){
	T max= array[0];
	for(int i=0; i<5; i++){
		if(array[i]>=max){
			max=array[i];
		}
	}
	return max;
}

int main(){
	int array_entero[5] = { 10,7,2, 8, 6 };
	float array_float [5] = {12.1, 8.7, 5.6, 8.4, 1.2};
	cout<<"Para el array de enteros: "<<endl;
	cout << "El menor número del array de enteros es: "<<num_menor<int>(array_entero)<<endl;
	cout << "El mayor número del array de enteros es: "<<num_mayor<int>(array_entero)<<endl;
	cout<<"Para el array de flotantes: "<<endl;
	cout << "El menor número del array de flotantes es: "<<num_menor<float>(array_float)<<endl;
	cout << "El mayor número del array de flotantes es: "<<num_mayor<float>(array_float)<<endl;
	return 0;
}
