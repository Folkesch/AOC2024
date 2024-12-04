//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//	std::ifstream RFile("Day1Inp.txt");
//
//	std::string inp1;
//	std::string inp2;
//	std::vector<int64_t> inpVec1;
//	std::vector<int64_t> inpVec2;
//
//	while (RFile >> inp1 >> inp2)
//	{
//		inpVec1.push_back(stoi(inp1));
//		inpVec2.push_back(stoi(inp2));
//	}
//
//	std::sort(inpVec1.begin(), inpVec1.end(), [](int a, int b) { return a > b; });
//	std::sort(inpVec2.begin(), inpVec2.end(), [](int a, int b) { return a > b; });
//
//	int64_t sum = 0;
//
//	for (int i = 0; i < inpVec1.size(); i++) {
//		sum += abs(inpVec1[i] - inpVec2[i]);
//	}
//
//	std::cout << sum;
//
//}