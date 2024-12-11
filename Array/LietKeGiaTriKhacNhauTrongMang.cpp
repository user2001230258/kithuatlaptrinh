#include <iostream>
using namespace std;

input  : 5 4 3 2 2 1 4 5 3 1
output : 5 4 3 2 1

int main() {
    int n = 10;
    int a[10] = {5, 4, 3, 2, 2, 1, 4, 5, 3, 1};
    bool check = false;
    for (int i = 0; i < n;i++) {
        check = false;
        // Duyet cac phan tu tu [0, i-1]
        for (int j = 0; j < i;j++) {
            if (a[j] == a[i]) {
                // Da tim thay
                check = true;
                break;
            }
        }
        if (check == false) {
            cout << a[i] << " ";
        }
    }

    return 0;
}