#include <iostream>
using namespace std;
int main() {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                       "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", 
                        "empat belas", "lima belas", "enam belas", 
                        "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                        "lima puluh", "enam puluh", "tujuh puluh", 
                        "delapan puluh", "sembilan puluh"};

    int a;
    cout << "masukkan angka (0 - 100): ";
    cin >> a;

    cout << a << " : ";

    if (a == 0) {
        cout << "nol";
    } 
    else if (a == 100) {
        cout << "seratus";
    }
    else if (a < 10) {
        cout << satuan[a];
    }
    else if (a < 20) {
        cout << belasan[a - 10];
    }
    else {
        int puluh = a / 10;
        int sisa = a % 10;
        cout << puluhan[puluh];
        if (sisa != 0) {
            cout << " " << satuan[sisa];
        }
    }

    cout << endl;
    return 0;
}