#ifndef mll_h
#define mll_h
#include <iostream>
#include <string>
using namespace std;

struct film { string idfilm, judulfilm; int durasifilm, tahuntayang; float ratingfilm; };
struct genre { string idgenre, namagenre; };

typedef struct elmf_child *adr_child;
struct elmf_child {
    film info;
    adr_child next, prev;
};

struct listchild { adr_child first, last; };

typedef struct elmg_parent *adr_parent;
struct elmg_parent {
    genre info;
    listchild child;
    adr_parent next, prev;
};

struct listparent { adr_parent first, last; };

void createlistparent(listparent &l);
adr_parent alokasinodeparent(genre data);
adr_child alokasinodechild(film data);
void insertfirstparent(listparent &l, adr_parent p);
void insertlastchild(listchild &l, adr_child c);
void deleteafterparent(listparent &l, adr_parent prec, adr_parent &p);
void hapuslistchild(listchild &l);
void printstrukturmll(listparent l);
void searchfilmbyratingrange(listparent l, float min, float max);

#endif