#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Task.h"
using namespace std;

class File{
private:
	string filename;

public:
	File(string);
	~File(void);
	void AccessFile(list<Task>);
	void SaveFile(list<Task>);
};
