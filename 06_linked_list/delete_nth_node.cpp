//BRUTE FORCE
class Solution {
public:
    ListNode* deleteHead(ListNode*& head) {
        ListNode* temp = head;
        if (head == NULL)
            return NULL;
        head = head->next;
        delete (temp);
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (count == n)
            return deleteHead(head);

        int new1 = count - n ;
        temp = head;
        count = 0;
        while(temp != NULL){
            count++;
            prev = temp;
            temp = temp->next;
            if(count == new1){
                if(temp->next == NULL){
                    prev->next = nullptr;
                    delete(temp);
                    break;
                }
                ListNode* curr = temp->next;
                prev->next = curr;
                temp->next = nullptr;
                delete(temp);
                break;
            }
        }
        return head;
    }
};
 // SAME CODE BETTER FORMAT
class Solution {
public:
    ListNode* deleteHead(ListNode*& head) {
        ListNode* temp = head;
        if (head == NULL)
            return NULL;
        head = head->next;
        delete (temp);
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (count == n)
            return deleteHead(head);

        int new1 = count - n ;
        temp = head;
        count = 0;
        while(temp != NULL){
            count++;
            prev = temp;
            temp = temp->next;
            if(count == new1) break;    
        }
        prev->next = temp->next;
        temp->next = nullptr;
        delete(temp);
        return head;
    }
};
