#include <stdio.h>
#include <stdbool.h>
#include "nbts.h"


void Create_tree(Isi_Tree X, int Jml_Node){
        int ascii = 65; // ASCII 'A'
        int i;
    
        // Inisialisasi info node
        for (i = 1; i <= Jml_Node; i++) {
            X[i].info = (char)ascii;
            ascii++;
            X[i].ps_fs = nil;
            X[i].ps_nb = nil;
            X[i].ps_pr = nil;
        }
    
        // A = 1
        X[1].ps_fs = 2;
        X[1].ps_pr = nil;
        X[1].ps_nb = nil;
    
        // B = 2
        X[2].ps_fs = 4;
        X[2].ps_pr = 1;
        X[2].ps_nb = 3;
    
        // C = 3
        X[3].ps_fs = 6;
        X[3].ps_pr = 1;
        X[3].ps_nb = nil;
    
        // D = 4
        X[4].ps_fs = nil;
        X[4].ps_pr = 2;
        X[4].ps_nb = 5;
    
        // E = 5
        X[5].ps_fs = 9;
        X[5].ps_pr = 2;
        X[5].ps_nb = nil;
    
        // F = 6
        X[6].ps_fs = nil;
        X[6].ps_pr = 3;
        X[6].ps_nb = 7;
    
        // G = 7
        X[7].ps_fs = nil;
        X[7].ps_pr = 3;
        X[7].ps_nb = 8;
    
        // H = 8
        X[8].ps_fs = nil;
        X[8].ps_pr = 3;
        X[8].ps_nb = nil;
    
        // I = 9
        X[9].ps_fs = nil;
        X[9].ps_pr = 5;
        X[9].ps_nb = 10;
    
        // J = 10
        X[10].ps_fs = nil;
        X[10].ps_pr = 5;
        X[10].ps_nb = nil;
    
}

boolean IsEmpty(Isi_Tree P) {
    return P[1].info == '\0';
}

void PreOrder(Isi_Tree P) {
    int current = 1;       
    boolean resmi = true;  
    printf("%c ", P[current].info); 
    while(current != nil){
        if(P[current].ps_fs != nil && resmi){
            current = P[current].ps_fs;
            printf("%c ", P[current].info);
        }else if(P[current].ps_nb != nil){
            current = P[current].ps_nb;
            printf("%c ", P[current].info);
            resmi = true;
        }else if(P[current].ps_nb == nil){
            current = P[current].ps_pr;
            resmi = false;
        }
    }
    printf("\n");
}

void InOrder(Isi_Tree P) {
    int current = 1;
    boolean resmi = true;
    while(current != nil){
        while(P[current].ps_fs != nil && resmi){
            current = P[current].ps_fs;
        }
        if(resmi){
            printf("%c ", P[current].info);
        }
        if(P[P[current].ps_pr].ps_fs == current){
            printf("%c ", P[P[current].ps_pr].info);
        }
        if(P[current].ps_nb != nil){
            current = P[current].ps_nb;
            resmi = true;
        }else {
            current = P[current].ps_pr;
            resmi = false;
        }
    }
}

void PostOrder(Isi_Tree P) {
    int current = 1; // berada di root
    boolean resmi = true;
    if(P[current].ps_fs != nil){
        current = P[current].ps_fs; // turun 1 level ke first son
        while(P[current].ps_pr != nil){
            while(P[current].ps_fs != nil && resmi){ // turun ke first son
                current = P[current].ps_fs;   
            }
            if(P[current].ps_fs == nil && resmi){
                printf("%c ", P[current].info);
            }
            if(P[current].ps_nb != nil){
                current = P[current].ps_nb;
                resmi = true;
            }else {
                current = P[current].ps_pr;
                printf("%c ", P[current].info);
                resmi = false;
            }
        }
        printf("\n"); 
    } 
}

void LevelOrder(Isi_Tree X, int Maks_node) {
    int i;
    for (i = 1; i <= Maks_node; i++) {
        if (X[i].info != '\0') {
            printf("%c ", X[i].info);
        }
    }
printf("\n");
}

void PrintTree(Isi_Tree P) {
    printf("Seluruh Node pada Non Binary Tree:\n\n");
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            printf("--> Indeks ke-%d\n", i);
            printf("-------------------------------------\n");
            printf("info array ke %d       : %c\n", i, P[i].info);
            printf("first son array ke %d  : %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d : %d\n", i, P[i].ps_nb);
            printf("parent array ke %d     : %d\n", i, P[i].ps_pr);
            printf("-------------------------------------\n\n");
        }
    }
}


boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            count++;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int parent = P[i].ps_pr;
            while (parent != nil) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int DepthR(Isi_Tree P, int idx) {
    if (idx == nil) return 0;  

    int maxChildDepth = 0;
    int child = P[idx].ps_fs; 

    while (child != nil) {  
        int depth = DepthR(P, child);  
        if (depth > maxChildDepth) {  
            maxChildDepth = depth;
        }
        child = P[child].ps_nb;  
    }

    return 1 + maxChildDepth; 
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return 0;  
    return DepthR(P, 1);  
}


int Max(infotype Data1, infotype Data2) {
    if (Data1 > Data2) {
        return Data1;
    } else {
        return Data2;
    }    
}