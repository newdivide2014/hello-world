//loop queue

typedef struct {
    int *array;
    int size;
    int capacity;
    int front;
    int rear;
} MyCircularQueue;

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->size == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return obj->size ==  obj->capacity;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->array = malloc((k) * sizeof(int));
    obj->size = 0;
    obj->front = obj->rear = 0;
    obj->capacity = k;
    while(k) {
        obj->array[--k] = 0;
    }
    return obj;
    
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    if(myCircularQueueIsEmpty(obj))
    {
        obj->array[obj->front] = value;
        obj->size++;
        return true;
    }  
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->array[obj->rear] = value;
    obj->size++;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    obj->array[obj->front] = 0;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  return obj->array[obj->rear];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
