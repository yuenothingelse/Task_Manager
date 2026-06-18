```text
██╗  ██╗███████╗██╗      ██████╗ ███╗   ███╗██████╗  ██████╗ ██╗  ██╗
██║ ██╔╝██╔════╝██║     ██╔═══██╗████╗ ████║██╔══██╗██╔═══██╗██║ ██╔╝
█████╔╝ █████╗  ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║█████╔╝
██╔═██╗ ██╔══╝  ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║██╔═██╗
██║  ██╗███████╗███████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝██║  ██╗
╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝ ╚═╝  ╚═╝

                    
```
# 📋 System Task Management

Sistem Manajemen Tugas Mahasiswa berbasis bahasa C yang mengimplementasikan berbagai struktur data dan algoritma untuk membantu pengguna mengelola tugas akademik secara efisien.

## 👥 Kelompok

**abrarmuda59-droid** as ABRAR MUDA 
**yuenothingelse** as MIRZA NUR AKHYAR
**Hafidhfrr** as M. HAFIDH FARRAS

Program ini dikembangkan sebagai tugas akhir mata kuliah Struktur Data dan Algoritma di Universitas Syiah Kuala.

---

## 📖 Deskripsi

System Task Management merupakan aplikasi berbasis terminal (CLI) yang dirancang untuk membantu mahasiswa mengelola tugas kuliah secara terstruktur.

Program memungkinkan pengguna untuk:

* Menambahkan tugas baru
* Mengedit tugas
* Menghapus tugas
* Mencari tugas berdasarkan ID
* Mencari tugas berdasarkan mata kuliah
* Mengurutkan tugas berdasarkan berbagai kriteria
* Menentukan tugas dengan prioritas tertinggi
* Menandai tugas sebagai selesai
* Melihat statistik penyelesaian tugas

---

## ✨ Fitur Utama

### Dashboard

Menampilkan ringkasan data tugas dan informasi penting mengenai tugas yang tersimpan.

### Manajemen Tugas

* Tambah tugas
* Edit tugas
* Hapus tugas
* Tampilkan seluruh tugas

### Pencarian Tugas

* Berdasarkan ID (BST)
* Berdasarkan Mata Kuliah (Hash Table)

### Pengurutan Tugas

* Berdasarkan Judul
* Berdasarkan Prioritas
* Berdasarkan Deadline

### Prioritas Tugas

* Menampilkan tugas dengan prioritas tertinggi menggunakan Min Heap

### Monitoring Progres

* Menandai tugas sebagai selesai
* Menampilkan statistik penyelesaian tugas

### Sample Data

* Import data tugas dari file CSV

---

## 🏗️ Struktur Data yang Digunakan

### Binary Search Tree (BST)

Digunakan untuk:

* Menyimpan data tugas berdasarkan ID
* Mempercepat proses pencarian tugas
* Menampilkan seluruh tugas secara terurut

Kompleksitas rata-rata:

```text
Search  : O(log n)
Insert  : O(log n)
Delete  : O(log n)
```

---

### Hash Table

Digunakan untuk:

* Mengelompokkan tugas berdasarkan mata kuliah
* Mempercepat pencarian tugas berdasarkan course

Kompleksitas rata-rata:

```text
Search : O(1)
Insert : O(1)
```

---

### Min Heap

Digunakan untuk:

* Menentukan tugas dengan prioritas tertinggi
* Menampilkan daftar prioritas tugas

Kompleksitas:

```text
Insert : O(log n)
```

---

### Quick Sort

Digunakan untuk:

* Mengurutkan tugas berdasarkan judul
* Mengurutkan tugas berdasarkan deadline
* Mengurutkan tugas berdasarkan prioritas

Kompleksitas rata-rata:

```text
O(n log n)
```

---

## 📂 Struktur Project

```text
TASK_MANAGER/
│
├── main.c
├── sample_data.csv
├── MakeFile
│
├── models/
│   └── task.h
│
├── bst/
│   ├── bst.c
│   └── bst.h
│
├── hash/
│   ├── hash.c
│   └── hash.h
│
├── heap/
│   ├── heap.c
│   └── heap.h
│
├── sort/
│   ├── sort.c
│   └── sort.h
│
└── utils/
    ├── display.c
    └── display.h
```

---

## 📑 Menu Program

```text
1. Dashboard
2. Add Task
3. Edit Task
4. Delete Task
5. Search Task By ID
6. Search Task By Course
7. Show All Tasks
8. Show Priority Tasks
9. Sort Tasks
10. Mark Task Completed
11. Show Statistics
12. Complexity Analysis
13. Load Sample Data
0. Exit
```

---

## 📊 Analisis Kompleksitas

| Operasi           | Kompleksitas |
| ----------------- | ------------ |
| Search BST        | O(log n)     |
| Insert BST        | O(log n)     |
| Delete BST        | O(log n)     |
| Search Hash Table | O(1)         |
| Insert Hash Table | O(1)         |
| Insert Heap       | O(log n)     |
| Quick Sort        | O(n log n)   |

---

## 🎯 Tujuan Pengembangan

Proyek ini dibuat untuk:

* Mengimplementasikan konsep struktur data dalam kasus nyata
* Memahami penggunaan BST, Hash Table, dan Heap
* Mengembangkan kemampuan pemrograman modular menggunakan bahasa C
* Menerapkan algoritma sorting dan searching pada aplikasi nyata

---

## 🛠️ Teknologi

* Language : C
* Compiler : GCC
* Data Structure :
  * Binary Search Tree
  * Hash Table
  * Min Heap    
* Algorithm :
  * Quick Sort

---

## 📜 Lisensi

Project ini dibuat untuk keperluan akademik pada mata kuliah Struktur Data dan Algoritma, Fakultas MIPA Universitas Syiah Kuala.
