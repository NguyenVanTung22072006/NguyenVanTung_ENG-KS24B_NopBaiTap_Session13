#include <stdio.h>

void inputMatrix(int *rows, int *cols, int matrix[100][100]){
    printf("Nhap so hang: ");
    scanf("%d", rows);
    printf("Nhap so cot: ");
    scanf("%d", cols);

    for(int i=0; i<*rows; i++){
        for(int j=0; j<*cols; j++){
            printf("Nhap gia tri cho phan tu [%d][%d]: ",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printMatrix(int rows, int cols, int matrix[100][100]){
    printf("Ma tran (%d x %d):\n", rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void printCorners(int rows, int cols, int matrix[100][100]){
    printf("Cac phan tu o goc cua ma tran: \n");
    printf("%d ", matrix[0][0]); 
    if(cols>1){
        printf("%d ", matrix[0][cols-1]); 
    }
    if(rows>1){
        printf("%d ", matrix[rows-1][0]); 
    }
    if(rows>1 && cols>1){
        printf("%d ", matrix[rows-1][cols-1]); 
    }
    printf("\n");
}
void printBorders(int rows, int cols, int matrix[100][100]){
    printf("Cac phan tu tren duong bien cua ma tran: \n");
    for(int i=0; i<cols; i++){
        printf("%d ", matrix[0][i]); 
    }
    for(int i=1; i<rows; i++){
        printf("%d ", matrix[i][cols-1]); 
    }
    for(int i=cols-2; i>=0; i--){
        printf("%d ", matrix[rows-1][i]); 
    }
    for(int i=rows-2; i>0; i--){
        printf("%d ", matrix[i][0]); 
    }
    printf("\n");
}
void printDiagonals(int rows, int cols, int matrix[100][100]){
    printf("Cac phan tu tren duong cheo chinh cua ma tran: \n");
    for(int i=0; i<rows && i<cols; i++){
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
    printf("Cac phan tu tren duong cheo phu cua ma tran: \n");
    for(int i=0; i<rows && i<cols; i++){
        printf("%d ", matrix[i][cols-i-1]);
    }
    printf("\n");
}
int isPrime(int num){
    if(num<2){
        return 0;
    }
    for(int i=2; i<=num/2; i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int rows=0, cols=0, choose;
    int matrix[100][100]={{0}}; 
    do{
        printf("\nMENU\n");
        printf("1. Nhap gia tri ma tran\n");
        printf("2. In ma tran\n");
        printf("3. In cac phan tu o goc\n");
        printf("4. In cac phan tu tren duong bien\n");
        printf("5. In cac phan tu tren duong cheo\n");
        printf("6. In cac phan tu la so nguyen to\n");
        printf("7. Thoat\n");

        printf("\nLua chon cua ban: ");
        scanf("%d", &choose);

        switch (choose){
            case 1:
                inputMatrix(&rows, &cols, matrix);
                break;
            case 2:
                printMatrix(rows, cols, matrix);
                break;
            case 3:
                printCorners(rows, cols, matrix);
                break;
            case 4:
                printBorders(rows, cols, matrix);
                break;
            case 5:
                printDiagonals(rows, cols, matrix);
                break;
            case 6:
                printPrimes(rows, cols, matrix);
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while(choose!=7);

    return 0;
}
