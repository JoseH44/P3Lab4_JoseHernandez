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
		Persona* persManipulada = NULL;
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
				
				int subOption = 0;
				string nombre,contra;
				cout<<"#MENU LOG IN#"<<endl;
				cout<<"Ingrese su nombre:";
				cin>>nombre;
				cout<<endl<<"Ingrese su contrasena:";
				cin>>contra;
				
				
				bool match = false;
				for(int i = 0;i < lista_personas.size();i++){
					if(nombre == lista_personas[i]->getNombre() && contra == lista_personas[i]->getContrasena()){
						match = true;
						persManipulada = lista_personas[i];
						break;
					}
				}
				
				if(match){
					cout<<endl<<"BIENVENIDO(A)------>"<<nombre<<endl;
					while(subOption != 4){
						cout<<"1)Enviar Mensaje"<<endl<<"2)Ver Mensajes"<<endl<<"3)Ver mi llave"<<endl<<"4)Salir"<<endl<<"Ingrese una opcion:";
						cin>>subOption ;
						switch(subOption){//switch con las opciones del menu dentro del log-in
							case 1:{
								cout<<endl<<"-------ENVIAR MENSAJE------"<<endl;
								cout<<"    Lista de Personas"<<endl;
								for(int i = 0;i < lista_personas.size();i++){
									
									cout<<i<<"."<<lista_personas[i]->getNombre()<<endl;
								}
								int seleccion;
								cout<<"Escoja el Numero de la Persona a quien le mandara un mensaje:";
								cin>>seleccion;
								break;
							}
							case 2:{
								cout<<endl<<"-------VER MENSAJES------"<<endl;
								break;
							}
							case 3:{
								cout<<endl<<"-------VER MI LLAVE------"<<endl;
								cout<<"Mi llave:"<<persManipulada->getLlave()<<endl;
								break;
							}
							case 4:{
								cout<<endl<<"Ha salido de su perfil"<<endl;
								
								break;
							}
						}
					}
					
				}else{
					cout<<endl<<"Nombre o Contrasena Invalidas"<<endl;
				}
				
				
				break;
			}
			case 3:{
				delete pers;
				delete persManipulada;
				cout<<endl<<"Vuelva Pronto";
				break;
			}
		}
	}
	
	return 0;
}
