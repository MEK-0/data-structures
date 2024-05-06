#include <stdio.h>
#include<stdlib.h>

   //      [*Back | Data | *Next]  formatında 

struct n {
    int x;
    n*next;
    n*back;
};
typedef n node;

void add(node*r,int x){  // bir yapı olmak zorunda
    while(r->next !=NULL){
        r=r->next;
        
    }
    r->next=(node*)malloc(sizeof(node));
    r->next->x=x;
    r->next->back=r;
}

void read(node*r){
    while(r !=NULL){
        printf("[%d] \t",r->x);
        r=r->next;
    }
}


int main () {
    
    node*root;
    
    root=(node*)malloc(sizeof(node));
    root->x=10;
    root->next=NULL;
    root->back=NULL;
    
    add(root,20);
//    read(root);
    printf("%d",root->back->x);
}
