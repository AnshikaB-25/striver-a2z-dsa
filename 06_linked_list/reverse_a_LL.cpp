// ITERATIVE APPROACH
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head ==NULL || head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!= NULL){
            ListNode* nextnode = curr->next;
            curr->next = prev;
             prev = curr;
            curr = nextnode;   
        } 
        return prev;
    }
};
// RECURSIVE
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode*newHead =reverseList(head->next);
        ListNode*front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;

    }
};
