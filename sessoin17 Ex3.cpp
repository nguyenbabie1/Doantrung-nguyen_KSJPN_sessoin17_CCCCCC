#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu();
void choice1();
void choice2();
void choice3();
void choice4();
void choice5();
void choice6();
void choice7();
char *arr = NULL;
int choice, n;
int main() {
    do {
        displayMenu();
        switch(choice) {
            case 1 :
                choice1();
                break;
            case 2 :
                choice2();
                break;
            case 3 :
                choice3();
                break;
            case 4 :
                choice4();
                break;
            case 5 :
                choice5();                
                break;
            case 6 :
                choice6();
                break;
            case 7 :
                choice7();
                break;        
        }
    } while(choice != 7);
    return 0;
}

// In ra cac lua chon trong menu
void displayMenu() {
    printf("\n---MENU--\n");
    printf("1. Nhap chuoi.\n");
    printf("2. In ra chuoi dao nguoc.\n");
    printf("3. Dem so phan tu trong chuoi.\n");
    printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau (Ket qua in ra la dai hoac ngan hon chuoi ban dau).\n");
    printf("5. In hoa tat ca chu cai trong chuoi.\n");
    printf("6. Nhap vao mot chuoi khac va them no vao chuoi ban dau.\n");
    printf("7. Thoat.\n");
    printf("Hay nhap lua chon cua ban: ");
    scanf("%d", &choice);
    getchar();
}

//Menu 1: Nhap vao chuoi
void choice1() {
    printf("Hay nhap do dai chuoi: ");
    scanf("%d", &n);
    getchar();
    arr = (char *)malloc((n + 1) * sizeof(char));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }

    printf("Hay nhap chuoi ma ban muon: ");
    fgets(arr, n + 1, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    printf("Chuoi ban da nhap: %s\n", arr);
}

// Menu 2: In ra chuoi dao nguoc
void choice2() {
    if (arr == NULL) {
        printf("Chua co chuoi duoc nhap!\n");
        return;
    }
    
    printf("Chuoi dao nguoc là: ");
    for (int i = strlen(arr) - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
    printf("\n");
}
// Menu 3: Dem so phan tu trong chuoi
void choice3() {
    if (arr == NULL) {
        printf("Chua co chuoi duoc nhap!\n");
        return;
    }

    int length = strlen(arr);
    printf("So phan tu trong chuoi: %d\n", length);
}

// Menu 4: Nhap vao mot chuoi moi va so sanh voi chuoi ban dau
void choice4() {
    if (arr == NULL) {
        printf("Chua co chuoi nao duoc nhap!\n");
        return;
    }

    char str2[100];
    printf("Nhap chuoi moi: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    int len1 = strlen(arr);
    int len2 = strlen(str2);

    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi dai bang nhau.\n");
    }
}

// Menu 5: In hoa tat ca chu cai trong chuoi
void choice5() {
    if (arr == NULL) {
        printf("Chua co chuoi nao duoc nhap!\n");
        return;
    }

    for (int i = 0; arr[i]; i++) {  // Duy?t chu?i
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            arr[i] = arr[i] - 'a' + 'A';  // Chuy?n thành ch? hoa
        }
    }
    printf("Chuoi sau khi in hoa: %s\n", arr);
}

// Menu 6: Nhap vao mot chuoi khac va them vao chuoi ban dau
void choice6() {
    if (arr == NULL) {
        printf("Chua chuoi nao duoc nhap!\n");
        return;
    }

    char str2[100];
    printf("Nhap chuoi can them: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    arr = (char *)realloc(arr, (strlen(arr) + strlen(str2) + 1) * sizeof(char));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }
    strcat(arr, str2);
    printf("Chuoi sau khi noi: %s\n", arr);
}
// Menu 7: Thoat chuong trình
void choice7() {
    printf("Thoat chuong trinh.\n");
    free(arr);
}

