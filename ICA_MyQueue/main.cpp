#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    friend ostream &operator<<(ostream &out, MyQueue obj)
    {
        if (!obj.dequeueStk.empty())
        {
            while (!obj.dequeueStk.empty())
            {
                out << (obj.dequeueStk.top());
                obj.enqueueStk.push(obj.dequeueStk.top());
                obj.dequeueStk.pop();
            }
        }
        else
        {
            while (!obj.enqueueStk.empty())
            {
                obj.dequeueStk.push(obj.enqueueStk.top());
                obj.enqueueStk.pop();
            }
            while (!obj.dequeueStk.empty())
            {
                out << (obj.dequeueStk.top());
                obj.enqueueStk.push(obj.dequeueStk.top());
                obj.dequeueStk.pop();
            }
        }
        return out;
    }

private:
    /**
 * @brief change these stack to function as 
 * a remove stack and a add stack
 */
    stack<int> dequeueStk;
    stack<int> enqueueStk;

public:
    MyQueue(){};
    ~MyQueue(){};
    bool enqueue(const int num)
    {
        while (!dequeueStk.empty())
        {
            enqueueStk.push(dequeueStk.top());
            dequeueStk.pop();
        }
        enqueueStk.push(num);
        return true;
    };
    bool dequeue()
    {
        if (enqueueStk.size() < 1 && dequeueStk.size() < 1)
            return false;
        while (!enqueueStk.empty())
        {
            dequeueStk.push(enqueueStk.top());
            enqueueStk.pop();
        }
        dequeueStk.pop();
        return true;
    };
};
void testRunner1()
{
    MyQueue test1;
    test1.enqueue(1);
    test1.enqueue(2);
    test1.enqueue(3);
    test1.dequeue();
    test1.enqueue(4);
    test1.enqueue(5);
    cout << test1 << endl;
    test1.dequeue();
    test1.dequeue();
    cout << test1 << endl;
    test1.dequeue();
    cout << test1 << endl;
    test1.dequeue();
    cout << test1 << endl;
    cout << "End of test 1 " << endl;
}
int main()
{
    testRunner1();
    MyQueue test1;
    test1.enqueue(1);
    test1.enqueue(2);
    test1.enqueue(3);
    test1.dequeue();
    test1.enqueue(4);
    test1.enqueue(5);
    cout << test1 << endl;
    return 0;
}
