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
//	std::wstring newLine;
//
//	bool odd = true;
//	std::string tempstr;
//	int stringIdx = 1;
//	// if file is length 0, fix
//
//	for (int i = 0; i < inpLine.size(); i++)
//	{
//		tempstr += inpLine[i];
//		for (int j = 0; j < std::stoi(tempstr); j++)
//		{
//			if (odd)
//			{
//				newLine += (short)stringIdx;
//			}
//			else
//			{
//				newLine += (short)0;
//			}
//		}
//
//		if (odd)
//			stringIdx++;
//
//		if (stringIdx > SHRT_MAX)
//			throw;
//
//		odd = (odd) ? false : true;
//
//		tempstr.clear();
//	}
//
//	int backindex = newLine.size() - 1;
//	int frontindex = 0;
//
//	short front;
//	short back;
//
//	bool done = false;
//
//	while (backindex > frontindex)
//	{
//		front = newLine[frontindex];
//		back = newLine[backindex];
//
//		while (front != 0)
//		{
//			frontindex++;
//			if (frontindex < backindex)
//			{
//				front = newLine[frontindex];
//			}
//			else
//			{
//				done = true;
//				break;
//			}
//		}
//
//		while (back == 0)
//		{
//			backindex--;
//			if (frontindex < backindex)
//			{
//				back = newLine[backindex];
//			}
//			else
//			{
//				done = true;
//				break;
//			}
//		}
//
//		if (done)
//		{
//			break;
//		}
//
//		newLine[frontindex] = back;
//		newLine[backindex] = front;
//
//		backindex--;
//		frontindex++;
//
//	}
//
//	uint64_t index = 0;
//	uint64_t sum = 0;
//
//	int itter = 0;
//
//
//	while (newLine[index] != 0)
//	{
//		sum += index * (newLine[index] - 1);
//
//		index++;
//		itter++;
//	}
//
//	std::cout << sum;
//
//}
//
////6242766523059
//
////6272188244509