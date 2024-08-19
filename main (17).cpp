#include <iostream>

using namespace std;

class Materia{
	private:
		int Clave;
		string Nombre;
		string ProfesorTit;
		string LibroTexto;
	protected:
	public:
		Materia(int C,string N,string P,string L):Clave(C),Nombre(N),ProfesorTit(P),LibroTexto(L){}
		void imprimir(){
			cout << "\nClave: "<< Clave<< "\n"<< "Nombre: "<< Nombre<< "\n"<< "Profesor: "<< ProfesorTit<< "\n"<< "Libro de texto: "<< LibroTexto<< "\n";   
		}
		void CambiaClave(int newclave){
			Clave = newclave;
			cout << "La clave ha sido cambiada exitosamente"; 
		}
		void CambiarProfe(string newprofe){
			ProfesorTit = newprofe;
			cout << "El maestro ha sido cambiado exitosamente";
		}
};

void menu(){
	cout << "//BIENVENIDO AL REGISTRO DE MATERIAS//\n\n";
	cout << "1. Cambiar la clave de la materia programacion \n2. Cambiar el nombre del maestro que imparte la materia BasesDatos \n3. Imprimir todos los datos de la materia BasesDatos \n4. Salir del programa\n\n";
	cout << "Ingresa el numero con la opcion deseada: ";
}

int main(){
	int opc,terminarPrograma = 0,newclave;
	string newprofe;
	Materia Programacion(5434,"Fernando","Juan Perez","Aprende a programar");
	Materia BasesDatos(2492,"Luis","Alexis Torres","Conceptos basicos para hacer una base de datos");
	while(terminarPrograma == 0){
		menu();
		cin >> opc;
		switch(opc){
			case 1: 
				cout << "\nIngresa la clave nueva para Programacion: ";
				cin >> newclave; 
				Programacion.CambiaClave(newclave);
				break;
			case 2:
				cout << "\nIngresa el nombre del nuevo maestro: ";
				cin >> newprofe;
				BasesDatos.CambiarProfe(newprofe);
				break;
			case 3:
				BasesDatos.imprimir();
				break;
			case 4:
				terminarPrograma = 1;
				cout << "Saliendo del programa..."; break;
			default: cout << "ingresa un numero valido"; break;
		}
	cout << "\n\n";
	}
	return 0;
}