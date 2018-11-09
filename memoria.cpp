//Algoritmos para el manejo de memoria

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int c, j, n, m[10], p[10], po[20];//Declaracion de variables
	
	srand(time(NULL));//Numeros aleatorios
	
	n = rand()%10;//Genera bloques de memoria aleatorios
	
	//Ciclo para generar el tamaño de memoria para todos los bloques generados
	for(int i = 1; i <= n; i++){
		m[i] = rand()%1000;//Genera el tamaño de memoria para un bloque generado 
		po[i]=i;       
	}
	
	j = rand()%10;//Genera el numero de procesos a ingresar a la memoria
	
	//Ciclo para generar el tamaño de memoria para todos los procesos generados
	for(int i = 1; i <= j; i++){
		p[i] = rand()%1000;//Genera el tamaño de un proceso                
	}
	
	//Menu
	cout<<"Seleccion de Algoritmo para Manejo de Memoria"<<endl;
	cout<<endl<<"\t1. Primer Ajuste"<<endl;
	cout<<"\t2. Mejor Ajuste"<<endl;
	cout<<"\t3. Peor Ajuste"<<endl;
	
	//Seleccion
	cout<<endl<<"Ingresa Seleccion: ";
	cin>>c;
	
	//Manejo de algoritmo seleccionado
	switch(c){
	case 1:
		int flag;
		cout << endl<<"[ID, TAMANIO, CUANTO]"<<endl;
		for(int i = 1; i <= j; i++){
			flag = 1;
			for(int k = 1; k <= n; k++){
				if(p[i] <= m[k]){
					cout<<"["<<i<<", "<<p[i]<<", "<<po[k]<<"]"<<endl;
					m[k] = m[k] - p[i];
					break;           
				}
				else{
					flag++;  
				}
			}   
			if(flag > n){
				cout<<"El proceso: "<<i<<" cuyo tamanio de memoria es de "<<p[i]<<" no puede ser asignado."<<endl;       
			}           
		}
		break;
	case 2:
		int temp, temp1;
		cout << endl<<"[ID, TAMANIO, CUANTO]"<<endl;
		for(int  y = 1; y <= n; y++){
			for(int z = y; z <= n; z++){
				if(m[y] > m[z]){
					temp = m[y];
					m[y] = m[z];
					m[z] = temp;
					temp1 = po[y]; 
					po[y] = po[z];
					po[z] = temp1;            
				}                 
			}             
		}
		
		for(int i = 1; i <= j; i++){
			flag = 1;
			for(int k = 1; k <= n; k++){
				if(p[i] <= m[k]){
					cout<<"["<<i<<", "<<p[i]<<", "<<po[k]<<"]"<<endl;
					m[k] = m[k] - p[i];
					break;           
				}
				else{
					flag++;  
				}
			}   
			if(flag > n){
				cout<<"El proceso: "<<i<<" cuyo tamanio de memoria es de "<<p[i]<<" no puede ser asignado."<<endl;       
			}           
		}
		break;
	case 3:
		cout << endl<<"[ID, TAMANIO, CUANTO]"<<endl;
		for(int y = 1; y <= n; y++){
			for(int z = y; z <= n; z++){
				if(m[y] < m[z]){
					temp = m[y];
					m[y] = m[z];
					m[z] = temp;
					temp1 = po[y]; 
					po[y] = po[z];
					po[z] = temp1;            
				}                 
			}             
		}
		
		for(int  i = 1; i <= j; i++){
			flag = 1;
			for(int k = 1; k <= n; k++){
				if(p[i] <= m[k]){
					cout<<"["<<i<<", "<<p[i]<<", "<<po[k]<<"]"<<endl;
					m[k] = m[k] - p[i];
					break;           
				}
				else{
					flag++;  
				}
			}   
			if(flag > n){
				cout<<"El proceso: "<<i<<" cuyo tamanio de memoria es de "<<p[i]<<" no puede ser asignado."<<endl;       
			}           
		}
		break;
	}
	
	return 0;
}
