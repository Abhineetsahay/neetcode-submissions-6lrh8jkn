class FreqStack {
   public:
    // freq,ind,value
    priority_queue<pair<pair<int, int>, int>> pq;
    unordered_map<int, int> mp;
    int ind;
    FreqStack() { ind = 0; }

    void push(int val) {
        mp[val]++;
        pq.push({{mp[val], ind++}, val});
    }

    int pop() {
        auto top = pq.top();
        pq.pop();
        mp[top.second]--;
        return top.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */