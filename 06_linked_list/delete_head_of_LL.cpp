class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        ListNode*temp = head;
        if(head == NULL ) return NULL;
        head = head->next;
        delete(temp);
        return head;
    }
};
