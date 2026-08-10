class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int limit;

    void add(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node; 
    }

    void del(Node* node) {
        Node* Oprev = node->prev;
        Node* Onext = node->next;

        Oprev->next = Onext;
        Onext->prev = Oprev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* ans = mp[key];
        int res = ans->val;

        mp.erase(key);
        del(ans);

        add(ans);
        mp[key] = ans;

        return res;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            del(temp);
            mp.erase(key);
        }

        if (mp.size() == limit) {
            mp.erase(tail->prev->key);
            del(tail->prev);
        }

        Node* temp = new Node(key, value);
        add(temp);
        mp[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */