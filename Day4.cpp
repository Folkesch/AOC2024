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
//	std::vector<std::string> U_DstrVec;
//	std::vector<std::string> UL_DRstrVec;
//	std::vector<std::string> UR_DLstrVec;
//
//	U_DstrVec.resize(line.size());
//	UL_DRstrVec.resize(line.size() + L_RstrVec.size());
//	UR_DLstrVec.resize(line.size() + L_RstrVec.size());
//
//	for (int y = 0; y < L_RstrVec.size(); y++)
//	{
//		for (int x = 0; x < L_RstrVec[0].size(); x++)
//		{
//			U_DstrVec[x] += L_RstrVec[y][x];
//		}
//	}
//
//	int tempX = 0, tempY = 0;
//
//	// UL_DRstrVec
//	int UL_DRIdx = 0;
//	for (int x = 0; x < L_RstrVec[0].size(); x++)
//	{
//		tempY = 0;
//		tempX = x;
//		while (tempY < L_RstrVec.size() && tempX < L_RstrVec[0].size())
//		{
//			UL_DRstrVec[UL_DRIdx] += L_RstrVec[tempY][tempX];
//			tempY++;
//			tempX++;
//		}
//		UL_DRIdx++;
//	}
//
//	for (int y = 1; y < L_RstrVec.size(); y++)
//	{
//		tempY = y;
//		tempX = 0;
//		while (tempY < L_RstrVec.size() && tempX < L_RstrVec[0].size())
//		{
//			UL_DRstrVec[UL_DRIdx] += L_RstrVec[tempY][tempX];
//			tempY++;
//			tempX++;
//		}
//		UL_DRIdx++;
//	}
//
//	// UR_DLstrVec
//	int UR_DLIdx = 0;
//	for (int x = L_RstrVec[0].size() - 1; x >= 0; x--)
//	{
//		tempY = 0;
//		tempX = x;
//		while (tempY < L_RstrVec.size() && tempX >= 0)
//		{
//			UR_DLstrVec[UR_DLIdx] += L_RstrVec[tempY][tempX];
//			tempY++;
//			tempX--;
//		}
//		UR_DLIdx++;
//	}
//
//	for (int y = 1; y < L_RstrVec.size(); y++)
//	{
//		tempY = y;
//		tempX = L_RstrVec[0].size() - 1;
//		while (tempY < L_RstrVec.size() && tempX >= 0)
//		{
//			UR_DLstrVec[UR_DLIdx] += L_RstrVec[tempY][tempX];
//			tempY++;
//			tempX--;
//		}
//		UR_DLIdx++;
//	}
//
//	std::vector<std::vector<std::string>> allVecs;
//
//	allVecs.push_back(L_RstrVec);
//	allVecs.push_back(U_DstrVec);
//	allVecs.push_back(UL_DRstrVec);
//	allVecs.push_back(UR_DLstrVec);
//
//	int sum = 0;
//
//	for (std::vector<std::string>& dirVec : allVecs)
//	{
//		for (std::string& str : dirVec)
//		{
//			std::regex reg1("XMAS");
//			std::regex reg2("SAMX");
//
//			std::smatch matches;
//
//			std::string tempstr = str;
//			while (std::regex_search(tempstr, matches, reg1))
//			{
//				sum++;
//				tempstr = matches.suffix().str();
//			}
//
//			tempstr = str;
//			while (std::regex_search(tempstr, matches, reg2))
//			{
//				sum++;
//				tempstr = matches.suffix().str();
//			}
//
//		}
//	}
//
//	std::cout << sum;
//
//}
//
//// 3135 Down
//
////2401