#include <iostream>
#include "../common/readFile.cpp"

using namespace std;

int binToDec(string binary) {
    int decimal = 0;
    int divisor = 2048;

    for (int x = 0; x < 12; x++)
    {
        if (binary[x] == '1')
        {
            decimal += divisor;
        }
        divisor /= 2;
    }
    return decimal;
}

char mostCommonInCol(string col) {
    char mostCommon;
    int zero = 0;
    int one = 0;

    for (int x = 0; x < col.size(); x++)
    {
        if (col[x] == '0')
        {
            zero++;
        }
        else if (col[x] == '1')
        {
            one++;
        }
    }
    
    if (zero > one)
    {
        mostCommon = '0';
    } 
    else if (one > 0) 
    {
        mostCommon = '1';
    }
    
    return mostCommon;
}


int stageOne(vector<string> data)
{
    string gamma = "";
    string epsilon = "";
    string col = "";

    for (int x = 0; x < 12; x++)
    {
        col = "";
        for (int y = 0; y < data.size(); y++)
        {
            col += data[y][x];
        }

        if (mostCommonInCol(col) == '0')
        {
            gamma += "0";
            epsilon += "1";
        } 
        else if (mostCommonInCol(col) == '1') 
        {
            gamma += "1";
            epsilon += "0";
        }
    }

    return binToDec(gamma) * binToDec(epsilon);
}

vector<string> findSubset(vector<string> data, int iteration, bool oxygen) {
    vector<string> oxygenSubset;
    vector<string> co2Subset;
    if (data.size() > 1)
    {
        string col = "";
        for (int row = 0; row < data.size(); row++)
        {
            col += data[row][iteration];
        }

        char mostCommon = mostCommonInCol(col);

        for (int x = 0; x < data.size(); x++)
        {
            if (data[x][iteration] == mostCommon)
            {
                oxygenSubset.push_back(data[x]);
            }
            else
            {
                co2Subset.push_back(data[x]);
            }
        }
        iteration++;

        if (oxygen) return findSubset(oxygenSubset, iteration, true);
        else return findSubset(co2Subset, iteration, false);
    } else {
        return data;
    }
}

int stageTwo(vector<string> data)
{
    int oxygenRating = binToDec(findSubset(data, 0, true)[0]);
    int c02Rating = binToDec(findSubset(data, 0, false)[0]);
    
    return oxygenRating * c02Rating;
}

int main(){
    vector<string> data = readFile<string>("day_3_input.txt");
    
    cout << "Stage One: " << stageOne(data) << endl;
    cout << "Stage Two: " << stageTwo(data) << endl;

    return 0;
}