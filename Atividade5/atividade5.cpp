#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Buque {
protected:
    static int totalPedidos;
    static int totalFlores;
    int flores;
public:
    Buque (int rosas) {
        flores = rosas;
        totalPedidos++;
        totalFlores = totalFlores + rosas;
    }
    virtual int getPreco() = 0;
    static int gettotalPedidos () {
        return totalPedidos;
    }
    static int gettotalFlores () {
        return totalFlores;
    }
};

class Tradicional : public Buque {

public:
    Tradicional (int rosas) : Buque (rosas) {}

    int getPreco () {
        int preco = flores * 2;
        return preco;
    }
};

class Especial : public Buque {

public:
    Especial (int rosas) : Buque (rosas) {}

    int getPreco () {
        int acrescimo = (flores / 10) + 1;
        int preco = (flores * 2) + (acrescimo * 5);
        return preco;
    }
};

vector <Buque*> leitura () {
    vector <Buque*> vetor;
    string pedido;
    int numFlores;
    while (pedido != "fim") {
        cin >> pedido;
        if (pedido == "fim") break;
        cin >> numFlores;
        if (pedido == "tradicional") {
            Buque * novo = new Tradicional(numFlores);
            vetor.push_back(novo);
        }
        if (pedido == "especial") {
            Buque * novo = new Especial(numFlores);
            vetor.push_back(novo);
        }
    }
    cout << endl;
    return vetor;
}

void escrita (vector <Buque*> meuVetor) {
    vector <Buque*>::iterator meuIterador;
    int precoTotal = 0;
    meuIterador = meuVetor.begin();
    int i = 1;
    cout << "Total: " << Buque::gettotalPedidos() << " pedidos" << endl;
    while (meuIterador != meuVetor.end()) {
        cout << "Pedido " << i << ": R$ " << (*meuIterador)->getPreco() << ",00" << endl;
        precoTotal = precoTotal + (*meuIterador)->getPreco();
        i++;
        meuIterador++;
    }
    cout << "Total de rosas: " << Buque::gettotalFlores() << endl;
    cout << "Valor total: R$ " << precoTotal << ",00" << endl;
}

int Buque::totalPedidos = 0;
int Buque::totalFlores = 0;

int main () {

    vector <Buque*> meuVetor = leitura ();
    escrita (meuVetor);
    vector <Buque*>::iterator meuIterador;
    meuIterador = meuVetor.end();
    while (meuVetor.size() > 0) {
        meuIterador = meuVetor.end() - 1;
        delete *meuIterador;
        meuVetor.pop_back();
    }
    return 0;
}