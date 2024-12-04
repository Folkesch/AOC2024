//#include <iostream>
//#include <string>
//#include <sstream>
//#include <regex>
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
//	while (std::getline(file, line))
//	{
//		inpStr += line;
//	}
//
//	std::regex reg(R"(mul\((\d{1,3}),(\d{1,3})\))");
//
//	std::smatch matches;
//
//	int sum = 0;
//
//	while (std::regex_search(inpStr, matches, reg))
//	{
//		std::cout << matches.str(0);
//		int x = stoi(matches.str(1));
//		int y = stoi(matches.str(2));
//
//		sum += x * y;
//
//		inpStr = matches.suffix().str();
//	}
//
//	std::cout << sum;
//
//}
//
////180695781 ner
////
////30039 upp
//// 
////29610384 upp
////
////170807108
//// 
//// 
////
////