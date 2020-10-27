/**
 *  很不完善的双向队列
**/

#define SIZE 5

class Queue {
public:
    Queue() : head(0), tail(0){}
    bool isEmpty();
    bool isFull();
    void insert(int value);
    void remove();
    void printQueue();
private:
    int queue[SIZE];
    int head;
    int tail;
};
