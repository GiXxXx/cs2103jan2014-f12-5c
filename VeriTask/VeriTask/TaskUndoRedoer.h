#pragma once
#include "Command.h"

class TaskUndoRedoer:public Command {
public:
	vector<DataStorage> undoList;
	vector<DataStorage> redoList;

public:
	TaskUndoRedoer(void);
	~TaskUndoRedoer(void);
	void executeCommand(Identifier, DataStorage &, TextUI);
	void pushCommand(Command);	
};

