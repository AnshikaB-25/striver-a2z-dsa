//T.C = O(n)
#include <bits/stdc++.h>

using namespace std;
bool isSorted(vector < int > & nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] >= nums[i - 1]) {

        }
        else return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        bool ans = isSorted(arr);
        cout << ans;

    }
}
