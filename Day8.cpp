//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//
//struct int2
//{
//	int x;
//	int y;
//};
//
//int main()
//{
//
//	std::ifstream file("Day8Inp.txt");
//
//	std::string line;
//	std::vector<std::string> inpVec;
//
//	while (std::getline(file, line))
//	{
//		inpVec.push_back(line);
//	}
//
//	std::vector<std::vector<int2>> antennaPos;
//	std::unordered_map<char, int> map;
//
//	int vecIdx = 0;
//	
//	for (int y = 0; y < inpVec.size(); y++)
//	{
//		for (int x = 0; x < inpVec[y].size(); x++)
//		{
//
//			if (inpVec[y][x] != '.')
//			{
//				if (map.find(inpVec[y][x]) == map.end())
//				{
//					map[inpVec[y][x]] = vecIdx;
//					vecIdx++;
//					antennaPos.emplace_back(std::vector<int2>());
//					antennaPos[map[inpVec[y][x]]].push_back({ x, y });
//				}
//				else
//				{
//					antennaPos[map[inpVec[y][x]]].push_back({ x, y });
//				}
//			}
//		}
//	}
//
//	std::vector<std::string> newGrid;
//
//	for (int i = 0; i < inpVec.size(); i++)
//	{
//		newGrid.emplace_back(std::string());
//		for (int j = 0; j < inpVec[i].size(); j++)
//		{
//			newGrid[i] += ".";
//		}
//	}
//
//	int sum = 0;
//
//	bool frequencyFound = false;
//
//	for (int y = 0; y < newGrid.size(); y++)
//	{
//		for (int x = 0; x < newGrid[y].size(); x++)
//		{
//			for (int i = 0; i < antennaPos.size(); i++)
//			{
//				std::vector<int2> VectorFromOther;
//				for (int j = 0; j < antennaPos[i].size(); j++)
//				{
//					VectorFromOther.push_back({ antennaPos[i][j].x - x, antennaPos[i][j].y - y });
//				}
//
//				for (int j = 0; j < VectorFromOther.size(); j++)
//				{
//					int2 tempLength = { VectorFromOther[j].x * 2, VectorFromOther[j].y * 2 };
//
//					for (int z = 0; z < VectorFromOther.size(); z++)
//					{
//						if (j != z)
//						{
//							if (tempLength.x == VectorFromOther[z].x && tempLength.y == VectorFromOther[z].y)
//							{
//								newGrid[y][x] = '#';
//								sum++;
//								frequencyFound = true;
//								break;
//							}
//						}
//
//					}
//
//					if (frequencyFound)
//					{
//						break;
//					}
//				}
//
//				if (frequencyFound)
//				{
//					break;
//				}
//			}
//
//			frequencyFound = false;
//
//		}
//	}
//
//	std::cout << sum;
//
//
//}
//
////249