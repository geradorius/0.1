#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
int main() {
    cout << "=== OPTIMIZUOTAS 10M TESTAS ===" << endl;
    auto start = chrono::high_resolution_clock::now();
    ifstream fin("studentai_10M.txt");
    if (!fin) { cerr << "Klaida!"; return 1; }
    ofstream fv("vargsai_10M.txt");
    ofstream fk("kieti_10M.txt");
    string vardas, pavarde;
    double balas;
    size_t vargsai = 0, kieti = 0;
    while (fin >> vardas >> pavarde >> balas) {
        if (balas < 5.0) { fv << vardas << " " << pavarde << " " << balas << "\n"; vargsai++; }
        else { fk << vardas << " " << pavarde << " " << balas << "\n"; kieti++; }
    }
    fin.close(); fv.close(); fk.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "BAIGTA! Vargsai: " << vargsai << " Kieti: " << kieti << " Laikas: " << elapsed.count() << " s" << endl;
    return 0;
}
