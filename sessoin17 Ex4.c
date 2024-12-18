#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void displayMenu();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
int menu6();
void menu7();

int *arr = NULL;
int choice, n;

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
				break;
			case 7 :
				menu7();
				break;		
		}
	}while(choice != 7);
	return 0;
}
//In ra MENU va lua chon cua nguoi dung
void displayMenu(){
	printf("\n\t\t---MENU--\n");
	printf("1.Nhap vao so phan tu va tung phan tu.\n");
	printf("2.In ra cac phan tu la so chan.\n");
	printf("3.In ra cac phan tu la so nguyen to.\n");
	printf("4.Dao nguoc mang.\n");
	printf("5.Sap xep mang.\n");
	printf("6.Nhap vao mot phan tu vao tim kiem phan tu trong mang\n");
	printf("7.Thoat.\n");
	printf("----> Lua chon cua ban : ");
	scanf("%d", &choice);
}
//Menu 1: Nhap vao so phan tu va tung phan tu
void menu1(){
	printf("Ban muon nhap bao nhieu phan tu : ");
	scanf("%d", &n);
	arr = (int *) malloc(n *sizeof(int));
	for(int i = 0 ; i < n ; i++){
		printf("Moi ban nhap phan tu thu %d : ", i + 1);
		scanf("%d", &arr[i]);
	}
}
//Menu 2: In ra cac phan tu la so chan
void menu2(){
	printf("Cac phan tu la so chan : ");
	for(int i = 0 ; i < n ; i++){
		if(arr[i] % 2 == 0){
			printf("%d\t", arr[i]);
		}
	}
}
//Menu 3: In ra cac phan tu la so nguyen to
void menu3(){
	printf("Cac phan tu la so nguyen to la : ");
	for(int i = 0 ; i < n ; i++){
		for(int i = 0 ;i < n ; i++){
			if(arr[i]==2){
				printf("%d\t", arr[i]);
			}
			for(int j = 2 ; j * j < arr[i] ; j++){
				if(arr[i] % j == 0){
					printf("%d\t", arr[i]);
					break;
				}
			}
		}
	}
}
//Menu 4: Dao nguoc mang
void menu4(){
	printf("Mang da dao nguoc : ");
	for(int i = n ; i >= 0 ; i--){
		if(arr[i] == '\0'){
			printf("\t");
			continue;
		}
		printf("%d\t", arr[i]);
	}
}
//Menu 5: Sap xep mang
void menu5(){
	char choab;
	printf("Ban muon sap xep theo ");
	printf("\na.Tang dan.");
	printf("\nb.Giam dan.");
	printf("\nLua chon cua ban : ");
	scanf("%s", &choab);
	// sap xep tang dan
	if(choab == 'a'){
		for(int i = 0; i < n - 1 ; i++){
			for(int j = 0; j < n - i - 1; j++){
				if(arr[j]>arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}	
			}
		}
		printf("Mang sau khi duoc sap xep theo yeu cau : ");
		for( int i = 0 ; i < n ; i++){
			printf("%d\t", arr[i]);
		}
	}
	// sap xep giam dan
	if(choab == 'b'){
		for(int i = 0; i < n - 1 ; i++){
			for(int j = 0; j < n - i - 1; j++){
				if(arr[j] < arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}	
			}
		}
		printf("Mang sau khi duoc sap xep theo yeu cau : ");
		for( int i = 0 ; i < n ; i++){
			printf("%d\t", arr[i]);
		}
	}
}
//Menu 6: Nhap vao mot gia tri va tim kiem gia tri do trong mang 
int menu6(int *arr , int n , int addNum){
	printf("Ban muon tim gia tri nao : ");
	scanf("%d", &addNum);
	for(int i = 0 ; i < n ; i++){
		if(arr[i] == addNum){
			printf("Phan tu ban dang tim o vi tri %d", i);
		}
	}
}
// Menu 7: Thoat
void menu7(){
	printf("Dang thoat khoi chuong trinh");
	for(int i = 0 ; i < 4 ; i++){
		printf("|\n");
	}
	printf("Hen gap lai !!!");
}
