#include <iostream>
using namespace std;

int main (){
    int angka1, angka2;
    cout << "Masukan Angka 1"<< endl;
    cin >> angka1 ;
    cout << "Masukan angka 2" << endl;
    cin >> angka2;

    if (angka1 < angka2)
    {
        cout << angka1 << " Kurang dari " << angka2 << endl;
    }else {
        cout << angka1 << " Lebih dari " << angka2 << endl;

    }

    if (angka1 == angka2)
    {
        cout << angka1 <<" sama dengan " << angka2 << endl;
    } else  {
        cout << "Angka berbeda" << endl;
    }

    return 0;
    
    
}
