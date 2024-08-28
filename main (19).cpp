#include <iostream>
#include <string>
using namespace std;

class Materia {
private:
    int clave;
    string nombre;
    string maestro;
    int creditos;

public:
    // Constructor
    Materia(int c = 0, string n = "", string m = "", int cr = 0)
        : clave(c), nombre(n), maestro(m), creditos(cr) {}

    // Sobrecarga de operadores
    bool operator==(const Materia& m) const {
        return this->clave == m.clave;
    }

    bool operator!=(const Materia& m) const {
        return this->clave != m.clave;
    }

    bool operator<(const Materia& m) const {
        return this->creditos < m.creditos;
    }

    bool operator>(const Materia& m) const {
        return this->creditos > m.creditos;
    }

    Materia operator+(const Materia& m) const {
        return Materia(this->clave + m.clave, this->nombre + " & " + m.nombre, 
                       this->maestro + " / " + m.maestro, 
                       this->creditos + m.creditos);
    }

    // Entrada y salida de flujo
    friend ostream& operator<<(ostream& os, const Materia& m) {
        os << "Clave: " << m.clave << "\nNombre: " << m.nombre
           << "\nMaestro: " << m.maestro << "\nCreditos: " << m.creditos << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Materia& m) {
        cout << "Ingrese la clave: "; is >> m.clave;
        cout << "Ingrese el nombre de la materia: "; is >> ws; getline(is, m.nombre);
        cout << "Ingrese el nombre del maestro: "; is >> ws; getline(is, m.maestro);
        cout << "Ingrese los creditos: "; is >> m.creditos;
        return is;
    }

    // Métodos para modificar datos
    void cambiarClave(int nuevaClave) {
        clave = nuevaClave;
    }

    void cambiarMaestro(string nuevoMaestro) {
        maestro = nuevoMaestro;
    }

    int getClave() const {
        return clave;
    }
};

// Funciones del menú
void cambiarClaveMateria(Materia& m) {
    int nuevaClave;
    cout << "Ingrese la nueva clave de la materia: ";
    cin >> nuevaClave;
    m.cambiarClave(nuevaClave);
    cout << "Clave actualizada exitosamente." << endl;
}

void cambiarMaestroMateria(Materia& m) {
    string nuevoMaestro;
    cout << "Ingrese el nuevo nombre del maestro: ";
    cin >> ws;
    getline(cin, nuevoMaestro);
    m.cambiarMaestro(nuevoMaestro);
    cout << "Maestro actualizado exitosamente." << endl;
}

void imprimirMateria(const Materia& m) {
    cout << m << endl;
}

int main() {
    // Crear las materias
    Materia Programacion(101, "Programacion", "Juan Perez", 6);
    Materia BasesDatos(102, "Bases de Datos", "Maria Lopez", 8);

    int opcion;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Cambiar clave de la materia Programacion\n";
        cout << "2. Cambiar nombre del maestro que imparte Bases de Datos\n";
        cout << "3. Imprimir datos de la materia Bases de Datos\n";
        cout << "4. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (opcion == 4) break;

        switch (opcion) {
        case 1:
            cambiarClaveMateria(Programacion);
            break;
        case 2:
            cambiarMaestroMateria(BasesDatos);
            break;
        case 3:
            imprimirMateria(BasesDatos);
            break;
        default:
            cout << "Opcion no valida.\n";
            break;
        }
    }

    return 0;
}
