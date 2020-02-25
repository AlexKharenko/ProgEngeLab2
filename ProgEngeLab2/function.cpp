#include "func.h"

void func::create()
{
    
    ifstream fout;
    fout.open("students1.txt", ios::out | ios::app);

    int roll;;
    fout >> roll;
    cout << roll << endl;
    string *name=new string[roll];
    while (!fout.eof()) {
        for (int i = 0; i < roll; i++) {
            fout >> name[i];
        }
        
    }
    
    for (int i = 0; i < roll; i++) {
        cout<< name[i];
        cout<< endl;
    }
    cout<< endl;
}