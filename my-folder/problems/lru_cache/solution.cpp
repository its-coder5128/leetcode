class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int x,int y){
        key = x;
        value = y;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
    int size;
    int totElements;
    Node* first;
    Node* last;
    unordered_map<int,Node*> m;
public:
    LRUCache(int capacity) {
        size = capacity;
        totElements = 0;
        first = new Node(-1,-1);
        last = new Node(-1,-1);

        first -> next = last;
        last -> prev = first;
    }

    void addNode(Node* temp)
    {
        temp -> next = first -> next;
        first -> next -> prev = temp;
        temp -> prev = first;
        first -> next = temp;
    }
    void removeNode(Node* temp)
    {
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;

        int x = m[key] -> value;
        removeNode(m[key]);

        Node* temp = new Node(key,x);
        m[key] = temp;

        addNode(temp);

        return x;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            removeNode(m[key]);

            Node* temp = new Node(key,value);
            m[key] = temp;

            addNode(temp);
            return;
        }
            
        Node* temp = new Node(key,value);
        m[key] = temp;

        if(totElements == size)
        {
            int key = last->prev->key;
            m.erase(key);
            totElements--;
            removeNode(last -> prev);
        }

        totElements++;
        addNode(temp);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */