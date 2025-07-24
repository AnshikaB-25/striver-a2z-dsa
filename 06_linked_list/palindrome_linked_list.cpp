//BRUTE FORCE
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val != st.top())return false;
            st.pop();
            temp = temp->next;
        }
        return true;
        
    }
};
// OPTIMAL APPROACH - REVERSE THE SECOND HALF AND CHECK
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newNode = reverseList(slow);
        while (head != NULL && newNode != NULL) {
            if (head->val == newNode->val) {
                head = head->next;
                newNode = newNode->next;
            } else
                return false;
        }
        return true;
    }
};
