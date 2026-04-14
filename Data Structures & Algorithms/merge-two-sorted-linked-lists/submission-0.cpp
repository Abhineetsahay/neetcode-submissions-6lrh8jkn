class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* mergedList=nullptr;
        if(list1->val<=list2->val){
            mergedList=list1;
            list1=list1->next;
        }
        else{
            mergedList=list2;
            list2=list2->next;
        }
        ListNode* temp=mergedList;
        while(list1&&list2){
            if(list1->val<=list2->val){
               temp->next=list1;
               list1=list1->next;
            }
            else{
               temp->next=list2;
               list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1){
            temp->next=list1;
        }
        else{
            temp->next=list2;
        }
        return mergedList;
    }
};
