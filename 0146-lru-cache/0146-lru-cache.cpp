class Node{
    public: 
    int key; 
    int value; 
    Node* prev; 
    Node* next; 
    Node(int k, int v){
        key = k; 
        value = v; 
        prev = NULL; 
        next = NULL; 
    }
};


class LRUCache {
public:
int capacity ; 
unordered_map<int, Node*>mp; 
Node* head; 
Node* tail; 
    LRUCache(int capacity) {
        this->capacity = capacity; 
        head = new Node(-1,-1); 
        tail = new Node(-1,-1); 
        head->next = tail; 
        tail->prev = head; 


    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
        return -1; 
        Node* node = mp[key]; 
        deleteNode(node); 
        addNode(node); 
        return node->value; 

    }
    
    void put(int key, int value) {
        // Case 1: Key exist
        if(mp.find(key) != mp.end()){
            Node* node = mp[key]; 
            node->value = value; 
            deleteNode(node); 
            addNode(node); 
            return;
        }
       // case 2: key doesn't exist and cache not full
      else if(mp.size() < capacity){
        Node* node = new Node(key, value); 
        mp[key] = node; 
        addNode(node); 
        return; 
       }
        // case 3 : cache full
        else{
        Node* lru = tail->prev; 
        mp.erase(lru->key); 
        deleteNode(lru); 
        delete lru; // address release 
        Node* node = new Node(key, value); 
        mp[key] = node; 
        addNode(node); 
        }
    }
        
void addNode(Node* node){
    node->next= head->next; 
    node->prev= head; 
    head->next->prev = node; 
    head->next = node; 
}

void deleteNode(Node* node){
    Node* prevNode = node->prev; 
    Node* nextNode = node->next; 

    prevNode->next = nextNode; 
    nextNode->prev = prevNode; 
}
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */