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
	int counter;
	counter = find_counter(rstr, n);
	string** budgets = new string * [counter];
	for (int i = 0; i < counter; i++)
		budgets[i] = new string[7];
	budgets = budget(rstr, n);
	seredniy(budgets, counter);
    fin.close();
}

int func::find_counter(string** str, int n) {
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
	return counter;
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
	string** budgeters = new string * [counter];
	for (int i = 0; i < counter; i++)
		budgeters[i] = new string[7];
	for (int j = 0; j < 7; j++) {
		for (int k = 0; k < counter; k++) {
			for (int i = 0; i < n; i++) {
					if (budget[i][j] == stroy) {
						budgeters[k] = budget[i];
						k++;
					}
				}
			}
		}

	/*for (int i = 0; i <counter ; i++) {
		for (int j = 0; j < 7; j++) {
			cout << budgeters[i][j] << "\t";
		}
		cout << endl;
	}*/
	return budgeters;
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
			if (matrix[i][j] == 0) {
				continue;
			}
			else cout <<setw(3)<< matrix[i][j];
		}
		cout << endl;
	}
}

