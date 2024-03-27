#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct tnode {
	char name[100];
	char date[20];
	struct tnode *left;
	struct tnode *right;
};

struct tnode *tree=NULL;

void push(char name[], char date[]){
	struct tnode *newtnode = (struct tnode*) malloc (sizeof(struct tnode));
	newtnode->left = newtnode->right = NULL;
	strcpy(newtnode->name,name);
	strcpy(newtnode->date, date);
	if(tree == NULL){
		tree = newtnode;
	}
	else{
		struct tnode *ptr = tree, *parentPtr = NULL;
		while(ptr != NULL){
			parentPtr = ptr;
			if(strcmp(name, ptr->name) > 0) ptr = ptr->right;
			else ptr = ptr->left;
		}
		if(parentPtr != NULL && strcmp(name, parentPtr->name) > 0) parentPtr->right = newtnode;
		else parentPtr->left = newtnode;
	}

}

void Insert(){
	char name[100];
    char date[20];
    
    system("cls");

    printf("Input name (ex: John Doe) : ");
    fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = 0;
    printf("Input date (ex: dd/mm/yyyy): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0;
    system("cls");
    if(strlen(date) != 10){ 
		puts("Format salah."); printf("\nPress any key to continue..."); getch();  
	}
    else{
    	push(name, date);
    	printf("%s's data succesfully inserted.",name);
    	Sleep(1000);
	}
	system("cls");
}

void Display(struct tnode* ptr){
	if(tree == NULL){
		printf("List is currently empty!\n");
		return;
	}
	if(ptr!=NULL){
		Display(ptr->left);
		printf("%-50s%-15s\n", ptr->name, ptr->date);
		Display(ptr->right);
	}
	
}

void deletetnode(struct tnode *ptr, char name[], struct tnode *parentPtr){
	if(ptr == NULL){
		printf("Value not found in the tree\n");
		printf("\nPress any key to continue..."); getch(); return;
	}
	else if(strcmp(name, ptr->name) > 0){
		deletetnode(ptr->right,name, ptr);
	}
	else if(strcmp(name, ptr->name) < 0){
		deletetnode(ptr->left, name, ptr);
	}
	else{
		if(ptr->right != NULL && ptr->left != NULL){
			struct tnode *parentTemp = ptr;
			struct tnode *temp = ptr->right;
			while(temp->left != NULL){
				parentTemp = temp;
				temp = temp->left;
			}
			
			if(parentTemp == ptr){
      			parentTemp->right = temp->right;
   			} 	
			else{
       			parentTemp->left = temp->right;
   			}
   			strcpy(ptr->name,temp->name);
			strcpy(ptr->date,temp->date);
			free(temp);
		}
		else{
			if(ptr->left != NULL){ // punya left child
				if(parentPtr == NULL){ // root tnode
					tree = ptr->left;
				}
				else if(parentPtr->left == ptr){
					parentPtr->left = ptr->left;
				}
				else{
					parentPtr->right = ptr->left;
				}
			}
			else if(ptr->right != NULL){ // punya right child
				if(parentPtr == NULL){
					tree = ptr->right;
				}
				else if(parentPtr->left == ptr){
					parentPtr->left = ptr->right;
				}
				else{
					parentPtr->right = ptr->right;
				}
			}
			else{
				if(parentPtr != NULL){
					if(parentPtr->left == ptr){
						parentPtr->left = NULL;
					}
					else if(parentPtr->right == ptr){
						parentPtr->right = NULL;
					}
				}
				else{
					tree = NULL;
				}
			}
			free(ptr);
			ptr = NULL;
		}
		printf("%s's data succesfully deleted.",name);
		Sleep(1000);
	}
}
    
void delete(){
	system("cls");
	if(tree == NULL){
		printf("Cannot remove a name from an empty list\n");
		return;
	}
	char name[100];
	printf("Insert the name you wish to delete\n");
	gets(name);
	deletetnode(tree, name,NULL);
	system("cls");
}
void binary(){
	int choice;
	system("cls");
    while(1){
		printf("\t\tBINARY\n");
        printf("----------------------------------------------\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Menu\n>> ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                Insert();
                break;
            case 2:
            	delete();
                break;
            case 3:
            	system("cls");
            	printf("%-50s%-15s\n","Name", "Date");
  				printf("---------------------------------------------------------------------\n");
                Display(tree);
				printf("\nPress any key to continue..."); getch(); system("cls");
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
