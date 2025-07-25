#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct node {
    int id;
    char title[MAX];
    int priority;
    char deadline[MAX];
    int completed;
    struct node *next;

}Node;
Node *head = NULL;
int currentIdx = 0;
Node *createNode(char title[MAX],int priority,char deadline[MAX]) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->id=currentIdx++;
    strcpy(newNode->title, title);
    newNode->priority = priority;
    strcpy(newNode->deadline, deadline);
    newNode->next = NULL;
    return newNode;
}
int isDuplicateTile(char title[]) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void addNode( ) {

    char title[MAX];
    int priority;
    char deadline[MAX];
    do {
        printf("nhap ten nhiem vu");
        while (getchar() != '\n');
        fgets(title, MAX, stdin);
        title[strlen(title) - 1] = '\0';
        if (isDuplicateTile(title)) {
            printf("Ten nhiem vu ton tai \n");
        }else {
            break;
        }

    }while (1);
    do {
        printf("Nhap thu tu uu tien nhiem vu");
        scanf("%d", &priority);
        printf("thoi gian hoan thanh nhiem vu");
        while (getchar() != '\n');
        fgets(deadline, MAX, stdin);
        deadline[strlen(deadline) - 1] = '\0';
        break;
    }while (1);
    Node *newNode=createNode(title,priority,deadline);
    if (head == NULL) {
        head = newNode;
    }else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Them thanh cong");

}
void updateTask() {
int idFind;
    Node *temp = head;
    printf("Nhap phan tu muon thay doi thong tin");
    scanf("%d", &idFind);
   while (temp && temp->id != idFind) {
       temp = temp->next;
   }
    if (temp == NULL) {
        printf("Khong tim thay nhiem vu");
    }
    char newTitle[MAX];
    char newDeadline[MAX];
    int newPriority;

    printf("Nhap tieu de moi");
    while (getchar() != '\n');
    fgets(newTitle, MAX, stdin);
    newTitle[strlen(newTitle) - 1] = '\0';

    printf("Nhap uu tien moi");
    scanf("%d", &newPriority);

    printf("Nhap deadline moi");
    while (getchar() != '\n');
    fgets(newDeadline, MAX, stdin);
    newDeadline[strlen(newDeadline) - 1] = '\0';

    strcpy(newTitle, newDeadline);
    temp->priority = newPriority;
    strcpy(newTitle, newDeadline);
    printf("Nhap thanh cong");
}
void deleteTask() {
    int idDelete;
    printf("Nhap id nhiem vu");
    scanf("%d", &idDelete);
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL) {
        if (temp->id == idDelete) {
            if (prev == NULL) {
                head = temp->next;
            }else {
                prev->next = temp->next;
                free(temp);
            }
            printf("Xoa thanh cong ");

        }else {
            printf("Khong tim thay san pham");
        }
        temp = temp->next;
    }

}
void displayTask() {
    Node *temp = head;
    if (temp == NULL) {
        printf("Danh sach rong");
        return;
    }
    printf("\n Danh sach san pham \n ");
    while (temp != NULL) {
        printf("Id: %d | Title :%s | Priority:%d |Dealine %s \n",temp->id,temp->title,temp->priority,temp->deadline);
        temp = temp->next;
    }
}
void markCompleted() {
    int id;
    printf("Nhap id nhiem vu da hoan thanh");
    scanf("%d", &id);
    Node *temp = head;
    while (temp && temp->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        temp->completed = 1;
        printf("Danh dau nhiem vu thanh cong");
    }else {
        printf("Khong tim thay nhiem vu");
    }
}
void sortTask() {
    if (!head|| !head->next) {
        return;
    }
    Node *i,*j;
    for (i=head;i!=NULL;i=i->next) {
        for ( j=i->next;j!=NULL;j=j->next) {
            if (i->priority > j->priority) {
                Node temp =*i;
                *i = *j;
                *j = temp;
            }
            Node *swap = i->next;
            i->next = j->next;
            j->next = swap;
        }
    }
    printf("Danh sach xep theo \n ");
}
void searchTask() {
    char keyWord[MAX];
    printf("Nhap title muon tim kiem");
    while (getchar() != '\n');
    fgets(keyWord, MAX, stdin);
    keyWord[strlen(keyWord) - 1] = '\0';

    Node *temp = head;
    int found = 0;
    while (temp) {
        if (strstr(temp->title, keyWord)) {
            printf("Id: %d | Tieu de %s | Ưu tien %d | deadline %s | %d \n",temp->id,temp->title,temp->priority,temp->completed);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Khong tim thay \n ");
    }
}
int main () {
    int choice;
    Node *head = NULL;
    do {
        printf("\n-----Task Manager-----\n");
        printf("1.Them nhiem vu \n");
        printf("2.Them luong phan tu \n");
        printf("3.Them luong phan tu \n");
        printf("4.cap nhap thong tin nhiem vu \n");
        printf("5.Danh dau nhieu vu da hoan thanh \n");
        printf("6.Sap xep nhieu vu \n");
        printf("7.Tim kiem nhiem vu \n");
        printf("8.Thoat \n");
        printf("Moi ban nhap lua chon : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                addNode(head);
                break;
            case 2:
                displayTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                updateTask();
                break;
            case 5:
                markCompleted();

                break;
            case 6:
                sortTask();
                break;
            case 7:
                searchTask();
                break;
            case 8:
                printf("thoat khoi chuong trinh");
                break;
            default:
                printf("ERORR");
                break;
        }
    }while(choice != 8);
    return 0;
}