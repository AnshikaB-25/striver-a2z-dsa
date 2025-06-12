// choose a pivot ...all elements smaller or equal to pivot on left and greater on right and that position of pivot is partition index...
//do the same of left of PI...and right of PI
//TC-O(n log2(n))....SC....O(1) as no new array is created
#include <bits/stdc++.h>

using namespace std;
int partition(vector < int > & arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (arr[i] <= pivot && i < high) {
                i++;
            }
            while (arr[j] > pivot && j > low) {
                j--;
            }
            if(i<j) swap(arr[i], arr[j]);

        }
        swap(arr[low], arr[j]);
        return j;
    
}

        void quick_sort(vector < int > & arr, int low, int high) {
            if (low < high) {
                int partition_index = partition(arr, low, high);
                quick_sort(arr, low, partition_index - 1);
                quick_sort(arr, partition_index + 1, high);
            }
        }

        int main() {
            int n;
            cin >> n;
            vector < int > arr(n);
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            quick_sort(arr, 0, n - 1);
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }

        }
