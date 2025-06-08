#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL, n = 0, choice, subChoice, search;
    int *temp;

    while (1) {
        printf("\nMENU\n");
        printf("Nhap vao so phan tu va tung phan tu\n");
        printf("In ra cac phan tu la so chan\n");
        printf("In ra cac phan tu la so nguyen to\n");
        printf("Dao nguoc mang\n");
        printf("Sap xep mang\n");
        printf("Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (arr != NULL) free(arr);
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
                printf("Mang chua duoc nhap!\n");
                continue;
            }
            printf("Cac phan tu la so chan: ");
            int i; 
            for (i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n");
        }
        else if (choice == 3) {
            if (arr == NULL) {
                printf("Mang chua duoc nhap!\n");
                continue;
            }
            printf("Cac phan tu la so nguyen to: ");
            int i; 
            for (i = 0; i < n; i++) {
                int isPrime = 1;
                if (arr[i] <= 1) isPrime = 0;
                int j; 
                for (j = 2; j * j <= arr[i]; j++) {
                    if (arr[i] % j == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime) printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 4) {
            if (arr == NULL) {
                printf("Mang chua duoc nhap!\n");
                continue;
            }
            temp = (int*)malloc(n * sizeof(int));
            if (temp == NULL) {
                printf("Khong du bo nho!\n");
                return 1;
            }
            int i; 
            for (i = 0; i < n; i++) {
                temp[i] = arr[n - 1 - i];
            } 
            for (i = 0; i < n; i++) {
                arr[i] = temp[i];
            }
            free(temp);
            printf("Mang da duoc dao nguoc\n");
        }
        else if (choice == 5) {
            if (arr == NULL) {
                printf("Mang chua duoc nhap!\n");
                continue;
            }
            printf("Sap xep mang\n");
            printf("1. Tang dan\n");
            printf("2. Giam dan\n");
            printf("Lua chon cua ban: ");
            scanf("%d", &subChoice);
            if (subChoice == 1) {
            	int i; 
                for (i = 0; i < n - 1; i++) {
                	int j; 
                    for (j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int t = arr[i];
                            arr[i] = arr[j];
                            arr[j] = t;
                        }
                    }
                }
                printf("Mang da duoc sap xep tang dan\n");
            }
            else if (subChoice == 2) {
            	int i; 
                for (i = 0; i < n - 1; i++) {
                	int j; 
                    for (j = i + 1; j < n; j++) {
                        if (arr[i] < arr[j]) {
                            int t = arr[i];
                            arr[i] = arr[j];
                            arr[j] = t;
                        }
                    }
                }
                printf("Mang da duoc sap xep giam dan\n");
            }
        }
        else if (choice == 6) {
            if (arr == NULL) {
                printf("Mang chua duoc nhap!\n");
                continue;
            }
            printf("Nhap phan tu can tim: ");
            scanf("%d", &search);
            int found = 0;
            int i; 
            for (i = 0; i < n; i++) {
                if (arr[i] == search) {
                    printf("Tim thay %d tai vi tri %d\n", search, i);
                    found = 1;
                }
            }
            if (!found) printf("Khong tim thay %d\n", search);
        }
        else if (choice == 7) {
            if (arr != NULL) free(arr);
            break;
        }
        else {
            printf("Lua chon khong hop le! Vui long chon 1-7.\n");
        }
    }

    return 0;
}
