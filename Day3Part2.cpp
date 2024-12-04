//#include <iostream>
//#include <string>
//#include <sstream>
//#include <regex>
//#include <vector>
//
//#include <fstream>
//
//int main()
//{
//	std::ifstream file("Day3Inp.txt");
//
//	std::string inpStr = "";
//	std::string line;
//
//	std::vector<std::string> strVec;
//
//	while (std::getline(file, line))
//	{
//		inpStr += line;
//	}
//	int sum = 0;
//
//
//	int curIdx = 0;
//	int startIdx = 0;
//	int endIdx = 0;
//	bool boolDo = true;
//
//	while (curIdx < inpStr.size() - 10)
//	{
//		if (inpStr[curIdx] == 'd' && inpStr[curIdx + 1] == 'o')
//		{
//			curIdx += 2;
//			if (inpStr[curIdx] == '(' && inpStr[curIdx + 1] == ')')
//			{
//				if (!boolDo)
//				{
//					startIdx = curIdx + 2;
//				}
//
//				boolDo = true;
//
//			}
//			else if (inpStr[curIdx] == 'n' && inpStr[curIdx + 1] == '\'' && inpStr[curIdx + 2] == 't' && inpStr[curIdx + 3] == '(' && inpStr[curIdx + 4] == ')')
//			{
//				if (boolDo)
//				{
//					endIdx = curIdx;
//					strVec.push_back(inpStr.substr(startIdx, endIdx - startIdx));
//				}
//
//				boolDo = false;
//			}
//			else
//				curIdx--;
//		}
//		curIdx++;
//	}
//
//
//
//	for (std::string str : strVec)
//	{
//
//		std::regex reg(R"(mul\((\d{1,3}),(\d{1,3})\))");
//
//		std::smatch matches;
//
//		while (std::regex_search(str, matches, reg))
//		{
//			std::cout << matches.str(0);
//			int x = stoi(matches.str(1));
//			int y = stoi(matches.str(2));
//
//			sum += x * y;
//
//			str = matches.suffix().str();
//		}
//
//	}
//
//	std::cout << sum;
//
//}