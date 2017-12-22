struct listnode {
    int key, val ; 
    listnode *next, *prev ;
    listnode(int x, int y) : key(x), val(y), next(NULL), prev(NULL) {}  
} ; 

class LRUCache {
public:
    void getnode(listnode* now) {
        listnode *t1 = now->prev, *t2 = now->next ; 
        if ( t1 != NULL ) 
            t1->next = t2 ;
        else if ( now == head ) {
            head = t2 ;
            if ( t2 ) 
                head->prev = NULL ; 
        }
        
        if ( t2 != NULL )  
            t2->prev = t1 ; 
        else if ( now == tail ) {
            tail = t1 ; 
            if ( t1 ) 
                tail->next = NULL ; 
        } 
        now->prev = NULL ; 
        now->next = NULL ;
    }
    
    void addnode(listnode* now) { 
        if ( head == NULL ) {
            head = tail = now ; 
            return ; 
        } 
        now->next = head ; 
        now->prev = NULL ; 
        head->prev = now ; 
        head = now ; 
        return ; 
    }
    
    void movetail() { 
        help.erase(tail->key) ;
        tail = tail->prev ; 
        if ( tail )
            tail->next = NULL ;
        index-- ; 
    }
    
    LRUCache(int capacity) {
        index = 0 ; 
        all = capacity ; 
        head = tail = NULL ; 
    }
    
    int get(int key) {
        if ( help.count(key) == 0 ) 
            return -1 ; 
        listnode* tmp = help[key] ; 
        getnode(tmp) ; 
        addnode(tmp) ; 
        return tmp->val ; 
    }
    
    void put(int key, int value) {
        if ( help.count(key) == 1 ) {
            help[key]->val = value ; 
            listnode* tmp = help[key] ; 
            getnode(tmp) ; 
            addnode(tmp) ;
            return ; 
        }   
        while ( index >= all  ) 
            movetail() ; 
        index++ ; 
        listnode* tmp = new listnode (key,value) ; 
        help[key] = tmp ; 
        addnode(tmp) ; 
        return ;
    }
private: 
    int index, all ;
    listnode *head, *tail ; 
    map <int,listnode*> help ; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */