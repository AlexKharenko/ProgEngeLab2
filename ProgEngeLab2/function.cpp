#include "func.h"


void func::create()
{
    ifstream fin;
    fin.open("students1.csv");
    if (!fin.is_open()) {
        cout << "dfgdgd" << endl;
    }
    int n;
    fin >> n;
    cout << n << endl;
    string **rstr=new string*[n];
    for (int i = 0; i < n; i++) {
        rstr[i] = new string[7];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
           
            getline(fin, rstr[i][j], ',');
            
        }
        getline(fin, rstr[i][6], '\n');
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            cout << rstr[i][j] << "\t";
        }
        
        cout << endl;
    }
    cout << endl;

    fin.close();
}