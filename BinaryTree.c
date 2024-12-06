#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* dugumolusturucu(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* AĞAÇ DÜZGÜN OLDUĞU İÇİN sagElemanEkle ve solElemanEkle gibi 2 ayrı fonksiyon kullanmamıza gerek elemanekleme fonksiyonu ile girilen değeri bulunan köke göre kontrol edecek eğer üst düğümdeki değer daha büyükse soluna eklenecek eğer girilen değer eklenen değerden dah büyükse o zaman sağına yazılır ve
    büyüklük onun olur*/

struct Node* elemanekleme(struct Node* root, int data) {
    if (root == NULL) {
        return dugumolusturucu(data);
    }

    if (data < root->data) { // bu kısımda soluna yazdırma
        root->left = elemanekleme(root->left, data);
    } else if (data > root->data) { // bu kısımda sağına yazdırma
        root->right = elemanekleme(root->right, data);
    }

    return root;
}
void solcocuklar(struct Node* root){
   
    
    // Sol çocuğu var ama sağ çocuğu yoksa yazdır
    if (root->left != NULL && root->right == NULL) {
        printf("%d ", root->data);
    }
    
    // Sol ve sağ alt ağaçları dolaş
    solcocuklar(root->left);
    solcocuklar(root->right);
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
struct Node* kucukelemanbulucu(struct Node* root) {
   
    while (root->left != NULL) {
        root = root->left;
    }
    printf("ağaçtaki en küçük eleman %d",root->data);
    return root;
}

int main() {
    struct Node* root = NULL;
    
    int veri;
    printf("kök için veri giriniz \n");
    scanf("%d",&veri); // bu kısmı yapma sebebim ilk değer kök while döngüsü dışında yazılacak
    root = elemanekleme(root, veri); // ana kök tanırız burada
    printf("%d değeri Ağaca eklendi \n",veri);
    while(true){
        scanf("%d",&veri);
        if(veri ==0){
            printf("Ağaç sonlandı \n");
            break;
        }else{
            elemanekleme(root, veri);
            printf("%d değeri Ağaca eklendi \n",veri);
        }
        
    }
    
    printf("Eklenen ağacın inorder ile yazdırılması \t \n");
    inorderTraversal(root);
    
    printf("Eklenen ağacın preorder ile yazdırılması \t \n");
    preorderTraversal(root);
    
    printf("Eklenen ağacın postorder ile yazdırılması \t \n");
    postorderTraversal(root);
    printf("\n");
    
    kucukelemanbulucu(root);
    solcocuklar(root);
    
    return 0;
}


