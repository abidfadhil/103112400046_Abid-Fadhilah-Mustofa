#include <iostream>
using namespace std;

void tampil_array(int arr[3][3]) {
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            cout << arr[a][b] << "\t";
        }
        cout << endl;
    }
}

void tukar_nilai(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int* ptr_a;
    int* ptr_b;

    ptr_a = &arr1[baris][kolom];
    ptr_b = &arr2[baris][kolom];

    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

int main() {
    int array_a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array_b[3][3] = {
        {99, 88, 77},
        {66, 55, 44},
        {33, 22, 11}
    };

    cout << "--- kondisi awal ---" << endl;
    cout << "isi array a:" << endl;
    tampil_array(array_a);

    cout << "\nisi array b:" << endl;
    tampil_array(array_b);

    int baris = 1;
    int kolom = 1;

    tukar_nilai(array_a, array_b, baris, kolom);

    cout << "\n--- setelah ditukar pada posisi [" << baris << "][" << kolom << "] ---" << endl;
    cout << "isi array a:" << endl;
    tampil_array(array_a);

    cout << "\nisi array b:" << endl;
    tampil_array(array_b);

}
