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
//				goto abcd;
//			}
//		}
//	}
//abcd:
//
//	std::vector<int2> visitedPos;
//
//	int2 dirVector = { 0, -1 };
//
//	while (gardPosition.y < InpVec.size() && gardPosition.y >= 0 && gardPosition.x < InpVec[0].size() && gardPosition.x >= 0)
//	{
//
//		if (InpVec[gardPosition.y + dirVector.y][gardPosition.x + dirVector.x] == '#')
//		{
//			if (dirVector.y == -1 && dirVector.x == 0)
//			{
//				dirVector.y = 0;
//				dirVector.x = 1;
//			}
//			else if (dirVector.y == 0 && dirVector.x == 1)
//			{
//				dirVector.y = 1;
//				dirVector.x = 0;
//			}
//			else if (dirVector.y == 1 && dirVector.x == 0)
//			{
//				dirVector.y = 0;
//				dirVector.x = -1;
//			}
//			else if (dirVector.y == 0 && dirVector.x == -1)
//			{
//				dirVector.y = -1;
//				dirVector.x = 0;
//			}
//			else
//				throw;
//		}
//		else
//		{
//			if (!contains(visitedPos, gardPosition))
//			{
//				visitedPos.push_back(gardPosition);
//			}
//
//			gardPosition.y += dirVector.y;
//			gardPosition.x += dirVector.x;
//		}
//	}
//
//	std::cout << visitedPos.size();
//
//}
//
////5131