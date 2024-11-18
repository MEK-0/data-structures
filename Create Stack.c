#include <stdio.h>


#define MAX 5

int stack[MAX];
int top = -1;

void ekle(int value){
    if (top == MAX-1) {
        printf("stack dolu \n");
    }else{
        stack[++top]=value;
        printf("%d stack'e eklendi \n",value);
    }
}

int sil(){
    if (top ==-1) {
        printf("stackte bişi yok nasıl silecen :D \n");
        return -1;
    } else{
        int value = stack[top--];
        printf("%d  Stackten çıkarıldı \n",value);
        return value;
    }
}
int StackKontrol(){
    if (top ==-1 ) {
        printf("Stack içinde şuan bir veri yok \n");
       
    } return -1;
}

int oku(){
    if (top == -1) {
        printf("Stackte bişi yok \n");
        return -1;
    }else{
    int value=stack[top];
        printf("%d en üstteki veri \n",value);
        return stack[top];
    }
}

int main(){
    StackKontrol();
    oku();
    ekle(10);
    ekle(20);
    oku();
    StackKontrol();
    sil();
    oku();
    sil();
    oku();
    StackKontrol();
}


/**
 Stack içinde şuan bir veri yok
 Stackte bişi yok
 10 stack'e eklendi
 20 stack'e eklendi
 20 en üstteki veri
 20  Stackten çıkarıldı
 10 en üstteki veri
 10  Stackten çıkarıldı
 Stackte bişi yok
 Stack içinde şuan bir veri yok
 */
