#include <stdio.h>
#include <stdlib.h>

//NODE
struct node
{
    int data;
    struct node *next;
};

//HEAD VE TAIL
struct node *head = NULL;
struct node *tail = NULL;


int insert_node_end(int data)
{
    if(head == NULL)    //ADD AS FIRST ELEMENT IF LINKED LIST EMPTY
    {
        struct node *new = (struct node *) malloc(sizeof(struct node)); //OPEN SPACE FOR NODE
        new->data = data;   //PASTE DATA
        new->next = NULL;   //CREATE NULL TAIL

        head = tail = new;
        return 0;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    tail->next = new;   //MEVCUT SON ELEMANIN TAIL'INA YENI ELEMANI ISARET ETTIR

    tail = new;     //TAIL'i GUNCELLE
}

int insert_node_head(int data)
{
    if(head == NULL)    // IF LİNKED LIST IS EMPTY
    {
        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        head = tail = new;
        return 0;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = data;
    new->next = head;

    head = new;     //HEAD'ın POZİSYONUNU EKLEDİĞİMİZ DATA OLARAK GÜNCELLE Kİ EKLENEN DATA BAŞA EKLENSİN
}

int print_linked_list()
{
    struct node *iterator = head;   //ITERATORE HEADİ POİNT ETTİR
    while (iterator != NULL)     //ITERATORUN POİNT ETTİGİ NODE NULL OLANA KADAR DÖN
    {
        printf("%d\n", iterator->data);
        iterator = iterator->next;  //SU AN POINT EDİLEN YERİN POINT ETTIĞI YERI POINT ETMEYE BASLA
    }
}

int delete_node(int data)
{
    struct node *before = NULL;
    struct node *current = head;

    if(head == NULL){   //LINKED LIST BOSSA FONKSİYONU KAPAT
        return 0;
    }

    if(head -> data == data)    //SILMEK ISTEDIGIMIZ ELEMAN HEAD İSE
    {
        struct node *temp = head;
        head = head->next;      //HEADI BİR İLERİ TASI
        free(temp);

        return 0;
    }

    while (current != NULL && current->data != data){   //SONA GELENE KADAR YA DA ARANAN ELEMAN BULUNANA KADAR DÖN
        before = current;
        current = current->next;
    }

    if (current == NULL)    //ARANAN ARKADAS BULUNAMADIYSA FONKSIYONU KAPAT
    {
        return -1;
    }

    before->next = current->next;   //ARADAN KOPAN ARKADASI ISARET EDEN POINTERI KOPAN ARKADASIN ISARET ETTIGI NODE'a BAGLA

    if(tail->data == data){     //EGER SILDIĞIMIZ ARKADAS SON ELEMAN ISE TAIL ARKADASI GUNCELLE
        tail = before;
    }

    free(current);
    return 0;

}



int main() {
    insert_node_end(32);
    insert_node_end(31);
    insert_node_end(3111);
    insert_node_head(1);

    print_linked_list();
    return 0;
}
