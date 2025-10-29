#include "studentas.h"
#include <algorithm>
#include <numeric>

// Rule of Three implementation
Studentas::Studentas() : egzaminas(0), rezultatas(0.0) {}

Studentas::Studentas(const Studentas& other) : 
    vardas(other.vardas),
    pavarde(other.pavarde),
    paz(other.paz),
    egzaminas(other.egzaminas),
    rezultatas(other.rezultatas) {}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        paz = other.paz;
        egzaminas = other.egzaminas;
        rezultatas = other.rezultatas;
    }
    return *this;
}

// Method implementations
std::istream& operator>>(std::istream& input, Studentas& s) {
    std::cout << "Iveskite varda: ";
    input >> s.vardas;
    std::cout << "Iveskite pavarde: ";
    input >> s.pavarde;
    
    std::cout << "Iveskite 5 namu darbu rezultatus:\n";
    int p;
    for (int i = 0; i < 5; i++) {
        std::cout << i+1 << "-as pazymys: ";
        input >> p;
        if(p >= 0 && p <= 10) {
            s.paz.push_back(p);
        }
    }
    
    std::cout << "Iveskite egzamino rezultata: ";
    input >> s.egzaminas;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Studentas& s) {
    output << std::left << std::setw(15) << s.pavarde 
           << std::setw(15) << s.vardas 
           << std::fixed << std::setprecision(2) << s.rezultatas;
    return output;
}

void Studentas::rez(bool useMedian) {
    double ndResult;
    if (useMedian) {
        std::vector<int> temp = paz;
        std::sort(temp.begin(), temp.end());
        if (temp.size() % 2 == 0) {
            ndResult = (temp[temp.size()/2 - 1] + temp[temp.size()/2]) / 2.0;
        } else {
            ndResult = temp[temp.size()/2];
        }
    } else {
        ndResult = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    }
    rezultatas = ndResult * 0.4 + egzaminas * 0.6;
}

Studentas::~Studentas() {
    paz.clear();
}