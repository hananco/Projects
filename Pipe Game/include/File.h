#pragma once
#include <string>
#include "Level.h"
#include <fstream>
#include "Globals.h"
#include <sstream>
class File
{
public:
	File() ;
	~File();
	Level readLevalFromFile();//read the file to the end and return oll level 
	bool getEof() const;// return if we finsh to read the level
private:
	void checkInput(std::istringstream& lineInput)const;// func thet check the firction is 0 or 1
	std::fstream m_file;
	bool m_endOfFile = false;

};



