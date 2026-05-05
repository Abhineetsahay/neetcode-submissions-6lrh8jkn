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
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* temp = head;

        while (rev != nullptr) {
            ListNode* temp1 = temp->next;
            ListNode* temp2 = rev->next;

            temp->next = rev;
            rev->next = temp1;

            temp = temp1;
            rev = temp2;
        }
    }
};
