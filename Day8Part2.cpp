#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct int2
{
	int x;
	int y;
};

int main()
{

	std::ifstream file("Day8Inp.txt");

	std::string line;
	std::vector<std::string> inpVec;

	while (std::getline(file, line))
	{
		inpVec.push_back(line);
	}

	std::vector<std::vector<int2>> antennaPos;
	std::unordered_map<char, int> map;

	int vecIdx = 0;

	for (int y = 0; y < inpVec.size(); y++)
	{
		for (int x = 0; x < inpVec[y].size(); x++)
		{

			if (inpVec[y][x] != '.')
			{
				if (map.find(inpVec[y][x]) == map.end())
				{
					map[inpVec[y][x]] = vecIdx;
					vecIdx++;
					antennaPos.emplace_back(std::vector<int2>());
					antennaPos[map[inpVec[y][x]]].push_back({ x, y });
				}
				else
				{
					antennaPos[map[inpVec[y][x]]].push_back({ x, y });
				}
			}
		}
	}

	std::vector<std::string> newGrid;

	for (int i = 0; i < inpVec.size(); i++)
	{
		newGrid.emplace_back(std::string());
		for (int j = 0; j < inpVec[i].size(); j++)
		{
			newGrid[i] += ".";
		}
	}


	bool frequencyFound = false;


	for (int i = 0; i < antennaPos.size(); i++)
	{
		for (int j = 0; j < antennaPos[i].size(); j++)
		{
			int2 antennPos = { antennaPos[i][j].x, antennaPos[i][j].y };

			std::vector<int2> vectors;
			for (int z = 0; z < antennaPos[i].size(); z++)
			{
				if (j != z)
				{
					vectors.push_back({ antennaPos[i][z].x - antennaPos[i][j].x, antennaPos[i][z].y - antennaPos[i][j].y });
				}
			}

			int multi = 1;

			for (int z = 0; z < vectors.size(); z++)
			{

				while (antennPos.x + vectors[z].x * multi < newGrid[0].size() && antennPos.x + vectors[z].x * multi >= 0 &&
					antennPos.y + vectors[z].y * multi < newGrid.size() && antennPos.y + vectors[z].y * multi >= 0)
				{
					newGrid[antennPos.y + vectors[z].y * multi][antennPos.x + vectors[z].x * multi] = '#';
					multi++;
				}

				multi = 1;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < newGrid.size(); i++)
	{
		for (int j = 0; j < newGrid[i].size(); j++)
		{
			if (newGrid[i][j] == '#')
			{
				sum++;
			}
		}
	}



	std::cout << sum;



}

//905