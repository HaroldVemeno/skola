#include <bits/stdc++.h>

using namespace std;

struct Prvek {
    int val;
    Prvek* next;
};

ostream& operator<< (ostream& o, Prvek& a) {
    o << "[";
    Prvek* p = &a;
    if (p != nullptr) {
        o << p->val;
        p = p->next;
    }
    while (p != nullptr) {
        o << ", " << p->val;
        p = p->next;
    }
    o << "]\n";
    return o;
}

void cons(Prvek*& p, int c) {
    p = new Prvek{c, p};
}

int uncons(Prvek*& p) {
    if(p == nullptr) {
        cout << "uncons: prázdný prvek\n";
    };
    int r = p->val;
    Prvek* pc = p;
    p = p->next;
    delete pc;
    return r;
}

int main() {
    Prvek* p = nullptr;
    int b = 0;
    bool bb = false;

    while(cin.good() && !cin.eof()) {
        char c = cin.get();
        if('0' <= c && c <= '9') {
            b = b * 10 + (c - '0');
            bb = true;
        } else {
            if(bb) {
                cons(p, b);
                b = 0;
                bb = false;
            }
            //cout << *p;
            if(c == '+') {
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor +\n";
                    continue;
                }
                int a = uncons(p);
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor +\n";
                    continue;
                }
                p->val += a;
            } else if(c == '-') {
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor -\n";
                    continue;
                }
                int a = uncons(p);
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor -\n";
                    continue;
                }
                p->val -= a;
            } else if(c == '*') {
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor *\n";
                    continue;
                }
                int a = uncons(p);
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor *\n";
                    continue;
                }
                p->val *= a;
            } else if(c == '/') {
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor /\n";
                    continue;
                }
                int a = uncons(p);
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor /\n";
                    continue;
                }
                p->val /= a;
            } else if(c == '=') {
                if(p == nullptr) {
                    cout << "main: Málo čísel na operátor =\n";
                    continue;
                }
                cout << p->val << "\n";
                break;
            }

        }
    }

    // cout << *p;
    // cout << p->val << '\n';

    return 0;
}
