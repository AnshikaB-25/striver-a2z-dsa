//tc - o(2n)
class Solution {
public:
    ListNode* getknode(ListNode* temp, int k){
        ListNode*prev = temp;
        int count = 0;
        while(temp!=NULL){
            prev = temp;
            count++;
            if(count==k){
                return prev;
            }
            temp = temp->next;
        }
        return NULL;
    }
    ListNode* reverselist(ListNode* head) {
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode*prevnode = temp;
        while (temp != NULL) {
            ListNode* kthnode = getknode(temp, k);
            if(kthnode == NULL){
                prevnode->next = temp;
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = nullptr;
            ListNode* newhead = reverselist(temp);
            if(head == temp) head = kthnode;
            else prevnode->next = kthnode;
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};
