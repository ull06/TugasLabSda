#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// logika program
int main(){
    Queue queueu;
    Stack stack;

    initQueue(&queueu); //inisialisasi queue

    initStack(&stack); //inisialisasi stack

    //
    printf("\n||=====================================||\n");
    printf("||     SELAMAT DATANG DI BANK KAMI!    ||\n");
    printf("|| ====================================||\n");
    printf("|| Nikmati layanan cepat dan nyaman.   ||\n");
    printf("|| Silakan ambil antrean dan tunggu    ||\n");
    printf("|| panggilan sesuai layanan Anda.      ||\n");
    printf("|| ====================================||\n\n");

    menuUser(&queueu, &stack);

    printf("\n||=========================================||\n");
    printf("||      TERIMA KASIH TELAH BERKUNJUNG!     ||\n");
    printf("||=========================================||\n");
    printf("||  Semoga layanan kami bermanfaat.        ||\n");
    printf("||  Sampai jumpa di kunjungan berikutnya!  ||\n");
    printf("||=========================================||\n\n");

    clearQueue(&queueu);

    clearStack(&stack);

    return 0;
}
