#include <stdio.h>
#include<stdlib.h>
void displayMenu();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();


int choice, n;
int *arr = NULL;
int main(){
	do{
		displayMenu();
		switch(choice){
			case 1 :
				menu1();
				break;
			case 2 :
				menu2();
				break;
			case 3 :
				menu3();
				break;
			case 4 :
				menu4();
				break;
			case 5 :		
				menu5();
				break;
			case 6 :
				menu6();
				return 0;	
		}
	}while(choice != 6);
	return 0;
}
void displayMenu(){
	printf("\n\t\t--MENU--\n");
	printf("1.Nhap so phan tu va tung phan tu.\n");
	printf("2.Hien thi cac phan tu trong mang.\n");
	printf("3.Tinh do dai mang.\n");
	printf("4.Tinh tong cac phan tu trong mang.\n");
	printf("5.Hien thi gia tri lon nhat.\n");
	printf("6.Thoat.\n");
	printf("Lua chon cua ban : ");
	scanf("%d", &choice);
}

void menu1(){
	printf("Ban muon nhap bao nhieu phan tu : ");
	scanf("%d", &n);
	
	arr = (int*) malloc(n * sizeof(int));
	
	if(n >= 0){
		int i;
		for(i = 0; i < n; i++){
			printf("Moi ban nhap so thu %d :", i + 1);
			scanf("%d", &arr[i]);
		}
		}else{
			printf("Do dai khong hop le");
	}
}

void menu2(){
	printf("Cac phan tu trong mang : ");
	for(int i = 0 ; i < n ; i++){
		printf("%d\t", arr[i]);
	}
}

void menu3(){
	if(n >= 0){
		printf("Mang co do dai la %d", n);
	}else{
		printf("Khong ton tai mang");
	}
}

void menu4(){
	int sum;
	if(n >= 0){
		printf("Tong cac phan tu trong mang : ");
		for(int i = 0; i < n; i++){
			sum += arr[i];
		}
	}else{
		printf(" ");
	}
	printf("%d", sum);
}

void menu5(){
	for(int i = 0 ; i < n ; i++){
		if(arr[i] > arr[i + 1]){
			arr[i] = arr[i + 1];
		}
	}
}

void menu6(){
	printf("Dang thoat chuong trinh");
}

