#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	int c, i, j, k, n, l, m[10], p[10], po[20], flag, z, y, temp, temp1;//Declaracion de variables
	
	srand(time(NULL));//Numeros aleatorios
	
	n = rand()%10;//Genera bloques de memoria aleatorios
	
    //Ciclo para generar el tamaño de memoria para todos los bloques generados
    for(i = 1; i <= n; i++){
        m[i] = rand()%1000;//Genera el tamaño de memoria para un bloque generado 
        po[i]=i;       
    }

    j = rand()%10;//Genera el numero de procesos a ingresar a la memoria
    
	//Ciclo para generar el tamaño de memoria para todos los procesos generados
    for(i = 1; i <= j; i++){
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
      		break;
    	case 2:
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
            break;
        case 3:
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
            break;
    }  

    return 0;
}
