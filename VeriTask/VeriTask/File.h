#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Task.h"
using namespace std;

const string FILENAME = "data.txt";

class File {
private:

public:
	File();
	~File();
	int accessIndex();
	vector<Task> accessFile();
	void saveFile(vector<Task>, int);
};