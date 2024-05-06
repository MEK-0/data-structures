#include<stdio.h>
#include<stdlib.h>

struct n {
	int x;
	 n*next;
	 n*prev;
};
typedef n node;

void add(node*r,int x){
	while(r->next !=NULL){
		r=r->next;
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;
	r->next->prev=r;
}

void read(node*r){
	while(r !=NULL){
		printf("%d ",r->x);
		r=r->next;
	}
}

void delete(node*r){
	node*temp=r;
	node*iter=r;
	
	printf("silinecek yapi no :: \n");
	int silici;
	scanf("%d",&silici);
	int counter=1;
	
	while(counter < silici){
		temp=temp->next;
		counter++;
		
	}
	printf("silinecek yapi datasi %d \n",temp->x);
   //	printf("%d",temp->prev->x); 
	iter=temp->prev;
   //	printf("%d",iter->x);
	iter->next=iter->next->next;
	temp->prev=temp->prev->prev;
	free(temp);
}



int main (){
	node*root;
	root=(node*)malloc(sizeof(node));
	root->x=10;
	root->next=NULL;
	root->prev=NULL;
	
	add(root,20);
	add(root,30);
	add(root,40);
	add(root,50);
	
	read(root);
	delete(root);
	printf("\n");
	read(root);
	
	
	
	
	
	
	
	
}
