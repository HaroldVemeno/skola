#include <bits/stdc++.h>

using namespace std;

/* Úkoly:
 * 1. clear
 * 2. cons
 * 3. operator<<
 * 4. uncons
 * 5. push
 * 6. pop
 * 7. insert_s
 * 8. remove
 *  */

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

void uncons(Prvek*& p) {
    if(p == nullptr) {
        cout << "uncons: prázdný prvek\n";
    };
    Prvek* pc = p;
    p = p->next;
    delete pc;
}

void clear(Prvek*& p) {
    while(p != nullptr) {
        uncons(p);
    }
}

void push(Prvek*& p, int c) {
    if(p == nullptr) {
        cons(p, c);
        return;
    }
    Prvek* pc = p;
    while(pc->next != nullptr) {
        pc = pc->next;
    }
    pc->next = new Prvek{c, nullptr};
}

void pop(Prvek*& p) {
    if(p == nullptr) {
        cout << "pop: prázdný vstup\n";
    };
    if(p->next == nullptr) {
        delete p;
        p = nullptr;
        return;
    }
    Prvek* pc = p;
    while(pc->next->next != nullptr) {
        pc = pc->next;
    }
    delete pc->next;
    pc->next = nullptr;
}

void insert(Prvek*& p, int c, int i) {
    Prvek* pc = p;
    while(i > 0) {
        if(pc == nullptr) {
            cout << "insert: Moc velký index\n";
            return;
        }
        pc = pc->next;
        i--;
    }
    int cc = pc->val;
    pc->val = c;
    pc->next = new Prvek{cc, pc->next};
}

void insert_s(Prvek*& p, int c) {
    Prvek* pc = p;
    if(p == nullptr || p->val > c) {
        cons(p, c);
        return;
    }
    while(pc->next != nullptr && pc->next->val < c) {
        pc = pc->next;
    }
    pc->next = new Prvek{c, pc->next};
}

void remove(Prvek*& p, int i) {
    Prvek* pc = p;
    if(i == 0) {
        uncons(p);
        return;
    }
    if(p == nullptr) {
        cout << "remove: Moc velký index\n";
        return;
    }
    while(i > 1) {
        if(pc->next == nullptr) {
            cout << "remove: Moc velký index\n";
            return;
        }
        pc = pc->next;
        i--;
    }
    if(pc->next == nullptr) {
        cout << "remove: Moc velký index\n";
        return;
    }
    Prvek* t = pc->next;
    pc->next = pc->next->next;
    delete t;
}

int main() {
    Prvek* p = nullptr;
    cons(p, 22);
    cout << *p;
    cons(p, 2393);
    cout << *p;
    push(p, 10101);
    cout << *p;
    push(p, 1019);
    cout << *p;
    pop(p);
    cout << *p;
    insert(p, 1019101, 2);
    cout << *p;
    insert(p, 292, 1);
    cout << *p;
    insert(p, 2920, 3);
    cout << *p;
    insert(p, 2920, 300);
    cout << *p;
    insert(p, 2920, 0);
    cout << *p;
    clear(p);
    cout << *p;
    insert_s(p, 12);
    cout << *p;
    for(int i = 0; i < 10; i++) {
        push(p, i*2+12);
    }
    cout << *p;
    insert_s(p, 15);
    cout << *p;
    insert_s(p, 0);
    cout << *p;
    insert_s(p, 100);
    cout << *p;
    remove(p, 5);
    cout << *p;
    remove(p, 0);
    cout << *p;
    remove(p, 11);
    cout << *p;
}
