#include <stdio.h>
#include <stdlib.h>
#include "nbts.h"
#include <unistd.h>

int main() {
    Isi_Tree Tree;
    int pilihan;
    int userChoice;
    char cari, node1, node2;
    Create_tree(Tree, jml_maks);

    for(;;){
        userChoice = 0;
        pilihan = 0;
        printf("\nMenu Program:\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        if(pilihan == 1){
            printf("PreOrder Traversal: ");
            PreOrder(Tree);
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 2){
            printf("InOrder Traversal: ");
            InOrder(Tree);
            printf("\n1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 3){
            printf("PostOrder Traversal: ");
            PostOrder(Tree);
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 4){
            printf("LevelOrder Traversal: ");
            LevelOrder(Tree, jml_maks);
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 5){
            PrintTree(Tree);
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 6){
            printf("Masukkan node yang dicari: ");
            scanf(" %c", &cari);
            if (Search(Tree, cari)) {
                printf("Node %c ditemukan!\n", cari);
            } else {
                printf("Node %c tidak ditemukan!\n", cari);
            }
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 7){
            printf("Jumlah daun/leaf: %d\n", nbDaun(Tree));
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 8){
            printf("Masukkan node untuk dicari levelnya: ");
            scanf(" %c", &cari);
            printf("Level node %c: %d\n", cari, Level(Tree, cari));
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 9){
            printf("Kedalaman tree: %d\n", Depth(Tree));
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 10){
            printf("Masukkan node pertama: ");
            scanf(" %c", &node1);
            printf("Masukkan node kedua: ");
            scanf(" %c", &node2);
            printf("Level node %c: %d\n", node1, Level(Tree, node1));
            printf("Level node %c: %d\n", node2, Level(Tree, node2));
            printf("1. Kembali \nMasukkan pilihan : ");
            scanf("%d", &userChoice);
        }else if(pilihan == 11){
            printf("Keluar dari program.\n");
            break;
        }else {
            printf("pilihan tidak valid.....");

        }
    }
    
    return 0;
}