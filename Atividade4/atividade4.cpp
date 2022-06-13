#include <iostream>
#include <vector>

using namespace std;

class Fila {
    vector <int> vetor;
    int numElementosLocais;
    static int numFilas;
    static int numElementos;
public:

    Fila (const Fila &obj) {
        this->vetor = obj.vetor;
        this->numElementosLocais = obj.numElementosLocais;
        numFilas++;
        numElementos = numElementos + this->numElementosLocais;
    }

    Fila () {
        numFilas++;
        numElementosLocais = 0;
    }
    ~Fila () {
        numFilas--;
        numElementos = numElementos - this->numElementosLocais;
    }

    vector <int> getVetor () {
        return vetor;
    }

    int getNumElementosLocais () {
        return numElementosLocais;
    }

    void enqueue (int valor) {
        if (numElementosLocais < 51) {
            vetor.push_back(valor);
            numElementos++;
            numElementosLocais++;
        }
        else {
            throw -1;
        }
    }

    int dequeue () {
        if (numElementosLocais > 0) {
            int retorno = vetor[0];
            for(int j = 0; j < numElementosLocais; j++) {
                vetor[j] = vetor[j + 1];
            }
            vetor.pop_back();
            numElementos--;
            return retorno;
        }
        else {
            throw -2;
        }
    }

    static void stats () {
        cout << "Ha " << numFilas << " filas com tamanho total " << numElementos << "." << endl;
    }

    Fila operator= (Fila obj) {
        numElementos = numElementos - this->numElementosLocais;
        this->vetor = obj.getVetor();
        this->numElementosLocais = obj.getNumElementosLocais();
        numElementos = numElementos + this->numElementosLocais;
        return *this;
    }

};

int Fila::numElementos = 0;
int Fila::numFilas = 0;

int main () {
    Fila::stats();
    Fila *a = new Fila();

    for (int i=0;i<4;i++) a->enqueue(i);

    Fila b = (*a);

    Fila::stats();

    b. enqueue (4);
    b. enqueue (5);

    Fila c = (*a);
    Fila::stats();
    
    c = b;
    Fila::stats();

    int x = c.dequeue();

    delete a;

    Fila::stats();
    return 0;
}