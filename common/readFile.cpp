#include <fstream>
#include <vector>

using namespace std;

vector<int> readFile(string filename) {
    vector<int> data;

    ifstream in(filename, ios::in);

    int temp;

    while(in >> temp){
        data.push_back(temp);
    }

    in.close();
    
    return data;
}