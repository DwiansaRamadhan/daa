#include<iostream>

using namespace std;

int main(){
    int apel;
    int pepaya;

    cout << "masukkan jumlah beli apel :" <<endl;
    cin >> apel;
    cout << "masukkan jumlah belu pepaya : "<< endl;
    cin >> pepaya;

    int total_bayar;
    total_bayar = (5000*apel) + (7000*pepaya);

    cout << "jumlah yang harus dibayarkan : "<< total_bayar <<endl;

    int bayar;

    cout << "Masukkan Pembayaran :" << endl;
    cin >> bayar;

    if(bayar < total_bayar){
        cout << "saldo anda kurang" <<endl;
    }else{
        cout << "anda berhasil membayar" <<endl;
    }

    
return 0;
}