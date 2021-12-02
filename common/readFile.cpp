#include <fstream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
vector<T> readFile(string filename) {
    vector<T> data;

    ifstream in(filename, ios::in);

    T temp;

    while(getline(in, temp)){
        if (temp.size() > 0)
        {
            data.push_back(temp);
        }
    }

    in.close();
    
    return data;
}