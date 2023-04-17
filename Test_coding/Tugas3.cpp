#include <iostream>
#include <string>
using namespace std;

// fungsi untuk memeriksa apakah suatu karakter adalah huruf vokal
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// fungsi untuk memeriksa apakah suatu karakter adalah angka
bool isNumeric(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    string kalimat, data;
    int konsonan = 0, vokal = 0, numerik = 0;

    // input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // input data yang ingin dicari
    cout << "Masukkan data yang ingin dicari: ";
    cin >> data;

    // loop melalui setiap karakter dalam kalimat
    for (char c : kalimat) {
        if (isVowel(c)) {
            vokal++;
        } else if (isNumeric(c)) {
            numerik++;
        } else if (isalpha(c)) {
            konsonan++;
        }
    }

    // output hasil
    cout << "Jumlah konsonan: " << konsonan << endl;
    cout << "Jumlah vokal: " << vokal << endl;
    cout << "Jumlah numerik: " << numerik << endl;

    // mencari data dalam kalimat
    size_t pos = kalimat.find(data);
    if (pos != string::npos) {
        cout << "Data ditemukan pada posisi " << pos << endl;
    } else {
        cout << "Data " << data << " tidak ditemukan" << endl;
    }

    return 0;
}