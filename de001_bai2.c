#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char action;
    char value;
} Operation;

typedef struct {
    Operation data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack* s, Operation op) {
    if (isFull(s)) {
        printf("Loi: Stack da day!\n");
        return;
    }
    s->data[++(s->top)] = op;
}

Operation pop(Stack* s) {
    if (isEmpty(s)) {
        return (Operation){'\0', '\0'};
    }
    return s->data[(s->top)--];
}

int main() {
    char* text = (char*)malloc(100 * sizeof(char));
    if (text == NULL) {
        printf("Loi cap phat bo nho.\n");
        return 1;
    }
    text[0] = '\0';
    int text_len = 0;

    Stack undoStack;
    Stack redoStack;
    initStack(&undoStack);
    initStack(&redoStack);

    char command[20];

    while (1) {
        printf("\n-------------------- TEXT EDITOR --------------------\n");
        printf("Cac chuc nang:\n");
        printf("  - INSERT x: them ky tu x vao cuoi van ban\n");
        printf("  - UNDO: hoan tac thao tac gan nhat\n");
        printf("  - REDO: phuc hoi thao tac vua undo\n");
        printf("  - HIEN THI: in van ban hien tai\n");
        printf("  - THOAT: ket thuc chuong trinh\n");
        printf("-----------------------------------------------------\n");

        printf("Nhap lenh: ");
        scanf("%s", command);

        if (strcmp(command, "INSERT") == 0) {
            char value;
            scanf(" %c", &value);

            text[text_len] = value;
            text_len++;
            text[text_len] = '\0';

            Operation op = {'I', value};
            push(&undoStack, op);

            while (!isEmpty(&redoStack)) {
                pop(&redoStack);
            }

            printf("Da them ky tu '%c'\n", value);
        }
        else if (strcmp(command, "UNDO") == 0) {
            if (!isEmpty(&undoStack)) {
                Operation lastOp = pop(&undoStack);
                if (lastOp.action == 'I') {
                    char undoneChar = lastOp.value;
                    if (text_len > 0) {
                        text_len--;
                        text[text_len] = '\0';
                        push(&redoStack, (Operation){'I', undoneChar});
                        printf("Da hoan tac thao tac them ky tu '%c'\n", undoneChar);
                    }
                }
            } else {
                printf("Khong co thao tac nao de hoan tac.\n");
            }
        }
        else if (strcmp(command, "REDO") == 0) {
            if (!isEmpty(&redoStack)) {
                Operation lastOp = pop(&redoStack);
                if (lastOp.action == 'I') {
                    char redoneChar = lastOp.value;
                    text[text_len] = redoneChar;
                    text_len++;
                    text[text_len] = '\0';
                    push(&undoStack, (Operation){'I', redoneChar});
                    printf("Da phuc hoi thao tac them ky tu '%c'\n", redoneChar);
                }
            } else {
                printf("Khong co thao tac nao de phuc hoi.\n");
            }
        }
        else if (strcmp(command, "HIEN") == 0) {
            char temp[10];
            scanf("%s", temp);
            if (strcmp(temp, "THI") == 0) {
                printf("Van ban hien tai: %s\n", text);
            } else {
                printf("Lenh khong hop le.\n");
            }
        }
        else if (strcmp(command, "THOAT") == 0) {
            printf("Ket thuc chuong trinh.\n");
            break;
        }
        else {
            printf("Lenh khong hop le. Vui long thu lai.\n");
        }
    }

    free(text);
    return 0;
}