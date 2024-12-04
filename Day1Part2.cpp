//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//	std::ifstream rfile("day1inp.txt");
//	
//	std::string inp1;
//	std::string inp2;
//	std::vector<int64_t> inpvec1;
//	std::vector<int64_t> inpvec2;
//
//	while (rfile >> inp1 >> inp2)
//	{
//		inpvec1.push_back(stoi(inp1));
//		inpvec2.push_back(stoi(inp2));
//	}
//
//	std::sort(inpvec1.begin(), inpvec1.end(), [](int a, int b) { return a > b; });
//	std::sort(inpvec2.begin(), inpvec2.end(), [](int a, int b) { return a > b; });
//
//	int64_t sum = 0;
//
//	for (int i = 0; i < inpvec1.size(); i++) {
//		for (int j = 0; j < inpvec2.size(); j++)
//		{
//			if (inpvec1[i] == inpvec2[j])
//				sum += inpvec1[i];
//		}
//	}
//
//	std::cout << sum;
//
//}