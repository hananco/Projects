#pragma once
#include <vector>
class Level
{
public:
	Level(std::vector<std::vector<int>>& level, const int& row , const int& col);
	Level() = default;
	std::vector <int> getPipe(const int & index)const;//return a line from the victor (ech line is object)
	int getRow() const;
	int getCol() const;
	int getWichObject(const int& indexRow ,const int& indexCol)const;//return wich object (sink / pipe / tap)

private:
	int m_row;// a mount of row
	int m_col;// a mount of col
	std::vector<std::vector<int>> m_level;// victor thet in ech row have a vector to level 
};

