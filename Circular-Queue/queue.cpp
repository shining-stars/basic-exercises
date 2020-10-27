/**
 *  很不完善的双向队列
**/


#include "test.h"
#include <iostream>
using namespace std;

bool Queue::isEmpty() {
    return this->head == this->tail;
}

bool Queue::isFull() {
    return (this->tail+1)%SIZE == this->head;
}

void Queue::insert(int value) {
    this->queue[ tail ] = value;
    tail = (tail+1) % SIZE;
}

void Queue::remove() {
    head = (head+1) % SIZE;
}

void Queue::printQueue() {
    for(int i=head; i != tail; i = (i+1)%SIZE) {
        cout<< this->queue[i]<<' ';
    }
    cout<<endl;
}

