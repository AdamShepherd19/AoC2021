#include <fstream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
vector<T> readFile(string filename) {
    vector<T> data;

    ifstream in(filename, ios::in);

    T temp;

    while(in >> temp){
        data.push_back(temp);
    }

    in.close();
    
    return data;
}