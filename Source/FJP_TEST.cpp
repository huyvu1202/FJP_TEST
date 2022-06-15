#include <queue>
#include "../Header/Common.h"
#include "../Header/HandleQueue.h"

int main()
{
    //Create the Queue handling object
    HandleQueue *instance = HandleQueue::getInstance();

    //Create elements, queue for testing
    queue<QueueTemplate> queueTesting;
    QueueTemplate test1 = { 10, 18, 19, "1bc" };
    QueueTemplate test2 = { 20, 28, 39, "2bc" };
    QueueTemplate test3 = { 30, 38, 39, "3bc" };
    QueueTemplate test4 = { 40, 48, 49, "4bc" };
    QueueTemplate test5 = { 50, 58, 59, "5bc" };

    //Pushing elements to queue
    queueTesting.push(test1);
    queueTesting.push(test2);
    queueTesting.push(test3);
    queueTesting.push(test4);
    queueTesting.push(test5);

    /*------------------------------------------------------------------
    Test case 1: Pushing 5 elements. Check the queue size, all elements.
    Expected: size: 5
              elements: test1 ... test5
    */
    cout << "\nCase 1:----------------------------------------" << endl;

    instance->push(test1);
    instance->push(test2);
    instance->push(test3);
    instance->push(test4);
    instance->push(test5);
    cout << "Size of Queue: " << instance->size() << endl << endl;
    instance->printQueue();


    /*------------------------------------------------------------------
    Test case 2: Show the front element
    Expected: Same test1 value.
    */
    cout << "\nCase 2::----------------------------------------" << endl;
    instance->copyFromOtherQueue(queueTesting); // Copy for testing

    cout << "The front data:" << endl;
    showValue(instance->front());


    /*------------------------------------------------------------------
    Test case 3: Show the back element
    Expected: Same test2 value.
    */
    cout << "\nCase 3::----------------------------------------" << endl;
    instance->copyFromOtherQueue(queueTesting); // Copy for testing

    cout << "The back data:" << endl;
    showValue(instance->back());


    /*------------------------------------------------------------------
    Test case 4: Get element at 3 position
                 Check size of queue
    Expected: Same test3 value.
              Size: 4
    */
    cout << "\nCase 4::----------------------------------------" << endl;
    instance->copyFromOtherQueue(queueTesting); // Copy for testing

    cout << "Element[3]:" << endl;
    showValue(instance->getAnyElement(3));

    cout << "\nQueue after getting a element" << endl;
    cout << "Size of Queue: " << instance->size() << endl << endl;
    instance->printQueue();


    /*------------------------------------------------------------------
    Test case 5: Access to 4rd element then modify it. Change: id: 40 -> 99, Pos x: 48-> 99, Pos y: 49 -> 99
    Expected: test4: { 40, 48, 49, "4bc" } -> { 99, 99, 99, "4bc" }
              Size of Queue: 5
    */
    cout << "\nCase 5::----------------------------------------" << endl;
    instance->copyFromOtherQueue(queueTesting); // Copy for testing

    QueueTemplate* pt = instance->accessToAnyElement(4);
    pt->iD = 99;
    pt->xPos = 99;
    pt->yPos = 99;
    cout << "Size of Queue: " << instance->size() << endl;
    instance->printQueue();


    /*------------------------------------------------------------------
    Test case 6: Try to create a new instacne by HandleQueue class.
                 Then check the address of its.
    Expected: Same
    */
    cout << "\nCase 6::----------------------------------------" << endl;
    HandleQueue *instance2 = HandleQueue::getInstance();
    cout << "Adress of old instance: " << instance << endl;
    cout << "Adress of new instance: " << instance2 << endl;


    /*------------------------------------------------------------------
    Test case 7: Pushing an in-validation to queue (id ranger: 01 to 999)
    Expected: Waring message: Can't push this value
    */
    cout << "\nCase 7:----------------------------------------" << endl;
    instance->copyFromOtherQueue(queueTesting); // Copy for testing

    QueueTemplate test7 = { 1234, 78, 79, "7bc" };
    instance->push(test7);


    /*------------------------------------------------------------------
    Test case 8: Pushing over 6 elements.
    Expected: Waring message: Over size
    */
    cout << "\nCase 8:----------------------------------------" << endl;
    instance->copyFromOtherQueue(queueTesting); // Copy for testing

    QueueTemplate test8 = { 80, 88, 89, "8bc" };
    instance->push(test8);
    instance->push(test8);

    system("pause");
    return 0;
}