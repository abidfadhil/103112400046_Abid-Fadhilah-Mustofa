#include <iostream>
using namespace std;

struct node;

struct edge {
    node* to;
    edge* next;
};

struct node {
    char name;
    bool lockdown;
    bool visited;
    edge* list;
    node* next_node;
};

node* head = NULL;

void tambah_node(char c) {
    node* n = new node;
    n->name = c;
    n->lockdown = false;
    n->visited = false;
    n->list = NULL;
    n->next_node = head;
    head = n;
}

void tambah_edge(char s, char d) {
    node *ns = head, *nd = head;
    while(ns && ns->name != s) ns = ns->next_node;
    while(nd && nd->name != d) nd = nd->next_node;

    if(ns && nd) {
        ns->list = new edge{nd, ns->list};
        nd->list = new edge{ns, nd->list};
    }
}

void jalan(node* n, int &total) {
    if (!n || n->visited || n->lockdown) return;
    n->visited = true;
    total++;
    for (edge* e = n->list; e; e = e->next) {
        jalan(e->to, total);
    }
}

int main() {
    tambah_node('e'); tambah_node('d'); tambah_node('c'); 
    tambah_node('b'); tambah_node('a');

    tambah_edge('a', 'b');
    tambah_edge('b', 'c');
    tambah_edge('b', 'e');
    tambah_edge('c', 'd');

    cout << "membangun jaringan distribusi vasin" << endl;
    for (node* n = head; n; n = n->next_node) {
        cout << "node " << n->name << " terhubung ke: ";
        for (edge* e = n->list; e; e = e->next) cout << e->to->name << " ";
        cout << endl;
    }

    cout << "\nanalisis kota kritis (single point of failure)" << endl;
    for (node* t = head; t; t = t->next_node) {
        for (node* r = head; r; r = r->next_node) r->visited = false;
        
        t->lockdown = true;
        node* s = (t == head) ? head->next_node : head;
        int hasil = 0;
        jalan(s, hasil);

        if (hasil < 4) {
            cout << "(peringatan) kota " << t->name << " adalah kota kritis!" << endl;
            cout << "> jika " << t->name << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "kota " << t->name << " aman (redundansi oke)." << endl;
        }
        t->lockdown = false;
    }

    return 0;
}