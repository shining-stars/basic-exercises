/**
 *  很不完善的双向队列
**/


#include "test.h"
#include <iostream>
using namespace std;

int main() {
    Queue queue;
    queue.insert(1);
    queue.insert(2);
    queue.printQueue();
    queue.remove();
    queue.insert(3);
    queue.printQueue();
    queue.insert(4);
    queue.insert(5);
    if(!queue.isFull())
        queue.insert(6);
    queue.printQueue();

    return 0;
}
