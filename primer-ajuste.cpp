//Implementation Mejor Ajuste en C++

#include <iostream>
#include<cstring>

using namespace std; 

//Funcion que asigna memoria a los bloques por metodo del Mejor Ajuste
void mejor_ajuste(int tamblock[], int m, int proceso[], int n){ 
	//Guarda el id del bloque al que se asigno el proceso
	int allocation[n]; 
	//inicializa los bloques de memoria como libres
	memset(allocation, -1, sizeof(allocation)); 
	// Busca cual bloque esta disponible para usar  y de acuerdo a su tamaño decide si lo usa o no
	for (int i=0; i<n; i++){
		// Busca el mejor bloque en cual guardar que es en el que sobre menos espacio 
		int Id = -1; 
		for (int j=0; j<m; j++){ 
			if (tamblock[j] >= proceso[i]){ 
				if (Id == -1) 
					Id = j; 
				else if (tamblock[Id] > tamblock[j]) 
					Id = j; 
			} 
		} 

		// Aqui guarda el proceso en el bloque 
		if (Id != -1){ 
			// Guarda el proceso p[i] en el bloque en posicion j  
			allocation[i] = Id; 

			// Quita  los espacios de memoria ya utilizados 
			tamblock[Id] -= proceso[i]; 
		} 
	} 

	cout << "\n [ID, TAMANO, CUANTO]\n"; 
	for (int i = 0; i < n; i++){ 
		cout << " " << i+1 << "\t\t" << proceso[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "No colocado"; 
		cout << endl; 
	} 
} 

void procesando(int tamblock[], int m, int proceso[], int n){

		for (int i = 0; i<n; ){
		}
	
}

int main(){
	
	int tamblock[] = {100, 500, 200, 300, 600};  //tamaño estatico de los bloques 
	int proceso[] = {212, 417, 112, 426};   //los procesos ya tienen asignados los tamaños 
	int m = sizeof(tamblock)/sizeof(tamblock[0]); 
	int n = sizeof(proceso)/sizeof(proceso[0]); 

	mejor_ajuste(tamblock, m, proceso, n); 

	return 0 ; 
} 
