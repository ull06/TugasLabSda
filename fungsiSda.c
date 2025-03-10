


















// fungsi untuk menghapus nasabah dari transaksi
void undoTransaksi(Queue *queue, Stack *stack){
    if (isEmptyStack(stack)){
        printf("Tidak ada transaksi untuk dibatalkan!\n");
        return;
    }

    //ambil transaksi terakhir dari stack
    StackNode *temp = stack->top;
    stack->top = stack->top->next;
    stack->size--;

    // Buat node baru untuk dimasukkan ke depan antrean
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Error: Gagal mengalokasikan memori!\n");
        free(temp->nama);
        free(temp->layanan);
        free(temp);
        return;
    }

    // Salin data nasabah
    newNode->Nama = strdup(temp->nama);
    newNode->Layanan = strdup(temp->layanan);

    //pengecekan apakah strdup berhasil
    if(!newNode->Nama || !newNode->Layanan){
        printf("Error: Gagal mengalokasikan memori");
        free(newNode->Nama);
        free(newNode->Layanan);
        free(newNode);
        free(temp->nama);
        free(temp->layanan);
        free(temp);
        return;
    }
    newNode->No = 1;              // Akan diperbarui setelah renumbering
    newNode->next = queue->front; // Hubungkan dengan antrean

    // Update front queue
    queue->front = newNode;

    // Jika antrean sebelumnya kosong, rear juga harus menunjuk ke node baru
    if (queue->rear == NULL){
        queue->rear = newNode;
    }

    queue->size++;

    //mengecek apakah node benar benar ditambahkan
    if(queue->front != newNode){
        printf("Error: Gagal memasukkan ke antrean!\n");
        return;
    }

    // Perbarui nomor antrean agar tetap berurutan
    renumberQueue(queue);

    printf("Transaksi terakhir: %s - %s\n", temp->nama, temp->layanan);
    printf("Transaksi dibatalkan. Nasabah dikembalikan ke antrean paling depan.\n");

    free(temp->nama);
    free(temp->layanan);
    free(temp);
}

// fungsi untuk menampilkan riwayat layanan
void tampilkanRiwayat(Stack *stack){
    
    printf("\n=============================   DAFTAR RIWAYAT NASABAH   ===========================\n");
    printf("| %-4s | %-50s | %-20s |\n", "No", "Nama""", "Layanan");
    printf("====================================================================================\n");

    if (isEmptyStack(stack)){

        char no[] = "-";
        char nama[] = "Riwayat Kosong";
        char layanan[] = "-";

        //tampilkan pesan riwayat kosong dalam tabel
        printf("| %-4s | %-50s | %-20s |\n", no, nama, layanan);
        printf("====================================================================================\n");
        printf("Total nasabah dalam riwayat: 0\n");
        return;
    }

    // Membuat stack sementara untuk membalikkan urutan
    Stack tempStack;
    initStack(&tempStack);

    // Memindahkan semua elemen dari stack asli ke tempStack
    while (!isEmptyStack(stack)){
        StackNode *temp = stack->top;
        stack->top = stack->top->next;
        stack->size--;

        // Push ke tempStack
        temp->next = tempStack.top;
        tempStack.top = temp;
        tempStack.size++;
    }

    StackNode *current = tempStack.top;
    while (current != NULL){
        printf("| %-4d | %-50s | %-20s |\n", current->no, current->nama, current->layanan);
        current = current->next;
        }

    printf("====================================================================================\n");
    printf("Total Nasabah Dalam Riwayat: %d\n", tempStack.size);

    // Kembalikan elemen ke stack asli (opsional, jika stack asli perlu dipertahankan)
    while (!isEmptyStack(&tempStack)){
        StackNode *temp = tempStack.top;
        tempStack.top = tempStack.top->next;
        tempStack.size--;

        // Push elemen tersebut kembali ke stack asli
        temp->next = stack->top; //hubungkan elemen ke stak asli
        stack->top = temp; //perbaharui stack top asli
        stack->size++; //tambahkan ukuran stack asli
    }
}

// fungsi untuk menampilkan antrean dalam queue
void tampilkanAntrean(Queue *queue){

    printf("===============================   DAFTAR ANTREAN NASABAH   =========================\n");
    printf("| %-4s | %-50s | %-20s |\n", "No", "Nama", "Layanan");
    printf("====================================================================================\n");

    if (isEmpty(queue)){
        char no[] = "-";
        char nama[] = "Antrian Kosong";
        char layanan[] = "-";

        printf("| %-4s | %-50s | %-20s |\n",no, nama, layanan);
        printf("====================================================================================\n");

        printf("Total nasabah dalam antrean: 0\n");
        return;
    }else{

   
    // mulai traversal dari depan(front)
    Node *current = queue->front;
    // printf("FRONT ");
    while (current != NULL){
        printf("| %-4d | %-50s | %-20s |\n", current->No, current->Nama, current->Layanan);
        current = current->next; // pindah ke node brikutnya
        }
    }

    printf("====================================================================================\n");
    printf("Total Nasabah Dalam Antrean: %d\n", queue->size);

    
}

// fungsi untuk memvalidasi apakah string hanya terdiri dari huruf dan spasi
bool isValidName(const char *name){
    for (int i = 0; name[i] != '\0'; i++){
        if (!isalpha(name[i]) && name[i] != ' '){
            return false;
        }
    }
    return true;
}

