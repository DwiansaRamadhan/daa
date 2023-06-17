#include<iostream>

using namespace std;

int main(){
    char nama[2][3][10] = {{"Pak","Bu", "Mas"}, {"Andi", "Budi", "Wahyu"}};
    
    cout<<nama[0][0] <<" " <<nama[1][0] <<endl;
    cout<<nama[0][1] <<" " <<nama[1][2] <<endl;
    cout<<nama[0][2] <<" " <<nama[1][1] <<endl;
}