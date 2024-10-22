#include<stdio.h>
#include<stdlib.h>

struct n{
	int x;
	
	n*next;
};

typedef n node;


void read(node*r){
	while(r !=NULL){
	
	   printf("%d \n",r->x);
	
		r=r->next;
	}

}

void add(node * r,int x){
	
	while(r->next !=NULL){
		r=r->next;
	}
    r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;
}


int main(){

	node*root;
	
	root=(node*)malloc(sizeof(node));
	root->x=100;
	root->next=(node*)malloc(sizeof(node));
	root->next=NULL;
	int i=0;
	
	
	
	for(i=0;i<5;i++){
		
		add(root,i*10);
	
		
	}
	// (100)-(0)-(10)-*(20)-(30)-(40)
    // (100)-(0)-(10)-(50)-(20)-(30)-(40)***
	
	node *iter;
	
	iter=root;
	
	
	for(i=0;i<3;i++){
		iter=iter->next;
		
	}
	
	node*temp;
	
	temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=50;
	
	read(root);
	
	

   
	 	

}
