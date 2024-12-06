#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    int veri;
    struct dugum *sonraki;
};

struct dugum *baslangic = NULL;
struct dugum *bitis = NULL;

void dugumekle(int data)
{
    struct dugum *baglanti = (struct dugum *)malloc(sizeof(struct dugum));
    baglanti->veri = data;
    baglanti->sonraki = baslangic;
    baslangic = baglanti;
    if (bitis == NULL)
    {
        bitis = baslangic;
    }
}

void sonadugumekle(int data)
{
    struct dugum *baglanti = (struct dugum *)malloc(sizeof(struct dugum));
    baglanti->veri = data;
    baglanti->sonraki = NULL;

    if (baslangic == NULL)
    {
        baslangic = baglanti;
        bitis = baglanti;
    }
    else
    {
        bitis->sonraki = baglanti;
        bitis = baglanti;
    }
}

void yazdir()
{
    struct dugum *ptr = baslangic;
    printf("\nBağlı Liste: [");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->veri);
        ptr = ptr->sonraki;
    }
    printf("]\n");
}

void bellegi_goster()
{
    struct dugum *ptr = baslangic;
    printf("\nBellekteki Yapı:\n");
    while (ptr != NULL)
    {
        printf("Düğüm Adresi: %p, Veri: %d, Sonraki: %p\n", 
               (void *)ptr, ptr->veri, (void *)ptr->sonraki);
        ptr = ptr->sonraki;
    }
}

void ilkelemansil()
{
    struct dugum *gecici = baslangic;
    baslangic = gecici->sonraki;
    free(gecici);
}

void sondanelemansil()
{
    struct dugum *ptr = baslangic;
    while (ptr->sonraki->sonraki != NULL)
    {
        ptr = ptr->sonraki;
    }
    free(ptr->sonraki);
    ptr->sonraki = NULL;
    yazdir();
}

struct dugum *arama(int data)
{
    struct dugum *ptr = baslangic;
    if (baslangic == NULL)
    {
        return NULL;
    }
    while (ptr->veri != data)
    {
        if (ptr->sonraki == NULL)
        {
            return NULL;
        }
        else
        {
            ptr = ptr->sonraki;
        }
    }
    return ptr;
}

_Bool bosmu()
{
    return baslangic == NULL;
}

int uzunluk()
{
    int uzunluk = 0;
    struct dugum *ptr;

    for (ptr = baslangic; ptr != NULL; ptr = ptr->sonraki)
    {
        uzunluk++;
    }

    return uzunluk;
}

int main()
{
    bosmu();
    sonadugumekle(1);
    sonadugumekle(4);
    dugumekle(5);
    dugumekle(8);
    dugumekle(9);
    sonadugumekle(3);
    ilkelemansil();
    yazdir();
    bellegi_goster();  // Bellek yapısını gösteren fonksiyon
    printf("Uzunluk: %d\n", uzunluk());
    sondanelemansil();
    sondanelemansil();
    printf("Bağlı Liste!\n");

    struct dugum *bulunan = arama(5);

    if (bulunan != NULL)
    {
        printf("Bulunan eleman: ");
        printf("(%d %p) ", bulunan->veri, (void *)bulunan->sonraki);
        printf("\n");
    }
    else
    {
        printf("Eleman bulunamadı!\n");
    }
    return 0;
}
