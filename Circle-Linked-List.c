#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    n*next;
};
typedef n node;

void add(node*r,int x){
    
    while(r->next != NULL){
        r=r->next;
    }
    r->next=(node*)malloc(sizeof(node));
    r->next->x=x;
    r->next->next=NULL;
}

void read(node*r){
    
    while(r !=NULL){
        printf("[%d]->\t",r->x);
        r=r->next;
    }
}
void soneleman(node*r){
    node*iter;
    while(r->next ==NULL){     //***********
        r=r->next;
    }
    
}


int main () {
    
    node*root;
    root=(node*)malloc(sizeof(node));
    root->x=10;
    root->next=NULL;
    
    add(root,20);
    add(root,30);
    add(root,40);
    add(root,50);
    
   //  read(root);
    node*iter=root;
   
    
    while(iter->next !=NULL){
        iter=iter->next;
    }
    
//    read(iter); // iter artık sadece son elemana bağlı output=[50]
    
    iter->next=root;
    
    printf("%d",iter->next->x);
    
}
