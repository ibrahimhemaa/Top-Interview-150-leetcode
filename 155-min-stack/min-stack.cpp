class MinStack {
public:
    struct node{
        int num;
        int mn;
        node *next;
    };
    // node *top=nullptr;
    MinStack() {
        
    }
    
    void push(int val) {
        node *v=new node;
        v->num=v->mn=val;
        v->next=nullptr;
        if(topp==nullptr)topp=v;
        else{
            v->mn=min(v->num,topp->mn);
            v->next=topp;
            topp=v;
        }
    }
    
    void pop() {
        topp=topp->next;
    }
    
    int top() {
        return topp->num;
    }
    
    int getMin() {
        return topp->mn;
    }
    node *topp=nullptr;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */