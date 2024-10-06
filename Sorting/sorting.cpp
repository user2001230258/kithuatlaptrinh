// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Bubble Sort
void bubbleSort(int a[], int n) {
    int temp = 0;
    for (int i = 0;i < n-1;i++) {
        for (int j = 0; j < n -1-i;j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Interchange Sort
void interchangeSort(int a[], int n) {
    int temp = 0;
    for (int i = 0; i < n - 1;i++) {
        for (int j = i+1;j<n;j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } 
        }
    }
}

// Insertion Sort
void insertionSort(int a[] , int n) {
    for (int i = 1; i < n;i++) {
        int x = a[i], pos = i- 1;
        while (pos >= 0 && x < a[pos]) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

// Selection Sort
void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1;i++) {
        int min = i;
        for (int j = i+1; j < n;j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}


void xuatMang(int a[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
   int a[] = {9,8,7,6,2,3,1,5,4};
   int n = sizeof(a)/sizeof(a[0]);
   int choice;
   while(1) {
       printf("1. Bubble Sort\n");
       printf("2. Interchange Sort\n");
       printf("3. Insertion Sort\n");
       printf("4. Selection Sort\n");
       printf("Nhap lua chon: ");
       scanf("%d",&choice);
       
       switch (choice)  {
           case 1:
            bubbleSort(a,n);
            xuatMang(a,n);
            break;
            
            case 2:
                interchangeSort(a,n);
                xuatMang(a,n);
                break;
            
            case 3:
                insertionSort(a,n);
                xuatMang(a,n);
                break;
                
            case 4:
                selectionSort(a,n);
                xuatMang(a,n);
                break;
       }
   }

    return 0;
}
