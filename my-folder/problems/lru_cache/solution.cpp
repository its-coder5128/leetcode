class LRUCache {
public: 
    class node{
        public:
        int key;
        int value;
        node* next;
        node* prev;

        node(int k,int v)
        {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    int cap;
    unordered_map<int,node*> mp;

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void addNode(node* newNode)
    {
        node* temp = head -> next;

        head -> next = newNode;
        newNode -> next = temp;

        temp -> prev = newNode;
        newNode -> prev = head;
    }
    void deleteNode(node* newNode)
    {
        newNode -> prev -> next = newNode -> next;
        newNode -> next -> prev = newNode -> prev;
    }
    int get(int key) {

        if(mp.find(key) != mp.end())
        {
            int res = mp[key] -> value;

            node* temp = new node(key,mp[key] -> value);

            deleteNode(mp[key]);
            mp.erase(key);

            addNode(temp);
            mp[key] = temp;

            return res;


        }
        
        return  -1;
        
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end())
        {
            deleteNode(mp[key]);
            mp.erase(key);
        }
        if(mp.size() == cap)
        {
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        node* temp = new node(key,value);
        mp[key] = temp;
        addNode(temp);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */