// MERGE SORT

class Solution {
public:
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergenode(ListNode* lefthead, ListNode* righthead) {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* temp = dummyhead;
        while (lefthead != NULL && righthead != NULL) {
            if (lefthead->val < righthead->val) {
                temp->next = lefthead;
                temp = lefthead;
                lefthead = lefthead->next;
            } else {
                temp->next = righthead;
                temp = righthead;
                righthead = righthead->next;
            }
        }
        if (lefthead != NULL) temp->next = lefthead;
        else temp->next = righthead;
        return dummyhead->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* middle = findmiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next = nullptr;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        head = mergenode(lefthead,righthead);
        return head;
         
    }
};
