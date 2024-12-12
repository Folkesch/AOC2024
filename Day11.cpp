//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <regex>
//#include <algorithm>
//
//int main()
//{
//
//	std::ifstream file("Day11Inp.txt");
//
//	std::string line;
//
//	std::getline(file, line);
//
//	std::regex reg("[0-9]{1,1000}");
//
//	std::smatch match;
//
//	std::vector<uint64_t> vec;
//
//	while (std::regex_search(line, match, reg))
//	{
//		vec.push_back(std::stoull(match.str(0)));
//		line = match.suffix().str();
//	}
//
//	std::vector<uint64_t> newVec;
//
//	std::string tempStr;
//
//
//	for (int iter = 0; iter < 75; iter++)
//	{
//		for (int i = 0; i < vec.size(); i++)
//		{
//			tempStr = std::to_string(vec[i]);
//
//			if (vec[i] == 0)
//			{
//				newVec.emplace_back(1);
//			}
//			else if (tempStr.size() % 2 == 0)
//			{
//				std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//				std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//				newVec.push_back(std::stoull(s1));
//				newVec.push_back(std::stoull(s2));
//			}
//			else
//			{
//				newVec.emplace_back(vec[i] * 2024);
//			}
//		}
//
//		vec = std::move(newVec);
//	}
//
//	std::cout << vec.size();
//
//}
//
////222461