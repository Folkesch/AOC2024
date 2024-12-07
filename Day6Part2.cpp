//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//
//struct int2
//{
//	int x;
//	int y;
//};
//
//struct int2FS
//{
//	int first;
//	int second;
//};
//
//struct ObsAria {
//	int rowFirst;
//	int rowSecond;
//	int columnFirst;
//	int columnSecond;
//	bool aimingPositiv;
//};
//
//#define OBST	(char)0b00000001
//#define UPP		(char)0b00000010
//#define DOWN	(char)0b00000100
//#define RIGHT	(char)0b00001000
//#define LEFT	(char)0b00010000
//#define BHEAR	(char)0b00100000
//
//
//
//bool contains(std::vector<int2>& vec, int2 pos)
//{
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		if (vec[i].x == pos.x && vec[i].y == pos.y)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//
//	std::ifstream file("Day6Inp.txt");
//
//	std::vector<std::string> InpVec;
//	std::string line;
//
//	while (std::getline(file, line))
//	{
//		InpVec.push_back(line);
//	}
//
//	int2 gardPosition = { 0,0 };
//
//	// find gard
//	for (int i = 0; i < InpVec.size(); i++)
//	{
//		for (int j = 0; j < InpVec[0].size(); j++)
//		{
//			if (InpVec[i][j] == '^')
//			{
//				gardPosition.y = i;
//				gardPosition.x = j;
//				InpVec[i][j] = '.';
//				goto abcd;
//			}
//		}
//	}
//abcd:
//
//	std::vector<std::vector<uint8_t>> newGrid;
//
//	for (int y = 0; y < InpVec.size(); y++)
//	{
//		newGrid.emplace_back(std::vector<uint8_t>());
//		for (int x = 0; x < InpVec[0].size(); x++)
//		{
//			if (InpVec[y][x] == '#')
//			{
//				newGrid[y].emplace_back((uint8_t)0 | OBST);
//			}
//			else
//			{
//				newGrid[y].emplace_back((uint8_t)0);
//			}
//		}
//	}
//
//	std::string str;
//
//	for (int i = 0; i < newGrid.size(); i++)
//	{
//		for (int j = 0; j < newGrid[i].size(); j++)
//		{
//			if ((newGrid[i][j] & OBST) == OBST)
//			{
//				str += "#";
//			}
//			else if (newGrid[i][j] != 0)
//			{
//				str += "+";
//			}
//			else
//				str += ".";
//		}
//		str += "\n";
//	}
//
//	std::vector<int2> ObsticalPositions;
//
//	int2 dirVector = { 0, -1 };
//
//	int iterations = 0;
//
//	while (gardPosition.y < newGrid.size() - 1 && gardPosition.y > 0 && gardPosition.x < newGrid[0].size() - 1 && gardPosition.x > 0)
//	{
//
//		if ((newGrid[gardPosition.y + dirVector.y][gardPosition.x + dirVector.x] & OBST) != 0)
//		{
//			if (dirVector.y == -1 && dirVector.x == 0)
//			{
//				int tempy = gardPosition.y;
//				while (tempy < newGrid.size() && (newGrid[tempy][gardPosition.x] & OBST) == 0)
//				{
//					if ((newGrid[tempy][gardPosition.x] & UPP) != 0)
//						throw;
//					newGrid[tempy][gardPosition.x] = newGrid[tempy][gardPosition.x] | UPP;
//
//					tempy++;
//				}
//				
//				dirVector.y = 0;
//				dirVector.x = 1;
//			}
//			else if (dirVector.y == 0 && dirVector.x == 1)
//			{
//
//				int tempx = gardPosition.x;
//				while (tempx > 0 && (newGrid[gardPosition.y][tempx] & OBST) == 0)
//				{
//					if ((newGrid[gardPosition.y][tempx] & RIGHT) != 0)
//						throw;
//					newGrid[gardPosition.y][tempx] = newGrid[gardPosition.y][tempx] | RIGHT;
//
//					tempx--;
//				}
//
//				dirVector.y = 1;
//				dirVector.x = 0;
//			}
//			else if (dirVector.y == 1 && dirVector.x == 0)
//			{
//
//				int tempy = gardPosition.y;
//				while (tempy > 0 && (newGrid[tempy][gardPosition.x] & OBST) == 0)
//				{
//					if ((newGrid[tempy][gardPosition.x] & DOWN) != 0)
//						throw;
//					newGrid[tempy][gardPosition.x] = newGrid[tempy][gardPosition.x] | DOWN;
//
//					tempy--;
//				}
//
//				dirVector.y = 0;
//				dirVector.x = -1;
//			}
//			else if (dirVector.y == 0 && dirVector.x == -1)
//			{
//
//				int tempx = gardPosition.x;
//				while (tempx < newGrid[0].size() && (newGrid[gardPosition.y][tempx] & OBST) == 0)
//				{
//					if ((newGrid[gardPosition.y][tempx] & LEFT) != 0)
//						throw;
//					newGrid[gardPosition.y][tempx] = newGrid[gardPosition.y][tempx] | LEFT;
//
//					tempx++;
//				}
//
//				dirVector.y = -1;
//				dirVector.x = 0;
//			}
//			else
//				throw;
//		}
//		else
//		{
//
//			if ((newGrid[gardPosition.y][gardPosition.x] & BHEAR) == BHEAR && (newGrid[gardPosition.y][gardPosition.x] - BHEAR) == 0)
//				throw;
//
//
//			if (dirVector.y == -1 && dirVector.x == 0)
//			{
//				if ((newGrid[gardPosition.y][gardPosition.x] & RIGHT) == RIGHT) {
//
//					if (!contains(ObsticalPositions, { gardPosition.x + dirVector.x, gardPosition.y + dirVector.y }) && newGrid[gardPosition.y + dirVector.y][gardPosition.x + dirVector.x] == 0)
//					{
//						ObsticalPositions.emplace_back(gardPosition.x + dirVector.x, gardPosition.y + dirVector.y);
//					}
//
//				}
//			}
//			else if (dirVector.y == 0 && dirVector.x == 1)
//			{
//				if ((newGrid[gardPosition.y][gardPosition.x] & DOWN) == DOWN) {
//
//					if (!contains(ObsticalPositions, { gardPosition.x + dirVector.x, gardPosition.y + dirVector.y }) && newGrid[gardPosition.y + dirVector.y][gardPosition.x + dirVector.x] == 0)
//					{
//						ObsticalPositions.emplace_back(gardPosition.x + dirVector.x, gardPosition.y + dirVector.y);
//					}
//
//				}
//			}
//			else if (dirVector.y == 1 && dirVector.x == 0)
//			{
//				if ((newGrid[gardPosition.y][gardPosition.x] & LEFT) == LEFT) {
//
//					if (!contains(ObsticalPositions, { gardPosition.x + dirVector.x, gardPosition.y + dirVector.y }) && newGrid[gardPosition.y + dirVector.y][gardPosition.x + dirVector.x] == 0)
//					{
//						ObsticalPositions.emplace_back(gardPosition.x + dirVector.x, gardPosition.y + dirVector.y);
//					}
//
//				}
//			}
//			else if (dirVector.y == 0 && dirVector.x == -1)
//			{
//				if ((newGrid[gardPosition.y][gardPosition.x] & UPP) == UPP) {
//
//					if (!contains(ObsticalPositions, { gardPosition.x + dirVector.x, gardPosition.y + dirVector.y }) && newGrid[gardPosition.y + dirVector.y][gardPosition.x + dirVector.x] == 0)
//					{
//						ObsticalPositions.emplace_back(gardPosition.x + dirVector.x, gardPosition.y + dirVector.y);
//					}
//
//				}
//			}
//			else
//				throw;
//			
//			newGrid[gardPosition.y][gardPosition.x] += BHEAR;
//
//			gardPosition.y += dirVector.y;
//			gardPosition.x += dirVector.x;
//
//			
//			if (iterations % 1 == 0)
//			{
//				str.clear();
//
//				for (int i = 0; i < newGrid.size(); i++)
//				{
//					for (int j = 0; j < newGrid[i].size(); j++)
//					{
//						if ((newGrid[i][j] & OBST) == OBST)
//						{
//							str += "#";
//						}
//						else if ((newGrid[i][j] & UPP) == UPP)
//						{
//							str += "^";
//						}
//						else if ((newGrid[i][j] & RIGHT) == RIGHT)
//						{
//							str += ">";
//						}
//						else if ((newGrid[i][j] & DOWN) == DOWN)
//						{
//							str += "!";
//						}
//						else if ((newGrid[i][j] & LEFT) == LEFT)
//						{
//							str += "<";
//						}
//						
//						else if ((newGrid[i][j] & BHEAR) == BHEAR && (newGrid[i][j] & LEFT) != LEFT && (newGrid[i][j] & DOWN) != DOWN && 
//							(newGrid[i][j] & RIGHT) != RIGHT && (newGrid[i][j] & UPP) != UPP)
//						{
//							str += "X";
//						}
//						else
//							str += ".";
//					}
//					str += "\n";
//				}
//			}
//			
//
//		}
//
//		if (iterations % 5790 == 0)
//		{
//			std::cout << "";
//		}
//
//		iterations++;
//	}
//
//	str.clear();
//
//	for (int i = 0; i < newGrid.size(); i++)
//	{
//		for (int j = 0; j < newGrid[i].size(); j++)
//		{
//			if ((newGrid[i][j] & OBST) == OBST)
//			{
//				str += "#";
//			}
//			else if ((newGrid[i][j] & UPP) == UPP)
//			{
//				str += "^";
//			}
//			else if ((newGrid[i][j] & RIGHT) == RIGHT)
//			{
//				str += ">";
//			}
//			else if ((newGrid[i][j] & DOWN) == DOWN)
//			{
//				str += "!";
//			}
//			else if ((newGrid[i][j] & LEFT) == LEFT)
//			{
//				str += "<";
//			}
//			else if ((newGrid[i][j] & BHEAR) == BHEAR)
//			{
//				str += "X";
//			}
//			else
//				str += ".";
//		}
//		str += "\n";
//	}
//
//	std::cout << ObsticalPositions.size();
//
//}
//
////16616 down
////
////3496 down
////
////407 upp
////
////214 nop
////
////440 nop
////
////421 nop
////
////