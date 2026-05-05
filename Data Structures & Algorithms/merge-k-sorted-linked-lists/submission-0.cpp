/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class cmp {
   public:
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (int i = 0; i < n; i++) {
            pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
