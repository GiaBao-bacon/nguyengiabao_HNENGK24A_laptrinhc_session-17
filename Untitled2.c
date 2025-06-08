#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL, n = 0, choice;
    int *max, sum = 0;

    while (1) {
        printf("\nMENU\n");
        printf("Nhap vao so phan tu va tung phan tu\n");
        printf("Hien thi cac phan tu trong mang\n");
        printf("Tinh do dai mang\n");
        printf("Tinh tong cac phan tu trong mang\n");
        printf("Hien thi phan tu lon nhat\n");
        printf("Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (arr != NULL) {
                free(arr); 
            }
            printf("Nhap so phan tu: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            if (arr == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            int i; 
            for (i = 0; i < n; i++) {
                printf("Nhap phan tu thu %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
        }
        else if (choice == 2) {
            if (arr == NULL) {
                printf("Mang chua duoc khoi tao!\n");
                continue;
            }
            printf("Cac phan tu trong mang: ");\
            int i; 
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 3) {
            if (arr == NULL) {
                printf("Mang chua duoc khoi tao!\n");
                continue;
            }
            printf("Do dai mang: %d\n", n);
        }
        else if (choice == 4) {
            if (arr == NULL) {
                printf("Mang chua duoc khoi tao!\n");
                continue;
            }
            sum = 0;
            int i; 
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Tong cac phan tu: %d\n", sum);
        }
        else if (choice == 5) {
            if (arr == NULL) {
                printf("Mang chua duoc khoi tao!\n");
                continue;
            }
            max = arr;
            int i; 
            for (i = 1; i < n; i++) {
                if (arr[i] > *max) {
                    max = &arr[i];
                }
            }
            printf("Phan tu lon nhat: %d\n", *max);
        }
        else if (choice == 6) {
            if (arr != NULL) {
                free(arr);
            }
            break;
        }
        else {
            printf("Lua chon khong hop le! Vui long chon 1-6.\n");
        }
    }

    return 0;
}
