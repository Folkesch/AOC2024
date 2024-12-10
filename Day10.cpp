//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <unordered_set>
//#include <algorithm>
//
//struct int2 {
//	int x;
//	int y;
//};
//
//std::vector<int2> findPath(int curInt, int2 pos, std::vector<std::string>& inpvec)
//{
//	int sum = 0;
//
//	std::string tempstr;
//
//	std::vector<int2> vec;
//
//	std::vector<int2> retVec;
//
//	if (pos.x == 0)
//	{
//		if (pos.y == 0)
//		{
//				tempstr = inpvec[pos.y + 1][pos.x];
//				if (std::stoi(tempstr) == curInt + 1)
//					vec.push_back({ pos.x, pos.y + 1 });
//
//				tempstr = inpvec[pos.y][pos.x + 1];
//				if (std::stoi(tempstr) == curInt + 1)
//					vec.push_back({ pos.x + 1, pos.y });
//		}
//		else if (pos.y == (inpvec.size() - 1))
//		{
//			tempstr = inpvec[pos.y - 1][pos.x];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x, pos.y - 1 });
//
//			tempstr = inpvec[pos.y][pos.x + 1];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x + 1, pos.y });
//		}
//		else
//		{
//			tempstr = inpvec[pos.y - 1][pos.x];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x, pos.y - 1 });
//
//			tempstr = inpvec[pos.y + 1][pos.x];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x, pos.y + 1 });
//
//			tempstr = inpvec[pos.y][pos.x + 1];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x + 1, pos.y });
//		}
//	}
//	else if (pos.x == (inpvec[0].size() - 1))
//	{
//		if (pos.y == 0)
//		{
//			tempstr = inpvec[pos.y + 1][pos.x];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x, pos.y + 1 });
//
//			tempstr = inpvec[pos.y][pos.x - 1];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x - 1, pos.y });
//		}
//		else if (pos.y == (inpvec.size() - 1))
//		{
//			tempstr = inpvec[pos.y - 1][pos.x];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x, pos.y - 1 });
//
//			tempstr = inpvec[pos.y][pos.x - 1];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x-+ 1, pos.y });
//		}
//		else
//		{
//			tempstr = inpvec[pos.y - 1][pos.x];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x, pos.y - 1 });
//
//			tempstr = inpvec[pos.y + 1][pos.x];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x, pos.y + 1 });
//
//			tempstr = inpvec[pos.y][pos.x - 1];
//			if (std::stoi(tempstr) == curInt + 1)
//				vec.push_back({ pos.x - 1, pos.y });
//		}
//	}
//	else if (pos.y == 0)
//	{
//		tempstr = inpvec[pos.y + 1][pos.x];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x, pos.y + 1 });
//
//		tempstr = inpvec[pos.y][pos.x + 1];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x + 1, pos.y });
//
//		tempstr = inpvec[pos.y][pos.x - 1];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x - 1, pos.y });
//	}
//	else if (pos.y == (inpvec[0].size() - 1))
//	{
//		tempstr = inpvec[pos.y - 1][pos.x];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x, pos.y - 1 });
//
//		tempstr = inpvec[pos.y][pos.x + 1];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x + 1, pos.y });
//
//		tempstr = inpvec[pos.y][pos.x - 1];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x - 1, pos.y });
//	}
//	else
//	{
//		tempstr = inpvec[pos.y + 1][pos.x];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x, pos.y + 1 });
//
//		tempstr = inpvec[pos.y - 1][pos.x];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x, pos.y - 1 });
//
//		tempstr = inpvec[pos.y][pos.x + 1];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x + 1, pos.y });
//
//		tempstr = inpvec[pos.y][pos.x - 1];
//		if (std::stoi(tempstr) == curInt + 1)
//			vec.push_back({ pos.x - 1, pos.y });
//	}
//
//	if (vec.size() == 0)
//	{
//		retVec.push_back({ -1, -1 });
//	}
//
//	for (int2& vecItem : vec)
//	{
//		tempstr = inpvec[vecItem.y][vecItem.x];
//		if (std::stoi(tempstr) == 9)
//		{
//			retVec.push_back({ vecItem.x, vecItem.y });
//		}
//		else
//		{
//			std::vector<int2> tempV = findPath(curInt + 1, { vecItem.x, vecItem.y }, inpvec);
//			retVec.insert(retVec.end(), tempV.begin(), tempV.end());
//		}
//	}
//
//
//	return retVec;
//}
//
//void removeCoppy(std::vector<int2>& vec)
//{
//	bool chage = true;
//	while (chage)
//	{
//		chage = false;
//		for (int i = 0; i < vec.size(); i++)
//		{
//			if (vec[i].x == -1)
//			{
//				vec.erase(vec.begin() + i, vec.begin() + i + 1);
//			go:
//				chage = true;
//				break;
//			}
//			else 
//			{
//				if (i != vec.size() - 1)
//				{
//					for (int x = i + 1; x < vec.size(); x++)
//					{
//						if (vec[i].x == vec[x].x && vec[i].y == vec[x].y)
//						{
//							vec.erase(vec.begin() + i, vec.begin() + i + 1);
//							goto go;
//						}
//					}
//				}
//			}
//		}
//	}
//
//}
//
//int main()
//{
//
//	std::ifstream file("Day10Inp.txt");
//
//	std::string line;
//	std::vector<std::string> inpVec;
//
//	while (std::getline(file, line))
//	{
//		inpVec.push_back(line);
//	}
//
//	std::string tempstr;
//	int sum = 0;
//
//	for (int y = 0; y < inpVec.size(); y++)
//	{
//		for (int x = 0; x < inpVec[y].size(); x++)
//		{
//			if (inpVec[y][x] == '0')
//			{
//				std::vector<int2> retVec = findPath(0, { x, y }, inpVec);
//				removeCoppy(retVec);
//				sum += retVec.size();
//			}
//		}
//
//	}
//
//	std::cout << sum;
//
//}
//
////582	