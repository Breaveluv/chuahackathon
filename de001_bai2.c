#include <stdio.h>
#include <stdlib.h>
int main() {
    int choice;
    do {
        printf("\n -----Text Editor-----\n");
        printf("1.Insert \n");
        printf("2.Undo \n");
        printf("3.Redo \n");
        printf("4.Display \n");
        printf("5.Exit \n");
        printf("Moi ban nhap lua chon");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Out ");
                break;
            default:
                printf("ERORR");
                break;

        }
    }while(choice != 5);
}