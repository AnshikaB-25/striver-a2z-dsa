/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/
// TC - o(2n) + o(nlog n) where n is total number if elements and sc is o(N)
class Solution {
public:
    ListNode* convertchild(vector<int>&ans){
        if(ans.size() == 0 ) return NULL;
        ListNode* newhead = new ListNode(ans[0]);
        ListNode* temp = newhead;
        for(int i = 1; i<ans.size(); i++){
            ListNode* newnode = new ListNode(ans[i]);
            temp->child = newnode;
            newnode->next = nullptr;
            temp=temp->child;
        }
        return newhead;
    }
    ListNode* flattenLinkedList(ListNode* &head) {
        ListNode* temp = head;
        ListNode* t2 = head;
        vector<int>ans;
        while(temp!= NULL){
            t2 =temp;
            while(t2 != NULL){
                ans.push_back(t2->val);
                t2 = t2->child;     
            }
            temp = temp->next;
        }
        sort(ans.begin(), ans.end());
        ListNode* newhead = convertchild(ans);
        return newhead;
    }
};
// RECURSIVE APPROACH
class Solution {
public:
    ListNode* merge(ListNode* &head , ListNode* &mergehead){
        ListNode* dummynode = new ListNode(-1);
        ListNode*temp = dummynode;
        while(head!= NULL && mergehead!= NULL){
            if(head->val < mergehead->val){
                temp->child = head;
                temp = head;
                head = head->child;
            } else{
                temp->child = mergehead;
                temp = mergehead;
                mergehead = mergehead->child;
            }
        }
        if(head!= NULL) temp->child = head;
        else if(mergehead!= NULL) temp->child = mergehead;
        return dummynode->child;
    }
    ListNode* helper(ListNode* &head){
        if( head == NULL || head->next == NULL) return head;
        ListNode* mergehead = helper(head->next);
         mergehead = merge(head,mergehead);
         return mergehead;

    }
    ListNode* flattenLinkedList(ListNode* &head) {
        ListNode* newhead = helper(head);
        return newhead;

    }
};
