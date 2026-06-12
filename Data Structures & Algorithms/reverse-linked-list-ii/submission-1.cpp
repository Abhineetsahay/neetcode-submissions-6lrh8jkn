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
class Solution {
   private:
    ListNode* reverseList(ListNode* head, ListNode* end) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* preLeft = dummy;

        for (int i = 1; i < left; i++) {
            preLeft = preLeft->next;
        }
        ListNode* start = preLeft->next;
        ListNode* end = start;
        for (int i = left; i < right; i++) {
            end = end->next;
        }
        ListNode* postRight = end->next;
        preLeft->next = reverseList(start, postRight);
        start->next = postRight;
        return dummy->next;
    }
};