#include "Persona.h"
#include <iostream>
using namespace std;


Persona::Persona(string nombre,string apellido,string contrasena,int llave){
	this->nombre = nombre;
	this->apellido = apellido;
	this->contrasena = contrasena;
	this->llave = llave;
}

string Persona::getNombre(){
	return (nombre);
}

string Persona::getApellido(){
	return (apellido);
}

string Persona::getContrasena(){
	return (contrasena);
}

vector <string> Persona::getMensajes(){
    return lista_mensajes;
}

Persona::Persona()
{
}

Persona::~Persona()
{
}
