#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// khai bao cau truc
typedef struct {
    char maDocGia[11];
    char tenDocGia[41];
    char gioiTinh[4];
    int namSinh;
    char diaChi[51];
} DocGia;

// khai bao mang 1 chieu chua n doc gia
typedef DocGia* DocGiaArray;

// dem so doc gia gioi tinh "Nam"
int demDocGiaNam(DocGiaArray a, int n) {
    int count = 0;
    for (int i = 0;i < n;i++) {
        if (strcmp(a[i].gioiTinh, "Nam") == 0) {
            count++;
        }
    }
    return count;
}

void swap(DocGia *x, DocGia *y) {
    DocGia temp = *x;
    *x = *y;
    *y = temp;
}

// ham sap xep doc gia theo nam sinh giam dan (quick sort)
int partition(DocGiaArray a, int left, int right) {
    int pivot = a[right].namSinh;
    int i = left - 1;
    
    for (int j = left; j <= right - 1; j++) {
        if (a[j].namSinh > pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[right]);
    return i + 1;
}

void quickSort(DocGiaArray a, int left , int right) {
    if (left < right) {
        int p = partition(a, left, right);
        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
    }
}

int main() {
    int n;
    printf("Nhap so luong doc gia: "); scanf("%d", &n);
    
    // kiem tra so luong doc gia
    if (n <= 0) {
        printf("So luong doc gia phai lon hon 0!\n");
        return 1;
    }
    
    
    // khai bao mang chua doc gia
    DocGiaArray a = (DocGiaArray)malloc(n*sizeof(DocGia));
    // nhap thong tin doc gia
    for (int i = 0; i < n;i++) {
        printf("\nNhap thong tin doc gia thu %d\n",i+1);
        printf("Ma doc gia: ");
        scanf("%s",a[i].maDocGia);
        getchar();
        printf("Ten doc gia: ");
        scanf("%[^\n]",a[i].tenDocGia);
        printf("Gioi tinh (Nam/Nu): ");
        scanf("%s",a[i].gioiTinh);
        printf("Nam sinh: ");
        scanf("%d",&a[i].namSinh);
        getchar();
        printf("Dia chi: ");
        scanf("%[^\n]",a[i].diaChi);
    }
    
    // dem so doc gia
    int soDocGiaNam = demDocGiaNam(a,n);
    printf("\nSo luong doc gia nam: %d\n",soDocGiaNam);
    
    // sap xep doc gia
    quickSort(a,0,n-1);
    printf("\nDanh sach doc gia sau khi sap xep theo nam sinh giam dan:\n");
    for (int i = 0; i < n ; i++) {
        printf("\nMa doc gia: %s\n", a[i].maDocGia);
        printf("Ten doc gia: %s\n", a[i].tenDocGia);
        printf("Gioi tinh: %s\n", a[i].gioiTinh);
        printf("Nam sinh: %d\n", a[i].namSinh);
        printf("Dia chi: %s\n", a[i].diaChi);
    }
    
    
    free(a);
    
    
    return 0;
}
