class Solution {
   public:
    void insertinorder(stack<int> &st, int ele) {
        if (st.empty() || st.top() <= ele) {
            st.push(ele);
            return;
        }
        int temp =st.top();
        st.pop();
        insertinorder(st,ele);
        st.push(temp);
    }
    void sortStack(stack<int> &st) {
        if (st.empty()) return;
        int temp = st.top();
        st.pop();
        sortStack(st);
        insertinorder(st, temp);
    }
};
