class Solution {
public:
    void insertatbottom(stack<int> &st , int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        int temp = st.top();
        st.pop();
        insertatbottom(st,ele);
        st.push(temp);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        int temp = st.top();
        st.pop();
        reverseStack(st);
        insertatbottom(st,temp);
    }
};
