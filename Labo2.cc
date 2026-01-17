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

class ListaEnlazada {
private:
    Estudiante* head;

    float sumarNotas(Estudiante* nodo, int& contador) {
        if (nodo == nullptr) {
            return 0;
        }
        contador++;
        return nodo->notaFinal + sumarNotas(nodo->siguiente, contador);
    }

public:
    ListaEnlazada() {
        head = nullptr;
    }

    void agregarEstudiante(string nombre, float nota) {
        Estudiante* nuevo = new Estudiante(nombre, nota);

        if (head == nullptr) {
            head = nuevo;
        } else {
            Estudiante* temp = head;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    void imprimirLista() {
        Estudiante* temp = head;
        while (temp != nullptr) {
            temp->imprimir();
            temp = temp->siguiente;
        }
    }

    float calcularPromedioRecursivo() {
        int contador = 0;
        float suma = sumarNotas(head, contador);

        if (contador == 0) {
            return 0;
        }
        return suma / contador;
    }
};

int main (){
    ListaEnlazada lista;

    lista.agregarEstudiante("Ana", 8.5);
    lista.agregarEstudiante("Luis", 7.0);
    lista.agregarEstudiante("Maria", 9.2);

    cout << "Lista de Estudiantes:" << endl;
    lista.imprimirLista();

    cout << "Promedio de notas: " << lista.calcularPromedioRecursivo() << endl;

    return 0;
}