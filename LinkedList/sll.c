#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertBegin(int data) {
    struct Node *n = createNode(data);
    n->next = head;
    head = n;
}

void insertEnd(int data) {
    struct Node *n = createNode(data);
    if (!head) {
        head = n;
        return;
    }
    struct Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void insertPos(int data, int pos) {
    if (pos == 1) {
        insertBegin(data);
        return;
    }
    struct Node *n = createNode(data);
    struct Node *t = head;
    for (int i=1; t && i<pos-1; i++) t = t->next;
    if (!t) return;
    n->next = t->next;
    t->next = n;
}

void deleteBegin() {
    if (!head) return;
    struct Node *t = head;
    head = head->next;
    free(t);
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *t = head;
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
}

void deletePos(int pos) {
    if (!head) return;
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node *t = head;
    for (int i=1; t && i<pos-1; i++) t = t->next;
    if (!t || !t->next) return;
    struct Node *d = t->next;
    t->next = d->next;
    free(d);
}

void display() {
    struct Node *t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, data, pos;
    while (1) {
        printf("1.InsertBegin 2.InsertEnd 3.InsertPos 4.DeleteBegin 5.DeleteEnd 6.DeletePos 7.Display 8.Exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1: scanf("%d",&data); insertBegin(data); break;
            case 2: scanf("%d",&data); insertEnd(data); break;
            case 3: scanf("%d%d",&data,&pos); insertPos(data,pos); break;
            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;
            case 6: scanf("%d",&pos); deletePos(pos); break;
            case 7: display(); break;
            case 8: exit(0);
        }
    }
}
