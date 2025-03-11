#include <stdbool.h>

#ifndef HEADER_H
#define HEADER_H


// Struktur Node untuk antrean (queue)
typedef struct Node{
    int No;
    char *Nama; // Pointer ke string dinamis
    char *Layanan;
    struct Node *next;
} Node;

// Struktur Queue
typedef struct Queue{
    Node *front;
    Node *rear;
    unsigned size;
} Queue;
/* kita butuh dua pointer yang menunjuk ke antrian pertama
dan ke antrian paling belakang*/

// stack untuk pengelolaan riwayat antrian
typedef struct stacknode *StackNodePtr;
typedef struct stacknode
{
    int no;
    char *nama;
    char *layanan;
    StackNodePtr next;
} StackNode;

typedef struct stack
{
    StackNodePtr top;
    unsigned size;
} Stack;

// fungsi untuk menginisialisasti queue
void initQueue(Queue *queue);

//fungsi untuk mengecek apakah queue kosong
bool isEmpty(Queue *queue);

// fungsi untuk inisialisasi stack
void initStack(Stack *stack);

// fungsi untuk mengecek apakah stack kosong
int isEmptyStack(Stack *stack);

// Fungsi untuk menomori ulang seluruh antrean
void renumberQueue(Queue *queue);

//fungsi untuk memasukkan nasabah dalam antrean
bool inQueue(Queue *queue, const char *Nama, const char *Layanan);

// fungsi untuk menambahkan data ke stack riwayat layanan)
bool push(Stack *stack, const char *nama, const char *layanan);

// fungsi untuk memproses nasabah(menghapus dari antrean) dan memindahkannya ke stack
void deQueue(Queue *queue, Stack *stack);

// fungsi untuk menghapus nasabah dari transaksi
void undoTransaksi(Queue *queue, Stack *stack);

//funsi untuk menampilkan riwayat layanan
void tampilkanRiwayat(Stack *stack);

//fungsi menampilkan antrean dalam queue
void tampilkanAntrean(Queue *queue);

// fungsi untuk memvalidasi apakah string hanya terdiri dari huruf dan spasi
bool isValidName(const char *name);

// fungsi untuk memvalidasi  apakah input menu hanya terdiri dari angka
bool isValidNumber(const char *input);

//fungsi untuk  menambah nasabah dengan input dari user
void addNasabah(Queue *queue, Stack *stack);

// fungsi untuk membersihkan antrian
void clearQueue(Queue *queue);

// fungsi untuk membersihkan riwayat layanan
void clearStack(Stack *stack);

//fungsi untuk antar muka program
void menuUser(Queue *queue, Stack *stack);



#endif
