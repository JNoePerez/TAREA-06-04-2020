
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;
void venta();
void mp();
void reporte();
void eliminar();
void modificar();
void mp(){
	int resp;

	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Ventas "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Eliminar Registro"<<"\n";
		cout<<" 4 - Modificar Registro"<<"\n";
		cout<<" 5 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			venta();			
		}
		else if (resp==2){		
			system("CLS");
			reporte();
		}
		else if (resp==3){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==4){
			system("CLS");
			modificar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}

void venta(){
	//declaracion de variables
	int dia, mod, cant;
	float inota;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"*** VENTA DE CUADERNOS ***\n\n";
	cout<<"*MODELO#1- Q10.00 ***"<<endl;
	cout<<"*MODELO#2- Q15.00 ***"<<endl;
	cout<<"*MODELO#3- Q18.50 ***"<<endl;
	cout<<"*MODELO#4- Q25.00 ***\n\n"<<endl;
	
	cout<<"Ingrese Dia: ";
	cin>>dia;
	cout<<"Ingrese Modelo: ";
	cin>>mod;
	cout<<"Ingrese cantidad: ";
	cin>>cant;
	fflush(stdin);	
	
	//Insercion de datos a un archivo
	try {
		db.open("cuadernos.txt",ios::app);
		db<<dia<<"\t"<<mod<<"\t"<<cant<<endl;   //"|"
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
}
void reporte(){
	//declaracion de variables
	int rdia,rmod,rcant;
	
	ifstream db;	
	try{
		db.open("cuadernos.txt",ios::in);	

		cout<<"Datos del archivo:"<<endl;
		cout<<" DIA|"<<"      MODELO      |"<<"CANTIDAD|"<<endl;		
		while (db>>rdia>>rmod>>rcant){

			cout<<setw(3)<<rdia<<"|"<<setw(18)<<rmod<<"|"<<setw(4)<<rcant<<"|"<<endl;
			
		}	
		db.close();	
		
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}

void eliminar(){
	ifstream txt; //archivo anterior
	ofstream txt_n; //archivo nuevo
	int aux,edia,emod,ecant,flag;
	string onombre;
	remove("Temporal.txt");
	
	txt.open("cuadernos.txt",ios::in);
	txt_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese DIA que desea borrar: "<<endl;
	cin>>aux;
	
	while (txt>>edia>>emod>>ecant){
		if(aux==edia){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=edia)
			txt_n<<edia<<"\t"<<emod<<"\t"<<ecant<<endl;

	}
	txt.close();
	txt_n.close();
	
	if (flag==1){
		remove("cuadernos.txt");
		rename("Temporal.txt","cuadernos.txt");
	}	
	system("Pause");
}

void modificar(){
	ifstream txt; //archivo anterior
	ofstream txt_n; //archivo nuevo
	int aux,mdia,mmod,flag,mod,mcant;
	char respuesta;
	remove("Temporal.txt");
	
	txt.open("cuadernos.txt",ios::in);
	txt_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese Dia al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese Modelo a modificar: "<<endl;
		cin>>mmod;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (txt>>mdia>>mmod>>mcant){
		if(aux==mdia){
			txt_n<<mdia<<"\t"<<mmod<<"\t"<<mod<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=mdia)
			txt_n<<mdia<<"\t"<<mmod<<"\t"<<mcant<<endl;					
	}
	txt.close();
	txt_n.close();
	
	if (flag==1){
		remove("cuadernos.txt");
		rename("Temporal.txt","cuadernos.txt");
	}	
	system("Pause");
}
