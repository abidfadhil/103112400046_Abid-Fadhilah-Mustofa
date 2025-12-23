#include "mll.h"

void createlistparent(listparent &l) { l.first = l.last = NULL; }

adr_parent alokasinodeparent(genre data) {
    adr_parent p = new elmg_parent;
    p->info = data; p->next = p->prev = NULL;
    p->child.first = p->child.last = NULL;
    return p;
}

adr_child alokasinodechild(film data) {
    adr_child c = new elmf_child;
    c->info = data; c->next = c->prev = NULL;
    return c;
}

void insertfirstparent(listparent &l, adr_parent p) {
    if (l.first == NULL) l.first = l.last = p;
    else { p->next = l.first; l.first->prev = p; l.first = p; }
}

void insertlastchild(listchild &l, adr_child c) {
    if (l.first == NULL) l.first = l.last = c;
    else { c->prev = l.last; l.last->next = c; l.last = c; }
}

void hapuslistchild(listchild &l) {
    adr_child c = l.first;
    while (c) { adr_child temp = c; c = c->next; delete temp; }
    l.first = l.last = NULL;
}

void deleteafterparent(listparent &l, adr_parent prec, adr_parent &p) {
    p = prec->next;
    if (p) {
        hapuslistchild(p->child);
        prec->next = p->next;
        if (p->next) p->next->prev = prec; else l.last = prec;
    }
}

void printstrukturmll(listparent l) {
    adr_parent p = l.first; int i = 1;
    while (p) {
        cout << "-- parent " << i++ << " --\nid genre : " << p->info.idgenre << "\nnama genre : " << p->info.namagenre << endl;
        adr_child c = p->child.first; int j = 1;
        while (c) {
            cout << "  - child " << j++ << " :\n    id film : " << c->info.idfilm << "\n    judul film : " << c->info.judulfilm << "\n    rating : " << c->info.ratingfilm << endl;
            c = c->next;
        }
        p = p->next;
    }
}

void searchfilmbyratingrange(listparent l, float min, float max) {
    adr_parent p = l.first;
    while (p) {
        adr_child c = p->child.first;
        while (c) {
            if (c->info.ratingfilm >= min && c->info.ratingfilm <= max)
                cout << "ditemukan: " << c->info.judulfilm << " (" << p->info.namagenre << ") rating: " << c->info.ratingfilm << endl;
            c = c->next;
        }
        p = p->next;
    }
}