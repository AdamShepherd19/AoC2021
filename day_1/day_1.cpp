#include <iostream>
#include "../common/readFile.cpp"

using namespace std;

int stageOne(vector<int> data) 
{
    int counter = 0;

    for (int x = 0; x < data.size() - 1; x++)
    {
        if (data[x] < data[x+1])
        {
            counter++;
        }
    }
    return counter;
}

int stageTwo(vector<int> data)
{
    int counter = 0;

    for (int x = 0; x < data.size()-3; x++)
    {
        int sum = data[x] + data[x+1] + data[x+2];
        int nextSum = data[x+1] + data[x+2] + data[x+3];
        if (sum < nextSum)
        {
            counter++;
        }
    }
    return counter;
}

int main(){
    vector<int> data = readFile<int>("day_1_input.txt");

    cout << " - Stage One: " << stageOne(data) << endl;
    cout << " - Stage Two: " << stageTwo(data) << endl;

    return 0;
}