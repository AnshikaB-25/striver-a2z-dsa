//for inner loop always check the index...for 1st outer loop dont go till the last element in inner loop as there would be nothing by its side to compare.
//this is the code for worst or average tc...ie O(N^2)...but what if the array is alreasy sorted
#include <bits/stdc++.h>

using namespace std;
void bubble_sort(int arr[], int n) {
    for (int i=n-1;i>=1;i--){
            for (int j=0;j<i;j++){
                if (arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
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
    bubble_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


  
  // for best tc... we will insert a break...ie if in the first outer loop there was no swap then break...so TC...O(n)
  #include <bits/stdc++.h>

using namespace std;
void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        int didswap = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }
        if (didswap==0) break;
    }

}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubble_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


}


}
