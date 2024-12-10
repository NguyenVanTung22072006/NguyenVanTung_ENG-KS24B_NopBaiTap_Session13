#include <stdio.h>

void taoMaTran(int row, int col, int matran[100][100]){
    printf("Nhap gia tri cho ma tran (%d x %d):\n", row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("Phan tu [%d][%d]: ",i,j);
            scanf("%d", &matran[i][j]);
        }
    }
}
void printMaTran(int row, int col, int matran[100][100]){
    printf("Ma tran (%d x %d):\n", row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matran[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int row, col;
    int matran[100][100];
    printf("Nhap so hang: ");
    scanf("%d", &row);
    printf("Nhap so cot: ");
    scanf("%d", &col);
    taoMaTran(row, col, matran);
    printMaTran(row, col, matran);
    return 0;
}
