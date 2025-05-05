#ifndef NBTREES_H
#define NBTREES_H
#include <stdio.h>
#include <stdbool.h>

typedef bool boolean;
typedef char infotype;

extern int jml_maks;

typedef struct {
    infotype info;
    int ps_fs;
    int ps_nb;
    int ps_pr;
} Node;

typedef Node Isi_Tree[100];
#define nil 0

// ... deklarasi fungsi ...

// Membuat pohon dengan jumlah node dan informasi yang sudah ditentukan
void Create_tree(Isi_Tree X, int Jml_Node);

// Mengecek apakah pohon kosong
boolean IsEmpty(Isi_Tree P);

// Fungsi traversal pohon
void PreOrder(Isi_Tree P);
void PreOrderR(Isi_Tree P, int idx);
void InOrder(Isi_Tree P);
void InOrderR(Isi_Tree P, int idx);
void PostOrder(Isi_Tree P);
void PostOrderR(Isi_Tree P, int idx);
void LevelOrder(Isi_Tree X, int jml_maks);

// Fungsi untuk mencetak informasi pohon
void PrintTree(Isi_Tree P);

// Fungsi untuk mencari node dengan informasi tertentu
boolean Search(Isi_Tree P, infotype X);

// Fungsi untuk menghitung jumlah elemen dalam pohon
int nbElmt(Isi_Tree P);

// Fungsi untuk menghitung jumlah daun (leaf) dalam pohon
int nbDaun(Isi_Tree P);

// Fungsi untuk menghitung level kedalaman node tertentu
int Level(Isi_Tree P, infotype X);

// Fungsi untuk menghitung kedalaman pohon (rekursif)
int DepthR(Isi_Tree P, int idx);
int Depth(Isi_Tree P);

// Fungsi untuk mencari nilai maksimum antara dua nilai
int Max(infotype Data1, infotype Data2);

#endif 