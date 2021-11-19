#include <iostream>
#include <vector>

using namespace std;

vector<int> dutchFlagPartition(int pivotIndex, vector<int> colorVector)
{
    int indexVal{0};

    for (int i{0}; i < colorVector.size(); i++)
    {
        if (colorVector[i] > colorVector[pivotIndex])
        {
            //cout << "test";
            //     int temp = colorVector[i];
            //     colorVector[i] = pivotValue;
            //     pivotValue = temp;
            swap(colorVector[pivotIndex], colorVector[i]);
        }
    }
    for (int i{colorVector.size() - 1}; i >= 0; i--)
    {
        if (colorVector[i] < colorVector[pivotIndex])
        {
            swap(colorVector[pivotIndex], colorVector[i]);
        }
    }
    return colorVector;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    vector<int> test = {0, 1, 2, 0, 2, 1};
    vector<int> test2 = {0, 1, 2, 0, 2, 1};
    vector<int> result = dutchFlagPartition(2, test);
    result = dutchFlagPartition(1, result);
    for (int num : result)
    {
        cout << num;
    }
    return 0;
}