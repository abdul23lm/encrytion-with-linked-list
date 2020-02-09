//TUGAS UAS PRAKTIKUM
//NAMA : ABDUL LATIF MUNJIAT
//NPM  : 1610631170004
//KELAS 3'A FASILKOM UNSIKA

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {              // Definisi struct untuk kasus double linked list
char data;
struct node *prev;
struct node *next;
};
typedef struct node node;  // memberi nama alias untuk struct node
node *head, *tail;         // deklarasi pointer head dan tail bertipe node

void append_node (node *temp) // Fungsi menambahkan node dalam linked list
{
if(head==NULL){
temp->prev=NULL;
head=temp;
} else
{
tail->next=temp;
temp->prev=tail;
}
temp->next=NULL;
tail=temp;
}

void tranverse(node *head) // Fungsi untuk menampilkan semua data dalam linked list
{
node *pWalker;
pWalker=head;
while(pWalker != NULL)
{
printf("%c", pWalker->data);
if(pWalker->next!=NULL)
printf("->");
pWalker=pWalker->next;
}
printf("\n");
}

void enkripsi(node *key)        // Fungsi untuk melakukan enkripsi data
{
node *pWalker1, *pWalker2;

pWalker1= tail;
int i=1;
while(i<=3)
{
pWalker1= pWalker1->prev;
i++;
}

pWalker2= pWalker1->next;
tail->next= key;
key->prev= tail;

key->next=head;
head->prev=key;

head=pWalker1->next;
head->prev=NULL;

pWalker1->next=tail;
pWalker1->next=NULL;
}

void deleteList(node *head) // Fungsi untuk menghapus linked list dari memori
{
node *pTemp;
while(head!=NULL)
{
pTemp=head;
head=head->next;
free(pTemp);
}
}

int main()  {     // Fungsi utama
printf("*======================================Tugas UAS Praktikum======================================*\n");
   printf(" Struktur Data & Pemrograman\n");
   printf(" Nomor 2 - Membuat Program Linked List Untuk Studi Kasus Enkripsi Password\n");
   printf(" Created By Abdul Latif Munjiat (1610631170004)\n");
   printf(" Kelas 3'A Fasilkom Unsika\n\n");
node *temp;  // Variable untuk menyimpan alokasi memori dinamis
node *key;   // Variable untuk meyimpan karakter kunci enkripsi
key=(node *)malloc(sizeof(node));
key->data='@'; // Karakter kunci enkripsi
for (int i=0; i<=5; i++){  // Perulangan untuk memasukkan password
temp=(node *) malloc (sizeof (node)); // Alokasi memori dinamis
printf("Masukkan Karakter Ke %d : ", i+1); scanf("%c", &temp->data);
append_node(temp); // Memanggil Fungsi append_node
fflush(stdin);
}
printf("\n\tData Sebelum Di Enkripsi : ");
tranverse(head);    // Memanggil Fungsi tranverse
enkripsi(key);  // Memanggil Fungsi untuk enkripsi data
printf("\tData Sesudah Di Enkripsi : ");
tranverse(head);    // Memanggil Fungsi tranverse
deleteList(head);  // Memanggil Fungsi deleteList
getch();
return 1;
}
