#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    if (list1 == nullptr)
    {
        return list2;
    }
    else if (list2 == nullptr)
    {
        return list1;
    }

    ListNode *mergedList = (list1->val < list2->val) ? list1 : list2;
    (list1->val < list2->val) ? list1 = list1->next : list2 = list2->next;
    ListNode *curr = mergedList;

    while (list1 != nullptr && list2 != nullptr)
    {
        ListNode *temp = new ListNode;

        temp->val = (list1->val < list2->val) ? list1->val : list2->val;
        curr->next = temp;
        curr = curr->next;
        (list1->val < list2->val) ? list1 = list1->next : list2 = list2->next;
    }
    if (list1 == nullptr)
    {
        curr->next = list2;
    }
    else
    {
        curr->next = list1;
    }
    return mergedList;
}
void test1()
{
    cout << "*** Begin Test 1 ***" << endl;
    ListNode *e1 = new ListNode(7);
    ListNode *e2 = new ListNode(6, e1);
    ListNode *e3 = new ListNode(5, e2);
    ListNode *e4 = new ListNode(4, e3);
    ListNode *e5 = new ListNode(3, e4);
    ListNode *e6 = new ListNode(2, e5);
    ListNode *e7 = new ListNode(1, e6);

    ListNode *f1 = new ListNode(7);
    ListNode *f2 = new ListNode(6, e1);
    ListNode *f3 = new ListNode(5, e2);
    ListNode *f4 = new ListNode(4, e3);
    ListNode *f5 = new ListNode(3, e4);
    ListNode *f6 = new ListNode(2, e5);
    ListNode *f7 = new ListNode(1, e6);

    ListNode *pointer = mergeTwoLists(e7, f7);

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
    ListNode *e1 = new ListNode(7);
    ListNode *e2 = new ListNode(6, e1);
    ListNode *e3 = new ListNode(5, e2);
    ListNode *e4 = new ListNode(4, e3);
    ListNode *e5 = new ListNode(3, e4);
    ListNode *e6 = new ListNode(2, e5);
    ListNode *e7 = new ListNode(1, e6);

    ListNode *f1 = new ListNode(6);

    ListNode *pointer = mergeTwoLists(e7, f1);

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
    ListNode *e1 = new ListNode(7);
    ListNode *e2 = new ListNode(6, e1);
    ListNode *e3 = new ListNode(5, e2);
    ListNode *e4 = new ListNode(4, e3);
    ListNode *e5 = new ListNode(3, e4);
    ListNode *e6 = new ListNode(2, e5);
    ListNode *e7 = new ListNode(1, e6);

    ListNode *f1 = nullptr;

    ListNode *pointer = mergeTwoLists(e7, f1);

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
    ListNode *e1 = new ListNode(3);

    ListNode *f1 = new ListNode(3);

    ListNode *pointer = mergeTwoLists(e1, f1);

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
    cout << "Starting..." << endl;
    test1();
    test2();
    test3();
    test4();
    cout << "Finished..." << endl;

    return -1;
}