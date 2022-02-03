//
// Created by Tyler Moore on 10/10/2021.
//
// Linked List still can't take any strings
//
// Main Class that executes test methods on Library class
//

#include <IOstream>
#include <cassert>
//#include "linkedList.cpp"
#include <sstream>
#include <map>

using namespace std;
char findTheDifference(string s, string t)
{
    map<char, int> str1;
    map<char, int> str2;

    for (int i{0}; i < t.length(); i++)
    {
        str1[s[i]]++;
    }
    for (int i{0}; i < s.length(); i++)
    {
        str2[t[i]]++;
    }

    for (auto ch : str1)
    {
        if (str2.count(ch.first) == 0)
            return ch.first;
    }
    for (auto ch : str2)
    {
        if (str1.count(ch.first) == 0);
            return ch.first;
    }
    return 'a';
}

int main()
{

    char dif = findTheDifference("abcd", "abcde");
    cout << "Differernt character is: " << dif << endl;
    // int num = 6;
    // std::string str = "[6]";
    // LinkedList<int> test1(num);

    // cout << test1 << endl;

    // stringstream ss;
    // cout << test1 << endl;

    // //Why does the value for test1 change useing stringstream??
    // ss << str;

    // assert(ss.str() == "[6]");

    // ss.str("");

    // cout << test1 << endl;

    //testAll();
    return 0;
}
