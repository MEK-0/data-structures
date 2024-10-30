#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef int YiginVeriTipi;

typedef struct Dugum {
    YiginVeriTipi veri;
    struct Dugum *sonraki;
} Dugum;

typedef struct Yigin {
    Dugum *bas;
} Yigin;

void ekle(Yigin *yigin, YiginVeriTipi yeni);
YiginVeriTipi cikar(Yigin *yigin);
int bosmu(Yigin *yigin);
void listele(Yigin *yigin);
void enust(Yigin *yigin);

void ekle(Yigin *yigin, YiginVeriTipi yeni) {
    Dugum *yenidugum = (Dugum*)malloc(sizeof(Dugum));
    yenidugum->veri = yeni;
    yenidugum->sonraki = yigin->bas;
    yigin->bas = yenidugum;
    printf("%d yığına eklendi\n", yeni);
}

YiginVeriTipi cikar(Yigin *yigin) {
    if (bosmu(yigin)) {
        printf("Yığın yetersiz\n");
        return -1;
    }
    Dugum *ustdugum = yigin->bas;
    YiginVeriTipi gecici = ustdugum->veri;
    yigin->bas = yigin->bas->sonraki;
    free(ustdugum);
    return gecici;
}

int bosmu(Yigin *yigin) {
    return yigin->bas == NULL;
}

void listele(Yigin *yigin) {
    Dugum *p = yigin->bas;
    while (p) {
        printf("%d\n", p->veri);
        p = p->sonraki;
    }
}

void enust(Yigin *yigin) {
    if (bosmu(yigin)) {
        printf("Yığın boş\n");
    } else {
        printf("Yığının en üstündeki eleman: %d\n", yigin->bas->veri);
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");
    Yigin yigin;
    yigin.bas = NULL;
    int secim, yigin_elemani;
    while (1) {
        printf("Yığın İşlemi (Linked List)\n");
        printf("[1] Push(Ekle) işlemi\n");
        printf("[2] Pop(Çıkar) işlemi\n");
        printf("[3] Yığında En üstteki eleman işlemi\n");
        printf("[4] Yığın Gezme İşlemi\n");
        printf("[5] Cıkış\n");
        printf("Seçiminiz : ");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("Bir Sayı giriniz : ");
                scanf("%d", &yigin_elemani);
                ekle(&yigin, yigin_elemani);
                break;
            case 2:
                yigin_elemani = cikar(&yigin);
                if (yigin_elemani != -1) {
                    printf("Yığındaki son eleman: %d\n", yigin_elemani);
                }
                break;
            case 3:
                enust(&yigin);
                break;
            case 4:
                listele(&yigin);
                break;
            case 5:
                return 0;
            default:
                printf("Lütfen doğru bir seçim girin : ");
        }
    }
    return 0;
}

