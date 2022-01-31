// ex4_hanan_cohen_shuval_zada.cpp : Defines the entry point for the application.
//
#include "Controller.h"
#include <iostream>
using namespace std;

int main()
{
	std::ofstream outPutExsption;
	outPutExsption.open("log.txt");
	if (!outPutExsption.is_open())
		cout << "conot open file";
	Controller pipeGame;
	try
	{
		pipeGame.run();
	}
	catch (std::out_of_range& ex)
	{
		outPutExsption << ex.what() << std::endl;
	}
	catch (std::invalid_argument& ex)
	{
		outPutExsption << ex.what() << std::endl;
	}
	catch (std::exception& ex)
	{
		outPutExsption << ex.what() << std::endl;
	}
	catch(...)
	{
		outPutExsption << "Unknown exception\n"<<std::endl;
	}
	outPutExsption.close();
	return 0;
}
