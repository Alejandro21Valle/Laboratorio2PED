#include <iostream>
#include <string>
using namespace std;

class Estudiante {
public:
    string nombre;
    float notaFinal;
    Estudiante* siguiente;

    Estudiante(string nombre, float notaFinal) {
        this->nombre = nombre;
        this->notaFinal = notaFinal;
        this->siguiente = nullptr;
    }

    void imprimir() {
        cout << "Nombre: " << nombre << " Nota Final: " << notaFinal << endl;
    }
};

int main (){

    return 0;
}