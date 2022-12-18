#include <bits/stdc++.h>
using namespace std;
int  totalCompareLinear = 0, totalCompareBinary = 0;
struct STUDENT
{
    string name;
    int age;
    string placeOfBirth;
    string sex;
};

// doc file
void coutStudent(STUDENT sv)
{
    cout << sv.name;
    cout << endl
         << sv.age;
    cout << endl
         << sv.placeOfBirth;
    cout << endl
         << sv.sex << endl;
}

void inputFile_sv(ifstream &fileIn, STUDENT &sv)
{

    getline(fileIn, sv.name, ',');
    fileIn >> sv.age;
    fileIn.ignore(2); // bo qua /n o tren, va bo qua dau ','
    getline(fileIn, sv.placeOfBirth, ',');
    getline(fileIn, sv.sex, '.');
    fileIn.ignore(1); // bo qua \n cua thang dau tien de tranh luot duyet sau hot vao .name
}

int sizeOfSv(ifstream &fileInCp)
{
    int size = 0;
    while (fileInCp.eof() == false)
    {
        string x;
        getline(fileInCp, x, '.');
        size++;
    }
    return size - 1; // tru di ki tu eof
}

void readFile_sv(ifstream &fileIn, ifstream &fileInCp, vector<STUDENT> &sv)
{
    int n = sizeOfSv(fileInCp);
    for (int i = 0; i < n; i++)
    {
        STUDENT tempSv;
        inputFile_sv(fileIn, tempSv);
        sv.push_back(tempSv);
    }
}

vector<STUDENT> linear_search(int svAge, vector<STUDENT> sv)
{

    vector<STUDENT> studentList;
    for (auto a : sv)
    {
        totalCompareLinear++;
        if (a.age == svAge)
            studentList.push_back(a);
    }
    return studentList;
}

int binary_search(int left, int right, vector<STUDENT> sv, int svAge)
{
    
    int mid = (left + right) / 2;
    if (left > right&&++totalCompareBinary)
        return -1;
    if (sv[mid].age == svAge&&++totalCompareBinary)
        return mid;
    if (sv[mid].age < svAge&&++totalCompareBinary)
        return binary_search(mid + 1, right, sv, svAge);
    else
        return binary_search(left, mid - 1, sv, svAge);
}

vector<STUDENT> binary_search_generic(int svAge, vector<STUDENT> sv)
{
    vector<STUDENT> studentList;
    int hasSvAge = 1;
    while (hasSvAge)
    {

        int posSv = binary_search(0, sv.size() - 1, sv, svAge);
        if (posSv != -1)
        {
            studentList.push_back(sv[posSv]);
            sv.erase(sv.begin() + posSv);
        }
        else
            hasSvAge = 0;
    }
    return studentList;
}

void findStudent(vector<STUDENT> sv, vector<STUDENT> (*callback)(int, vector<STUDENT>),int &totalCompare)
{
    int svAge;
    cin >> svAge;
    vector<STUDENT> svFinded = callback(svAge, sv);
    cout << endl
         << "---------------------------------------------" << endl;
    for (auto s : svFinded)
    {
        coutStudent(s);
    }
    cout<<"-->So lan so sanh: "<<totalCompare<<endl;
    cout << "---------------------------------------------";
}

int compare(STUDENT a, STUDENT b)
{
    if (a.age < b.age)
        return 1;
    return 0;
}

int main()
{
    vector<STUDENT> sv;
    ifstream fileIn, fileInCp;
    fileIn.open("input.txt", ios::in);
    fileInCp.open("input.txt", ios::in);
    STUDENT tempSv;
    readFile_sv(fileIn, fileInCp, sv);
    sort(sv.begin(), sv.end(), compare);
    int choice;
    do
    {
        cin >> choice;
        switch (choice)
        {
        // tim kiem nhung nguoi co ten duoc nhap
        case 1:
        {
            findStudent(sv, linear_search,totalCompareLinear);
            break;
        }
        case 2:
        {
            findStudent(sv, binary_search_generic,totalCompareBinary);
            break;
        }
        }
    } while (choice);

    fileIn.close();
    fileInCp.close();
    system("pause");
}
