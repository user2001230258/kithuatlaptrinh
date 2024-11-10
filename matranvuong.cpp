#include<stdio.h>
#include <stdlib.h>

void nhapMaTran(int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuatMaTran(int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int tongTamGiacTrenDuongCheoChinh(int **a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {  // Điều kiện này đảm bảo j >= i
            sum += a[i][j];
        }
    }
    return sum;
}

int tongTamGiacDuoiDuongCheoChinh(int **a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j <= i; j++) { 
            sum += a[i][j];
        }
    }
    return sum;
}

int tongDuongCheoChinh(int **a, int n) {
    int sum =0;
    for (int i = 0; i<n;i++) {
        sum+=a[i][i];
    }
    return sum;
}

int tongDuongCheoPhu(int **a, int n) {
    int sum = 0;
    for (int i =0; i < n;i++) {
        sum += a[i][n - i-1];
    }
    return sum;
}

void xuatCacDuongCheoSSVoiDuongCheoChinh(int **a, int n) {
    printf("Cac phan tu thuoc cac duong cheo song song voi duong cheo chinh:\n");
    for (int k = 1;k<n;k++) {
        int i =0;
        int j = k;
        while(j < n) {
            printf("%d ",a[i][j]);
            i++;
            j++;
        }
        printf("\n");
    }
    for (int k = 1;k <n;k++) {
        int i = k;
        int j = 0;
        while (i < n) {
            printf("%d ",a[i][j]);
            i++;
            j++;
        }
        printf("\n");
    }
}

void xuatCacDuongCheoSSVoiDuongCheoPhu(int **a, int n) {
    printf("Cac phan tu nam tren duong cheo song song voi duong cheo phu:\n");
    // Cac duong cheo phia tren 
    for (int k =1 ; k < n;k++) {
        int i = 0; 
        int j = n - k - 1;
        while(j >= 0) {
            printf("%d ",a[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }
    
    // Cac duong cheo phia duoi
    for (int k = 1; k < n;k++) {
        int i =k;
        int j=n - 1;
        while(i < n) {
            printf("%d ",a[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }
}

int main() {
    int n;
    int **a;
    printf("Nhap cap cua ma tran: "); 
    scanf("%d", &n);

    // Cấp phát bộ nhớ cho ma trận
    a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
    }
    
    nhapMaTran(a, n);
    
    printf("Ma tran vuong:\n");
    xuatMaTran(a, n);
    
    xuatCacDuongCheoSSVoiDuongCheoChinh(a,n);
    xuatCacDuongCheoSSVoiDuongCheoPhu(a,n);

    //printf("Tong tam giac tren duong cheo chinh: %d\n", tongTamGiacTrenDuongCheoChinh(a, n));
    //printf("Tong tam giac duoi duong cheo chinh: %d\n", tongTamGiacDuoiDuongCheoChinh(a, n));
    //printf("Tong duong cheo chinh: %d\n",tongDuongCheoChinh(a,n));
    //printf("Tong duong cheo phu: %d\n",tongDuongCheoPhu(a,n));
    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    
    return 0;
}
