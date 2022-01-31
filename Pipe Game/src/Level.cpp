#include "Level.h"

Level::Level(std::vector<std::vector<int>>& level, const int& row, const int& col)
 :m_level(level) ,m_row(row) , m_col(col)
{
}

std::vector<int> Level::getPipe(const int& index) const
{
	return m_level[index];
}

int Level::getRow() const
{
	return m_row;
}

int Level::getCol() const
{
	return m_col;
}

int Level::getWichObject(const int& indexRow ,const int & indexCol)const
{
	return m_level[indexRow][indexCol] ;
}
