// selection sort..... swap lowest index with first index
// t.c = O(n^2)

#include <bits/stdc++.h>

using namespace std;
void selection_sort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int minimum = i;
        for (int j = i; j <= n - 1; j++) {
            if (arr[j] < arr[minimum]) minimum = j;
        }
        swap(arr[minimum], arr[i]);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selection_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


}
