#include <iostream>
#include <string>
#include <vector>

using namespace std;

int leStrings (vector <string> &lista) {
    int N, charNumber;
    string palavra;
    charNumber = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> palavra;
        lista.push_back(palavra);
        int n = lista[i].size();
        charNumber = charNumber + n;
        for (int j = 0; j < n; j++) {
            if (lista[i][j] < 97 or lista[i][j] > 122) {
                lista[i][j] = lista[i][j] + 32;
            }
        }
    }
    cout << endl << charNumber << endl;
    return N;
}

void ordenaString (vector <string> &lista, int N) {
    if (N == 1) return;
    for (int i = 0; i < N-1; i++) {
        for (int m = 0; m < N-1; m++) {
            if (lista[m] > lista[m+1]){
                string c;
                c = lista[m];
                lista[m] = lista[m+1];
                lista[m+1] = c;
            }
            
        }
    }
    return;
}

void imprimeStrings (vector <string> &lista, int N) {
    for (int i = 0; i < N; i++) {
        cout << lista[i] << endl;
    }
    return;
}

int main() {
    vector <string> lista;
    int N = leStrings (lista);
    ordenaString (lista, N);
    imprimeStrings (lista, N);
    return 0;
}

