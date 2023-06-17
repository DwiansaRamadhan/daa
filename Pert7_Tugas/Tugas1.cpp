#include <iostream>
#include<string.h>

using namespace std;

// int main(){
//     int i,j, count;
//     char nama[30];

//     cout << "program membalik nama";
//     cout << "\n\nMasukkan nama Anda = "; 
//     cin.ignore(); 
//     cin.getline(nama,sizeof(nama));
//     cout << endl;

//     for (i=0; i<=nama[i];i++){
//       count = i+1;
//     }

//     cout << "Nama terbalik anda = "; 

//     for (j=count; j>=0;j--){
//       cout << nama[j];
//     }

//     cout <<endl;

//     return 0;
// }

int main(){

    char kalimat[100];
    
    cout<<"Masukan Kalimat :"; 
    cin.getline(kalimat, sizeof(kalimat));
    int x = strlen(kalimat);

    cout<<"Kata yang sudah di balik :";

    for(int i=x-1;i>=0;i--){
        cout<<kalimat[i];
    }

 cout << endl;

}