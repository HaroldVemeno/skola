#include <bits/stdc++.h>

using namespace std;

class TPole {
protected:
    int kapacita;
    int pocet;
    int *pole;
public:
    TPole(int n = 100);
    ~TPole();
    virtual bool vloz(int cislo);
    int dej(int index);
    void tiskni();
    int dejPocet();
    bool zrus(int index);
    int& operator[](int index);
    friend ostream& operator <<(ostream& o, const TPole& a);
    void nactiZeSouboru(const char* file);
};

void TPole::nactiZeSouboru(const char* file) {
    ifstream i{file};
    while(!i.bad()) {
        int k; cin >> k;
        vloz(k);
    }

}

bool TPole::zrus(int index) {
    if(index >= pocet) return false;
    --pocet;
    for(int i = index; i < pocet; ++i) {
        pole[i] = pole[i+1];
    }
    return true;
}

int TPole::dejPocet() {
    return pocet;
}

TPole::TPole(int n): kapacita{n}, pocet{0}, pole{new int[n]} {}

bool TPole::vloz(int cislo) {
    if(pocet == kapacita) {
        return false;
    } else {
        pole[pocet++] = cislo;
        return true;
    }
}

TPole::~TPole() {
    delete[] pole;
}

int TPole::dej(int index) {
    return pole[index];
}
void TPole::tiskni() {cout << *this;};
int& TPole::operator[](int index) {return pole[index];};

ostream& operator<<(ostream& o, const TPole& a) {
    o << '[';
    for(int i = 0; i < a.pocet; ++i) {
        if(i == 0) {
            o << a.pole[i];
        } else {
            o << ", " << a.pole[i];
        }
    }
    o << ']';
    return o;
}

class TSetridenePole : public TPole {
public:
    TSetridenePole(int n);
    bool vloz(int cislo) override;
};

bool TSetridenePole::vloz(int cislo) {
    if(pocet == kapacita) {
        return false;
    } else {
        int b = 0, t = pocet, m = 0;
        while(t > b) {
            int m = (b + t) / 2;
            if(pole[m] == cislo) {
                b = m;
                break;
            };
            if(pole[m] < cislo) {
                t = m;
            } else {
                b = m;
            }

            for(int i = pocet++; i > m; ++i) {
                pole[i] = pole[i-1];
            }
            pole[m] = cislo;
        }
        return true;
    }
}

TSetridenePole::TSetridenePole(int n): TPole(n) {};

int main() {
    TSetridenePole p(101);
    cout << p << '\n';
    p.vloz(2345);
    p.vloz(2);
    p.vloz(245);
    p.vloz(0);
    p.vloz(25);
    p.zrus(2);
    cout << p << '\n';
    return 0;
}
