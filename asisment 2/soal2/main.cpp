#include "mll.h"

int main() {
    listparent l; createlistparent(l);
    
    insertfirstparent(l, alokasinodeparent({"g004", "romance"}));
    insertfirstparent(l, alokasinodeparent({"g003", "horror"}));
    insertfirstparent(l, alokasinodeparent({"g002", "comedy"}));
    insertfirstparent(l, alokasinodeparent({"g001", "action"}));

    insertlastchild(l.first->child, alokasinodechild({"fa001", "the raid", 101, 2011, 7.6}));
    insertlastchild(l.first->next->child, alokasinodechild({"fc001", "agak laen", 119, 2024, 8.0}));
    insertlastchild(l.first->next->child, alokasinodechild({"fc002", "my stupid boss", 108, 2016, 6.8}));
    insertlastchild(l.first->next->next->child, alokasinodechild({"fh001", "pengabdi setan", 107, 2017, 8.4}));
    insertlastchild(l.last->child, alokasinodechild({"fr001", "habibie & ainun", 118, 2012, 7.6}));
    insertlastchild(l.last->child, alokasinodechild({"fr002", "dilan 1990", 110, 2018, 6.6}));

    printstrukturmll(l);

    cout << "\n- cari rating 8.0 - 8.5 -" << endl;
    searchfilmbyratingrange(l, 8.0, 8.5);

    cout << "\n- hapus node g002 -" << endl;
    adr_parent p; deleteafterparent(l, l.first, p); delete p;

    printstrukturmll(l);

    return 0;
}