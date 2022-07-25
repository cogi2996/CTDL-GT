#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct STUDENT
{   
    string name;
    string placeOfBirth;
    string sex;
    /* data */
};

// doc file

void inputFile_sv(istream& fileIn,STUDENT &sv){
    getline(fileIn,sv.name,',');
    getline(fileIn,sv.placeOfBirth,',');
    getline(fileIn,sv.sex,'.');
}

int main()
{
    vector <STUDENT> sv;
    ifstream fileIn;
    fileIn.open("input.txt",ios::in);
    inputFile_sv(fileIn,sv[0]);
    cout<<sv[0].name;
    fileIn.close();
   
}
