#include "func.h"


void func::create()
{
	//string ad;
	//adress(ad);
    ifstream fin1;
	ifstream fin2;
    fin1.open("students1.csv");
	fin2.open("students2.csv");
	if (!fin1.is_open() && !fin2.is_open()) {
		cout << "Error! Files didn`t opened!" << endl;
	}
    int n1, n2;
    fin1 >> n1;
	fin2 >> n2;
    string **file1=new string*[n1];
    for (int i = 0; i < n1; i++) {
        file1[i] = new string[7];
    }
	string** file2 = new string * [n2];
	for (int i = 0; i < n2; i++) {
		file2[i] = new string[7];
	}
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < 6; j++) {
           
            getline(fin1, file1[i][j], ',');
			getline(fin2, file2[i][j], ',');
            
        }
		getline(fin1, file1[i][6], '\n');
        getline(fin2, file2[i][6], '\n');
    }
	fin1.close();
	fin2.close();
	outmatr(file1, n1, 7);
	outmatr(file2, n2, 7);
	int count1, count2 ;
	count1 = find_counter(file1, n1);
	count2 = find_counter(file2, n2);
	int countsum = count1 + count2;
	string** budgets = new string * [countsum];
	for (int i = 0; i < countsum; i++)
		budgets[i] = new string[7];
	budget(budgets, file1, file2, n1, n2, count1, count2);
	cout << "Матриця бюджетників: " << endl;
	outmatr(budgets, countsum, 7);
	seredniy(budgets, countsum);
    
}

void func::outmatr(string** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << "\t";
		}

		cout << endl;
	}
	cout << endl;
}

void func::adress(string adr) {
	cout << "Введіть адресу діректорії: ";
	getline(cin, adr);
	cout << adr<<endl;
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

void func::budget(string** budg, string** str1, string** str2, int n1, int n2, int count1, int count2) {
	string stroy = "FALSE";
	int k = 0;
	for (int i = 0; i < n1; i++)
	{
		if (str1[i][6] == stroy) {
			budg[k] = str1[i];
			k++;
		}
	}
	for (int i = 0; i < n2; i++)
	{
		if (str2[i][6] == stroy) {
			budg[k] = str2[i];
			k++;
		}
	}
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
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cout << matrix[i][j]<<"\t";
		}
		cout << endl;
	}*/
}

