class LRUCache {
    class node{
        public:
        int k;
        int v;
        node* next;
        node* prev;

        node(int key,int val)
        {
            k = key;
            v = val;

            next = NULL;
            prev = NULL;
        }
    };
    int size;
    unordered_map<int,node*> m;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);

    void Add(node* temp)
    {
        temp -> next = head -> next;
        head -> next = temp;
        temp -> prev = head;
        temp -> next -> prev = temp;
    }

    void Remove(node* temp)
    {
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
public:

    LRUCache(int capacity) {
        size = capacity;


        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {

        if(m.find(key) != m.end())
        {
            int val = m[key]->v;

            Remove(m[key]);

            node *temp = new node(key,val);

            m[key] = temp;

            Add(temp);

            return val;

        }
        return -1;
        
    }
    
    void put(int key, int value) {

        if(m.find(key) != m.end())
        {
            Remove(m[key]);

            node *temp = new node(key,value);

            m[key] = temp;

            Add(temp);
        }
        else if(m.size() == size)
        {
            m.erase(tail -> prev -> k);
            Remove(tail->prev);

            node *temp = new node(key,value);

            m[key] = temp;

            Add(temp);
        }
        else
        {
            node *temp = new node(key,value);

            m[key] = temp;

            Add(temp);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */