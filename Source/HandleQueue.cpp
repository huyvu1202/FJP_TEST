#include "../Header/HandleQueue.h"

HandleQueue* HandleQueue::_instance = NULL;

HandleQueue::HandleQueue() {
}

HandleQueue::~HandleQueue() {
}

HandleQueue* HandleQueue::getInstance() {
    if (_instance == NULL)
        _instance = new HandleQueue();
    return _instance;
}

//Return true if the queue is emty otherwise return false
bool HandleQueue::empty() {
    return queue_obj.empty();
}

//Return the last element
QueueTemplate HandleQueue::back() {
    return queue_obj.back();
}

//Return the first element
QueueTemplate HandleQueue::front() {
    return queue_obj.front();
}

//Add the element at the end
void HandleQueue::push(QueueTemplate value) {

    // Before pushing, check the input data
    if (queue_obj.size() < MAXIMUM) {
        if (validateInputData(value))
            return queue_obj.push(value);
        cout << "Invalidation!!!" << endl;
        return;
    }
    cout << "Over size, MAX: !!!" << MAXIMUM << endl;
}

//Delete the first the element
void HandleQueue::pop() {
    return queue_obj.pop();
}

//Return the size of the queue
unsigned HandleQueue::size() {
    return queue_obj.size();
}

void HandleQueue::copyFromOtherQueue(queue<QueueTemplate> queue2) {
    return queue_obj.swap(queue2);
}

void HandleQueue::printQueue() {
    if (!queue_obj.empty()) {
        while (!queue_obj.empty()) {
            showValue(queue_obj.front());
            queue_obj.pop();
        }
        cout << endl;
        return;
    }
    cout << "No thing" << endl;
}

QueueTemplate HandleQueue::getAnyElement(const size_t position) {
    QueueTemplate returnValue = {};
    if (!queue_obj.empty()) {
        QueueTemplate temp = {};
        size_t sizeQueue = queue_obj.size();

        for (size_t iCount = 0; iCount < sizeQueue; iCount++) {
            temp = queue_obj.front();
            queue_obj.pop();
            if (iCount == position - 1) {
                returnValue = temp;
                continue;
            }
            queue_obj.push(temp);
        }
    }
    return returnValue;
}

QueueTemplate* HandleQueue::accessToAnyElement(const size_t position) {

    QueueTemplate* returnValue = nullptr;
    if (!queue_obj.empty()) {
        QueueTemplate temp = {};

        size_t sizeQueue = queue_obj.size();

        for (size_t iCount = 0; iCount < sizeQueue; iCount++) {
            temp = queue_obj.front();
            queue_obj.pop();
            queue_obj.push(temp);
            if (iCount == position-1) {
                returnValue = &queue_obj.back();
            }
        }
    }
    return returnValue;
}