#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
// #include "index.c"
struct node{
    char name[100];
    char date[50];
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *tail = NULL;

struct node *createnode(char name[], char date[]){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    strcpy(newnode->date, date);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void pushHead(char name[], char date[]){
    struct node *newnode = createnode(name, date);
    if(head == NULL){
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void pushTail(char name[], char date[]){
    struct node *newnode = createnode(name, date);
    if(head == NULL){
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void pushBetween(char name[], char date[], char target[]){
    struct node *newnode = createnode(name, date);
    struct node *temp = head;
    while(temp != NULL && strcmp(temp->name, target) != 0){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Target not found.\n");
    } else {
        newnode->next = temp->next;
        newnode->prev = temp;
        if(temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
}

void deletee(char target[]){
    if(head == NULL && tail == NULL ){
        printf("List is empty.\n");
    } else if(strcmp(head->name, target) == 0){
        struct node *temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        free(temp);
    } else {
        struct node *temp = head;
        while(temp != NULL && strcmp(temp->name, target) != 0){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Target not found.\n");
        } else {
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
    }
}

void display(){
    system("cls");
    struct node *temp = head;
    printf("%-50s%-15s\n","Name", "Date");
    printf("---------------------------------------------------------------------\n");
    if(temp == NULL){
        printf("List is empty.\n");
    }
    while(temp != NULL){
        
        printf("%-50s%-15s\n", temp->name, temp->date);
        temp = temp->next;
    }
    printf("\nPress any key to continue..."); getch(); system("cls");
}
void insert(){
    char name[100];
    char date[10];
    int option;
    system("cls");
    printf("1. Insert Head\n2. Insert Tail\n3. Insert Between\n");
    scanf("%d", &option); getchar();
    system("cls");
    if(option == 1){
        printf("Input name (ex: John Doe) : ");
        gets(name);
        printf("Input date (ex: dd/mm/yyyy): ");
        gets(date);
        if(strlen(date) != 10){ 
            system("cls");puts("Format salah."); printf("\nPress any key to continue..."); getch(); 
        }else
        pushHead(name, date);
    } else if(option == 2){
        printf("Input name (ex: John Doe) : ");
        gets(name);
        printf("Input date (ex: dd/mm/yyyy): ");
        gets(date);
        if(strlen(date) != 10){ 
            system("cls");puts("Format salah."); printf("\nPress any key to continue..."); getch(); 
        }else
        pushTail(name, date);
    } else if(option == 3){
        char target[100];
        struct node *temp = head;
        printf("%-50s%-15s\n","Name", "Date");
        printf("---------------------------------------------------------------------\n");
        if(temp == NULL){
            printf("List is empty.\n");
        }
        while(temp != NULL){
            
            printf("%-50s%-15s\n", temp->name, temp->date);
            temp = temp->next;
        }
        printf("\n\nInput name (ex: John Doe) : ");
        gets(name);
        printf("Input date (ex: dd/mm/yyyy): ");
        gets(date);
        
        printf("Input target name (ex: Jane Doe) : ");
        fgets(target, sizeof(target), stdin); 
        target[strcspn(target, "\n")] = 0;
		if(strlen(date) != 10){ 
            system("cls");puts("Format salah."); printf("\nPress any key to continue..."); getch(); 
        }else
    	pushBetween(name, date, target);
    }else {
        printf("Invalid input.\n");
    }
    system("cls");
}

void deletenode(){
    system("cls");
    char target[100];
    printf("Input target name to Delete : ");
    getchar(); 
    fgets(target, sizeof(target), stdin); 
    target[strcspn(target, "\n")] = 0;
    deletee(target);
//    system("cls");
}

void link(){
    int choice;
    
    while(1){
        system("cls");
        printf("\t\tLINKED LIST\n");
        printf("----------------------------------------------\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Menu\n>> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                deletenode();
                break;
            case 3:
                display();
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
