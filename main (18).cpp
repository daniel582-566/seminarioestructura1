#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
    int clave;
    string nombre;
    string domicilio;
    string reporteA;
    double sueldo;

public:
    // Constructor
    Empleado(int c = 0, string n = "", string d = "", string r = "", double s = 0.0)
        : clave(c), nombre(n), domicilio(d), reporteA(r), sueldo(s) {}

    // Sobrecarga de operadores
    bool operator==(const Empleado& e) const {
        return this->clave == e.clave;
    }

    bool operator!=(const Empleado& e) const {
        return this->clave != e.clave;
    }

    bool operator<(const Empleado& e) const {
        return this->sueldo < e.sueldo;
    }

    bool operator>(const Empleado& e) const {
        return this->sueldo > e.sueldo;
    }

    Empleado operator+(const Empleado& e) const {
        return Empleado(this->clave + e.clave, this->nombre + " & " + e.nombre, 
                        this->domicilio + " / " + e.domicilio, 
                        this->reporteA + " & " + e.reporteA, 
                        this->sueldo + e.sueldo);
    }

    // Entrada y salida de flujo
    friend ostream& operator<<(ostream& os, const Empleado& e) {
        os << "Clave: " << e.clave << "\nNombre: " << e.nombre
           << "\nDomicilio: " << e.domicilio << "\nSueldo: " << e.sueldo
           << "\nReporta a: " << e.reporteA << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Empleado& e) {
        cout << "Ingrese la clave: "; is >> e.clave;
        cout << "Ingrese el nombre: "; is >> ws; getline(is, e.nombre);
        cout << "Ingrese el domicilio: "; getline(is, e.domicilio);
        cout << "Ingrese el sueldo: "; is >> e.sueldo;
        cout << "Ingrese el nombre de la persona a quien reporta: "; is >> ws; getline(is, e.reporteA);
        return is;
    }

    // Métodos para modificar datos
    void cambiarDomicilio(string nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void actualizarSueldo(double porcentaje) {
        sueldo += sueldo * (porcentaje / 100.0);
    }

    void cambiarReporteA(string nuevoReporteA) {
        reporteA = nuevoReporteA;
    }

    int getClave() const {
        return clave;
    }
};

// Funciones del menú
void cambiarDomicilio(Empleado& e) {
    string nuevoDomicilio;
    cout << "Ingrese el nuevo domicilio: ";
    cin >> ws;
    getline(cin, nuevoDomicilio);
    e.cambiarDomicilio(nuevoDomicilio);
    cout << "Domicilio actualizado exitosamente." << endl;
}

void actualizarSueldo(Empleado& e) {
    double porcentaje;
    cout << "Ingrese el porcentaje de incremento: ";
    cin >> porcentaje;
    e.actualizarSueldo(porcentaje);
    cout << "Sueldo actualizado exitosamente." << endl;
}

void imprimirEmpleado(const Empleado& e) {
    cout << e << endl;
}

void cambiarReporteA(Empleado& e) {
    string nuevoReporteA;
    cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
    cin >> ws;
    getline(cin, nuevoReporteA);
    e.cambiarReporteA(nuevoReporteA);
    cout << "Reporte actualizado exitosamente." << endl;
}

int main() {
    // Crear los empleados
    Empleado JefePlanta(1, "Carlos Lopez", "Calle 123", "CEO", 5000);
    Empleado JefePersonal(2, "Ana Gomez", "Avenida 456", "CEO", 4500);

    int opcion, claveEmpleado;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Cambiar domicilio de un empleado\n";
        cout << "2. Actualizar sueldo de un empleado\n";
        cout << "3. Imprimir datos de un empleado\n";
        cout << "4. Cambiar nombre de la persona a quien reporta un empleado\n";
        cout << "5. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (opcion == 5) break;

        cout << "Ingrese la clave del empleado (1 para JefePlanta, 2 para JefePersonal): ";
        cin >> claveEmpleado;

        Empleado* empleado = nullptr;
        if (claveEmpleado == 1) {
            empleado = &JefePlanta;
        } else if (claveEmpleado == 2) {
            empleado = &JefePersonal;
        } else {
            cout << "Clave de empleado invalida.\n";
            continue;
        }

        switch (opcion) {
        case 1:
            cambiarDomicilio(*empleado);
            break;
        case 2:
            actualizarSueldo(*empleado);
            break;
        case 3:
            imprimirEmpleado(*empleado);
            break;
        case 4:
            cambiarReporteA(*empleado);
            break;
        default:
            cout << "Opcion no valida.\n";
            break;
        }
    }

    return 0;
}
