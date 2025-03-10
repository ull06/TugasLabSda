# 📚 Tugas Kelompok Praktikum Struktur Data dan Algoritma 📚
## Sistem Antrean Bank 💰 
---

### Anggota Kelompok 4:
| Nama                   | NPM           |
|------------------------|---------------|
| Hazairin               | 2408107010001 |
| Nayla Nabila Syahel    | 2408107010005 |
| Raisa Salsa Nabila     | 2408107010007 |
| Rahmatul Uliya         | 2408107010012 |
| Dara Ramadhani         | 2408107010028 |
| Habib Nuran Mulkan     | 2408107010109 |

---

### 🗒 Deskripsi Singkat Program:

Program ini adalah sitem manajemen antrean nasabah di bank yang menggunakan queue berbasis linked list untuk mengelola antrean layanan, serta stack berbasis linked list untuk menyimpan riwayat transaksi nasabah yang telah di proses.

---
### 📌 Instruksi Kompilasi dan Cara Menjalankan Program:

Program ini menggunakan *Makefile* untuk mempermudah proses kompilasi dan eksekusi.

- Jalankan perintah berikut di terminal:  
  sh
  make
  
  📌 Perintah ini akan mengompilasi semua file sumber dan menghasilkan file eksekusi mainSda.

- Setelah berhasil dikompilasi, jalankan program dengan:  
  sh
  ./mainSda
  
  📌 Pastikan file mainSda telah dibuat sebelum menjalankan perintah ini.
  
---






### ⚙️ Implementasi Struktur Data:

#### 🔹 Queue berbasis Linked List
Dalam program antrean nasabah, **Queue** diimplementasikan untuk melakukan beberapa proses berikut:

⓵ **enqueue()** – Menambahkan nasabah ke daftar antrean.
   - Nasabah ditambahkan dari belakang sesuai dengan konsep antrean dalam kehidupan nyata, sehingga proses pelayanan dilakukan teratur.

⓶ **dequeue()** – Menghapus nasabah dari antrean setelah selesai diproses.
   - Penghapusan nasabah dilakukan dari depan sesuai dengan konsep FIFO.
   - Setelah penghapusan, nasabah berikutnya akan diproses.

⓷ **tampilkanAntrian()** – Menampilkan daftar antrean yang menunggu untuk dilayani.
   - Data antrean ditampilkan sesuai dengan urutan masuk.
   - Jika antrean kosong, sistem akan menampilkan pesan **"Antrean kosong"**.

#### 🔹 Stack berbasis Linked List
Dalam program antrean nasabah, **Stack** diimplementasikan untuk melakukan beberapa proses berikut:

⓵ **pop()** – Menambahkan nasabah ke daftar riwayat layanan.
   - Ketika seorang nasabah telah selesai dilayani (dikeluarkan dari Queue), data nasabah tersebut akan dimasukkan ke dalam **Stack**.
   - Penambahan dilakukan dari **atas (top)**, sehingga data terakhir yang masuk selalu berada di posisi paling atas.

⓶ **push() / undoTransaksi** – Menghapus data nasabah dari riwayat layanan.
   - Data nasabah terakhir yang masuk ke daftar riwayat layanan akan dihapus dan dikembalikan ke daftar antrean.
   - Penghapusan dilakukan dari posisi **top**, mengikuti konsep **LIFO**.

⓷ **tampilkanRiwayat()** – Menampilkan riwayat nasabah yang telah selesai diproses.
   - Nasabah pertama yang diproses akan ditampilkan lebih dahulu.
   - Jika tidak ada nasabah yang telah dilayani, sistem akan menampilkan pesan **"Riwayat kosong"**.

---

### 🛠️ Fitur Utama:

1️⃣ **Menambahkan Nasabah ke Antrean** 📥  
   - Nasabah dapat mendaftar dengan nama dan memilih jenis layanan (Setor Tunai, Tarik Tunai, Pembukaan Rekening).  
   
2️⃣ **Memproses Nasabah** 🔄  
   - Nasabah yang berada di antrean paling depan akan diproses dan dipindahkan ke **riwayat layanan**.  

3️⃣ **Menampilkan Antrean Saat Ini** 📋  
   - Menampilkan daftar nasabah yang masih dalam antrean.  

4️⃣ **Menampilkan Riwayat Layanan** 📜  
   - Menampilkan daftar nasabah yang sudah dilayani.  

5️⃣ **Batalkan Transaksi Terakhir (Undo)** ⏪  
   - Mengembalikan nasabah yang sudah diproses ke antrean.  

6️⃣ **Keluar dari Program** ❌  

---

### 📝 Alur Program 

**🌟 Tampilan Awal Program 🌟**

- Saat program dijalankan, pengguna disambut dengan pesan berikut

  ![Screenshot 2025-03-10 131737](https://github.com/user-attachments/assets/83065517-f3a0-4dc9-b04b-34a6fdcbd652)

**🖥️ Antarmuka Program**

- Saat program dijalankan, pengguna akan disambut dengan antarmuka yang sederhana dan informatif. 

  ![Screenshot 2025-03-10 135540](https://github.com/user-attachments/assets/87ee314a-758c-409c-85b7-be7b75bf3f27)

### Pilihan 𝟙 

- Menambahkan nasabah ke daftar antrean

  ![Screenshot 2025-03-10 140504](https://github.com/user-attachments/assets/9a2a9f97-1613-40f3-8d28-274b9c8b3966)

### Pilihan 𝟚 

- Memproses nasabah dalam antrean

  ![Screenshot 2025-03-10 140622](https://github.com/user-attachments/assets/829d85bb-92b1-4de3-ba7d-10c745c77203)

### Pilihan 𝟛 

- Menampilkan antrean saat ini 

  ![Screenshot 2025-03-10 141051](https://github.com/user-attachments/assets/a2e14634-e07b-4576-8434-aa2f3948b64a)

### Pilihan 𝟜

- Menampilkan riwayat layanan nasabah

  ![Screenshot 2025-03-10 141716](https://github.com/user-attachments/assets/b9e0ec2f-814c-4de0-995c-98211f58082c)

### Pilihan 𝟝

- Membatalkan transaksi terakhir nasabah

  ![Screenshot 2025-03-10 141832](https://github.com/user-attachments/assets/1a81c87f-4637-48a2-a572-916aa4e97359)

### Pilihan 𝟞

- Keluar dari program 

  ![Screenshot 2025-03-10 142231](https://github.com/user-attachments/assets/2d0623ac-44d3-4760-b10a-84547c047b6f)

### 🎉 Pesan Penutup Program

- Saat pengguna memilih keluar dari sistem, program akan menampilkan pesan perpisahan yang hangat

  ![Screenshot 2025-03-10 142409](https://github.com/user-attachments/assets/c71e5985-9b23-4f16-b1e7-e6ae2fb7c70f)

---
### 📝 Manajemen Memori

- Sebelum program keluar, semua memori yang digunakan untuk menyimpan data nasabah akan dibersihkan secara otomatis. Ini dilakukan untuk mencegah kebocoran memori (memory leak), sehingga sumber 
  daya komputer tetap optimal dan tidak ada memori yang terbuang sia-sia.
  
---
