#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

int isEmpty(Node *head){
    if(head==NULL) return 1;
    else return 0;
}
Node *insertStart(Node *head,int data){
    Node* new = (Node*) malloc(sizeof(Node));
    new->data=data;
    new->link=NULL;
    if(head==NULL) return new;
    else{
        new->link=head;
        return new;
    }
}
Node *deleteForValue(Node *head,int value){
    Node *start=head;

    while(start->link!=NULL){
        if(start->data==value) {
            Node *aux=start;
            start = start->link;
            head=start;
            free(aux);
        }
        else if(start->link->data==value) {
            Node *aux=start->link;
            start->link=aux->link;
            free(aux);
        }
        start=start->link;
    }
    return head;
}
void modify(Node *head){
    if(isEmpty(head)) {
        printf("\nList is empty");

    }
    else {
        int found;
        Node *next=head;
        printf("\nIntroduceti valoarea nodului pe care doriti sa il modificati:");
        scanf("%d", &found);
        while(next!=NULL){
            if(next->data==found){
                printf("\nIntroduceti valoarea noua a nodului: ");
                scanf("%d",&found);
                next->data=found;
                found=-1;
            }
            next=next->link;
        }
        if(found!=-1) printf("\nNu a fost gasit nod cu asa valore!");
        else printf("\nValoarea a fost modificata cu succes");
    }

}
void print(Node *head){
    if(isEmpty(head)) printf("\nList is empty");
    else {
        Node *next = head;
        int i = 1;
        while (next != NULL) {
            printf("\nNod %d: data=%d", i++, next->data);
            next = next->link;
        }
        printf("\n\n");
    }
}
int main() {
    Node *head= insertStart(head,3);
    head= insertStart(head,2);
    head= insertStart(head,1);
    print(head);
    head= deleteForValue(head,1);
    print(head);
    modify(head);
    print(head);

    getch();
    return 0;
}
