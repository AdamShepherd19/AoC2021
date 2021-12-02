#include <iostream>
#include "../common/readFile.cpp"

using namespace std;

int stageOne() {
    vector<int> data = readFile();
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

int main(){
    cout << " - Stage One: " << stageOne() << endl;

    return 0;
}