//Algoritmos para el manejo de memoria

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void primerAjuste(int p[], int po[], int m[], int n, int j);
void mejorAjuste(int y, int n, int z, int m[], int temp1, int temp, int po[], int flag, int k, int p[],int i, int j);
void peorAjuste(int y, int n, int z, int m[], int temp1, int temp, int po[], int flag, int k, int p[],int i, int j);

int main(){
	int c, j, k, n, l, m[10], p[10], po[20], flag, z, y, temp, temp1;//Declaracion de variables
	
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
			primerAjuste(p,po,m,n,j);//Funcion Primer Ajuste
    	case 2:
        	mejorAjuste(y,n,z,m,temp1,temp,po,flag,k,p,i,j);//Funcion Mejor Ajuste
        case 3:
        	peorAjuste(y,n,z,m,temp1,temp,po,flag,k,p,i,j);//Funcion Peor Ajuste
    }

    return 0;
}

void primerAjuste(int p[], int po[], int m[], int n, int j){
    int flag, i, k;
	
	for(i = 1; i <= j; i++){
        flag = 1;
        for(k = 1; k <= n; k++){
         	if(p[i ]<= m[k]){
			    cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
             	m[k] = m[k] - p[i];
             	break;           
          	}
          	else{
          		flag++;  
          	}
      	}   
      	if(flag > n){
      		cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";       
      	}           
    }
}

void mejorAjuste(int y, int n, int z, int m[], int temp1, int temp, int po[], int flag, int k, int p[],int i, int j){
	for(y=1;y<=n;y++){
	    for(z=y;z<=n;z++){
        	if(m[y]>m[z]){
        		temp=m[y];
          		m[y]=m[z];
          		m[z]=temp;
          		temp1=po[y]; 
          		po[y]=po[z];
          		po[z]=temp1;            
          	}                 
        }             
    }
    
    for(i=1;i<=j;i++){
    	flag=1;
        for(k=1;k<=n;k++){
          	if(p[i]<=m[k]){
             	cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
             	m[k]=m[k]-p[i];
             	break;           
          	}
          	else{
            flag++;  
          	}
      	}   
      	if(flag>n){
        	cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";       
      	}           
    }
}

void peorAjuste(int y, int n, int z, int m[], int temp1, int temp, int po[], int flag, int k, int p[],int i, int j){
	for(y=1;y<=n;y++){
        for(z=y;z<=n;z++){
          	if(m[y]<m[z]){
          		temp=m[y];
          		m[y]=m[z];
          		m[z]=temp;
          		temp1=po[y]; 
          		po[y]=po[z];
          		po[z]=temp1;            
          	}                 
        }             
    }
    for(i=1;i<=j;i++){
        flag=1;
        for(k=1;k<=n;k++){
          	if(p[i]<=m[k]){
             	cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
             	m[k]=m[k]-p[i];
             	break;           
          	}
          	else{
            	flag++;  
          	}
      	}   
      	if(flag>n){
        	cout<<"\nprocess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";       
      	}           
    }
}
