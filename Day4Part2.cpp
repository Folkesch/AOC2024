//#include <iostream>
//#include <regex>
//#include <vector>
//#include <fstream>
//#include <string>
//
//int main()
//{
//	std::ifstream file("Day4Inp.txt");
//
//	std::vector<std::string> L_RstrVec;
//
//	std::string line;
//
//	while (std::getline(file, line))
//	{
//		L_RstrVec.push_back(line);
//	}
//
//	int sum = 0;
//
//	for (int y = 1; y < L_RstrVec.size() - 1; y++)
//	{
//		for (int x = 1; x < L_RstrVec[0].size() - 1; x++)
//		{
//			if (L_RstrVec[y][x] == 'A')
//			{
//				if ((L_RstrVec[y - 1][x - 1] == 'M' && L_RstrVec[y + 1][x + 1] == 'S' && L_RstrVec[y - 1][x + 1] == 'M' && L_RstrVec[y + 1][x - 1] == 'S') ||
//					(L_RstrVec[y - 1][x - 1] == 'S' && L_RstrVec[y + 1][x + 1] == 'M' && L_RstrVec[y - 1][x + 1] == 'S' && L_RstrVec[y + 1][x - 1] == 'M') ||
//					(L_RstrVec[y - 1][x - 1] == 'M' && L_RstrVec[y + 1][x + 1] == 'S' && L_RstrVec[y - 1][x + 1] == 'S' && L_RstrVec[y + 1][x - 1] == 'M') ||
//					(L_RstrVec[y - 1][x - 1] == 'S' && L_RstrVec[y + 1][x + 1] == 'M' && L_RstrVec[y - 1][x + 1] == 'M' && L_RstrVec[y + 1][x - 1] == 'S'))
//				{
//					sum++;
//				}
//			}
//		}
//	}
//
//	std::cout << sum;
//
//}
//
//// 1822
