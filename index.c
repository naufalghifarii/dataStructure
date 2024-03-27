#include "linked.c"
#include "hash.c"
#include "binary.c"
#include <stdio.h>

// Alvin Eagan - 2702319114
// Jeremy Axel - 2702331782
// Naufal Ghifari - 2702314460

void menu(){
    int option;
    while(1){
        system("cls");
        printf("\t\tWELCOME TO MENU\n");
        printf("----------------------------------------------\n");
        printf("1. Linked\n2. Hash\n3. Binary\n4. Exit\n>> ");
        scanf("%d", &option);
        switch(option){
            case 1:
                link();
                break;
            case 2:
                hashing();
                break;
            case 3:
                binary();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
        }
    }
}

int main(){
    menu();
    return 0;
}
