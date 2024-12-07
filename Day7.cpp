//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <regex>
//#include <cmath>
//
//int main()
//{
//
//	std::ifstream file("Day7Inp.txt");
//
//	std::vector<std::string> inpVec;
//	std::string line;
//
//	while (std::getline(file, line))
//	{
//		inpVec.push_back(line);
//	}
//
//	std::vector<int64_t> leftNumber;
//	std::vector<std::vector<int64_t>> rightNumbers;
//
//	for (int i = 0; i < inpVec.size(); i++)
//	{
//		std::regex reg("[0-9]{1,100}");
//
//		std::smatch match;
//
//		std::string str = inpVec[i];
//
//		if (!std::regex_search(str, match, reg))
//		{
//			throw;
//		}
//
//		std::string s = match.str(0);
//
//		leftNumber.push_back(std::stoll(match.str(0)));
//
//		str = match.suffix().str();
//
//
//
//		rightNumbers.emplace_back(std::vector<int64_t>());
//
//		while (std::regex_search(str, match, reg))
//		{
//			std::string s = match.str(0);
//
//			rightNumbers[i].push_back(std::stoll(match.str(0)));
//
//			str = match.suffix().str();
//		}
//	}
//
//#define PLUSS (uint64_t)0
//#define MUL (uint64_t)1
//
//	uint64_t sum = 0;
//
//	for (int i = 0; i < leftNumber.size(); i++)
//	{
//
//		for (uint64_t mulOrpluss = 0; mulOrpluss < pow(2.0, rightNumbers[i].size()); mulOrpluss++)
//		{
//			uint64_t tempSum = rightNumbers[i][0];
//			for (int j = 0; j < rightNumbers[i].size() - 1; j++)
//			{
//
//				if ((mulOrpluss & (MUL << j)) != 0)
//				{
//					tempSum *= rightNumbers[i][j + 1];
//					//std::cout << 1 << " ";
//				}
//				else
//				{
//					tempSum += rightNumbers[i][j + 1];
//					//std::cout << 0 << " ";
//				}
//			}
//			//std::cout << "\n";
//
//			if (tempSum == leftNumber[i])
//			{
//				sum += tempSum;
//				break;
//			}
//		}
//	}
//
//	std::cout << sum;
//
//}
//
////10778790118 upp
////
////10789368296 upp
////
////2299996598890