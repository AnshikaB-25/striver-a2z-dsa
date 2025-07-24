class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
         ListNode* slow = head; 
         int count = 0;
        ListNode* fast = head;
        while(fast!= NULL && fast->next !=NULL){
            slow = slow->next;
            count++;
            fast = fast->next->next;
            if(slow == fast) {
                return count;
            }
        }
        return 0;

    }
};
