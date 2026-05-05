/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* newHead = new Node(head->val);
        Node* newTemp = newHead;
        Node* temp = head->next;

        mp[head] = newHead;

        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            newTemp->next = newNode;

            newTemp = newTemp->next;
            temp = temp->next;
        }
        temp = head;
        newTemp = newHead;

        while (temp != nullptr) {
            newTemp->random = mp[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }
        return newHead;
    }
};
