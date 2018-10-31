// C++ implementation mejor ajuste 
#include<cstring>
#include <iostream>
using namespace std; 

// Function to allocate memory to blocks as per Best fit 
// algorithm 
void bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
	// Stores block id of the block allocated to a 
	// process 
	int allocation[n]; 

	// inicializa los bloques de memoria como libres
	memset(allocation, -1, sizeof(allocation)); 

	// Busca cual bloque esta disponible para usar  y de acuerdo a su tamaño decide si lo usa o no
	for (int i=0; i<n; i++) 
	{ 
		// Busca el mejor bloque en cual guardar que es en el que sobre menos espacio 
		int bestIdx = -1; 
		for (int j=0; j<m; j++) 
		{ 
			if (blockSize[j] >= processSize[i]) 
			{ 
				if (bestIdx == -1) 
					bestIdx = j; 
				else if (blockSize[bestIdx] > blockSize[j]) 
					bestIdx = j; 
			} 
		} 

		// Aqui guarda el proceso en el bloque 
		if (bestIdx != -1) 
		{ 
			// Guarda el proceso p[i] en el bloque en posicion j  
			allocation[i] = bestIdx; 

			// Quita  los espacios de memoria ya utilizados 
			blockSize[bestIdx] -= processSize[i]; 
		} 
	} 

	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 


int main() 
{ 
	int blockSize[] = {100, 500, 200, 300, 600}; 
	int processSize[] = {212, 417, 112, 426}; 
	int m = sizeof(blockSize)/sizeof(blockSize[0]); 
	int n = sizeof(processSize)/sizeof(processSize[0]); 

	bestFit(blockSize, m, processSize, n); 

	return 0 ; 
} 
