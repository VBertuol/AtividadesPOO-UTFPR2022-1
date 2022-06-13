#include <iostream>
#include <cmath>

using namespace std;

class ponto {
    double x;
    double y;
public:
    ponto (double X, double Y) {
        x = X;
        y = Y;
    }
    double getX () {
        return x;
    }
    double getY () {
        return y;
    }
    double distanciaParaPonto ( ponto p) {
        double x1 = x;
        double y1 = y;
        double x2 = p.getX ();
        double y2 = p.getY ();
        double j = (x2 - x1)*(x2 - x1);
        double k = (y2 - y1)*(y2 - y1);
        double n = j + k;
        double d = sqrt(n);
        return d;
    }
};

class reta {
    double m;
    double b;
public:
    reta (ponto p1, ponto p2) {
        double x1 = p1.getX ();
        double x2 = p2.getX ();
        double y1 = p1.getY ();
        double y2 = p2.getY ();

        m = (y2 - y1)/(x2 - x1);
        b = (y2)-(m*x2);
    }
    double getM () {
        return m;
    }
    double getB () {
        return b;
    }
    double distanciaParaPonto (ponto p) {
        double x = p.getX ();
        double y = p.getY ();
        double j = m * x;
        double k = b - y;
        double l = j + k;
        if ( l < 0) l = l * -1;
        double n = 1 + (m*m);
        double c = sqrt(n);
        double d = l/c;
        return d;
    }
    bool saoParalelas (reta r) {
        double c = r.getM ();
        if (c == m) return true;
        else return false;
    }

};

int main () {

    ponto A (1, 2);
    ponto B (4, 4);
    ponto C (1, 4);
    ponto D (4, 6);
    ponto E (4, 2);
    reta AB (A, B);
    reta CD (C, D);

    cout << "Distancia entre os pontos A e B: " << A.distanciaParaPonto(B) << endl;
    cout << "Valor de m para reta entre A e B: " << AB.getM() << endl;
    cout << "Valor de b para reta entre A e B: " << AB.getB() << endl;
    cout << "Valor de m para reta entre C e D: " << CD.getM() << endl;
    cout << "Valor de b para reta entre C e D: " << CD.getB() << endl;
    cout << "Distancia entre a reta AB e o ponto E: " << AB.distanciaParaPonto(E) << endl;
    cout << "Reta AB e reta CD sao paralelas? " << AB.saoParalelas(CD) << endl;



    return 0;
}