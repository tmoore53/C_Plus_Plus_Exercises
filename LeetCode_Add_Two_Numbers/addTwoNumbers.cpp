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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr && l2 == nullptr)
    {
        return nullptr;
    }
    ListNode *sumList = new ListNode();
    ListNode *lastList = new ListNode();
    // If list 1 is empty and 2 was not
    if (l1 == nullptr && l2 != nullptr)
    {
        sumList->val = (l2->val) % 10;

        if (l2->next == nullptr)
        {
            if (l2->val > 9)
            {
                lastList->val = l2->val / 10;
                sumList->next = lastList;
                return sumList;
            }
        }
        else
        {
            lastList->val = l2->val / 10;
            sumList->next = addTwoNumbers(l2->next, lastList);
        }
    }
    // If list 2 is empty and 1 was not
    if (l1 != nullptr && l2 == nullptr)
    {
        sumList->val = (l1->val) % 10;

        if (l1->next == nullptr)
        {
            if (l1->val > 9)
            {
                lastList->val = l1->val / 10;
                sumList->next = lastList;
                return sumList;
            }
        }
        else
        {
            l1->next->val += l1->val / 10;
            sumList->next = addTwoNumbers(l1->next, lastList);
        }
    }
    if (l1 != nullptr && l2 != nullptr)
    {
        sumList->val = (l1->val + l2->val) % 10;
        if (l1->val + l2->val > 9 && l1->next == nullptr && l2->next == nullptr)
        {
            lastList->val = (l1->val + l2->val) / 10;
            sumList->next = lastList;
            return sumList;
        }
        else if (l1->val + l2->val > 9 && l1->next != nullptr)
        {
            l1->next->val += (l1->val + l2->val) / 10;
        }
        else if (l1->val + l2->val > 9 && l2->next != nullptr)
        {
            l2->next->val += (l1->val + l2->val) / 10;
        }
        sumList->next = addTwoNumbers(l1->next, l2->next);
    }
    return sumList;
}
int main()
{
    cout << "Hello World" << endl;
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(9, l1);
    ListNode *l3 = new ListNode(9, l2);
    ListNode *l4 = new ListNode(9, l3);
    ListNode *l5 = new ListNode(9, l4);
    ListNode *l6 = new ListNode(9, l5);
    ListNode *l7 = new ListNode(9, l6);

    ListNode *lL1 = new ListNode(9);
    ListNode *lL2 = new ListNode(9, l1);
    ListNode *lL3 = new ListNode(9, l2);
    ListNode *lL4 = new ListNode(9, l3);

    ListNode *lLL1 = new ListNode(1);
    ListNode *lLL2 = new ListNode(8, lLL1);

    ListNode *lLL3 = new ListNode(0);

    ListNode *curr = addTwoNumbers(l7, lL4);
    ListNode *curr2 = addTwoNumbers(lLL2, lLL3);

    while (curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }

    //MyStack<int> test;

    int one = 1;
    int two = 2;

    cout << "(9+9)/10 = " << (9 + 9) / 10 << endl;
    cout << "(3+4)/10 = " << (3 + 4) / 10 << endl;
    cout << "(5+5)/10 = " << (5 + 5) / 10 << endl;
    cout << "(5+5)%10 = " << (5 + 5) % 10 << endl;
    cout << "(9+9)%10 = " << (9 + 9) % 10 << endl;
    cout << "(3+4)%10 = " << (3 + 4) % 10 << endl;

    while (curr2 != nullptr)
    {
        cout << curr2->val << endl;
        curr2 = curr2->next;
    }
}