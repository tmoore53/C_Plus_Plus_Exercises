#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief Failed 17/22 test cases
 * https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen
 *
 *
 * @param steps
 * @param path
 * @return int
 */
int countingValleys(int steps, string path)
{
    int level{1};
    int valleys{0};
    string pathTaken = "";
    for (int i{1}; i < path.size(); i++)
    {
        pathTaken += path[i - 1];
        if (path[i - 1] == 'U' && path[i] == 'U')
        {
            level++;
        }
        else if (path[i - 1] == 'D' && path[i] == 'D')
        {
            valleys++;
        }
        while (path[i - 1] == 'D' && path[i] == 'D')
        {
            pathTaken += path[i - 1];
            level--;
            i++;
        }
    }
    // if (path[path.size() - 1] == 'D' && path[path.size() - 2] == 'D')
    // {
    //     valleys++;
    // }
    pathTaken += path[path.size() - 1];
    cout << "The path given was: " << path << endl;
    cout << "The path take was: " << pathTaken << endl;
    return valleys;
}
void test1()
{
    cout << "--- Test1 Start ---" << endl;

    int steps = 8;
    string path = "UDDDUDUU";
    cout << countingValleys(steps, path) << endl;
    cout << "--- Test1 Ending ---" << endl;
}
void test2()
{
    cout << "--- Test2 Start ---" << endl;
    int steps = 12;
    string path = "DDUUDDUDUUUD";
    cout << countingValleys(steps, path) << endl;
    cout << "--- Test2 Ending ---" << endl;
}
void test3()
{
    cout << "--- Test3 Start ---" << endl;
    int steps = 17;
    string path = "DDUUDDUDUUUDDDDDD";
    cout << countingValleys(steps, path) << endl;
    cout << "--- Test3 Ending ---" << endl;
}
void test4()
{
    cout << "--- Test4 Start ---" << endl;
    int steps = 13;
    string path = "DDUUDDUDUUUDUD";
    cout << countingValleys(steps, path) << endl;
    cout << "--- Test4 Ending ---" << endl;
}

string isValid(string s)
{
    unordered_map<char, int> data;
    char prev = s[0];
    bool removeOnce = false;

    for (int i{0}; i < s.size(); i++)
    {
        // if (i > 1 && s[i - 1] == s[i] && removeOnce)
        // {
        //     return "NO";
        // }
        // else if (i > 1 && s[i - 1] == s[i])
        // {
        //     removeOnce = true;
        // }

        if (data.find(s[i]) == data.end())
        {
            data[s[i]] = 1;
        }
        else if (data.find(s[i]) != data.end())
        {
            data[s[i]]++;
        }
    }
    cout << "String: " << s << endl;
    int averageVal{0};
    for (const auto c : data)
    {
        averageVal += c.second;

        cout << c.first;
    }
    averageVal = averageVal / data.size();
    cout << endl;
    for (const auto c : data)
    {
        if (c.second > averageVal)
        {
            if (c.second - 1 == averageVal && !removeOnce)
            {
                removeOnce = true;
            }
            else
            {
                return "NO";
            }
        }
    }

    return "YES";
}

void test101()
{
    cout << "--- Test101 Start ---" << endl;
    cout << isValid("abc") << endl;
}
void test102()
{
    cout << "--- Test102 Start ---" << endl;
    cout << isValid("abcc") << endl;
}
void test103()
{
    cout << "--- Test103 Start ---" << endl;
    cout << isValid("abccc") << endl;
}
void test104()
{
    cout << "--- Test104 Start ---" << endl;
    cout << isValid("abcdefghhgfedecba") << endl;
}
int main()
{
    // test1();
    // test2();
    // test3();
    // test4();

    test101();
    test102();
    test103();
    test104();

    cout << "Testing 123" << endl;

    return -1;
}
