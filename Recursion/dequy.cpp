#include <stdio.h>

void nhapN(int &n) {
    do {
        printf("Nhap so phan tu: "); scanf("%d",&n);
    }while(n <= 0 || n > 100);
}

void nhapMang(int a[], int n) {
    if (n==0) return; 	// Dieu kien dung
    nhapMang(a,n-1);	// Da nhap n-1 phan tu: a[0] -> a[n-2]
    printf("a[%d] = ",n-1); scanf("%d",&a[n-1]); // Nhap phan tu cuoi cung
}

void xuatMang(int a[], int n) {
	if(n==0) return;
	xuatMang(a,n-1);
	printf("%d ", a[n-1]);
}

int tongMang(int a[], int n) {
	if (n==0) return 0;
	int tong;
	tong = tongMang(a, n-1);
	tong += a[n-1];
	return tong;
}

int tichMang(int a[], int n) {
	if(n==0) return 1; // Tra ve 1 vi tich cua mang rong la 1
	int tich = tichMang(a,n-1);
	tich *= a[n-1];
	return tich;
}

int tongSoChan(int a[], int n) {
	if (n==0) return 0;
	int tong = tongSoChan(a,n-1);
	if(a[n-1]%2==0) tong += a[n-1];
	return tong;
}

int tongSoLe(int a[], int n) {
	if(n==0) return 0;
	int tong = tongSoLe(a, n-1);
	if(a[n-1]%2!=0) tong += a[n-1];
	return tong;
}

int demSoDuong(int a[], int n) {
	if(n==0) return 0; // Mang k co phan tu duong
	int dem = demSoDuong(a, n-1);
	if(a[n-1] > 0) dem++;
	return dem;
}

int timMax(int a[], int n) {
	if(n==1) return a[0]; // Neu mang cho co 1 phan tu duy nhat thi phan tu do la max
	int max = timMax(a, n-1);
	if (a[n-1] > max) max = a[n-1];
	return max;
}

int timMin(int a[], int n) {
	if(n==1) return a[0]; // Neu mang cho co 1 phan tu duy nhat thi phan tu do la min
	int min = timMin(a, n-1);
	if(a[n-1] < min) min = a[n-1];
	return min;
}

int soChanCuoi(int a[], int n) {
	if(n==0) return -1; // Neu mang k co phan tu chan thi return -1
	int chancuoi = soChanCuoi(a,n-1);
	if(a[n-1] % 2==0) chancuoi = a[n-1];
	return chancuoi;
}

int viTriXCuoi(int a[], int n, int x) {
	if(n==0) return -1; 
	int vitri = viTriXCuoi(a, n-1,x);
	if(a[n-1] == x) vitri = n-1;
	return vitri;
}

int main() {
    int a[100], n;
    nhapN(n);
    
    nhapMang(a,n);
    printf("Mang vua nhap: ");
    xuatMang(a,n);
    
    printf("\nTong mang = %d", tongMang(a,n));
    
    printf("\nTich mang = %d", tichMang(a,n));
    
    printf("\nTong so chan = %d", tongSoChan(a,n));
    
    printf("\nTong so le = %d", tongSoLe(a,n));
    
    printf("\nSo phan tu duong = %d", demSoDuong(a,n));
    
    printf("\nMax = %d", timMax(a,n));
    
    printf("\nMin = %d", timMin(a,n));
    
    int chancuoi = soChanCuoi(a,n);
    if(chancuoi==-1) printf("\nMang k co phan tu chan!");
    else printf("\nPhan tu chan cuoi = %d", chancuoi);
    
   	int x; 
   	printf("\nNhap gia tri muon tim: "); scanf("%d",&x);
   	int vitri = viTriXCuoi(a,n,x);
   	if(vitri == -1) printf("\nTrong mang khong co phan tu %d!",x);
   	else printf("\nPhan tu %d nam o vi tri %d", x, vitri);
    
    return 0;
}
