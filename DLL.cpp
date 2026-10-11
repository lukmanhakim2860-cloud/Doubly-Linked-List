#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

void cetakMaju(Node* head) {
    Node* temp = head;
    cout << "Forward:\n";
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << endl;
}

void cetakMundur(Node* tail) {
    Node* temp = tail;
    cout << "Backward:\n";
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* a = new Node{"Song A", NULL, NULL};
    Node* b = new Node{"Song B", NULL, NULL};
    Node* c = new Node{"Song C", NULL, NULL};
    Node* d = new Node{"Song D", NULL, NULL};
    Node* e = new Node{"Song E", NULL, NULL};

    a->next = b; 
    b->prev = a; b->next = c;
    c->prev = b; c->next = d;
    d->prev = c; d->next = e;
    e->prev = d;

    Node* head = a;
    Node* tail = e;

    cetakMaju(head);
    cetakMundur(tail);

    Node* x = new Node{"Song X", NULL, NULL};
    b->next = x;
    x->prev = b;
    x->next = c;
    c->prev = x;

    cetakMaju(head);
    cetakMundur(tail);

    x->next = d;
    d->prev = x;
    delete c;

    cetakMaju(head);
    cetakMundur(tail);

    return 0;
}
