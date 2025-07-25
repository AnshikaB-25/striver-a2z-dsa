/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
   public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        ListNode* left = head;
        ListNode* temp = head;
        ListNode* right = head;
        vector<vector<int>> ans;
        while (temp != NULL) {
            right = temp;
            temp = temp->next;
        }
        while (left->val < right->val) {
            if (left->val + right->val == target) {
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            } else if (left->val + right->val > target)
                right = right->prev;
            else
                left = left->next;
        }
        return ans;
    }
};
