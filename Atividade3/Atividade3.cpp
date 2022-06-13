#include <iostream>
#include <cmath>

using namespace std;

class Base {
    
public:
    Base () {}
    ~Base () {}
    virtual void resolver () = 0;
};

class Eq1Grau : Base {
    double a;
    double b;
    double x;

public:
    Eq1Grau (double a, double b) {
        this->a = a;
        this->b = b;
    }

    ~Eq1Grau () {}

    void resolver () {
        x = ((-b)/a);
         cout << "Raiz:" << x << endl;
    }

    double getA () {
        return a;
    }

    double getB () {
        return b;
    }

    Eq1Grau operator- (Eq1Grau parametro) {
        double x, y;
        x = this->a - parametro.getA ();
        y = this->b - parametro.getB ();
        Eq1Grau novo (x, y);
        return novo;
    }

    Eq1Grau operator+ (Eq1Grau parametro) {
        double x, y;
        x = this->a + parametro.getA ();
        y = this->b + parametro.getB ();
        Eq1Grau novo (x, y);
        return novo;
    }
    
};

class Eq2Grau : Base {
    double a;
    double b;
    double c;

public:
    Eq2Grau (double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    ~Eq2Grau () {}

    void resolver () {
        double delta = (b*b) - (4*a*c);
        double raiz1, raiz2;
        if(delta<0){
            cout <<"Não tem raízes reais\n";
        }
        else if (delta==0){
            raiz1 = (-b)/(2*a);
            cout << "Possui apenas uma raiz real: "<< raiz1 << endl;
        }
        else{
            raiz1=(-b - sqrt(delta))/(2*a);
            raiz2=(-b + sqrt(delta))/(2*a);
            cout << "Raiz 1: " << raiz1 << endl;
            cout << "Raiz 2: " << raiz2 << endl;
        }
    }

    double getA () {
        return a;
    }

    double getB () {
        return b;
    }

    double getC () {
        return c;
    }

    Eq2Grau operator- (Eq1Grau parametro) {
        double x, y, z;
        x = this-> a;
        y = this->b - parametro.getA ();
        z = this->c - parametro.getB ();
        Eq2Grau novo (x, y, z);
        return novo;
    }

    Eq2Grau operator- (Eq2Grau parametro) {
        double x, y, z;
        x = this->a - parametro.getA ();
        y = this->b - parametro.getB ();
        z = this->c - parametro.getC ();
        Eq2Grau novo (x, y, z);
        return novo;
    }

    Eq2Grau operator+ (Eq1Grau parametro) {
        double x, y, z;
        x = this-> a;
        y = this->b + parametro.getA ();
        z = this->c + parametro.getB ();
        Eq2Grau novo (x, y, z);
        return novo;
    }

    Eq2Grau operator+ (Eq2Grau parametro) {
        double x, y, z;
        x = this->a + parametro.getA ();
        y = this->b + parametro.getB ();
        z = this->c + parametro.getC ();
        Eq2Grau novo (x, y, z);
        return novo;
    }

};

ostream& operator<< (ostream& stream, Eq1Grau parametro) {
    if (parametro.getB() < 0) {
        stream << parametro.getA () << "*x " << parametro.getB ();
    }
    else {
        stream << parametro.getA () << "*x + " << parametro.getB ();
    }
    return stream;
}

ostream& operator<< (ostream& stream, Eq2Grau parametro) {
    if (parametro.getC() < 0 ) {
        if (parametro.getB() > 0) {
            stream << parametro.getA () << "*x^2 + " << parametro.getB () << "*x " << parametro.getC ();
        }
        else {
            stream << parametro.getA () << "*x^2 " << parametro.getB () << "*x " << parametro.getC ();
        }
    }
    else {
        if (parametro.getB() > 0) {
        stream << parametro.getA () << "*x^2 + " << parametro.getB () << "*x + " << parametro.getC ();
        }
        else {
            stream << parametro.getA () << "*x^2 " << parametro.getB () << "*x + " << parametro.getC ();
        }
    }
    return stream;
} 

int main () {
    Eq1Grau eq1(2, 3); //2*x + 3 = 0

    cout << "Eq1: " << eq1 << endl;

    eq1.resolver();

    Eq2Grau eq2(1, 1, -6); // 1*x^2 + 1*x – 6 = 0
    
    cout << "Eq2: " << eq2 << endl;
    
    eq2.resolver();
    
    Eq2Grau eq3 (1,1,1); // 1*x^2 + 1*x + 1 = 0
    
    Eq2Grau eq4 = eq2 + eq3;
    
    cout << "Eq4: " << eq4 << endl;
    
    eq4 = eq4 - eq3;
    
    cout << "Eq4: " << eq4 << endl;
    
    return 0;
}