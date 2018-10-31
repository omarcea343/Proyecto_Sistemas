//Metodo de Asignacion de memoria "Primer Ajuste"  //
//Hecho por: J. Refugio Muñoz Serna  //

#include <iostream>

using namespace std;

struct proceso {
	int ID;
	int tam;
	int cont ;
};

void colocacion ();
void remplazo ();
void mostrar (int tam, struct proceso);


int main (){
	proceso dato;
	
	int tam;
	cout<<"Tamanio de la memoria (cantidad de espacios): "<<endl;
	cin>>tam;
	
	mostrar(tam, dato);
	
	return 0;
}

void mostrar(int tam, struct proceso ){
	
	proceso dato;
	
	for(int i=0; i<tam; i++){	
	cout<<"["; cout<<", ",dato.tam; cout<<", ]", dato.cont;  //[ID, Tamaño, Cuanto];
	}
}
void colocacion (){
	
	
}

void remplazo(){
	
	
}
