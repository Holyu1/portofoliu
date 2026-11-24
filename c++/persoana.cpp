#include <iostream>
#include <cstring>
using namespace std;
class Persoana {
private:
    char* nume = nullptr;
    int varsta = 0;
    char* job = nullptr;
public:
    Persoana() {
        nume = nullptr;
        varsta = 0;
        job = nullptr;
    }
    Persoana(const char* nume, int varsta, const char* job) {
        if (nume!=nullptr && varsta > 0 && job != nullptr) {
            this->nume = new char[strlen(nume) + 1];
            this->job = new char[strlen(job) + 1];
            strcpy_s(this->nume,strlen(nume)+1,nume);
            strcpy_s(this->job, strlen(job) + 1, job);
            this->varsta = varsta;
        }
    }
    ~Persoana() {
        delete[] nume;
        delete[] job;
        nume = nullptr;
        job = nullptr;
    }
    Persoana(const Persoana& p) {
        if (p.nume != nullptr && p.varsta > 0 && p.job != nullptr) {
            nume = new char[strlen(p.nume) + 1];
            job = new char[strlen(p.job) + 1];
            strcpy_s(nume, strlen(p.nume) + 1, p.nume);
            strcpy_s(job, strlen(p.job) + 1, p.job);
            varsta = p.varsta;
        }
    }
    Persoana& operator= (const Persoana& p) {
        if (this != &p) {
            if (p.nume != nullptr && p.varsta > 0 && p.job != nullptr) {
                nume = new char[strlen(p.nume) + 1];
                job = new char[strlen(p.job) + 1];
                strcpy_s(nume, strlen(p.nume) + 1, p.nume);
                strcpy_s(job, strlen(p.job) + 1, p.job);
                varsta = p.varsta;
            }
        }
        return *this;
    }
    friend istream& operator>>(istream&,Persoana&);
    friend ostream& operator<<(ostream&, const Persoana&);
};
istream& operator>>(istream& in, Persoana& p) {
    delete[] p.nume;
    p.nume = new char[20];
    cout << "Nume: "; in >> p.nume;
    delete[] p.job;
    p.job = new char[20];
    cout << "Job: "; in >> p.job;
    cout << "Varsta: "; in >> p.varsta;
    return in;
}
ostream& operator<<(ostream& out, const Persoana& p) {
    out << "Nume: " << p.nume << endl;
    out << "Job: " << p.job << endl;
    out << "Varsta: " << p.varsta << endl;
    return out;
}
class Student: public Persoana {
private:
    int an_studiu = 0;
    char* facultate = nullptr;
    float medie;
public:
    Student(): Persoana(nullptr,0,nullptr) {
        an_studiu = 0;
        facultate = nullptr;
        medie = 0;
    }
    Student(int an_studiu, const char* facultate, float medie, const char* nume, int varsta, const char* job): Persoana(nume,varsta,job) {
        if (an_studiu > 0 && facultate != nullptr && medie > 0) {
            this->an_studiu = an_studiu;
            this->medie = medie;
            this->facultate = new char[strlen(facultate)+1];
            strcpy_s(this->facultate,strlen(facultate)+1,facultate);
        }
    }
    ~Student() {
        delete[] facultate;
        facultate = nullptr;
    }
    Student& operator=(const Student& s) {
        if (this!= &s) {
            Persoana::operator=(s);
            if (s.an_studiu > 0 && s.facultate != nullptr && s.medie > 0) {
                an_studiu = s.an_studiu;
                medie = s.medie;
                facultate = new char[strlen(s.facultate) + 1];
                strcpy_s(facultate, strlen(s.facultate) + 1, s.facultate);
            }
        }
        return *this;
    }
    Student(const Student& s): Persoana(s) {
        if (s.an_studiu > 0 && s.facultate != nullptr && s.medie > 0) {
            an_studiu = s.an_studiu;
            medie = s.medie;
            facultate = new char[strlen(s.facultate) + 1];
            strcpy_s(facultate, strlen(s.facultate) + 1, s.facultate);
        }
    }
    friend istream& operator>>(istream&, Student&);
    friend ostream& operator<<(ostream&, const Student&);
};
istream& operator>> (istream& in, Student& s) {
    in >> (Persoana&) s;
    cout << "An studiu: " ; in >> s.an_studiu;
    delete[] s.facultate;
    s.facultate = new char[20];
    cout << "Facultate: "; in >> s.facultate;
    cout << "Medie: "; in >> s.medie;
    return in;
}
ostream& operator<< (ostream& out, const Student& s) {
    out << (Persoana&) s;
    out << "An studiu: " << s.an_studiu << endl;
    out << "Facultate: " << s.facultate << endl;
    out << "Medie: " << s.medie << endl;
    return out;
}
int main() {
    Student s1(3,"CSIE",9.5,"Popescu Ion",21,"Student");
    Student s2; // aici apeleaza constructorul implicit care trebuie creat
                // de mine deoarece am creat un constructor cu parametrii
                // si compilatorul nu il mai creeaza el singur
    s2 = s1;
    Student s3(s1); // sau Student s3 = s1 face aceeasi chestie
                      // apeleaza constructorul de copiere
    //Persoana p1;
    //cin >> p1;
   // cout << p1;
    Student s4;
    cin >> s4;
    cout << s4;
    cout << "sf main";
}

