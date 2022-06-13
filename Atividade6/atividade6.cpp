#include <iostream>
#include <set>

using namespace std;

int main () {

    set<int> meuSet;
    set<int>::iterator meuIterador;
    char c;
    int i;

    while (c != '*') {
        cin >> c;
        if (c == '+') {
            cin >> i;
            meuSet.insert(i);
        }
        if (c == '?') {
            cin >> i;
            meuIterador = meuSet.find(i);
            if (meuIterador == meuSet.end()) cout << "nao" << endl;
            else cout << "sim" << endl;
        } 
        if (c == '-') {
            cin >> i;
            meuSet.erase(i);
        }
        if (c == '<') {
            meuIterador = meuSet.begin();
            cout << *meuIterador;
        }
        if (c == '>') {
            meuIterador = meuSet.end();
            meuIterador--;
            cout << *meuIterador;
        }
        if (c == '*') {
            meuIterador = meuSet.begin();
            while (meuIterador != meuSet.end()) {
                cout << *meuIterador << " ";
                meuIterador++;
            }
        }
    }
    return 0;
}