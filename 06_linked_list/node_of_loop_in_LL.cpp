class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                fast = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};  


   When the slow and fast pointers meet inside the cycle, it means a loop exists. Let’s say the distance from the head to the start of the cycle is `L`, 
   and the point where they meet is `x` steps ahead into the cycle. Since the fast pointer moves twice as fast, by the time they meet, it has completed full loops in the cycle. 
   This gives the relation `L = R - x` (where `R` is the cycle length), meaning if we now start one pointer from the head and another from the meeting point, and move
   both one step at a time, they will meet exactly at the start of the cycle. That’s why we reset one pointer to the head after detecting the cycle — so they both reach the cycle start together.