// fungsi untuk memvalidasi apakah input menu hanya terdiri dari angka
bool isValidNumber(const char *input){
    for (int i = 0; input[i] != '\0'; i++){
        if (!isdigit(input[i])){
            return false;
        }
    }
    return true;
}

// fungsi untuk menambah nasabah dengan input dari user
void addNasabah(Queue *queue, Stack *stack){
    char nama[50], layanan[20];
    int choise;
    char input[10]; // menyimpan input user

    while (1){
        printf("\nMasukkan nama nasabah (Ketik 'exit' untuk kembali ke menu utama): ");
        scanf(" %49[^\n]", nama); // Maksimal 49 karakter + 1 null terminator
        //while (getchar() != '\n');// Membersihkan karakter sisa setelah input

        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Bersihkan buffer input setelah scanf

        // cek user ingin kembali ke menu utama
        if (strcmp(nama, "exit") == 0){
            printf("Kembali ke menu utama..\n");
            return; //kembali ke menu utama
        }

        // validasi input nama
        if (isValidName(nama)){
            break;
        }else{
            printf("Nama tidak valid! hanya boleh mengandung huruf dan spasi!\n");
        }
    }
    // menampilkan pilihan layanan
    while (1){ // loop hingga input valid
        printf("\nPilih jenis layanan:\n");
        printf("1. Setor Tunai\n");
        printf("2. Tarik Tunai\n");
        printf("3. Pembukaan rekening\n");
        printf("Ketik 'exit' untuk kembali ke menu utama!\n");
        printf("Pilihan (1-3): ");
        

        scanf("%s", input);
        while (getchar() != '\n');// Bersihkan buffer setelah input

        // cek user ingin kembali ke menu utama
        if (strcmp(input, "exit") == 0){
            printf("Kembali ke menu utama.\n");
            return;
        }

        // validasi apakah input adalah angka
        if (!isValidNumber(input)){
            printf("Input tidak valid! Masukkan angka 1-3.\n");
            continue;
        }

        // mengkonversi input string ke int
        choise = atoi(input);

        if (choise >= 1 && choise <= 3){
            break;
        }else{
            printf("Pilihan tidak valid! Masukkan angka 1-3.\n");
        }
    }
    // menentukan jenis layanan berdasarkan input user
    switch (choise){
    case 1:
        strcpy(layanan, "Setor Tunai");
        break;
    case 2:
        strcpy(layanan, "Tarik Tunai");
        break;
    case 3:
        strcpy(layanan, "Pembukaan Rekening");
        break;
    default:
        printf("Pilihan anda tidak valid! Harap input (1-3)\n");
        break;
    }

    // masukkan nasabah ke antrean;
    if (inQueue(queue, nama, layanan)){

        printf("\nNasabah \"%s\" berhasil ditambahkan ke antrean dengan layanan \"%s\"\n\n", nama, layanan);
    }else{
        printf("\nGagal menambahkan nasabah ke antrean.\n\n");
    }
}

// fungsi untuk membersihkan antrian
void clearQueue(Queue *queue){
    while (!isEmpty(queue)){
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp->Nama); //bebaskan string
        free(temp->Layanan);
        free(temp); //bebaskan node
    }
}

// fungsi untuk membersihkan riwayat layanan
void clearStack(Stack *stack){
    while (!isEmptyStack(stack)){
        // StackNode *temp = pop(stack);
        StackNode *temp = stack->top;
        stack->top = stack->top->next;
        // free(temp->no);
        free(temp->nama);
        free(temp->layanan);
        free(temp);
    }
}

// fungsi untuk antar muka program dengan user
void menuUser(Queue *queue, Stack *stack){
    int choice;
    char input[10]; // menyimpan input user
    do{
        printf("\n+-------------------------------------------+\n");
        printf("|             SISTEM ANTREAN BANK           |\n");
        printf("+-------------------------------------------+\n");
        printf("| 1. Tambahkan Nasabah Ke Antrian           |\n");
        printf("| 2. Proses Nasabah                         |\n");
        printf("| 3. Tampilkan Antrean Saat Ini             |\n");
        printf("| 4. Tampilkan Riwayat Layanan              |\n");
        printf("| 5. Batalkan Transaksi Terakhir (Undo)     |\n");
        printf("| 6. Keluar                                 |\n");
        printf("+-------------------------------------------+\n");
        printf("Pilihan anda: ");

        if (scanf("%s", input) != 1){
            printf("\nInput tidak valid! Masukkan angka.\n");

            while (getchar() != '\n'); // membersihkan buffer
            continue;
        }

        // validasi apakah input adalah angka
        if (!isValidNumber(input)){
            printf("Input tidak valid! Masukkan angka 1-3.\n");
            while (getchar() != '\n'); // Membersihkan buffer
            continue;
        }

        // mengkonversi string ke int
        choice = atoi(input);

        while (getchar() != '\n'); // menghapus karakter \n yg tersisa
        printf("\n"); // memberikan \n sebelum output berikutnya

        switch (choice){
        case 1:
            addNasabah(queue, stack);
            break;
        case 2:
            deQueue(queue, stack);
            break;
        case 3:
            tampilkanAntrean(queue);
            break;
        case 4:
            tampilkanRiwayat(stack);
            break;
        case 5:
            undoTransaksi(queue, stack);
            break;
        case 6:
            printf("\nSedang keluar dari sistem...\n");
            printf("Anda telah berhasil keluar. Terima kasih dan sampai jumpa!\n");
            return;
        default:
            printf("Pilihan Tidak Valid, Coba Lagi!\n");
        }

    } while (choice != 6);
}

