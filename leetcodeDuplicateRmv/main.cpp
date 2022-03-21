#include <iostream>
using namespace std;
/**
 * @brief
 *
 * @return int
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(const int &n) : val(n), next(nullptr){};
    ListNode(const int &n, ListNode *next) : val(n), next(next){};
};
ListNode *deleteDuplicates(ListNode *head)
{
    // If the list is empty or only has one value return the list
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *curr = head;
    ListNode *temp = nullptr;

    while (curr->next != nullptr)
    {
        while (curr->val == curr->next->val)
        {
            temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            temp = nullptr;
            if (curr->next == nullptr)
            {
                return head;
            }
        }
        curr = curr->next;
    }
    return head;
};

void test1()
{
    cout << "*** Begin Test 1 ***" << endl;
    ListNode *e1 = new ListNode(1);
    ListNode *current = e1;
    for (int i{2}; i < 101; i++)
    {
        ListNode *n;
        if (i % 2 == 0)
        {
            i--;
            n = new ListNode(i);
            i++;
        }
        else
        {
            n = new ListNode(i);
        }
        current->next = n;
        current = current->next;
    }
    ListNode *pointer = deleteDuplicates(e1);

    while (pointer != nullptr)
    {
        cout << pointer->val << " ";
        pointer = pointer->next;
    }
    cout << endl;
    cout << "*** End Test 1 ***" << endl;
}
void test2()
{
    cout << "*** Begin Test 2 ***" << endl;
    ListNode *e1 = new ListNode(1);
    ListNode *current = e1;

    ListNode *pointer = deleteDuplicates(e1);

    while (pointer != nullptr)
    {
        cout << pointer->val << " ";
        pointer = pointer->next;
    }
    cout << endl;
    cout << "*** End Test 2 ***" << endl;
}
void test3()
{
    cout << "*** Begin Test 3 ***" << endl;
    ListNode *e1 = nullptr;
    ListNode *current = e1;

    ListNode *pointer = deleteDuplicates(e1);

    while (pointer != nullptr)
    {
        cout << pointer->val << " ";
        pointer = pointer->next;
    }
    cout << endl;
    cout << "*** End Test 3 ***" << endl;
}
void test4()
{
    cout << "*** Begin Test 4 ***" << endl;
    ListNode *e1 = new ListNode(0);
    ListNode *current = e1;
    for (int i{0}; i < 101; i++)
    {
        ListNode *n;
        if (i % 2 == 1)
        {
            i--;
            n = new ListNode(i);
            i++;
        }
        else
        {
            n = new ListNode(i);
        }
        current->next = n;
        current = current->next;
    }
    ListNode *pointer = deleteDuplicates(e1);

    while (pointer != nullptr)
    {
        cout << pointer->val << " ";
        pointer = pointer->next;
    }
    cout << endl;
    cout << "*** End Test 4 ***" << endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();

    return -1;
}