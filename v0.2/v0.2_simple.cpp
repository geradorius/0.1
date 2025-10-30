#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <random>

using namespace std;
using clk = chrono::high_resolution_clock;
using ns  = chrono::duration<double>;

struct Student {
    string vardas;
    string pavarde;
    double galutinis;
};

void generuotiFaila(const string& filename, size_t kiek) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Klaida: nepavyko sukurti failo " << filename << endl;
        return;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 10.0);
    for (size_t i = 1; i <= kiek; ++i) {
        fout << "Vardas" << i << " Pavarde" << i << " " << fixed << setprecision(2) << dist(gen) << "\n";
    }
    fout.close();
}

template <typename Container>
void nuskaitytiFaila(const string& filename, Container& container) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Klaida: nepavyko atidaryti failo " << filename << endl;
        return;
    }
    string vardas, pavarde;
    double balas;
    while (fin >> vardas >> pavarde >> balas) {
        container.push_back({vardas, pavarde, balas});
    }
    fin.close();
}

template <typename Container>
void rusiuoti(const Container& visi, Container& vargsai, Container& kieti) {
    for (auto& s : visi) {
        if (s.galutinis < 5.0) vargsai.push_back(s);
        else kieti.push_back(s);
    }
}

template <typename Container>
void isvesti(const string& f1, const string& f2, const Container& vargsai, const Container& kieti) {
    ofstream fv(f1);
    for (auto& s : vargsai) fv << s.vardas << " " << s.pavarde << " " << s.galutinis << "\n";
    fv.close();
    ofstream fk(f2);
    for (auto& s : kieti) fk << s.vardas << " " << s.pavarde << " " << s.galutinis << "\n";
    fk.close();
}

template <typename Container>
void testuoti(const string& filename, const string& cont_name) {
    cout << "=== TESTAS SU " << cont_name << " ===" << endl;
    auto start_read = clk::now();
    Container visi;
    nuskaitytiFaila(filename, visi);
    auto end_read = clk::now();
    auto start_sort = clk::now();
    Container vargsai, kieti;
    rusiuoti(visi, vargsai, kieti);
    auto end_sort = clk::now();
    auto start_write = clk::now();
    isvesti("vargsai_" + cont_name + ".txt", "kieti_" + cont_name + ".txt", vargsai, kieti);
    auto end_write = clk::now();
    ns t_read = end_read - start_read;
    ns t_sort = end_sort - start_sort;
    ns t_write = end_write - start_write;
    cout << "Failas: " << filename << endl;
    cout << "Skaitymas: " << t_read.count() << " s\n";
    cout << "Rūšiavimas: " << t_sort.count() << " s\n";
    cout << "Rašymas: " << t_write.count() << " s\n";
    cout << "Bendras laikas: " << (t_read + t_sort + t_write).count() << " s\n\n";
}

int main() {
    cout << fixed << setprecision(6);
    cout << "Generuojami testiniai failai..." << endl;
    auto t0 = clk::now();
    generuotiFaila("studentai_1k.txt", 1000);
    generuotiFaila("studentai_10k.txt", 10000);
    generuotiFaila("studentai_100k.txt", 100000);
    generuotiFaila("studentai_1M.txt", 1000000);
    generuotiFaila("studentai_10M.txt", 10000000);
    auto t1 = clk::now();
    cout << "Failu generavimo laikas: " << (chrono::duration<double>(t1 - t0)).count() << " s\n\n";
    vector<string> files = {"studentai_1k.txt", "studentai_10k.txt", "studentai_100k.txt", "studentai_1M.txt", "studentai_10M.txt"};
    for (auto& f : files) {
        testuoti<vector<Student>>(f, "vector");
        testuoti<list<Student>>(f, "list");
        testuoti<deque<Student>>(f, "deque");
    }
    cout << "VISI TESTAI BAIGTI." << endl;
    return 0;
}
