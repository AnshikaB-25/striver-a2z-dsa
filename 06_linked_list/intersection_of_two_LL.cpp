// BRUTE FORCE: CHEKCING FOR EACH ELEMENT ... O(N1*N2) WORST CASE
// YOU CAN ALSO USE MAP AND STORE NODE AND KEY THIS IS ALSO BRUTE FORCE: TRAVERSE THROUGH EACH LL ONCE AND STORE EACH NODE...O((N1+N2) * LOG N).. LOG N FOR MAP SC-O(N1+N2) IN WORST CASE

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;

        ListNode* tempa = headA;
        while(tempa!=NULL){
            ListNode* tempb = headB;
            while(tempb!= NULL){
                if(tempa == tempb) return tempa;
                tempb=tempb->next;
            }
            
            tempa = tempa->next;
        }
        return NULL;

        
    }
};
// OPTIMAL : INIITATE TWO POINTERS AND MOVE THEM ONE BY ONE IS ONE REACHES END SEND IT TO THE HEAD OF OTHER AND VIVE VERSA...SO TILL COMMON ELEMENT NUMBER OF STEPS WILL BE EQUAL
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if(headA==NULL || headB == NULL) return NULL;
        ListNode* ta = headA;
        ListNode* tb = headB;
        while (ta != tb) {
            tb = tb->next;
            ta = ta->next;
            if (ta == NULL && tb == NULL)
                return NULL;
            if (ta == NULL)
                ta = headB;
            if (tb == NULL)
                tb = headA;
        }
        return ta;
    }
};
