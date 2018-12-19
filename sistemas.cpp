#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	int memPrin, maxPro, cuantoPro, cuantoSis, algoritmo, tiempo;
	
	srand(time(NULL));
	
	cout<<"Ingrese el tamanio de la memoria principal: ";
	cin>>memPrin;
	cout<<"Ingrese el tamanio maximo de memoria por proceso: ";
	cin>>maxPro;
	cout<<"Ingrese el cuanto maximo por proceso: ";
	cin>>cuantoPro;
	cout<<"Ingrese el cuanto del sistema: ";
	cin>>cuantoSis;
	cout<<"ingrese el tiempo maximo de ejecucion: ";
	cin>>tiempo;
	
	cout<<endl<<"Seleccion de Algoritmo para Manejo de Memoria"<<endl;
	cout<<endl<<"\t1. Primer Ajuste"<<endl;
	cout<<"\t2. Mejor Ajuste"<<endl;
	cout<<"\t3. Peor Ajuste"<<endl;
	cout<<endl<<"Seleccion: ";
	cin>>algoritmo;

	int memoria;
	
	for(int i = 0;i < 2; i++){
		memoria = 1;
	}
	
	switch(algoritmo){
	case 1:
		cout<<endl<<"Selecciono Primer Ajuste";
		break;
	case 2:
		cout<<endl<<"Selecciono Mejor Ajuste";
		break;
	case 3:
		cout<<endl<<"Selecciono Peor Ajuste";
		break;
	default:
		cout<<endl<<"No selecciono una opcion correcta";
		break;
	}
	
	return 0;
}

