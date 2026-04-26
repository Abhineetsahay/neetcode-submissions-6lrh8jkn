class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow!=nullptr){
            st.push(slow);
            slow=slow->next;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int i=1;
        temp->next=head;
        temp=temp->next;
        head=head->next;
        while(head && !st.empty()){
            if(i%2==1){
                temp->next=st.top();
            }
            else{
                temp->next=head;
                head=head->next;
            }
        }
        head=dummy->next;
    }
};
