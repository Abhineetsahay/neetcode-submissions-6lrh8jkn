class Node {
   public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->value = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
   public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
            mp.erase(key);
        }

        if (cap == mp.size()) {
            mp.erase(tail->prev->key);
            remove(tail->prev);
        }
        Node* newNode = new Node(key, value);

        mp[key] = newNode;
        insert(newNode);
    }
};
