#ifndef PERSONA_H
#define PERSONA_H



#include<iomanip> 
#include<vector>
#include<bits/stdc++.h>


#include <iostream>
using namespace std;

#include <string>
using std::string;

class Persona
{
	public:
		Persona();
		
		Persona(string nombre,string apellido,string contrasena,int llave);
		
		string getNombre();
		string getApellido();
		string getContrasena();
		vector<string> getMensajes();
		
		
		~Persona();
	private:
		int llave;
		string nombre;
		string apellido;
		string contrasena;
		vector <string> lista_mensajes;
		
		
		
};

#endif
