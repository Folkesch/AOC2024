///*#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <regex>
//
//struct beforeAfter
//{
//	int before;
//	int after;
//};
//
//int main()
//{
//	std::ifstream file("Day5Inp.txt");
//	std::vector<std::string> inpStrVec;
//	std::vector<std::string> inpStrVec2;
//	std::string line;
//
//	std::getline(file, line);
//
//	while (line != "")
//	{
//		inpStrVec.push_back(line);
//		
//
//		if (!std::getline(file, line))
//		{
//			throw;
//		}
//	}
//
//	while (std::getline(file, line))
//	{
//		inpStrVec2.push_back(line);
//	}
//
//	std::vector<beforeAfter> conditions;
//	std::vector<std::vector<int>> pages;
//
//	for (int i = 0; i < inpStrVec.size(); i++)
//	{
//		std::regex reg("([0-9]{2})\\|([0-9]{2})");
//
//		std::smatch matches;
//
//		std::regex_search(inpStrVec[i], matches, reg);
//
//		conditions.push_back({ stoi(matches.str(1)), stoi(matches.str(2)) });
//
//	}
//
//	for (int i = 0; i < inpStrVec2.size(); i++)
//	{
//		pages.emplace_back(std::vector<int>());
//		std::regex reg("([0-9]{2})");
//
//		std::smatch matches;
//
//		std::string str = inpStrVec2[i];
//
//		while (std::regex_search(str, matches, reg))
//		{
//			pages[i].push_back(stoi(matches.str(0)));
//
//			str = matches.suffix().str();
//		}
//
//	}
//
//	bool innerGood = false;
//	int sum = 0;
//
//	for (int i = 0; i < pages.size(); i++)
//	{
//
//		for (int j = 0; j < pages[i].size() - 1; j++)
//		{
//
//			for (int j2 = j + 1; j2 < pages[i].size(); j2++)
//			{
//
//				for (int x = 0; x < conditions.size(); x++)
//				{
//					
//					if (conditions[x].before == pages[i][j] && conditions[x].after == pages[i][j2])
//					{
//						innerGood = false;
//						break;
//					}
//				}
//
//				if (innerGood == false)
//				{
//					break;
//				}
//			}
//
//			if (innerGood)
//			{
//				sum += pages[i][pages[i].size() / 2];
//			}
//
//			innerGood = true;
//
//		}
//
//	}
//
//	std::cout << sum;
//
//
//}
//*/
//
//
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <regex>
//
//struct beforeAfter
//{
//	int before;
//	int after;
//};
//
//int main()
//{
//	std::ifstream file("Day5Inp.txt");
//	std::string inpStrVec;
//	std::vector<std::string> inpStrVec2;
//	std::string line;
//
//	std::getline(file, line);
//
//	while (line != "")
//	{
//		inpStrVec += " " + line;
//
//
//		std::getline(file, line);
//	}
//
//	while (std::getline(file, line))
//	{
//		inpStrVec2.push_back(line);
//	}
//
//	std::vector<std::vector<int>> pages;
//
//	for (int i = 0; i < inpStrVec2.size(); i++)
//	{
//		pages.emplace_back(std::vector<int>());
//		std::regex reg("([0-9]{2})");
//
//		std::smatch matches;
//
//		std::string str = inpStrVec2[i];
//
//		while (std::regex_search(str, matches, reg))
//		{
//			pages[i].push_back(stoi(matches.str(0)));
//
//			str = matches.suffix().str();
//		}
//
//	}
//
//	bool good = true;
//	bool nextGood = true;
//
//	int sum = 0;
//
//	for (int i = 0; i < pages.size(); i++)
//	{
//		for (int j = 0; j < pages[i].size(); j++)
//		{
//
//			for (int j2 = j + 1; j2 < pages[i].size(); j2++)
//			{
//				std::regex reg(std::to_string(pages[i][j]) + "\\|" + std::to_string(pages[i][j2]));
//
//				std::smatch match;
//
//				if (!std::regex_search(inpStrVec, match, reg))
//				{
//					good = false;
//					break;
//				}
//			}
//
//			if (good == false)
//			{
//				break;
//			}
//		}
//
//		if (good)
//		{
//			sum += pages[i][pages[i].size() / 2];
//		}
//
//		good = true;
//
//		std::cout << "b";
//
//	}
//
//	std::cout << sum;
//
//
//}
//
////96504 down
////
////95266 down
////
////6260