//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//
//	std::ifstream file("Day9Inp.txt");
//
//	std::string inpLine;
//
//	std::getline(file, inpLine);
//
//	std::vector<std::wstring> fileVec;
//	std::string tempstr;
//
//	uint16_t fileInd = 2;
//	bool odd = true;
//
//	for (int i = 0; i < inpLine.size(); i++)
//	{
//		fileVec.emplace_back(std::wstring());
//
//		tempstr = inpLine[i];
//
//		for (int j = 0; j < std::stoi(tempstr); j++)
//		{
//			if (odd)
//			{
//				fileVec[i] += fileInd;
//			}
//			else
//			{
//				fileVec[i] += (short)1;
//			}
//		}
//
//		if (odd)
//		{
//			odd = false;
//			fileInd++;
//		}
//		else
//		{
//			odd = true;
//		}
//	}
//
//	bool chage = true;
//
//	while (chage)
//	{
//		chage = false;
//		for (int j = fileVec.size() - 1; j > 0; j--)
//		{
//
//			if (fileVec[j].size() <= 0)
//			{
//				continue;
//			}
//
//			if (fileVec[j][0] == (short)1)
//			{
//				continue;
//			}
//
//			for (int i = 0; i < j; i++)
//			{
//
//				if (fileVec[i].size() <= 0)
//				{
//					continue;
//				}
//
//				if (fileVec[i][fileVec[i].size() - 1] != (short)1)
//				{
//					continue;
//				}
//
//				int freespace = 0;
//
//				for (int x = 0; x < fileVec[i].size(); x++)
//				{
//					if (fileVec[i][x] == (short)1)
//						freespace++;
//				}
//
//				if (freespace >= fileVec[j].size())
//				{
//					for (int x = 0; x < fileVec[j].size(); x++)
//					{
//						for (int z = 0; z < fileVec[i].size(); z++)
//						{
//							if (fileVec[i][z] == (short)1)
//							{
//								fileVec[i][z] = fileVec[j][x];
//								fileVec[j][x] = (short)1;
//								break;
//							}
//						}
//					}
//
//					//chage = true;
//				}
//			}
//		}
//	}
//
//	/*
//	for (int i = 0; i < fileVec.size(); i++)
//	{
//
//		if (fileVec[i].size() < 0)
//		{
//			continue;
//		}
//
//		if (fileVec[i][0] != (short)1)
//		{
//			continue;
//		}
//
//		for (int j = fileVec.size() - 1; j > i; j--)
//		{
//			if (fileVec[j].size() <= 0)
//			{
//				continue;
//			}
//
//			if (fileVec[j][0] == (short)1)
//			{
//				continue;
//			}
//
//			int freespace = 0;
//
//			for (int x = 0; x < fileVec[i].size(); x++)
//			{
//				if (fileVec[i][x] == (short)1)
//					freespace++;
//			}
//
//			if (freespace >= fileVec[j].size())
//			{
//				for (int x = 0; x < fileVec[j].size(); x++)
//				{
//					for (int z = 0; z < fileVec[i].size(); z++)
//					{
//						if (fileVec[i][z] == (short)1)
//						{ 
//							fileVec[i][z] = fileVec[j][x];
//							fileVec[j][x] = (short)1;
//							break;
//						}
//					}
//				}
//			}
//		}
//	}
//	*/
//
//	int idx = 0;
//	uint64_t sum = 0;
//
//	for (int i = 0; i < fileVec.size(); i++)
//	{
//		for (int j = 0; j < fileVec[i].size(); j++)
//		{
//			if (fileVec[i][j] != (short)1)
//			{
//				sum += (fileVec[i][j] - 2) * idx;
//			}
//			idx++;
//		}
//	}
//
//	std::cout << sum;
//
//}
//
////6254272652034 upp