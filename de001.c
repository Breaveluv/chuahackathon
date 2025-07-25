#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct node {
    int id;
    char title[MAX];
    int priority;
    char deadline[MAX];
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

void updateTask() {
    int id;
    printf("Nhập ID nhiệm vụ cần cập nhật: ");
    scanf("%d", &id);

    Node *temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Không tìm thấy nhiệm vụ.\n");
        return;
    }

    char newTitle[MAX], newDeadline[MAX];
    int newPriority;

    printf("Nhập tiêu đề mới: ");
    while (getchar() != '\n');
    fgets(newTitle, MAX, stdin);
    newTitle[strcspn(newTitle, "\n")] = '\0';

    printf("Nhập ưu tiên mới: ");
    scanf("%d", &newPriority);

    printf("Nhập deadline mới: ");
    while (getchar() != '\n');
    fgets(newDeadline, MAX, stdin);
    newDeadline[strcspn(newDeadline, "\n")] = '\0';

    strcpy(temp->title, newTitle);
    temp->priority = newPriority;
    strcpy(temp->deadline, newDeadline);

    printf("🔄 Cập nhật thành công.\n");
}

void markCompleted() {
    int id;
    printf("Nhập ID nhiệm vụ đã hoàn thành: ");
    scanf("%d", &id);

    Node *temp = head;
    while (temp && temp->id != id) {
        temp = temp->next;
    }

    if (temp) {
        temp->isCompleted = 1;
        printf("🎉 Nhiệm vụ đã được đánh dấu là hoàn thành.\n");
    } else {
        printf("❌ Không tìm thấy nhiệm vụ.\n");
    }
}

void sortTasksByPriority() {
    if (!head || !head->next) return;

    Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->priority < j->priority) {
                // Hoán đổi toàn bộ nội dung
                Node temp = *i;
                *i = *j;
                *j = temp;

                // Khôi phục liên kết
                Node *swap = i->next;
                i->next = j->next;
                j->next = swap;
            }
        }
    }
    printf("📊 Danh sách đã được sắp xếp theo mức độ ưu tiên giảm dần.\n");
}

void searchByTitle() {
    char keyword[MAX];
    printf("Nhập từ khóa tìm kiếm: ");
    while (getchar() != '\n');
    fgets(keyword, MAX, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    Node *temp = head;
    int found = 0;
    while (temp) {
        if (strstr(temp->title, keyword)) {
            printf("🔍 ID: %d | Tiêu đề: %s | Ưu tiên: %d | Deadline: %s | %s\n",
                   temp->id, temp->title, temp->priority, temp->deadline,
                   temp->isCompleted ? "✅" : "❌");
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Không tìm thấy nhiệm vụ nào khớp với từ khóa.\n");
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
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("thoat khoi chuong trinh");
                break;
            default:
                printf("ERORR");
                break;
        }
    }while(choice != 8);
}
