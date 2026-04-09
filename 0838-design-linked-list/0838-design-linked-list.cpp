class MyLinkedList {

public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }
    
    int get(int index) {
        LinkedNode * cur=_dummyHead->next;
        if(index<0||index>(_size-1))
            return -1;
        while(index--)
        {
            cur=cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode * cur=_dummyHead;  
        LinkedNode *NewNode=new LinkedNode(val);
        NewNode->next=cur->next;
        cur->next=NewNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode * cur=_dummyHead;  
        LinkedNode *NewNode=new LinkedNode(val);
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=NewNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>_size-1)
            return ;
        if(index < 0)
        index = 0; 
        LinkedNode * cur=_dummyHead;  
        LinkedNode *NewNode=new LinkedNode(val);
        while(index--)
        {
            cur=cur->next;
        }       
        NewNode->next=cur->next;
        cur->next=NewNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>_size-1)
            return ;
        LinkedNode * cur=_dummyHead;  
        while(index--)
        {
            cur=cur->next;
        }
        LinkedNode * temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        temp=nullptr;
        _size--;
    }
private:
    LinkedNode* _dummyHead;  
    int _size;
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */