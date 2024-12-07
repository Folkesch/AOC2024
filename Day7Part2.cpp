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
//	std::vector<uint64_t> leftNumber;
//	std::vector<std::vector<uint64_t>> rightNumbers;
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
//		leftNumber.push_back(std::stoull(match.str(0)));
//
//		str = match.suffix().str();
//
//
//
//		rightNumbers.emplace_back(std::vector<uint64_t>());
//
//		while (std::regex_search(str, match, reg))
//		{
//			std::string s = match.str(0);
//
//			rightNumbers[i].push_back(std::stoull(match.str(0)));
//
//			str = match.suffix().str();
//		}
//	}
//
//#define PLUSS			(uint64_t)0
//#define MUL				(uint64_t)1
//#define ADDTOGETHER		(uint64_t)2
//
//	uint64_t sum = 0;
//
//	bool skipp = false;
//
//	std::vector<unsigned short> mulAddVec;
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
//				skipp = true;
//				break;
//			}
//		}
//
//
//		if (!skipp)
//		{
//		for (int j = 0; j < rightNumbers[i].size() - 1; j++)
//		{
//			mulAddVec.push_back(0);
//		}
//
//
//		for (uint64_t mulOrpluss = 0; mulOrpluss < pow(3.0, rightNumbers[i].size()); mulOrpluss++)
//		{
//
//			std::vector<uint64_t> tempRightNumbers = rightNumbers[i];
//			std::vector<unsigned short> tempMulAddVec = mulAddVec;
//
//			bool chaged = true;
//
//			while (chaged)
//			{
//				chaged = false;
//				for (int j = 0; j < tempRightNumbers.size() - 1; j++)
//				{
//					if (tempMulAddVec[j] == ADDTOGETHER)
//					{
//						std::string s = std::to_string(tempRightNumbers[j]) + std::to_string(tempRightNumbers[j + 1]);
//
//						tempRightNumbers[j] = std::stoull(s);
//
//						tempRightNumbers.erase(tempRightNumbers.begin() + j + 1, tempRightNumbers.begin() + j + 2);
//						tempMulAddVec.erase(tempMulAddVec.begin() + j, tempMulAddVec.begin() + j + 1);
//
//						chaged = true;
//
//						break;
//					}
//					else if (tempMulAddVec[j] == MUL)
//					{
//						tempRightNumbers[j] *= tempRightNumbers[j + 1];
//
//						tempRightNumbers.erase(tempRightNumbers.begin() + j + 1, tempRightNumbers.begin() + j + 2);
//						tempMulAddVec.erase(tempMulAddVec.begin() + j, tempMulAddVec.begin() + j + 1);
//
//						chaged = true;
//
//						break;
//					}
//					else if (tempMulAddVec[j] == PLUSS)
//					{
//						tempRightNumbers[j] += tempRightNumbers[j + 1];
//
//						tempRightNumbers.erase(tempRightNumbers.begin() + j + 1, tempRightNumbers.begin() + j + 2);
//						tempMulAddVec.erase(tempMulAddVec.begin() + j, tempMulAddVec.begin() + j + 1);
//
//						chaged = true;
//
//						break;
//					}
//					else
//						throw;
//				}
//			}
//
//			if (tempRightNumbers[0] == leftNumber[i])
//			{
//				sum += leftNumber[i];
//				break;
//			}
//
//			for (int x = 0; x < mulAddVec.size(); x++)
//			{
//				if (mulAddVec[x] < 2)
//				{
//					mulAddVec[x]++;
//					break;
//				}
//				else
//				{
//					mulAddVec[x] = 0;
//				}
//			}
//
//		}
//
//		}
//		skipp = false;
//
//		mulAddVec.clear();
//
//		std::cout << i << "\n";
//
//	}
//
//	std::cout << sum;
//
//}
//
////3626331661
//// 
////242546995005
//// 
////243007819611
////
////2299996598890
////
////60306638138231 upp
////
////362646859298554