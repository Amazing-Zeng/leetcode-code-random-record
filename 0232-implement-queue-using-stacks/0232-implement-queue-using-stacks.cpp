class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
         // 只有当stackOut为空的时候，再从stackIn里导入数据（导入stackIn全部数据）
        if(stackOut.empty())
        {
            while(!stackIn.empty())
            {
                stackOut.push(stackIn.top()); //取出栈顶元素，不会删掉栈里边的元素
                stackIn.pop();  //删除栈顶元素
            } 
        }
        int result=stackOut.top();
        stackOut.pop();
        return result;
    }
    
    int peek() {
        // 输出队列有可能是空的
        int result=this->pop();
        stackOut.push(result);
        return result;
    }
    
    bool empty() {
        return stackIn.empty()&&stackOut.empty();
    }
private:
    std::stack<int, std::vector<int> > stackIn;  // 使用vector为底层容器的栈
    std::stack<int, std::vector<int> > stackOut;  // 使用vector为底层容器的栈

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */