// TC - O(N) + O(newtailindex)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        int count = 0;
        ListNode* temp = head;
        ListNode* temp1 = head;
        while(temp!= NULL){
            count++;
            temp1=temp;
            temp = temp->next;
        }
        if(k%count == 0) return head;
        else{
            k = k%count;
        }
        int newtailindex = count-k;
        int newheadindex = count-k+1;
        temp = head;
        ListNode* newtail = head;
        ListNode*newhead = head;
        count = 0;
        while(temp!= NULL){
            count++;
            if(count==newtailindex){
                newtail = temp;
                newhead = temp->next;
                break;
            }
            else temp = temp->next;
        }
        newtail->next = nullptr;
        temp1->next = head;
        return newhead;

        
    }
};
