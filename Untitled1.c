#include <stdio.h>

int main() {
    int *arr, n, choice;
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
            printf("Nhap so phan tu: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            int i; 
            for (i = 0; i < n; i++) {
                printf("Nhap phan tu thu %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
        }
        else if (choice == 2) {
            printf("Cac phan tu trong mang: ");
            int i; 
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 3) {
            printf("Do dai mang: %d\n", n);
        }
        else if (choice == 4) {
            sum = 0;
            int i; 
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Tong cac phan tu: %d\n", sum);
        }
        else if (choice == 5) {
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
            free(arr);
            break;
        }
    }

    return 0;
}
