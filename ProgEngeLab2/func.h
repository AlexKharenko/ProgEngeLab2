#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "windows.h"
#include <vector>


using namespace std;

namespace func{
	void create();
	void outmatr(string** , int, int);
	void adress(string);
	int find_counter(string**, int);
	void budget(string** ,string**,string** ,int ,int, int, int);
	void seredniy(string**, int);
}


