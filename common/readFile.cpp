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