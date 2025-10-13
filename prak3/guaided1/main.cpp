#include<iostream>
#include "mahasiswa.h"
#include<cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout<<"rata-rata nilai adalah: "<<rata2(mhs);
    system("pause");

    return 0;
}