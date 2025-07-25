class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        ListNode* temp = head;
        while(temp->next !=NULL){
            ListNode* after = temp->next;
            if(temp->val == after->val){
                ListNode* forward = after->next;
                temp->next = forward;
                if(forward!= NULL) forward->prev = temp;
                delete(after);
            }
            else(temp=temp->next);
        }
        return head;
    }
    
};
