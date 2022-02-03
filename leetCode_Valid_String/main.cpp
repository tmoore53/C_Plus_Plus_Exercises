#include <iostream>
#include <map>
#include <stack>
using namespace std;

// Helper method that compares parentheses and returns if it matches
bool compareCharPar(char c1, char c2)
{
    if (c1 == '{' && c2 == '}')
        return true;
    else if (c1 == '(' && c2 == ')')
        return true;
    else if (c1 == '[' && c2 == ']')
        return true;
    else
    {
        return false;
    }
}

bool isValid(string s)
{
    // Return false if the string has a odd length
    if (s.length() % 2 == 1)
        return false;
    bool result = true;

    stack<char> startPar;
    // Parse through the string and compare open parenthesis
    for (int i = 0; i < s.length(); i++)
    {
        char currChar = s[i];

        // If character is a open parenthesis add to stack
        if (currChar == '{' || currChar == '(' || currChar == '[')
            startPar.push(currChar);
        else
        {
            // If the stack is empty and the char is a closed parenthesis
            // return false
            if (startPar.empty())
                return false;

            // Compare the value of the characters
            result = compareCharPar(startPar.top(), currChar);
            startPar.pop();
        }

        // If the characters did not match then return false
        if (!result)
            return result;
    }
    // If the stack is empty and the string has been parsed through
    // then return true
    if (startPar.empty())
        return true;
    else
    {
        // If the stack still has characters in it the return false
        return false;
    }
}

char findTheDifference(string s, string t)
{
    map<char, int> str1;
    map<char, int> str2;

    for (int i{0}; i < s.length(); i++)
    {
        str1[s[i]]++;
    }
    for (int i{0}; i < t.length(); i++)
    {
        str2[t[i]]++;
    }
    for (auto ch : str1)
    {
        if (str2.count(ch.first) == 0 || str2.at(ch.first) != ch.second)
        {
            return ch.first;
        }
    }
    for (auto ch : str2)
    {
        if (str1.count(ch.first) == 0 || str1.at(ch.first) != ch.second)
        {
            return ch.first;
        }
    }
    return 'a';
}

int main()
{
    char dif = findTheDifference("ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor",
                                 "qhxepbshlrhoecdaodgpousbzfcqjxulatciapuftffahhlmxbufgjuxstfjvljybfxnenlacmjqoymvamphpxnolwijwcecgwbcjhgdybfffwoygikvoecdggplfohemfypxfsvdrseyhmvkoovxhdvoavsqqbrsqrkqhbtmgwaurgisloqjixfwfvwtszcxwktkwesaxsmhsvlitegrlzkvfqoiiwxbzskzoewbkxtphapavbyvhzvgrrfriddnsrftfowhdanvhjvurhljmpxvpddxmzfgwwpkjrfgqptrmumoemhfpojnxzwlrxkcafvbhlwrapubhveattfifsmiounhqusvhywnxhwrgamgnesxmzliyzisqrwvkiyderyotxhwspqrrkeczjysfujvovsfcfouykcqyjoobfdgnlswfzjmyucaxuaslzwfnetekymrwbvponiaojdqnbmboldvvitamntwnyaeppjaohwkrisrlrgwcjqqgxeqerjrbapfzurcwxhcwzugcgnirkkrxdthtbmdqgvqxilllrsbwjhwqszrjtzyetwubdrlyakzxcveufvhqugyawvkivwonvmrgnchkzdysngqdibhkyboyftxcvvjoggecjsajbuqkjjxfvynrjsnvtfvgpgveycxidhhfauvjovmnbqgoxsafknluyimkczykwdgvqwlvvgdmufxdypwnajkncoynqticfetcdafvtqszuwfmrdggifokwmkgzuxnhncmnsstffqpqbplypapctctfhqpihavligbrutxmmygiyaklqtakdidvnvrjfteazeqmbgklrgrorudayokxptswwkcircwuhcavhdparjfkjypkyxhbgwxbkvpvrtzjaetahmxevmkhdfyidhrdeejapfbafwmdqjqszwnwzgclitdhlnkaiyldwkwwzvhyorgbysyjbxsspnjdewjxbhpsvj");
    cout << "Differernt character is: " << dif << endl;
    //cout << isValid("[][");

    return 0;
}
