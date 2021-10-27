#include <iostream>
#include<vector>
using namespace std;
void p1(){
    cout << "Podaj liczbe elementow" << endl;
    int ile = -1;
    while (ile <= 0) {
        cin >> ile;
    }
    vector<double> v(ile);
    for (int i = 0 ; i < ile;i++) {
        cin>>v[i];
    }
    for (int i = 0; i < ile;i++) {
        cout << "v["<<i<<"]=" << v[i] << endl;
    }
    double m=v[0];
    int p = 0;
    double M=v[0];
    int P = 0;
    for (double tmp : v) {
        if (tmp < m) {
            p++;
            m = tmp;
        }
        if (tmp > M) {
            P++;
            M = tmp;
        }

    }
    cout << "Wartosc najmniejsza =" << m <<" na pozycji "<<p<< endl << "Wartosc najwieksza =" << M <<" na pozycji " << P << endl;
}
void p2() {
    cout << "Podaj liczbe wierszy" << endl;
    int w = -1;
    while (w <= 0) {
        cin >> w;
    }
    cout << "Podaj liczbe kolumn" << endl;
    int kol = -1;
    while (kol <= 0) {
        cin >> kol;
    }
    float** tab= new float*[kol];
    for (int i = 0; i < kol; i++) {
        tab[i] = new float[w];
    }
    for (int i = 0; i < kol; i++) {
        for (int u = 0; u < w; u++) {
            cout << "T[ " << u << "][" << i << "]=";
            cin >> tab[i][u];
        }
    }
    cout << endl;
    int m = tab[0][0];
    int M = tab[0][0];
    int w1 = 0, w2 = 0, k1 = 0, k2 = 0;
    for (int i = 0; i < kol; i++) {
        for (int u = 0; u < w; u++) {
            if (tab[i][u] < m) {
                k1 = i;
                w1 = u;
                m = tab[i][u];
            }
            if (tab[i][u] > M) {
                k2=i;
                w2 = u;
                M = tab[i][u];
            }
        }
    }
    cout << "Wartosc najmniejsza =" << m << " na pozycji " << k1 <<","<<w1<< endl << "Wartosc najwieksza =" << M << " na pozycji " << k2 << "," << w2 << endl;
}
int main() {
    //p1();
    p2();
}