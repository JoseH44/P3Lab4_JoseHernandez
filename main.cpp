#include <iostream>
using namespace std;

#include "Persona.h"
using std::vector;


#include <string>
using std::string;

#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int option = 0;
	cout<<"------ENCRIPTED MESSENGER-----   "<<endl<<endl;
	while(option != 3){
		
		cout<<"1)Registrarse"<<endl<<"2)Ingresar"<<endl<<"3)Salir"<<endl<<"Ingrese una opcion:";
		cin>>option;
		switch(option){
			case 1:{
				break;
			}
			case 2:{
				
				break;
			}
			case 3:{
				cout<<endl<<"Vuelva Pronto";
				break;
			}
		}
	}
	
	return 0;
}
