#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Task.h"
using namespace std;

class File{
private:
	string filename;

public:
	File(string);
	~File(void);
	void AccessFile(Vector<Task>);
	void SaveFile(Vector<Task>);
};
