//
// Created by Tyler Moore on 10/10/2021.
//
// Linked List still can't take any strings
//
// Main Class that executes test methods on Library class
//

#include <IOstream>
#include <cassert>
#include "linkedList.cpp"
#include <sstream>

using namespace std;

int main()
{
    int num = 6;
    std::string str = "[6]";
    LinkedList<int> test1(num);

    cout << test1 << endl;

    stringstream ss;
    cout << test1 << endl;

    //Why does the value for test1 change useing stringstream??
    ss << str;

    assert(ss.str() == "[6]");

    ss.str("");

    cout << test1 << endl;

    //testAll();
    return 0;
}
