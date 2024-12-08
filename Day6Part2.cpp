////16616 down
////
////3496 down
////
////407 upp
////
////214 nop
////
////440 nop
////
////421 nop
////
////1834 nop
////
////1978 nop
////
////1835 nop
////
////1784
//
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//
//#define NUTHING	0b00000001
//#define BLOCK	0b00000010
//
//struct int2
//{
//	int x;
//	int y;
//};
//
//struct int4
//{
//	int posx;
//	int posy;
//	int dirx;
//	int diry;
//};
//
//bool containes(std::vector<int2> vec, int x, int y)
//{
//	for (int i = 0; i < vec.size(); i++)
//	{
//		if (vec[i].x == x && vec[i].y == y)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//bool containesi4(std::vector<int4> vec, int posx, int posy, int dirx, int diry)
//{
//	for (int i = 0; i < vec.size(); i++)
//	{
//		if (vec[i].posx == posx && vec[i].posy == posy && vec[i].dirx == dirx && vec[i].diry == diry)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//int main()
//{
//
//	std::ifstream file("Day6Inp.txt");
//
//	std::vector<std::vector<char>> inpVec;
//	std::string line;
//
//	int2 gardPos = { 0, 0 };
//	int2 gardPosStart = { 0, 0 };
//
//	while (std::getline(file, line))
//	{
//		inpVec.emplace_back(std::vector<char>());
//
//		for (int i = 0; i < line.size(); i++)
//		{
//			if (line[i] == '.')
//			{
//				inpVec[inpVec.size() - 1].emplace_back(NUTHING);
//			}
//			else if (line[i] == '#')
//			{
//				inpVec[inpVec.size() - 1].emplace_back(BLOCK);
//			}
//			else if (line[i] == '^')
//			{
//				inpVec[inpVec.size() - 1].emplace_back(NUTHING);
//				gardPos.x = i;
//				gardPos.y = inpVec.size() - 1;
//				gardPosStart.x = i;
//				gardPosStart.y = inpVec.size() - 1;
//			}
//			else
//				throw;
//		}
//	}
//
//	int2 gardDir = { 0, -1 };
//
//	uint64_t sum = 0;
//
//	for (int y = 0; y < inpVec.size(); y++)
//	{
//		for (int x = 0; x < inpVec[y].size(); x++)
//		{
//
//			int2 testGardDir = gardDir;
//			int2 testGardPos = gardPos;
//
//			std::vector<int4> bineHear;
//
//			std::vector<std::vector<char>> testInpVec(inpVec);
//
//			testInpVec[y][x] = BLOCK;
//
//			bool loopFound = false;
//
//			while (testGardPos.y < testInpVec.size() - 1 && testGardPos.y > 0 && testGardPos.x < testInpVec[0].size() - 1 && testGardPos.x > 0)
//			{
//				if (testInpVec[testGardPos.y + testGardDir.y][testGardPos.x + testGardDir.x] == BLOCK)
//				{
//					if (testGardDir.y == -1 && testGardDir.x == 0)
//					{
//						testGardDir.y = 0;
//						testGardDir.x = 1;
//					}
//					else if (testGardDir.y == 0 && testGardDir.x == 1)
//					{
//						testGardDir.y = 1;
//						testGardDir.x = 0;
//					}
//					else if (testGardDir.y == 1 && testGardDir.x == 0)
//					{
//						testGardDir.y = 0;
//						testGardDir.x = -1;
//					}
//					else if (testGardDir.y == 0 && testGardDir.x == -1)
//					{
//						testGardDir.y = -1;
//						testGardDir.x = 0;
//					}
//					else
//						throw;
//				}
//				else
//				{
//					if (containesi4(bineHear, testGardPos.x, testGardPos.y, testGardDir.x, testGardDir.y))
//					{
//						loopFound = true;
//						break;
//					}
//					else
//					{
//						bineHear.push_back({ testGardPos.x, testGardPos.y, testGardDir.x, testGardDir.y });
//					}
//
//					testGardPos.x += testGardDir.x;
//					testGardPos.y += testGardDir.y;
//				}
//			}
//
//			if (loopFound)
//			{
//				sum++;
//			}
//
//		}
//
//		std::cout << y << "\n";
//	}
//
//	/*
//	int2 gardDir = { 0, -1 };
//
//	std::vector<int2> obstacles;
//
//	std::vector<int2> FullBinHear;
//
//	bool LoopFound = false;
//
//	int iterations = 0;
//
//	while (gardPos.y < inpVec.size() - 1 && gardPos.y > 0 && gardPos.x < inpVec[0].size() - 1 && gardPos.x > 0)
//	{
//		if (inpVec[gardPos.y + gardDir.y][gardPos.x + gardDir.x] == BLOCK)
//		{
//			if (gardDir.y == -1 && gardDir.x == 0)
//			{
//				gardDir.y = 0;
//				gardDir.x = 1;
//			}
//			else if (gardDir.y == 0 && gardDir.x == 1)
//			{
//				gardDir.y = 1;
//				gardDir.x = 0;
//			}
//			else if (gardDir.y == 1 && gardDir.x == 0)
//			{
//				gardDir.y = 0;
//				gardDir.x = -1;
//			}
//			else if (gardDir.y == 0 && gardDir.x == -1)
//			{
//				gardDir.y = -1;
//				gardDir.x = 0;
//			}
//			else
//				throw;
//		}
//		else
//		{
//
//			if (!containes(obstacles, gardPos.x + gardDir.x, gardPos.y + gardDir.y))
//			{
//
//				std::vector<int4> bineHear;
//
//				std::vector<std::vector<char>> testInpVec(inpVec);
//
//				int2 testGardPos = gardPos;
//				int2 testGardDir = gardDir;
//
//				testInpVec[gardPos.y + gardDir.y][gardPos.x + gardDir.x] = BLOCK;
//
//				while (testGardPos.y < testInpVec.size() - 1 && testGardPos.y > 0 && testGardPos.x < testInpVec[0].size() - 1 && testGardPos.x > 0)
//				{
//					if (testInpVec[testGardPos.y + testGardDir.y][testGardPos.x + testGardDir.x] == BLOCK)
//					{
//						if (testGardDir.y == -1 && testGardDir.x == 0)
//						{
//							testGardDir.y = 0;
//							testGardDir.x = 1;
//						}
//						else if (testGardDir.y == 0 && testGardDir.x == 1)
//						{
//							testGardDir.y = 1;
//							testGardDir.x = 0;
//						}
//						else if (testGardDir.y == 1 && testGardDir.x == 0)
//						{
//							testGardDir.y = 0;
//							testGardDir.x = -1;
//						}
//						else if (testGardDir.y == 0 && testGardDir.x == -1)
//						{
//							testGardDir.y = -1;
//							testGardDir.x = 0;
//						}
//						else
//							throw;
//					}
//					else {
//
//						if (!containesi4(bineHear, testGardPos.x, testGardPos.y, testGardDir.x, testGardDir.y))
//						{
//							int4 tempInt4 = { testGardPos.x, testGardPos.y, testGardDir.x, testGardDir.y };
//							bineHear.push_back(tempInt4);
//						}
//						else
//						{
//							LoopFound = true;
//							break;
//						}
//
//					}
//				}
//
//				if (LoopFound)
//				{
//					int2 tempInt2 = { gardPos.x + gardDir.x, gardPos.y + gardDir.y };
//					obstacles.push_back(tempInt2);
//				}
//
//				LoopFound = false;
//
//			}
//
//			if (!containes(FullBinHear, gardPos.x, gardPos.y))
//			{
//				FullBinHear.push_back({ gardPos.x, gardPos.y });
//			}
//
//			gardPos.y += gardDir.y;
//			gardPos.x += gardDir.x;
//
//			std::cout << iterations << std::endl;
//			iterations++;
//		}
//	}
//
//	std::cout << FullBinHear.size() << "\n";
//
//	if (containes(obstacles, gardPosStart.x, gardPosStart.y))
//	{
//		std::cout << obstacles.size() - 1;
//	}
//	else
//	{
//		std::cout << obstacles.size();
//	}
//	*/
//
//	std::cout << sum;
//
//}