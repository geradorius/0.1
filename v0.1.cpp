#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egzaminas;
    double rezultatas;

public:
    // Default constructor
    Studentas() : egzaminas(0), rezultatas(0.0) {}
    
    // Overloaded input operator
    friend std::istream& operator>>(std::istream& input, Studentas& s) {
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

    // Overloaded output operator
    friend std::ostream& operator<<(std::ostream& output, const Studentas& s) {
        output << std::left << std::setw(15) << s.pavarde 
               << std::setw(15) << s.vardas 
               << std::fixed << std::setprecision(2) << s.rezultatas;
        return output;
    }

    // Calculate final grade (with choice between median and mean)
    void rez(bool useMedian = false) {
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

    // Copy constructor (Rule of three - 1)
    Studentas(const Studentas& other) : 
        vardas(other.vardas),
        pavarde(other.pavarde),
        egzaminas(other.egzaminas),
        rezultatas(other.rezultatas) {
        paz = other.paz;
    }
    
    // Assignment operator (Rule of three - 2)
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            paz = other.paz;
            egzaminas = other.egzaminas;
            rezultatas = other.rezultatas;
        }
        return *this;
    }
    
    // Destructor (Rule of three - 3)
    ~Studentas() {
        paz.clear();
    }
};

int main() {
    std::vector<Studentas> grupe;
    char choice;
    bool useMedian;

    std::cout << "Skaiciuoti galutini bala naudojant mediana? (t/n): ";
    std::cin >> choice;
    useMedian = (choice == 't' || choice == 'T');

    std::cout << "Iveskite studentu duomenis:\n";
    do {
        Studentas stud;
        std::cin >> stud;
        stud.rez(useMedian);
        grupe.push_back(stud);

        std::cout << "Ar norite prideti dar viena studenta? (t/n): ";
        std::cin >> choice;
    } while (choice == 't' || choice == 'T');

    // Print header
    std::cout << "\nPavarde         Vardas          Galutinis " 
              << (useMedian ? "(Med.)" : "(Vid.)") << "\n";
    std::cout << std::string(50, '-') << "\n";

    // Print all students
    for (const auto& student : grupe) {
        std::cout << student << "\n";
    }

    return 0;
}
