#include <iostream>
#include "../common/readFile.cpp"

using namespace std;

struct instruction {
    string instruction;
    int amount;
};

int stageOne(vector<instruction> analysedData)
{
    int horizontal = 0;
    int depth = 0;

    for (int x = 0; x < analysedData.size(); x++)
    {
        if (analysedData[x].instruction.compare("forward") == 0)
        {
            horizontal += analysedData[x].amount;
        } 
        else if (analysedData[x].instruction.compare("down") == 0)
        {
            depth += analysedData[x].amount;
        } 
        else if (analysedData[x].instruction.compare("up") == 0)
        {
            depth -= analysedData[x].amount;
        }
    }
    
    return horizontal * depth;
}

int stageTwo(vector<instruction> analysedData)
{
    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    for (int x = 0; x < analysedData.size(); x++)
    {
        if (analysedData[x].instruction.compare("forward") == 0)
        {
            horizontal += analysedData[x].amount;
            depth += aim * analysedData[x].amount;
        } 
        else if (analysedData[x].instruction.compare("down") == 0)
        {
            aim += analysedData[x].amount;
        } 
        else if (analysedData[x].instruction.compare("up") == 0)
        {
            aim -= analysedData[x].amount;
        }

    }

    return horizontal * depth;
}

vector<instruction> analyseData(vector<string> data)
{
    vector<instruction> analysedData;

    for (int x = 0; x < data.size(); x++)
    {
        instruction temp;
        temp.instruction = data[x].substr(0, data[x].find(" "));
        temp.amount = stoi(data[x].substr(data[x].find(" ") + 1, data[x].size()));
        analysedData.push_back(temp);
    }
    
    return analysedData;
}

int main(){
    vector<string> data = readFile<string>("day_2_input.txt");
    vector<instruction> analysedData = analyseData(data);
    
    cout << "Stage One: " << stageOne(analysedData) << endl;
    cout << "Stage Two: " << stageTwo(analysedData) << endl;

    return 0;
}