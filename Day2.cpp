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
//	int sum = 0;
//	bool safe = true;
//	bool asending = false;
//
//
//	for (int i = 0; i < inpVec.size(); i++)
//	{
//		asending = (inpVec[i][0] < inpVec[i][1]) ? true : false;
//
//		for (int j = 1; j < inpVec[i].size(); j++)
//		{
//			if (inpVec[i][j - 1] < inpVec[i][j])
//			{
//				if (asending == false)
//				{
//					safe = false;
//				}
//			}
//			else 
//			{
//				if (asending == true)
//				{
//					safe = false;
//				}
//			}
//
//			if (abs(inpVec[i][j - 1] - inpVec[i][j]) < 1 || abs(inpVec[i][j - 1] - inpVec[i][j]) > 3)
//			{
//				safe = false;
//			}
//		}
//
//		sum += (safe) ? 1 : 0;
//		safe = true;
//	}
//
//	std::cout << sum;
//
//
//}