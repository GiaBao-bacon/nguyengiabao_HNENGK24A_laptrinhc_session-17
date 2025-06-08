#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char *str1 = NULL, *str2 = NULL, *temp = NULL;
    int choice, len1 = 0, len2 = 0;

    while (1) {
        printf("\nMENU\n");
        printf("Nhap vao chuoi\n");
        printf("In ra chuoi dao nguoc\n");
        printf("Dem so luong tu trong chuoi\n");
        printf("Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("In hoa tat ca chu cai trong chuoi\n");
        printf("Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (str1 != NULL) free(str1);
            printf("Nhap chuoi: ");
            char buffer[1000];
            fgets(buffer, 1000, stdin);
            int i; 
            for (i = 0; buffer[i]; i++) {
                if (buffer[i] == '\n') {
                    buffer[i] = '\0';
                    break;
                }
            }
            len1 = strlen(buffer) + 1;
            str1 = (char*)malloc(len1 * sizeof(char));
            if (str1 == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            strcpy(str1, buffer);
        }
        else if (choice == 2) {
            if (str1 == NULL) {
                printf("Chuoi chua duoc nhap!\n");
                continue;
            }
            printf("Chuoi dao nguoc: ");
            int i; 
            for (i = strlen(str1) - 1; i >= 0; i--) {
                printf("%c", str1[i]);
            }
            printf("\n");
        }
        else if (choice == 3) {
            if (str1 == NULL) {
                printf("Chuoi chua duoc nhap!\n");
                continue;
            }
            int wordCount = 1;
            int i; 
            for (i = 0; str1[i]; i++) {
                if (str1[i] == ' ' && str1[i + 1] != ' ' && str1[i + 1] != '\0') {
                    wordCount++;
                }
            }
            printf("So luong tu: %d\n", wordCount);
        }
        else if (choice == 4) {
            if (str1 == NULL) {
                printf("Chuoi ban dau chua duoc nhap!\n");
                continue;
            }
            if (str2 != NULL) free(str2);
            printf("Nhap chuoi khac de so sanh: ");
            char buffer[1000];
            fgets(buffer, 1000, stdin);
            int i; 
            for (i = 0; buffer[i]; i++) {
                if (buffer[i] == '\n') {
                    buffer[i] = '\0';
                    break;
                }
            }
            len2 = strlen(buffer) + 1;
            str2 = (char*)malloc(len2 * sizeof(char));
            if (str2 == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            strcpy(str2, buffer);
            if (strlen(str2) < strlen(str1)) {
                printf("Chuoi moi ngan hon chuoi ban dau\n");
            } else if (strlen(str2) > strlen(str1)) {
                printf("Chuoi moi dai hon chuoi ban dau\n");
            } else {
                printf("Hai chuoi co do dai bang nhau\n");
            }
        }
        else if (choice == 5) {
            if (str1 == NULL) {
                printf("Chuoi chua duoc nhap!\n");
                continue;
            }
            temp = (char*)malloc((strlen(str1) + 1) * sizeof(char));
            if (temp == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            strcpy(temp, str1);
            int i; 
            for (i = 0; temp[i]; i++) {
                temp[i] = toupper(temp[i]);
            }
            printf("Chuoi in hoa: %s\n", temp);
            free(temp);
        }
        else if (choice == 6) {
            if (str1 == NULL) {
                printf("Chuoi ban dau chua duoc nhap!\n");
                continue;
            }
            if (str2 != NULL) free(str2);
            printf("Nhap chuoi khac de them vao: ");
            char buffer[1000];
            fgets(buffer, 1000, stdin);
            int i; 
            for (i = 0; buffer[i]; i++) {
                if (buffer[i] == '\n') {
                    buffer[i] = '\0';
                    break;
                }
            }
            len2 = strlen(buffer) + 1;
            str2 = (char*)malloc(len2 * sizeof(char));
            if (str2 == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            strcpy(str2, buffer);
            temp = (char*)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
            if (temp == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            strcpy(temp, str1);
            strcat(temp, str2);
            if (str1 != NULL) free(str1);
            str1 = (char*)malloc((strlen(temp) + 1) * sizeof(char));
            if (str1 == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            strcpy(str1, temp);
            free(temp);
            free(str2);
            str2 = NULL;
            printf("Chuoi sau khi them: %s\n", str1);
        }
        else if (choice == 7) {
            if (str1 != NULL) free(str1);
            if (str2 != NULL) free(str2);
            break;
        }
        else {
            printf("Lua chon khong hop le! Vui long chon 1-7.\n");
        }
    }

    return 0;
}
