// TC - O(2N)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        if(count == 1) return head;
        int n = (count/2) + 1;
        count = 0;
        temp = head;
        while(temp!=NULL){
            count++;
            if(count == n ) return temp;
            temp = temp->next;
        }
        return NULL;
        
    }
};
// OPTIMAL APPROACH - HARE TORTOISE...O(N)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
