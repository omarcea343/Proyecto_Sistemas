#include <iostream>
#include <cstdlib>
#include <ctime>
#define CAP 30


struct Bloques{
	char control;
	int id;
	int tam;
	int quantum;
};

struct Control{
	int memoria;
	int procactivos;
};

using namespace std;
void iniciar(Bloques [],Control);
void imprimir(Bloques []);
bool cond(Bloques [],Control,int);
int primerajuste(Bloques[],int);
void recorrer(Bloques[],int,int);
void cargar(Bloques[],Control,int,int,int&,int);
void condensar(Bloques []);
Control pasoquantum(Bloques [],Control,int&);

int main(){
	srand(time(NULL));
	Bloques mP[CAP];
	Control ctrl;
	ctrl.procactivos=0;
	int tammaxproc,quantummaxproc,tamproc=0,simulacion=100,ajuste;
	int auxposi=0,auxid=0;
	int auxquantumproc=1;//es en la posicion de proceso que se quedo en ejecucion
	cout<<"Dame tamanio de la memoria principal:"<<endl;
	cin>>ctrl.memoria;
	iniciar(mP,ctrl);
	cout<<endl<<"Dame el tamanio maximo por proceso:"<<endl;
	cin>>tammaxproc;
	cout<<endl<<"Dame el quantum maximo por proceso:"<<endl;
	cin>>quantummaxproc;
	cout<<endl<<"1.Primer ajuste"<<endl;
	cout<<"2.Mejor ajuste"<<endl;
	cout<<"3.Peor ajuste";
	cout<<endl<<"Dame el ajuste por el cual quieres hacer la simulacion:"<<endl;
	cin>>ajuste;
//	cout<<endl<<"Dame tiempo de simulacion: "<<endl;
	//cin>>simulacion;
	system("cls");
	cout<<"["<<mP[0].id<<","<<mP[0].tam<<","<<mP[0].quantum<<"]";
	for(int i=0;i<100;i++){//while(simulacion>0){
		if(tamproc==0){
			tamproc=1+rand()%(tammaxproc-1+1);
		}
		
		//getchar();
		cout<<endl;
		//imprimir(mP);
		if(ctrl.memoria>=tamproc&&cond(mP,ctrl,tamproc)){
			switch (ajuste){
				case 1: 
						auxposi=primerajuste(mP,tamproc);
						recorrer(mP,tamproc,auxposi);
						cargar(mP,ctrl,tamproc,auxposi,auxid,quantummaxproc);
						//simulacion--;
						ctrl.memoria-=tamproc;
						cout<<endl<<"Entra proceso["<<mP[auxposi].id<<","<<mP[auxposi].tam<<","<<mP[auxposi].quantum<<"]"<<endl;
						tamproc=0;
						ctrl.procactivos++;
						break;
				case 2:
						break;
				case 3:
						break;
			}
		}else{
			//	simulacion--;
			cout<<endl<<"No hay espacio suficiente para el proceso: "<<tamproc<<endl;
		}
		imprimir(mP);
		ctrl=pasoquantum(mP,ctrl,auxquantumproc);
		//simulacion--;
		imprimir(mP);
		condensar(mP);
		fflush(stdin);
	//	getchar();
	}
	
	return 0;
}

int primerajuste(Bloques mP[CAP],int tamproc){
	int auxposi=0;
	for(int i=0;i<CAP;i++){
		if(mP[i].control=='o'){
			continue;
		}
		if(mP[i].control=='h'&&mP[i].tam>=tamproc){
			auxposi=i;
			break;
		}
		if(mP[i].control=='l'){
			auxposi=i;
			break;
		}
	}
	return auxposi;
}

void cargar(Bloques mP[CAP],Control ctrl,int tamproc,int auxposi,int &auxid,int quantummaxproc){
	mP[auxposi].tam=tamproc;
	auxid++;
	mP[auxposi].id=auxid;
	mP[auxposi].quantum=1+rand()%(quantummaxproc-1+1);
	mP[auxposi].control='o';
	
}

Control pasoquantum(Bloques mP[CAP],Control ctrl,int &auxquantumproc){
	if(auxquantumproc>=ctrl.procactivos){
		auxquantumproc=1;
	}
	int cont=0,i,aux;
	for(i=0;i<CAP;i++){
		if(mP[i].control=='o'){
			cont++;
		}
		if(cont==auxquantumproc){
			aux=i;
			break;
		}
	}
	cout<<endl<<"Ejecutando "<<auxquantumproc<<"--"<<ctrl.procactivos<<"["<<mP[aux].id<<","<<mP[aux].tam<<","<<mP[aux].quantum<<"]"<<endl;
	mP[aux].quantum--;
	auxquantumproc++;
	if(mP[aux].quantum==0&&mP[aux].control=='o'){
		ctrl.memoria+=mP[aux].tam;
		mP[aux].control='h';
		mP[aux].id=0;
		ctrl.procactivos--;
	}
	return ctrl;
}
void condensar(Bloques mP[CAP]){
	//int band=0;
	for(int i=0;i<CAP;i++){
		if(mP[i].control!='o'&&mP[i+1].control!='o'){
			//band=1;
			mP[i].tam+=mP[i+1].tam;
			mP[i+1].tam=0;
			mP[i+1].control='l';
		}
	}
	/*if(band==1){
		simulacion--;
	}*/
}

void recorrer(Bloques mP[CAP],int tamproc,int auxposi){
	int i=0;
	for(i=CAP-1;i>auxposi;i--){
		mP[i]=mP[i-1];
	}
	mP[auxposi+1].tam-=tamproc;
}

bool cond(Bloques mP[CAP],Control ctrl,int tamproc){
	int acum=0;
	for(int i=0;i<CAP;i++){
		if(mP[i].control=='o'){
			continue;
		}
		if(mP[i].control=='h'&&mP[i].tam>=tamproc){
			return true;
		}
		if(mP[i].control=='h'&&mP[i].tam<tamproc){
			acum+=mP[i].tam;
		}
	}
	if(acum==ctrl.memoria){
		return false;
	}else{
		return true;
	}
}

void imprimir(Bloques mP[CAP]){
	for(int i=0;i<CAP;i++){
		if((mP[i].control!='e'||mP[i].control=='l')&&mP[i].tam>0){
			cout<<"["<<mP[i].id<<","<<mP[i].tam<<","<<mP[i].quantum<<"]";
		}
	}
}

void iniciar(Bloques mP[CAP],Control ctrl){
	mP[0].id=0;
	mP[0].tam=ctrl.memoria;
	mP[0].quantum=0;
	mP[0].control='h';
	for(int i=1;i<CAP;i++){
		mP[i].id=0;
		mP[i].tam=0;
		mP[i].quantum=0;
		mP[i].control='l';
	}
}
