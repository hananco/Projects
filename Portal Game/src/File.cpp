#include "File.h"

//================================CONSTRACTOR==================================
File::File():m_col(0), m_row(0), m_time(0){}

//=================================READ LEVEL==================================
//This function getting the index of the level, open it and insert the objects
//and their position on file into pair and return the pair.
//the first element of the pair - objects represent by letters
//the second element of the pair - objects locations according to the file
//=============================================================================
std::pair<std::vector <char>, std::vector <sf::Vector2f>> File::readLevel(const int& indexLevel)
{
	openFile(indexLevel);
	std::pair<std::vector <char>, std::vector <sf::Vector2f>> map;
	char type;

	// Get the size of the map
	m_file >> m_row >> m_col >> m_time;

	// Calc the size of each object
	auto objctWidth = (WINDOW_WIDTH / m_col);
	auto objctHeight = ((WINDOW_HEIGHT - DATA_BAR_HEIGHT) / m_row);
	m_size = sf::Vector2f(objctWidth, objctHeight);

	m_file.get();

	// Build the map
	for (auto i = 0; i < m_row; i++)
	{
		for (auto j = 0; j < m_col; j++)
		{
			m_file.get(type);
			charIsValid(type);
			map.first.push_back(type);
			sf::Vector2f loc = sf::Vector2f(j * objctWidth, i * objctHeight);
			map.second.push_back(loc);
			type = ' ';
		}
		m_file.get();
	}

	m_file.close();
	return map;
}
//==================================GET SIZE==================================
//This function return the size that each object supposed to be according 
//to the amount of rows and cols in the input file
//=============================================================================
sf::Vector2f File::getSize() const
{
	return m_size;
}
int File::getTime() const
{
	return m_time;
}
//=================================OPEN FILE==================================
//This function open the file , the format of the file name is -
//"level_(number).txt" , in case that the file doesnt exist it throw exeption - 
//the file name is ivalid
//=============================================================================
void File::openFile(const int& index)
{
	std::string fileName;
	Menu m;
	if (m.getDifficulty())
		fileName = "difficult_level_";
	else
		fileName = "level_";
	fileName.append(std::to_string(index));
	fileName.append(".txt");

	m_file.open(fileName);

	if (!m_file.is_open())
		throw std::exception("The file name is ivalid or doesnt exist \n format is : level_(number).txt");
}
//===============================CHAR IS VALID=================================
//This function check if the char in the input is valid - there is existing 
//object that it char defined to be that, in case that the char ivalid it 
//throw exepetion - the input file is not valid.
//=============================================================================
bool File::charIsValid(const char& obj) const
{

	if (obj == 'P' ||
		obj == 'W' ||
		obj == '*' ||
		obj == '#' ||
		obj == 'B' ||
		obj == 'A' ||
		obj == 'E' ||
		obj == 'O' ||
		obj == ' ' ||
		obj == 'T' ||
		obj == 'G' ||
		obj == '-' )
		return true;

	throw std::invalid_argument("One of the chars in the input file is invalid \n");
}
