#include <iostream>
#include "../common/readFile.cpp"

using namespace std;

int stageOne()
{
    
    return 0;
}

int stageTwo()
{

    return 0;
}

int main(){
    vector<string> data = readFile<string>("day_x_input.txt");
    
    cout << "Stage One: " << stageOne() << endl;
    cout << "Stage Two: " << stageTwo() << endl;

    return 0;
}