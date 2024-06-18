class Node{
public:

    bool flag = false;
    Node* list[26];

    bool isContain(char c)
    {
        return list[c-'a'] != NULL;
    }
    void createLink(char c)
    {
        list[c-'a'] = new Node();
    }
    Node* goTo(char c)
    {
        return list[c-'a'];
    }
    void ended()
    {
        flag = true;
    }
    bool isEnded(){
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {

        int n = word.size();
        Node* temp = root;
        for(int i= 0;i<n;i++)
        {
            if(!(temp -> isContain(word[i])))
            {
                temp -> createLink(word[i]);
            }

            temp = temp -> goTo(word[i]);
        }

        temp -> ended();
        
    }
    
    bool search(string word) {
        int n = word.size();
        Node* temp = root;
        for(int i= 0;i<n;i++)
        {
            if(!(temp -> isContain(word[i])))
            {
                return false;
            }

            temp = temp -> goTo(word[i]);
        }

        return temp -> isEnded();
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* temp = root;
        for(int i= 0;i<n;i++)
        {
            if(!(temp -> isContain(prefix[i])))
            {
                return false;
            }

            temp = temp -> goTo(prefix[i]);
        }

        return temp != NULL;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */