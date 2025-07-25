class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode(-1);
        ListNode* dummy = newhead;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            int vals = sum;
            if (sum >= 10) {
                vals = sum - 10;
                carry = 1;
            }
            else{ 
                vals = sum;
                carry =0;
            }
            ListNode* newnode = new ListNode(vals);
            dummy->next = newnode;
            dummy = dummy->next;
        }
        return newhead->next;
    }
};
