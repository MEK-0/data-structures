#include <stdlib.h>
#include <stdio.h>

struct n{
    int x;
    n*next;
};
typedef n node;

void add(node*r,int x){
    while(r->next !=NULL){
        r=r->next;
    }
    r->next=(node*)malloc(sizeof(node));
    r->next->x=x;
    r->next->next=NULL;
}


void read2(node*r){
    node*temp=r;
    
    printf(" %d",r->x);
    r=r->next;
    
    while (r !=temp) {
        printf(" %d ",r->x);
        r=r->next;
    }
}
void lastadd(node*r,int x){
    node*laststruct=r;
    laststruct=laststruct->next;
    
    while (laststruct->next !=r) {
        laststruct=laststruct->next;
    }
    laststruct->next=(node*)malloc(sizeof(node));
    laststruct->next->x=x;
    laststruct->next->next=r;
    printf("ekleme başarılı \n");
}



int main(){
    
    node*root;
    root=(node*)malloc(sizeof(node));
    root->x=10;
    root->next=NULL;
    
    add(root, 20);
    add(root, 30);
    node*iter=root;
    while(iter->next !=NULL){
        iter=iter->next;
    }
    iter->next=root;
    
    // dairesel link listte eleman ekleme
    
    lastadd(root, 40);
    
    read2(root);
    
    
   
    
}
