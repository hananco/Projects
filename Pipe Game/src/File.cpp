#include "File.h"

File::File()	
{
	m_file.open(FILE_NAME);
	if (!m_file.is_open())
		throw std::exception("conot open file");
}

File::~File()
{
	if (m_file.is_open())
		m_file.close();

}

Level File::readLevalFromFile()
{
	auto res = std::vector<std::vector<int>>();
	std::istringstream getDataFromFile;
	std::string row, col;
	int numOfRow, NumOfCol , sizeOfPipe , input;

	m_file >> row >> col;
	numOfRow = stoi(row);
	NumOfCol = stoi(col);
	sizeOfPipe = numOfRow * NumOfCol;
	m_file.get();

	res.resize(sizeOfPipe);
	for (int index = 0; index < sizeOfPipe; index++)
	{
		std::string lineInput;
		std::getline(m_file, lineInput);
		getDataFromFile = std::istringstream(lineInput);
		checkInput(getDataFromFile);
		getDataFromFile = std::istringstream(lineInput);
		while (getDataFromFile >> input)
		{

			res[index].push_back(input);
		}
	}
	

	if (m_file.eof())
		m_endOfFile = true;

	return Level(res, numOfRow, NumOfCol);
}

bool File::getEof() const
{
	return m_endOfFile;
}

void File::checkInput(std::istringstream& lineInput) const
{
	
	int input;
	for(int i = 0 ; i < LINE_SIZE ; i++)
	{
		lineInput >> input;
		if (input != 0 && input != 1)
		{
			throw  std::invalid_argument("One of the bits invalid");
		}
	}
}


