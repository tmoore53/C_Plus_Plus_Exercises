//
// Created by Tyler Moore on 10/10/2021.
//
// Main Class that executes test methods on Library class
//
#include <IOstream>
#include <cassert>
#include "linkedList.cpp"

using namespace std;

int main()
{
    int num = 6;
    std::string str = "Hello world";
    LinkedList<string> test1(str);

    cout << test1;

    //testAll();
    return 0;
}
