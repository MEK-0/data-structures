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
void read(node*r){
    while (r != NULL) {
        printf("[%d] ",r->x);             // read adlı bu fonksiyonda normal linked list bağlantılarında  sorunsuz çalışıyor lakin dairesel yapılı listlerde root un next pointer i
                                          // hiç bir zaman NULL değerini düşmez çünkü son eleman her zaman ilk elemana bağlanır .... dairesel linked listte read2 fonksiyonu kullanılabilir    
        r=r->next;
    }
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



int main(){
    
    node*root;
    root=(node*)malloc(sizeof(node));
    root->x=10;
    root->next=NULL;
    
    add(root, 20);
    add(root, 30);
    
    
  //  read(root);
    node*iter=root;
    
    while(iter->next !=NULL){
        iter=iter->next;
        
    }
   // printf("%d",iter->x);
    
    iter->next=root;
    
//    printf("%d",iter->next->x);
    
    read2(root);
   
    
}
