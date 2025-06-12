//takes an element and puts it in right place 
//You pick one card at a time and insert it into its correct place among the already sorted cards in your hand.
//T.C ...BEST O(n) for already sorted .... O(n^2) for average and worst

#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
