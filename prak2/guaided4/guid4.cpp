#include<iostream>
using namespace std;

void ubahnilai(int*ptr){
    *ptr=20;
}

int main(){
    int x = 10;
    cout << "nilai sebelum diuabh:"<< x << endl;

    ubahnilai(&x);
    cout<<"nilai setelah di ubah:"<< x << endl;

    return 0;
}