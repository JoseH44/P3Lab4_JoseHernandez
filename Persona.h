#ifndef PERSONA_H
#define PERSONA_H
#include <vector>
using std::vector;


#include <string>
using std::string;

class Persona
{
	public:
		Persona();
		~Persona();
	protected:
		int llave;
		string nombre;
		string apellido;
		vector <string> lista;
		
};

#endif
