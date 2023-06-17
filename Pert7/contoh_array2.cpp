#include<iostream>
using namespace std;

int main(){
    char cnama[5][50];
    float fnilai[5], fnilai2[5], fhasil[5];

    for(int i=1;i<=2;i++){
        cout <<"Input data ke -"<<i<<endl;
        cout <<"--------------------"<<endl;

        cout <<"Nama siswa :";
        cin.getline(cnama[i],50);

        cout <<"Nilai UTS :";
        cin >>fnilai[i];

        cout <<"Nilai UAS :";
        cin >>fnilai2[i];

        fhasil[i] = (fnilai[i] * 0.4) + (fnilai2[i] * 0.6);
        cout << endl;

        cin.ignore();
    }
    cout <<endl;

    //tampilan data

    cout<<"=\t"<<endl;
    cout<<"Nama|UTS|UAS|Nilai Akhir"<<endl;
    cout<<"=\t"<<endl;

    for(int i=1;i<=2;i++){
        cout<<cnama[i]<<"\t";
        cout<<fnilai[i]<<"\t";
        cout<<fnilai2[i]<<"\t";
        cout<<fhasil[i]<<endl;
    }
    
    return 0;

}