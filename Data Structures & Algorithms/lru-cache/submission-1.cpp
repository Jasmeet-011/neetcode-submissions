
class LRUCache {
public:
    struct Node{
    Node* prev; 
    Node* next;
    int key,val;
    Node(int k, int v){
        this->key =k;
        this->val=v;
        prev=NULL;
        next= NULL;
    }
};
    int capacity;
    unordered_map<int, Node*>cache;
    Node*head;
    Node*tail;
    void addToFront(Node* node){
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void moveToFornt(Node* node){
        removeNode(node);
        addToFront(node);
    }

    
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;

        
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())return-1;
        Node* node=cache[key];
        moveToFornt(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end()){
        Node* node=cache[key];
        node->val=value;
        moveToFornt(node);
        return;
        }
        if(cache.size()==capacity){
            Node* node=tail->prev;
            removeNode(node);
            cache.erase(node->key);
            delete node;
        }
        Node* node=new Node(key,value);
        addToFront(node);
        cache[key]=node;
        
    }
};
