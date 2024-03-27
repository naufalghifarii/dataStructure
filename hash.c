#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
// #include "declare.h"

#define MAX_NAMA 50
#define MAX_TL 10 //strlen("dd/mm/yyyy");
#define SIZE 10

typedef struct data{
	char nama[MAX_NAMA];
	char tl[MAX_TL];
	struct data *next;
} data;

data *hashTable[SIZE];

void input(){
	system("cls");
	char nama[MAX_NAMA];
	char tl[MAX_TL];
	
	printf("Nama: "); gets(nama);
	printf("Tanggal lahir: "); gets(tl);
	
	if(strlen(tl) != 10){ 
		system("cls");
		puts("Format salah."); printf("\nPress any key to continue..."); getch(); system("cls"); 
		// main();
	}
	else
		hash(nama, tl);
}

int hash(char nama[], char tl[]){
	int length = strlen(nama);
	
	int hashIndex;
	data *x = (data*) malloc(sizeof(data));
	
	strcpy(x->nama, nama);
    strcpy(x->tl, tl);
    x->next = NULL;
	
	hashIndex = length % SIZE;
	if(hashTable[hashIndex] == NULL)
		hashTable[hashIndex] = x;
	else{
		data *temp = hashTable[hashIndex];
		while(temp->next != NULL)
			temp = temp->next;
			
		temp->next = x;
	}
	
	system("cls"); 
	// main();
}

void view(){
    int i, isEmpty = 0;
    system("cls");
	
	for(i = 0; i < SIZE; i++){
		if(hashTable[i] == NULL)
			continue;
		else{
			isEmpty = 1;
			break;
		}
	}
	
	if(isEmpty == 0){
		puts("Hash Table is empty.");
	}
	else{
		printf("%-6s%-50s%-15s\n", "Index", "Nama", "Tanggal Lahir");
    	printf("---------------------------------------------------------------------\n");
    	
    	for(i = 0; i < SIZE; i++){
        	if(hashTable[i] != NULL){
            	printf("%-6d%-50s%-15s\n", i, hashTable[i]->nama, hashTable[i]->tl);
    
            	data *temp = hashTable[i]->next;
            	while(temp != NULL){
                	printf("%-6s%-50s%-15s\n", "", temp->nama, temp->tl);
                	temp = temp->next;
            	}
        	}
    	}
	}
	
    printf("\nPress any key to continue..."); getch(); system("cls"); 
	// main();
}

void Delete(){
	system("cls");
	
	int i, isEmpty = 0;
	for(i = 0; i < SIZE; i++){
		if(hashTable[i] == NULL)
			continue;
		else{
			isEmpty = 1;
			break;
		}
	}
	
	if(isEmpty == 0){
		puts("Hash Table is empty."); printf("\nPress any key to continue..."); getch(); system("cls"); 
		// main();
	}
	
	char nama[MAX_NAMA];
    printf("Nama: "); gets(nama);

    int hashIndex = strlen(nama) % SIZE;

    data *temp = hashTable[hashIndex];
    data *prev = NULL;
    
    while(temp != NULL){
        if(strcmp(temp->nama, nama) == 0){
            if(prev == NULL)
                hashTable[hashIndex] = temp->next;
            else
                prev->next = temp->next;
            free(temp);
        }
        prev = temp;
        temp = temp->next;
    }
    
	printf("\nPress any key to continue..."); getch(); system("cls"); 
	// main();
}

void hashing(){
	int option;
	while(1){
		system("cls");
		printf("\t\tHASH TABLE\n");
        printf("----------------------------------------------\n");
		puts("1. Insert");
		puts("2. View");
		puts("3. Delete");
		puts("4. Menu");
		printf(">> ");
		
		scanf("%d", &option); getchar();
		
		switch(option){
			case 1:
				input();
				break;
			case 2:
				view();
				break;
			case 3:
				Delete();
				break;
			case 4:
                main();
                break;
            default:
                printf("Invalid input.\n");
		}
	}
	
	
	
	// return 0;
}

