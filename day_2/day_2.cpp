#include <iostream>
#include "../common/readFile.cpp"

using namespace std;

int main(){
    vector<string> data = readFile<string>("day_2_input.txt");

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    

    return 0;
}