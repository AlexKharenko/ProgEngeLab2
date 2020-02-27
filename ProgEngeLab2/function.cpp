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
	string** budgets = new string * [n];
	for (int i = 0; i < n; i++)
		budgets[i] = new string[7];
    cout << endl;
	budgets = budget(rstr, n);
	seredniy(budgets, n);
    fin.close();
}

string** func::budget(string** str, int n) {
	string stroy = "FALSE";
	int counter = 0;
	bool yes = true;
	string** budget = new string * [n];
	for (int i = 0; i < n; i++)
		budget[i] = new string[7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			if (str[i][j] == stroy) {
				budget[i] = str[i];
				counter++;
			}
		}
	}
	return budget;
}
void func::seredniy(string** str, int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[5];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 6; j++) {
			matrix[i][j - 1] = atoi(str[i][j].c_str());
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cout <<setw(3)<< matrix[i][j];
		}
		cout << endl;
	}
}

