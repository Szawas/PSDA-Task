#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// struktur dari informasi store library 
struct Library {
    string name;
    string type;
    string address;
    int establishmentYear;
    string architect;
};

// fungsi dari add library information
void addLibrary(vector<Library>& libraries) {
    Library newLibrary;
    cout << "Nama perpustakaan: ";
    getline(cin >> ws, newLibrary.name);
    cout << "Tipe perpustakaan: ";
    getline(cin >> ws, newLibrary.type);
    cout << "Alamat: ";
    getline(cin >> ws, newLibrary.address);
    cout << "Tahun berdiri: ";
    cin >> newLibrary.establishmentYear;
    cout << "Architect's: ";
    getline(cin >> ws, newLibrary.architect);
    libraries.push_back(newLibrary);
    cout << "Informasi perpustakaan berhasil ditambahkan." << endl;
}

void searchLibrary(const vector<Library>& libraries, const string&keyword){
    vector<string> searchWords;
    stringstream ss(keyword);
    string word;
    while (ss >> word){
        searchWords.push_back(word);
    }

  bool found = false;
    for (const auto& lib : libraries) {
        bool match = true;
        for (const string& searchWord : searchWords) {
            if (lib.name.find(searchWord) == string::npos &&
                lib.type.find(searchWord) == string::npos &&
                lib.address.find(searchWord) == string::npos &&
                to_string(lib.establishmentYear).find(searchWord) == string::npos &&
                lib.architect.find(searchWord) == string::npos) {
                match = false;
                break;
            }       
        }
        if (match){
            cout << "Informasi perpustakaan ditemukan: " << endl;
            cout << "Nama perpustakaan: " << lib.name << endl;
            cout << "Tipe perpustakaan: " << lib.type << endl;
            cout << "Alamat: " << lib.address << endl;
            cout << "Tahun berdiri: " <<lib.establishmentYear << endl;
            cout << "Architect: " << lib.architect << endl;
            found = true;
        }
    }  
    if (!found){
        cout << "Informasi perpustakaan tidak ditemukan" << endl;
  }
}

int main(){
    vector<Library> libraries;
    char choice;

    do{
        cout << "\nMenu:\n";
        cout << "1. Tambah Informasi Perpustakaan\n";
        cout << "2. Mencari Informasi Perpustakaan\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case '1':
                addLibrary(libraries);
                break;
            case '2': {
                string keyword;
                cout << "Masukkan kata kunci pencarian: ";
                getline(cin >> ws, keyword);
                searchLibrary(libraries, keyword);
                break;
            }
            case '3':
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak sesuai." << endl;      
        }
    } while (choice != '3');

    return 0;
  }

