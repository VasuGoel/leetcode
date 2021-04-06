class MyCircularQueue {
    vector<int> q;
    int front = 0, rear = -1, len = 0, k;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): k(k) {
        q.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())    return false;
        
        rear = (rear + 1) % k;
        q[rear] = value;
        len++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())   return false;
        
        front = (front + 1) % k;
        len--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() { 
        return !isEmpty() ? q[front] : -1; 
    }
    
    /** Get the last item from the queue. */
    int Rear() { 
        return !isEmpty() ? q[rear] : -1; 
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() { 
        return len == 0; 
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() { 
        return len == k; 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
