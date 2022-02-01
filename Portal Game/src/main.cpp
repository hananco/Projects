#include "GameMaster.h"

int main()
{
	try {
		GameMaster portal;
		portal.run();
	}
	catch (const std::exception&) {
		
	}
	catch (...)
	{
		cerr << "Error unknown" << std::endl;
	}
	
	return 0;
}
