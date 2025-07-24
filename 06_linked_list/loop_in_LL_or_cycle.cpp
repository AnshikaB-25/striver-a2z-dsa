// BRUTE FORCE - USE MAP AND STORE EACH NODE NOT JUST THE DATA,,,THE NODE
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>mpp;
        ListNode*temp = head;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()) return true;
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};
// BETTER APPROACH - HARE AND TURTLE
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
        
    }
};
