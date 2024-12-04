//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//
//int main()
//{
//	std::ifstream fileInp("Day2Inp.txt");
//
//	std::string inpArr;
//
//	std::vector<std::vector<int>> inpVec;
//	int index = 0;
//
//	for (std::string line; std::getline(fileInp, line); )
//	{
//		std::stringstream test(line);
//		std::string segment;
//		inpVec.emplace_back(std::vector<int>());
//
//		while (std::getline(test, segment, ' '))
//		{
//			inpVec[index].push_back(stoi(segment));
//		}
//		index++;
//
//	}
//
//
//
//	//std::vector<std::vector<std::vector<int>>> inpVec2;
//
//	//for (int i = 0; i < inpVec.size(); i++)
//	//{
//	//	inpVec2.emplace_back(std::vector<std::vector<int>>());
//	//	for (int j = 0; j < inpVec[i].size(); j++)
//	//	{
//	//		inpVec2[i].emplace_back(std::vector<int>());
//
//
//	//	}
//	//}
//
//
//
//
//	int sum = 0;
//	bool safe = true;
//	bool isSafe = false;
//	int safeSum = 0;
//	bool asending = false;
//
//	std::vector<std::vector<int>> variants;
//
//	for (int i = 0; i < inpVec.size(); i++)
//	{
//		variants.push_back(inpVec[i]);
//		for (int j = 1; j < inpVec[i].size() + 1; j++)
//		{
//			variants.push_back(inpVec[i]);
//			variants[j].erase(variants[j].begin() + j - 1);
//		}
//
//		asending = (variants[0][0] < variants[0][1]) ? true : false;
//
//		for (int x = 1; x < variants[0].size(); x++)
//		{
//			if (variants[0][x - 1] < variants[0][x])
//			{
//				if (asending == false)
//				{
//					safe = false;
//				}
//			}
//			else
//			{
//				if (true == asending)
//				{
//					safe = false;
//				}
//			}
//
//			if (abs(variants[0][x - 1] - variants[0][x]) < 1 || abs(variants[0][x - 1] - variants[0][x]) > 3)
//			{
//				safe = false;
//			}
//		}
//
//		if (safe) {
//
//			sum++;
//			safe = true;
//			variants.clear();
//		}
//		else
//		{
//
//			safe = true;
//
//			safeSum = 0;
//
//			for (int j = 1; j < variants.size(); j++)
//			{
//				asending = (variants[j][0] < variants[j][1]) ? true : false;
//
//				for (int x = 1; x < variants[j].size(); x++)
//				{
//					if (variants[j][x - 1] < variants[j][x])
//					{
//						if (asending == false)
//						{
//							safe = false;
//						}
//					}
//					else
//					{
//						if (true == asending)
//						{
//							safe = false;
//						}
//					}
//
//					if (abs(variants[j][x - 1] - variants[j][x]) < 1 || abs(variants[j][x - 1] - variants[j][x]) > 3)
//					{
//						safe = false;
//					}
//
//					if (safe == false)
//					{
//						safeSum++;
//						break;
//					}
//				}
//				safe = true;
//			}
//
//			if (safeSum < variants.size() - 1)
//			{
//				sum++;
//			}
//
//
//			variants.clear();
//		}
//
//	}
//
//	std::cout << sum;
//
//}
//
////594