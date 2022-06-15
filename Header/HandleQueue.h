#ifndef HANDLEQUEUE
#define HANDLEQUEUE
#include "Common.h"
#include <queue>
#include <mutex>

using namespace std;

class HandleQueue {
private:
    static HandleQueue* _instance;
    static const int MAXIMUM = 6;
    //static mutex mLocker;

    HandleQueue();
    queue<QueueTemplate> queue_obj;

public:
    ~HandleQueue();
    static HandleQueue* getInstance();

    bool empty();
    QueueTemplate back(void);
    QueueTemplate front(void);
    void push(QueueTemplate value);
    void pop();
    unsigned int size();

    void copyFromOtherQueue(queue<QueueTemplate> queue2);
    void printQueue();

    QueueTemplate getAnyElement(const size_t position);
    QueueTemplate* accessToAnyElement(const size_t position);
};

#endif // HANDLEQUEUE
