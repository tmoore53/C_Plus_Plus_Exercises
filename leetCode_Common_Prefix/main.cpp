#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0];
    if (strs.empty() || strs[0].length() == 0)
        return "";
    string longPrefix = "";
    int count{0};
    char target = strs[0].at(count);

    while (count < strs[count].length() - 1)
    {
        for (string str : strs)
        {
            if (str.length() <= count || str.at(count) != target)
                return longPrefix;
        }
        longPrefix += target;
        count++;
        if (strs[0].length() > count)
            target = strs[0].at(count);
    }
    return longPrefix;
}

int main()
{
    vector<string> v1 = {"flag", "flower", "flounder", "flow"};
    vector<string> v2 = {"ab", "a"};
    vector<string> v3 = {"flower", "flower", "flower", "flower"};

    cout << longestCommonPrefix(v3) << endl;

    cout << "Testing 1234";
    return 0;
}

// while string char i == string2 char j

// for (int i{0}, j{1}; i < strs.size() - 1; i++, j++)
// {
//     cout << i << " " << j << endl;

//     if (strs[i].length() < strs[j].length())
//     {
//         longeststr = strs[j].length();
//     }
//     else
//     {
//         longeststr = strs[i].length();
//     }
//     while (strs[i].substr(count) == strs[j].substr(count))
//     {
//         longPrefix += strs[i].substr(count);
//     }
// }