#include <iostream>

using namespace std;

int main(){
    int pil, c;
    char back;
    int a = 10;
    int b = 5;

    kurang:
        c=a-b;
        cout<<c<<endl;

    do{
        cout<<"0, Exit"<<endl;
        cout<<"1. angka di Tambah"<<endl;
        cout<<"2. angka di Kurang"<<endl;
        cout<<"Input Pilihan : "<<endl;
        cin>>pil;
        switch(pil){
            case 0:
                cout<<"exit"<<endl;
                break;
            
            case 1:
                c=a+b;
                cout<<c<<endl;
                break;
            
            case 2:
                goto kurang;
            
            default:
                cout<<"pilihan salah"<<endl;
                break;
        }
        cout<<"Pilih anda ingin kembali?"<<endl;
        cin>>back;

    }while(back !='t');
    cout<<"thanks"<<endl;
    return 0;
}