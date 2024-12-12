//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <regex>
//#include <unordered_map>
//#include <algorithm>
//#include <execution>
//#include <unordered_set>
//#include <stack>
//
//int main()
//{
//
//	std::ifstream file("Day12Inp.txt");
//
//	std::string line;
//	std::string inpStr;
//
//	uint64_t xLength = 0;
//	uint64_t yLength = 0;
//
//	std::getline(file, line);
//	std::string templine;
//
//	for (int i = 0; i < line.size(); i++)
//		templine += '#';
//
//	inpStr += templine + "##";
//	inpStr += "#" + line + "#";
//
//	while (std::getline(file, line))
//	{
//		xLength = line.size() + 2;
//		inpStr += "#" + line + "#";
//	}
//
//	inpStr += templine + "##";
//
//	yLength = inpStr.size() / (line.size() + 2);
//
//	if (inpStr.size() % (line.size() + 2) != 0)
//		throw;
//
//	uint64_t sum = 0;
//
//	std::unordered_set<uint64_t> set;
//
//	for (int y = 1; y < yLength - 1; y++)
//	{
//		for (int x = 1; x < xLength - 1; x++)
//		{
//			if (set.find(y * xLength + x) == set.end())
//			{
//				char grassTyp = inpStr[y * xLength + x];
//				std::stack<uint64_t> stack;
//				set.insert(y * xLength + x);
//				stack.push((y)*xLength + (x));
//
//				bool done = false;
//				uint64_t aria = 1;
//				uint64_t perimeter = 0;
//				if (inpStr[(y)*xLength + (x + 1)] != grassTyp)
//					perimeter++;
//				if (inpStr[(y)*xLength + (x - 1)] != grassTyp)
//					perimeter++;
//				if (inpStr[(y + 1)*xLength + (x)] != grassTyp)
//					perimeter++;
//				if (inpStr[(y - 1)*xLength + (x)] != grassTyp)
//					perimeter++;
//
//				while (stack.size() != 0)
//				{
//					if (set.find(stack.top() + 1) == set.end() && inpStr[stack.top() + 1] == grassTyp)
//					{
//						stack.push(stack.top() + 1);
//						set.insert(stack.top());
//						if (inpStr[stack.top() + 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() + (xLength)] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - (xLength)] != grassTyp)
//							perimeter++;
//						aria++;
//					}
//					else if (set.find(stack.top() - 1) == set.end() && inpStr[stack.top() - 1] == grassTyp)
//					{
//						stack.push(stack.top() - 1);
//						set.insert(stack.top());
//						if (inpStr[stack.top() + 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() + (xLength)] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - (xLength)] != grassTyp)
//							perimeter++;
//						aria++;
//					}
//					else if (set.find(stack.top() + xLength) == set.end() && inpStr[stack.top() + xLength] == grassTyp)
//					{
//						stack.push(stack.top() + (xLength));
//						set.insert(stack.top());
//						if (inpStr[stack.top() + 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() + (xLength)] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - (xLength)] != grassTyp)
//							perimeter++;
//						aria++;
//					}
//					else if (set.find(stack.top() - xLength) == set.end() && inpStr[stack.top() - xLength] == grassTyp)
//					{
//						stack.push(stack.top() - (xLength));
//						set.insert(stack.top());
//						if (inpStr[stack.top() + 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - 1] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() + (xLength)] != grassTyp)
//							perimeter++;
//						if (inpStr[stack.top() - (xLength)] != grassTyp)
//							perimeter++;
//						aria++;
//					}
//					else
//					{
//						stack.pop();
//					}
//				}
//
//				sum += aria * perimeter;
//			}
//		}
//		std::cout << y;
//	}
//
//	std::cout << sum;
//
//}
//
//2950097 no (prob to high)
//
//1375476