#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egzaminas;
    double rezultatas;

public:
    Studentas();
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    ~Studentas();

    friend std::istream& operator>>(std::istream& input, Studentas& s);
    friend std::ostream& operator<<(std::ostream& output, const Studentas& s);
    void rez(bool useMedian = false);
};