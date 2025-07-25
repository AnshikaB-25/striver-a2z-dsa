// O(2N)
int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        if (head == NULL || head->next == NULL) return head;
        ListNode *temp = head;
        while (temp != NULL) {
            if (temp->val == 0)
                count0++;
            else if (temp->val == 1)
                count1++;
            else
                count2++;
            temp = temp->next;
        }
        temp = head;

        while (count0 > 0) {
            temp->val = 0;
            temp = temp->next;
            count0--;
        }
        while (count1 > 0) {
            temp->val = 1;
            temp = temp->next;
            count1--;
        }
        while (count2 > 0) {
            temp->val = 2;
            temp = temp->next;
            count2--;
        }
        return head;

//  USING THREE DIFFERENT NODES FOR 0 1 AND 2 AND THEN CONNECTING THEM SO IT CAN BE SINGLE PASS
ListNode* zerohead = new ListNode(-1);
        ListNode* zero = zerohead;
         ListNode* onehead = new ListNode(-1);
        ListNode* one = onehead;
         ListNode* twohead = new ListNode(-1);
        ListNode* two = twohead;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val ==0){
                zero->next = temp;
                zero = zero->next;
            }
            else  if(temp->val ==1){
                one->next = temp;
                one = one->next;
            }
            else  if(temp->val ==2){
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        
        zero->next = (onehead->next !=NULL) ? onehead->next : twohead->next;
        one->next = twohead->next;
        two->next = nullptr;
        return zerohead->next;
