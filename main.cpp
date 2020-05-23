#include <iostream>
using namespace std;

#include "Persona.h"
#include<vector>

#include <sstream>



#include <string>
using std::string;

#include <stdlib.h>
#include <time.h>

vector<Persona*> lista_personas;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string encriptacion(string,string,int,int);


int main(int argc, char** argv) {
	
	int option = 0;
	/*string message = "pepeelgallo";
	char caracter_pos_1 = message[1];
	int valor_ascci = caracter_pos_1;//pasar de caracter a ascci
	cout<<caracter_pos_1<<endl;
	cout<<valor_ascci<<endl;
	char caracter = (char) valor_ascci;//pasar de ascci a caracter
	cout<<caracter<<endl;*/
	
	string s = "gato+perro";
	string delimeter = "+";
	string token = s.substr(0,s.find(delimeter));
	cout<<token;
	
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
					int key;
					cout<<endl<<"BIENVENIDO(A)------>"<<nombre<<endl;
					while(subOption != 4){
						cout<<"1)Enviar Mensaje"<<endl<<"2)Ver Mensajes"<<endl<<"3)Ver mi llave"<<endl<<"4)Salir"<<endl<<"Ingrese una opcion:";
						cin>>subOption ;
						switch(subOption){//switch con las opciones del menu dentro del log-in
							case 1:{
								string mensaje = "";
								string mensaje_enviar;
								cout<<endl<<"-------ENVIAR MENSAJE------"<<endl;
								cout<<"    Lista de Personas"<<endl;
								for(int i = 0;i < lista_personas.size();i++){
									
									cout<<i<<"."<<lista_personas[i]->getNombre()<<endl;
								}
								int seleccion;
								
								cout<<"Escoja el Numero de la Persona a quien le mandara un mensaje:";
								cin>>seleccion;
								while(seleccion< 0 || seleccion > lista_personas.size()){
									cout<<endl<<"El numero ingresado debe ser mayor que 0 y menor que el numero de personas"<<endl;
									cout<<"Escoja el Numero de la Persona a quien le mandara un mensaje:";
									cin>>seleccion;
								}
								cout<<endl<<"Ingrese el Mensaje:";
								cin>>mensaje;
								key = lista_personas[seleccion]->getLlave();
								
								mensaje_enviar = encriptacion(mensaje,persManipulada->getNombre(),key,-100);
								lista_personas[seleccion]->getMensajes().push_back(mensaje_enviar);
								
								break;
							}
							case 2:{
								int pos_mensaje;
								string mensajeDes = "";
								cout<<endl<<"-------VER MENSAJES------"<<endl;
								for(int i = 0;i<persManipulada->getMensajes().size();i++){
									cout<<persManipulada->getMensajes()[i]<<endl;
								}
								
								cout<<endl<<"Ingrese el numero de mensaje que desea ver:";
								cin>>pos_mensaje;
								while(pos_mensaje < 0 || pos_mensaje>persManipulada->getMensajes().size()){
									cout<<endl<<"El numero debe ser mayor que 0 y debe ser un numero de los que estan en la lista"<<endl;
									cout<<"Ingrese el numero de mensaje que desea ver:";
									cin>>pos_mensaje;
								}
								
								mensajeDes = persManipulada->getMensajes()[pos_mensaje];
								
								string subcadena = mensajeDes;
								string delimeter = "---->";
								string token = subcadena.substr(0,s.find(delimeter));
								cout<<token;
								
								
								string mensajeOriginal = encriptacion(token,"",persManipulada->getLlave(),100);
								
								cout<<endl<<"El mensaje es: "<<mensajeOriginal<<endl;
								
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
				cout<<endl<<"Vuelva Pronto :)";
				break;
			}
		}
	}
	
	return 0;
}//fin del main


string encriptacion(string mensaje,string emisor,int llave,int estado){
	string salida = "";
	int cont = 0;
	int pos = 0;
	int cont_intercambio = 0;
	int state = estado;
	while(cont<llave){//numero de iteraciones
		for(int i=0;i<mensaje.size()/llave;i++){//numero de grupos
			for(int j = 0;j<llave;j++){//numero de llave
				if(state == -100){
				char caracter_pos_1 = mensaje[pos];//agarra el caracter en la posicion pos
				int valor_ascci = caracter_pos_1;//pasa el caracter a numero en la tabla ascci
				valor_ascci += llave;//le suma el valor de la llave al valor de la tabla ascci
				char caracter = (char) valor_ascci;//pasa el numero a caracter
				salida += caracter;
				pos++;
				
				}
				if(state == 100){
					
					char caracter_pos_1 = mensaje[pos];//agarra el caracter en la posicion pos
					int valor_ascci = caracter_pos_1;//pasa el caracter a numero en la tabla ascci
					valor_ascci -= llave;//le resta el valor de la llave al valor de la tabla ascci
					char caracter = (char) valor_ascci;//pasa el numero a caracter
					salida += caracter;
					pos++;
				
				}
				
			}//fin del for interno
			state *= (-1);//cambia el estado
		}
	}//fin del while
	salida += "---->";
	salida += emisor;
	return salida;
}
