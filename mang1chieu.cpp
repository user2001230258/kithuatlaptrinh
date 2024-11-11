
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void nhapMang(int *a, int n) {
    for (int i = 0; i <n;i++) {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

void xuatMang(int *a, int n) {
    for (int i = 0; i  < n;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1;i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void interchangeSort(int *a, int n) {
    for (int i = 0; i < n - 1;i++) {
        for (int j = i+ 1; j < n;j++) {
            if (a[j] < a[i]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void selectionSort(int *a, int n) {
    for (int i =0; i < n - 1;i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
    }
}

void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+ 1] = a[j];
            j = j -1;
        }
        a[j + 1] = key;
    }
}

int partition(int *a, int l, int r) {
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (1) {
        do {
            i++;
        }while (a[i] < pivot);
        do {
            j--;
        }while(a[j] > pivot);
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else return j;
    }
}

void quickSort(int *a ,int l, int r) {
    if (l>=r) return;
    int p = partition(a,l,r);
    quickSort(a,l,p);
    quickSort(a,p+1,r);
}

void themPhanTu(int **a ,int *n, int x) {
    int maxIndex = 0;
    for (int i = 1; i < *n;i++) {
        if ((*a)[i] > (*a)[maxIndex]) {
            maxIndex = i;
        }
    }
    *a = (int*)realloc(*a, (*n+1)*sizeof(int));
    for (int i = *n; i > maxIndex + 1; i--) {
        (*a)[i] = (*a)[i-1];
    }
    (*a)[maxIndex + 1] = x;
    (*n)++;
}

int timMax(int *a, int n) {
    int max = a[0];
    for (int i =1; i <n;i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n;i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

bool kiemTraSoNguyenTo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i*i <= n;i++) {
        if (n % i ==0) {
            return false;
        }
    }
    return true;
}

void soNguyenTo(int *a, int n) {
    printf("SNT = ");
    for (int i = 0; i < n;i++) {
        if (kiemTraSoNguyenTo(a[i])) {
            printf("%d ",a[i]);
        }
    }
    printf("\n");
}

int linearSearch(int *a,int n, int x) {
    for (int i = 0; i < n;i++) {
        if (a[i] == x) {
            return i; // tra ve chi so phan tu tim thay
        }
    }
    return -1; // tra ve -1 neu k tim thay
}

int binarySearch(int *a, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // kiem tra neu phan tu mid la khoa tim kiem
        if (a[mid] == x) {
            return mid;
        }
        // neu x lon hon, bo qua nua trai
        if (a[mid] < x) {
            left = mid + 1;
        }
        // neu x nho hon, bo qua nua phai
        else {
            right = mid -1;
        }
    }
    return -1;
}

int main()
{
    int n,x,key;
    int *a; 
    printf("Nhap so phan tu cua mang: "); scanf("%d",&n);
    
    a = (int*)malloc(n*sizeof(int));
    nhapMang(a,n);
    //bubbleSort(a,n);
    //interchangeSort(a,n);
    //selectionSort(a,n);
    //insertionSort(a,n);
    //quickSort(a,0,n - 1);
    //printf("Nhap x: "); scanf("%d",&x);
    //themPhanTu(&a,&n,x);
    printf("Mang: ");
    xuatMang(a,n);
    //printf("Max = %d\n",timMax(a,n));
    //printf("Min = %d\n",timMin(a,n));
    //soNguyenTo(a,n);
    printf("Nhap phan tu can tim: "); scanf("%d",&key);
    /*int result = linearSearch(a,n,key);
    if (result != -1) {
        printf("Gia tri %d duoc tim thay tai chi so a[%d]\n",key,result);
    } else {
        printf("Gia tri %d khong ton tai trong mang!",key);
    }*/
    
    int timKiem = binarySearch(a,0,n-1,key);
    if (timKiem != -1) {
        printf("Gia tri %d duoc tim thay tai chi so a[%d]", key, timKiem);
    } else {
        printf("Gia tri %d k ton tai trong mang!", key);
    }
    
    free(a);
   
    return 0;
}
