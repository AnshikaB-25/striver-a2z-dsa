class Solution {
   public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
         ListNode* temp = head;
         if(head)
        while (temp != NULL) {
           if(temp->val == target){
                ListNode* delnode = temp;
                ListNode* before = temp->prev;
                ListNode* after = temp->next;
                if(before == NULL){
                   head = after;
                }
                else before->next = after;
                if(after != NULL){
                    after->prev = before;
                }
                temp = after;
                delete(delnode);
           }
           else temp = temp->next;
            
            
        }
        return head;
    }
};
