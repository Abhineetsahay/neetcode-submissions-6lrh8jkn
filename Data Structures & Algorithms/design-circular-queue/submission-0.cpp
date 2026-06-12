class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyCircularQueue {
   public:
    int size;
    ListNode* left;
    ListNode* right;
    MyCircularQueue(int k) {
        this->size = k;
        left = new ListNode(-1);
        right = new ListNode(-1);
        left->next = right;
        right->prev = left;
    }

    bool enQueue(int value) {
        if(isFull()) return false;

        ListNode* newNode = new ListNode(value);

        newNode->next = right;
        newNode->prev = right->prev;

        right->prev->next = newNode;
        right->prev = newNode;
        size--;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        ListNode* deleteNode = left->next;

        left->next = deleteNode->next;
        left->next->prev = left;
        delete deleteNode;
        size++;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return left->next->val;
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return right->prev->val;
    }

    bool isEmpty() { return left->next == right; }

    bool isFull() { return size == 0; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */