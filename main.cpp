#include <iostream>
using namespace std;

#include "Persona.h"
#include<vector>



#include <string>
using std::string;

#include <stdlib.h>
#include <time.h>

vector<Persona*> lista_personas;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int option = 0;
	cout<<"------ENCRIPTED MESSENGER-----   "<<endl<<endl;
	while(option != 3){
		
		cout<<"1)Registrarse"<<endl<<"2)Ingresar"<<endl<<"3)Salir"<<endl<<"Ingrese una opcion:";
		cin>>option;
		
		Persona* pers = NULL;
		switch(option){
			case 1:{
				string nombre,apellido,contrasena;
				cout<<endl<<"#MENU REGISTRO#"<<endl;
				cout<<"--Ingrese su nombre:";
				cin>>nombre;
				cout<<endl<<"--Ingrese su apellido:";
				cin>>apellido;
				cout<<endl<<"--Ingrese la contrasena:";
				cin>>contrasena;
				cout<<endl;
				
				int num_random;//numero random de la llave
				srand(time(NULL));
				
				num_random = 1 + rand()% (16-1);
				int llave = num_random;
				
				
				pers = new Persona(nombre,apellido,contrasena,llave);
				lista_personas.push_back(pers);
				
				break;
			}
			case 2:{
				string nombre,contra;
				cout<<"#MENU LOG IN#"<<endl;
				cout<<"Ingrese su nombre:";
				cin>>nombre;
				cout<<endl<<"Ingrese su contrasena:";
				cin>>contra;
				
				break;
			}
			case 3:{
				delete pers;
				cout<<endl<<"Vuelva Pronto";
				break;
			}
		}
	}
	
	return 0;
}
