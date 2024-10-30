#include <stdio.h>
#include <stdlib.h>
// 233301076 M.Esat.kolay nö

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//  main de ilk ptr null değeri gösteriyor bu fonksiyon ilk node u oluşturmak için
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void grup(Node* head) {
    Node* current = head;

    while (current != NULL) { // node varlığını sorgulama
        Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Aynı değere sahip düğüm varsa ve son olan o olacağı için son node u sileriz
                Node* temp = runner->next;
                runner->next = runner->next->next; // bu kısımda next->next gitme sebebimiz free yaptığımızda diğer node ları kaybetmemek için
                free(temp);  // temp ptr aynı dataya sahip olan son node u tutuyordu onu siliyoruz
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Bağlı listeye düğüm ekleme
void add(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {   // düğüm olmama durumunu kontrol ediyoruz
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {// ekleyeceğimiz düğüm son düğüm olacağı için next i null sa yani son node demektir
        temp = temp->next;
    }
    temp->next = newNode;
}

// Bağlı listeyi yazdırma
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {  // node olduğu sürece çalışır ve içindeki data yı yazdırır
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;  // ptr oluşturma
    char ogr_no[20];  // ogr noyu karakter olarak alıp for döngüsü ile teker teker int e çevirecez

    printf("Öğrenci numaranızı girin: ");
    scanf("%s", ogr_no);


    for (int i = 0; ogr_no[i] != '\0'; i++) {
        int sayac = ogr_no[i] - '0'; // Karakteri sayıya çevirme kısmıı
        add(&head, sayac);
    }

    printf("ilk hali \n");
    printList(head);
    grup(head);
    printf("Gruplama sonrası \n");
    printList(head);
    printf("\n");
    printf("kodu xcode da yazdım  22-24-29-41-49-55-70-72-77 breaking point noktaları \n");
    return 0;
}
