// BRUTE FORCE TC - O(N/2) + O(N/2) + O(N) = O(2N) .... SC = O(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        vector<int>nums;
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            nums.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) nums.push_back(temp->val);

        temp = head->next;
         while (temp != NULL && temp->next != NULL) {
            nums.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) nums.push_back(temp->val);
        int i = 0;
        temp = head;
        while(temp!=NULL){
            temp->val = nums[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};

// OPTIMAL - O(2 * N/2)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        while(even!= NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
