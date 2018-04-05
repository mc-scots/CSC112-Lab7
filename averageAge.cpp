#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

//Function prototypes
pair<string, double> getRecord(ifstream &file);
double average(const vector<pair<string, double>> &data);


int main(int argc, char** argv) 
{
    vector<pair<string, double>> data;   //the data to average
    ifstream file;                       //the file containing the average
    
    //read the vector from the file
    file.open(argv[1]);
    while(not file.eof()) {
        data.push_back(getRecord(file));
    }
    file.close();
    
    
    //print out the average age of our friends
    cout << "Average Age of Friends: " << average(data) << endl;
}


//Read a record from the file and return it as a double 
pair<string, double> 
getRecord(ifstream &file)
{
    //read the pair in 
    pair<string, double> result;
    file >> result.first >> result.second;
    
    return result;
}


//compute the average of the ages in the list
double 
average(const vector<pair<string, double>> &data)
{
    double total=0.0;
    
    for(auto itr=data.begin(); itr != data.end(); itr++) {
        total += itr->second;
    }
    
    return total / data.size();
}