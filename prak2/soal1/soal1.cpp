#include <iostream>
using namespace std;

int matriksa[3][3] = {
    {7, 12, 22},
    {31, 6, 41},
    {15, 19, 36}
};

int matriksb[3][3] = {
    {11, 34, 7},
    {3, 25, 41},
    {5, 18, 33}
};

int hasil[3][3] = {0};

void jumlahmatriks(int matriksa[3][3], int matriksb[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = matriksa[i][j] + matriksb[i][j];
        }
    }
    cout << "hasil penjumlahan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

void kurangmatriks(int matriksa[3][3], int matriksb[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = matriksa[i][j] - matriksb[i][j];
        }
    }
    cout << "hasil pengurangan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

void kalimatriks(int matriksa[3][3], int matriksb[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){           
        for (int j = 0; j < 3; j++){        
            for (int k = 0; k < 3; k++){    
                hasil[i][j] += matriksa[i][k] * matriksb[k][j];
            }
        }
    }
    cout << "hasil perkalian: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n menu " << endl;
        cout << "1. penjumlahan matriks" << endl;
        cout << "2. pengurangan matriks" << endl;
        cout << "3. perkalian matriks" << endl;
        cout << "4. keluar" << endl;
        cout << "pilih operasi (1-4): ";
        cin >> pilihan;

         switch (pilihan) {
            case 1:
                jumlahmatriks(matriksa, matriksb, hasil);
                break;
            case 2:
                kurangmatriks(matriksa, matriksb, hasil);
                break;
            case 3:
                kalimatriks(matriksa, matriksb, hasil);
                break;
            case 4:
                cout << "keluar." << endl;
                break;
            default:
                cout << "tidak ada pilihan" << endl;
        }
        cout << endl; 
    } while (pilihan != 4);

    return 0;
}
