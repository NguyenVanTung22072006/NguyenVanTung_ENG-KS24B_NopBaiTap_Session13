#include<stdio.h>

void addAllItem(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("Nhap phan tu thu arr[%d]: ",i);
		scanf("%d", &arr[i]);
	}
}
void showItems(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("Phan tu thu arr[%d] co gia tri %d \n",i,arr[i]);
	}
}
void addIndex(int arr[], int *size, int position, int value){
    for(int i=*size; i>=position; i--){
        arr[i] = arr[i-1];
    }
    arr[position] = value;
    (*size)++;
    printf("Mang sau khi chen: \n");
    showItems(arr, *size);
}
void editItem(int arr[], int size, int position, int value){
	arr[position]=value;
	printf("Mang sau khi sua: \n");
	showItems(arr, size);
}
void deleteIndex(int arr[], int *size, int position){
	for(int i=position-1; i<*size-1; i++){
		arr[i]=arr[i+1];
	}
	(*size)--;
	printf("Mang sau khi xoa: \n");
	showItems(arr, *size);
}
int main(){
	int arr[100];
	int size=0;
	int choose;
	do{
		printf("\n1. Nhap so phan  tu can nhap va gia tri cac phan tu \n");
		printf("2. In ra gia tri cac phan tu dang quan ly \n");
		printf("3. Them mot phan tu vao vi tri chi dinh \n");
		printf("4. Sua mot phan tu o vi tri chi dinh \n");
		printf("5. Xoa mot phan tu o vi tri chi dinh \n");
		printf("6. Sap xep cac phan tu(khi lua chon menu cha thi hien thu menu con): a.Giam dan b.Tang dan\n");
		printf("7. Tim kiem phan tu nhap vao a.Tim kiem tuyen tinh b.Tim kiem nhi phan \n");
		printf("Moi ban chon case: ");
		scanf("%d", &choose);
		switch(choose){
			case 1:
				printf("Moi ban nhap so luong phan tu: ");
				scanf("%d", &size);
				addAllItem(arr,size);
				break;
			case 2:
				showItems(arr,size);
				break;
			case 3:{
				int position, value;
			    printf("Nhap vi tri chen phan tu: ");
	            scanf("%d", &position);
	            printf("Nhap phan tu muon chen: ");
	            scanf("%d", &value);
	            addIndex(arr,&size,position,value);
	            break;
			}
		    case 4:{
		    	int position, value;
		    	printf("Nhap vi tri muon sua: ");
                scanf("%d", &position);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                editItem(arr, size, position, value);
				break;
			}
			case 5:{
                int position;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &position);
                deleteIndex(arr, size, position);
                break;
            }
            default:
                printf("Lua chon khong hop le\n");
                break;
		}
		
	}while(1);
	
	return 0;
}
