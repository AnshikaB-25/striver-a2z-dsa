class Solution {
   public:
    ListNode* reversell(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    ListNode* addOne(ListNode* head) {
        ListNode* newHead = reversell(head);
        ListNode* temp = newHead;
        int carr = 1;
        while (temp!= NULL ) {
            temp->val = temp->val+1;
            if(temp->val < 10){
                carr = 0;
                break;
            }
            else {
                temp->val = 0;
            }
            temp = temp->next;
        }

        if (carr == 0) {
            return reversell(newHead);
        }

        else {
            ListNode* newnode = new ListNode(1);
            head = reversell(newHead);
            newnode->next = head;
            return newnode;
        }
        return NULL;
    }
};

// RECURSIVE
int helper(ListNode *temp){
    ListNode*temp1 = temp;
    if (temp1 == NULL) return 1;
    int carry1 = helper(temp1->next);
    temp->val+=carry1;
    if(temp->val < 10) return 0;
    temp->val = 0;
    return 1;
}
    ListNode *addOne(ListNode *head) {
        ListNode* temp = head;
        int finalcarry = helper(temp);
        if(finalcarry == 1){
            ListNode* newnode = new ListNode(1);
            newnode->next = head;
            return newnode;
        }
        return head;

    }
