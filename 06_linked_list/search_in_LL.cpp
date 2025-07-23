struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int data1)
    {
        data = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        data = data1;
        next = next1;
    }
};
class Solution {
public:

    bool searchKey(ListNode* head, int key) {
        ListNode* temp = head;
        while(temp){
            if (temp->data == key) return true; 
            temp = temp->next;
        }
        return false;
    }
};
