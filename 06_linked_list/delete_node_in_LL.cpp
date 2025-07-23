/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next=node->next->next;
        delete (temp);
        
    }
};

| Step | Operation                                        | Resulting List      |
| ---- | ------------------------------------------------ | ------------------- |
| 1    | `node->val = node->next->val` → 5 becomes 1      | `4 → 1 → 1 → 9`     |
| 2    | `temp = node->next` → store original 1           | temp points to 1    |
| 3    | `node->next = node->next->next` → skip the 2nd 1 | `4 → 1 → 9`         |
| 4    | `delete temp` → free the memory                  | `4 → 1 → 9` (clean) |
