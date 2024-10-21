#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    // Ben trai: left -> mid
    int len_left = mid - left + 1;
    // Ben phai: mid + 1 -> right
    int len_right = right - mid;
    
    // Tao mang tam thoi
    int a_left[len_left];
    int a_right[len_right];
    
    // Copy du lieu tu mang a[] vao 2 mang tam thoi
    for (int i = 0; i < len_left; i++) {
        a_left[i] = a[left+i];
    }
    for (int i = 0; i < len_right; i++) {
        a_right[i] = a[mid+1+i];
    }
    
    // Gop 2 mang theo quy tac phan tu nho hon vao truoc
    int i1 = 0; // Vi tri hien tai cua phan tu mang ben trai
    int i2 = 0; // Vi tri hien tai cua phan tu mang ben phai
    int k = left;
    while(i1 < len_left && i2 < len_right) {
        if(a_left[i1] <= a_right[i2]) {
            a[k] = a_left[i1];
            i1++;
        } else {
            a[k] = a_right[i2];
            i2++;
        }
        k++;
    }
    
    // Copy nhung phan tu cua mang ben trai chua duoc vao
    while(i1 < len_left) {
        a[k] = a_left[i1];
        i1++;
        k++;
    }
    while(i2 < len_right) {
        a[k] = a_right[i2];
        i2++;
        k++;
    }
    
}


void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a,left,mid,right);
    }
}


int main() {
    int a[1000], n; cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n;i++) cin>>a[i];
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    return 0;
}
