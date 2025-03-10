






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
