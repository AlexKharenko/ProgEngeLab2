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
	float** matrix1 = new float* [n];
	for (int i = 0; i < n; i++)
		matrix1[i] = new float[6];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			matrix1[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			matrix1[i][j] = matrix[i][j];
			matrix1[i][5] += matrix[i][j];
		}
	}
	/*for (int i = 0; i < n; i++) {
		matrix1[i][5] = matrix1[i][5] / 5;
	}*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			 cout <<setw(3)<< matrix1[i][j];
		}
		cout << endl;
	}
	string** strok = new string * [n];
	for (int i = 0; i < n; i++)
		strok[i] = new string[7];
	for (int i = 0; i < n; i++) {
		strok[i][0] = str[i][0];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 7; j++) {
			strok[i][j] = to_string(matrix1[i][j - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			cout << strok[i][j] << "\t";
		}
		cout << endl;
	}
	string **temp = new string*[n];
	for (int i = 0; i < n; i++)
		temp[i] = new string[7];
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 7; i++) {
			if (atoi(strok[j][6].c_str()) < atoi(strok[j + 1][6].c_str())) {
				temp[j][i] = strok[j][i];
				strok[j][i] = strok[j + 1][i];
				strok[j + 1][i] = temp[j][i];
				cout << "it works" << endl;
				cout << atoi(strok[j + 1][6].c_str()) << endl;
			}
		}
	}

}

