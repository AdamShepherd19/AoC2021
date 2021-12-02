#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> readFile() {
    vector<int> data;

    ifstream in("day_1_input.txt", ios::in);

    int temp;

    while(in >> temp){
        data.push_back(temp);
    }

    in.close();
    
    return data;
}

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