#include <iostream>
#include <string>

using namespace std;

// Definición de la clase Empleado
class Empleado {
private:
    int clave;
    string nombre;
    string domicilio;
    double sueldo;
    string reporta_a;

public:
    // Constructor
    Empleado(int c, string n, string d, double s, string r) 
        : clave(c), nombre(n), domicilio(d), sueldo(s), reporta_a(r) {}

    // Métodos para modificar los atributos
    void cambiarDomicilio(string nuevo_domicilio) {
        domicilio = nuevo_domicilio;
    }

    void actualizarSueldo(double porcentaje_incremento) {
        sueldo += sueldo * (porcentaje_incremento / 100.0);
    }

    void cambiarReportaA(string nuevo_jefe) {
        reporta_a = nuevo_jefe;
    }

    void imprimirDatos() const {
        cout << "Clave: " << clave << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reporta_a << endl;
    }

    int getClave() const {
        return clave;
    }
};

// Menú interactivo
int main() {
    // Declaración de objetos JefePlanta y JefePersonal
    Empleado JefePlanta(1, "Carlos Martinez", "Av. Central 123", 50000, "Director General");
    Empleado JefePersonal(2, "Ana Gomez", "Calle Mayor 456", 45000, "Director General");

    int opcion, clave;
    string nuevo_domicilio, nuevo_jefe;
    double porcentaje_incremento;

    do {
        cout << "\nMenú de opciones:\n";
        cout << "1. Cambiar domicilio de un empleado\n";
        cout << "2. Actualizar sueldo de un empleado\n";
        cout << "3. Imprimir datos de un empleado\n";
        cout << "4. Cambiar el nombre de la persona a quien reporta un empleado\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nuevo domicilio: ";
                cin.ignore();
                getline(cin, nuevo_domicilio);

                if (clave == JefePlanta.getClave()) {
                    JefePlanta.cambiarDomicilio(nuevo_domicilio);
                } else if (clave == JefePersonal.getClave()) {
                    JefePersonal.cambiarDomicilio(nuevo_domicilio);
                } else {
                    cout << "Clave de empleado no válida.\n";
                }
                break;

            case 2:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el porcentaje de incremento de sueldo: ";
                cin >> porcentaje_incremento;

                if (clave == JefePlanta.getClave()) {
                    JefePlanta.actualizarSueldo(porcentaje_incremento);
                } else if (clave == JefePersonal.getClave()) {
                    JefePersonal.actualizarSueldo(porcentaje_incremento);
                } else {
                    cout << "Clave de empleado no válida.\n";
                }
                break;

            case 3:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;

                if (clave == JefePlanta.getClave()) {
                    JefePlanta.imprimirDatos();
                } else if (clave == JefePersonal.getClave()) {
                    JefePersonal.imprimirDatos();
                } else {
                    cout << "Clave de empleado no válida.\n";
                }
                break;

            case 4:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nombre de la nueva persona a quien reporta: ";
                cin.ignore();
                getline(cin, nuevo_jefe);

                if (clave == JefePlanta.getClave()) {
                    JefePlanta.cambiarReportaA(nuevo_jefe);
                } else if (clave == JefePersonal.getClave()) {
                    JefePersonal.cambiarReportaA(nuevo_jefe);
                } else {
                    cout << "Clave de empleado no válida.\n";
                }
                break;

            case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}
