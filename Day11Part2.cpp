#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

int main()
{

	std::ifstream file("Day11Inp.txt");

	std::string line;

	std::getline(file, line);

	std::regex reg("[0-9]{1,1000}");

	std::smatch match;

	std::vector<uint64_t> vec;

	while (std::regex_search(line, match, reg))
	{
		vec.push_back(std::stoull(match.str(0)));
		line = match.suffix().str();
	}

	std::vector<uint64_t> newVec;

	std::string tempStr;


	for (int iter = 0; iter < 40; iter++)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			tempStr = std::to_string(vec[i]);

			if (vec[i] == 0)
			{
				newVec.emplace_back(1);
			}
			else if (tempStr.size() % 2 == 0)
			{
				std::string s1 = tempStr.substr(0, tempStr.size() / 2);
				std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);

				newVec.push_back(std::stoull(s1));
				newVec.push_back(std::stoull(s2));
			}
			else
			{
				newVec.emplace_back(vec[i] * 2024);
			}
		}

		vec = std::move(newVec);
	}

	std::unordered_map<uint64_t, std::vector<uint64_t>> map;
	std::unordered_set<uint64_t> set;

	for (auto vecitem : vec)
		set.insert(vecitem);

	std::cout << vec.size() << "\n";
	std::cout << set.size() << "\n";

	uint64_t idx = 0;

	for (auto vecitem : set)
	{
		std::vector<uint64_t> Vec2 = { vecitem };

		for (int iter = 0; iter < 35; iter++)
		{
			for (int i = 0; i < Vec2.size(); i++)
			{
				tempStr = std::to_string(Vec2[i]);

				if (Vec2[i] == 0)
				{
					newVec.emplace_back(1);
				}
				else if (tempStr.size() % 2 == 0)
				{
					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);

					newVec.push_back(std::stoull(s1));
					newVec.push_back(std::stoull(s2));
				}
				else
				{
					newVec.emplace_back(Vec2[i] * 2024);
				}
			}

			Vec2 = std::move(newVec);
		}

		map[vecitem] = Vec2;


		idx++;
		if (idx % 10 == 0)
		{
			std::cout << idx << "\n";
		}
	}


	uint64_t sum = 0;

	for (auto vecitem : vec)
	{
		sum += map[vecitem].size();
	}

	std::cout << "\n\n" << sum << "\n\n";


}

//264350935776416



//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <regex>
//#include <unordered_map>
//#include <algorithm>
//#include <execution>
//#include <unordered_set>


//
//
//std::mutex mtx;
//
//uint64_t rval = 0;
//
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map60 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map50 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map40 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map35 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map25 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map20 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map15 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map10 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//std::unordered_map<uint64_t, std::vector<uint64_t>>* map5 = new std::unordered_map<uint64_t, std::vector<uint64_t>>();
//
//uint64_t hitt = 0;
//uint64_t miss = 0;
//
//std::vector<uint64_t> makemap(uint64_t val, uint16_t idx, uint16_t uppTo)
//{
//	std::vector<uint64_t> newVec;
//
//	bool done = false;
//
//	if (idx <= uppTo - 60)
//	{
//		if (map60->find(val) != map60->end())
//		{
//			newVec = (*map60)[val];
//			idx += 60;
//			done = true;
//		}
//	}
//	else if (idx <= uppTo - 50)
//	{
//		if (map50->find(val) != map50->end())
//		{
//			newVec = (*map50)[val];
//			idx += 50;
//			done = true;
//		}
//	}
//	if (idx <= uppTo - 40)
//	{
//		if (map40->find(val) != map40->end())
//		{
//			newVec = (*map40)[val];
//			idx += 40;
//			done = true;
//		}
//	}
//	else if (idx <= uppTo - 35)
//	{
//		if (map35->find(val) != map35->end())
//		{
//			newVec = (*map35)[val];
//			idx += 35;
//			done = true;
//		}
//	}
//	else if (idx <= uppTo - 25)
//	{
//		if (map25->find(val) != map25->end())
//		{
//			newVec = (*map25)[val];
//			idx += 25;
//			done = true;
//		}
//	}
//	else if (idx <= uppTo - 20)
//	{
//		if (map20->find(val) != map20->end())
//		{
//			newVec = (*map20)[val];
//			idx += 20;
//			done = true;
//		}
//	}
//	else if (idx <= uppTo - 15)
//	{
//		if (map15->find(val) != map15->end())
//		{
//			newVec = (*map15)[val];
//			idx += 15;
//			done = true;
//		}
//	}
//	else if (idx <= uppTo - 10)
//	{
//		if (map10->find(val) != map10->end())
//		{
//			newVec = (*map10)[val];
//			idx += 10;
//			done = true;
//		}
//	}
//	else if (idx <= uppTo - 5)
//	{
//		if (map5->find(val) != map5->end())
//		{
//			newVec = (*map5)[val];
//			idx += 5;
//			done = true;
//		}
//	}
//
//	if (!done)
//	{
//		newVec = { val };
//		std::vector<uint64_t> tempNewVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 5; iter++)
//		{
//			for (int i = 0; i < newVec.size(); i++)
//			{
//				tempStr = std::to_string(newVec[i]);
//
//				if (newVec[i] == 0)
//				{
//					tempNewVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					tempNewVec.emplace_back(std::stoull(s1));
//					tempNewVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					tempNewVec.push_back(newVec[i] * 2024);
//				}
//			}
//
//			newVec = std::move(tempNewVec);
//			tempNewVec.reserve((uint64_t)newVec.size() * 1.5);
//		}
//		idx += 5;
//	}
//
//	if (done)
//		hitt++;
//	else
//		miss++;
//
//	if (idx > uppTo)
//		throw;
//
//	if (idx == uppTo)
//	{
//		return newVec;
//	}
//	else
//	{
//		std::vector<uint64_t> sum;
//
//		for (int i = 0; i < newVec.size(); i++)
//		{
//			std::vector<uint64_t> temp = makemap(newVec[i], idx, uppTo);
//			sum.insert(sum.end(), temp.begin(), temp.end());
//		}
//
//		return sum;
//	}
//}
///*
//uint64_t iterInp(uint64_t val, int idx)
//{
//	std::vector<uint64_t> newVec;
//
//	int inpidx = idx;
//
//	bool done = false;
//
//	if (idx <= 35)
//	{
//		if (map40.find(val) != map40.end())
//		{
//			newVec = map40[val];
//			idx += 40;
//			done = true;
//		}
//		else if (map25.find(val) != map25.end())
//		{
//			newVec = map25[val];
//			idx += 25;
//			done = true;
//		}
//
//
//	} else if (idx <= 40)
//	{
//		if (map35.find(val) != map35.end())
//		{
//			newVec = map35[val];
//			idx += 35;
//			done = true;
//		}
//		else if (map25.find(val) != map25.end())
//		{
//			newVec = map25[val];
//			idx += 25;
//			done = true;
//		}
//	}
//	else if (idx <= 50)
//	{
//		if (map25.find(val) != map25.end())
//		{
//			newVec = map25[val];
//			idx += 25;
//			done = true;
//		}
//	}
//	else if (idx <= 65)
//	{
//		if (map10.find(val) != map10.end())
//		{
//			newVec = map10[val];
//			idx += 10;
//			done = true;
//		}
//	}
//	else if (idx <= 70)
//	{
//		if (map5.find(val) != map5.end())
//		{
//			newVec = map5[val];
//			idx += 5;
//			done = true;
//		}
//	}
//
//	if (!done)
//	{
//		newVec = { val };
//		std::vector<uint64_t> tempNewVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 5; iter++)
//		{
//			for (int i = 0; i < newVec.size(); i++)
//			{
//				tempStr = std::to_string(newVec[i]);
//
//				if (newVec[i] == 0)
//				{
//					tempNewVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					tempNewVec.emplace_back(std::stoull(s1));
//					tempNewVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					tempNewVec.push_back(newVec[i] * 2024);
//				}
//			}
//
//			newVec = std::move(tempNewVec);
//			tempNewVec.reserve((uint64_t)newVec.size() * 1.5);
//		}
//		idx += 5;
//	}
//	
//
//	if (idx > 75)
//		throw;
//
//	if (idx == 75)
//	{
//		return newVec.size();
//	}
//	else
//	{
//		uint64_t sum = 0;
//
//		if (inpidx == 0)
//			printf("\n%d\n", newVec.size());
//
//		for (int i = 0; i < newVec.size(); i++)
//		{
//			sum += iterInp(newVec[i], idx);
//			if (inpidx == 0)
//				printf("i");
//		}
//		return sum;
//	}
//}
//*/
//
//int main()
//{
//
//	std::ifstream file("Day11Inp.txt");
//
//	std::string line;
//
//	std::getline(file, line);
//
//	std::regex reg("[0-9]{1,1000}");
//
//	std::smatch match;
//
//	std::vector<uint64_t> vec;
//
//	while (std::regex_search(line, match, reg))
//	{
//		vec.push_back(std::stoull(match.str(0)));
//		line = match.suffix().str();
//	}
//
//	
//	std::vector<uint32_t> toFoThroVec;
//
//	for (int i = 0; i < 10; i++)
//	{
//		toFoThroVec.push_back(i);
//	}
//
//	for (auto vecitem : vec)
//	{
//		if (vecitem != 2 && vecitem != 0)
//			toFoThroVec.push_back(vecitem);
//	}
//
//	std::unordered_set<uint64_t> set;
//
//	for (auto vecitem : toFoThroVec)
//	{
//
//		std::vector<uint64_t> tempVec = { vecitem };
//
//		std::vector<uint64_t> newVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 20; iter++)
//		{
//			for (uint64_t i = 0; i < tempVec.size(); i++)
//			{
//				tempStr = std::to_string(tempVec[i]);
//
//				if (tempVec[i] == 0)
//				{
//					newVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					newVec.emplace_back(std::stoull(s1));
//					newVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					newVec.emplace_back(tempVec[i] * 2024);
//				}
//			}
//
//			tempVec = std::move(newVec);
//			newVec.reserve(tempVec.size() * 1.5);
//
//			for (auto tempVecitem : tempVec)
//			{
//				set.insert(tempVecitem);
//			}
//		}
//	}
//
//	std::cout << "set done " << set.size() << "\n";
//
//	for (auto setitem : set)
//	{
//		(*map5)[setitem] = makemap(setitem, 0, 5);
//	}
//
//	std::cout << "map5 done\n";
//
//	for (auto setitem : set)
//	{
//		(*map10)[setitem] = makemap(setitem, 0, 10);
//	}
//
//	std::cout << "map10 done\n";
//
//	for (auto setitem : set)
//	{
//		(*map15)[setitem] = makemap(setitem, 0, 15);
//	}
//
//	std::cout << "map15 done\n";
//
//	for (auto setitem : set)
//	{
//		(*map10)[setitem] = makemap(setitem, 0, 10);
//	}
//
//	std::cout << "map20 done\n";
//
//	for (auto setitem : set)
//	{
//		(*map20)[setitem] = makemap(setitem, 0, 20);
//	}
//
//	std::cout << "map25 done\n";
//
//	for (auto setitem : set)
//	{
//		(*map35)[setitem] = makemap(setitem, 0, 35);
//	}
//
//	std::cout << "map35 done\n";
//	
//	
//	for (auto setitem : set)
//	{
//		(*map40)[setitem] = makemap(setitem, 0, 40);
//		std::cout << "4";
//	}
//	
//	std::cout << "\nmap40 done\n";
//	std::cout << "hitt / miss = " << (double)hitt / (hitt + miss) << "\n";
//
//	for (auto setitem : set)
//	{
//		(*map50)[setitem] = makemap(setitem, 0, 50);
//		std::cout << "4";
//	}
//
//	std::cout << "\nmap60 done\n";
//
//	for (auto setitem : set)
//	{
//		(*map60)[setitem] = makemap(setitem, 0, 60);
//		std::cout << "4";
//	}
//
//	std::cout << "\nmap60 done\n";
//	
//	/*
//	std::cout << "vec35 done\n";
//
//	for (int i = 0; i < 1000; i++)
//	{
//		vec40.push_back(makevec(i, 0, 40));
//	}
//
//	std::cout << "vec40 done\n";
//
//	*/
//	
//	/*
//	for (uint64_t setItem = 0; setItem < 10; setItem++)
//	{
//		std::vector<uint64_t> tempVec = { setItem };
//
//		std::vector<uint64_t> newVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 40; iter++)
//		{
//			for (uint64_t i = 0; i < tempVec.size(); i++)
//			{
//				tempStr = std::to_string(tempVec[i]);
//
//				if (tempVec[i] == 0)
//				{
//					newVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					newVec.emplace_back(std::stoull(s1));
//					newVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					newVec.emplace_back(tempVec[i] * 2024);
//				}
//			}
//
//			tempVec = std::move(newVec);
//			newVec.reserve(tempVec.size() * 1.5);
//		}
//
//		map40[setItem] = std::move(tempVec);
//		std::cout << "4";
//	}
//
//	std::cout << "map40 done \n" << map40.size();
//	
//	
//	for (uint64_t setItem = 0; setItem < 10; setItem++)
//	{
//		std::vector<uint64_t> tempVec = { setItem };
//
//		std::vector<uint64_t> newVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 35; iter++)
//		{
//			for (uint64_t i = 0; i < tempVec.size(); i++)
//			{
//				tempStr = std::to_string(tempVec[i]);
//
//				if (tempVec[i] == 0)
//				{
//					newVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					newVec.emplace_back(std::stoull(s1));
//					newVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					newVec.emplace_back(tempVec[i] * 2024);
//				}
//			}
//
//			tempVec = std::move(newVec);
//			newVec.reserve(tempVec.size() * 1.5);
//		}
//
//		map35[setItem] = std::move(tempVec);
//	}
//	
//
//	std::cout << "map35 done \n" << map35.size();
//
//	
//	for (uint64_t setItem : set)
//	{
//
//		std::vector<uint64_t> tempVec = { setItem };
//
//		std::vector<uint64_t> newVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 25; iter++)
//		{
//			for (uint64_t i = 0; i < tempVec.size(); i++)
//			{
//				tempStr = std::to_string(tempVec[i]);
//
//				if (tempVec[i] == 0)
//				{
//					newVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					newVec.emplace_back(std::stoull(s1));
//					newVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					newVec.emplace_back(tempVec[i] * 2024);
//				}
//			}
//
//			tempVec = std::move(newVec);
//			newVec.reserve(tempVec.size() * 1.5);
//		}
//
//		//mtx.lock(); // Lock the resource
//		map25[setItem] = std::move(tempVec);
//		//mtx.unlock(); // Unlock the resource
//	}
//	
//
//	std::cout << "map25 done \n" << map25.size();
//
//	for (uint64_t setItem : set)
//	{
//
//		std::vector<uint64_t> tempVec = { setItem };
//
//		std::vector<uint64_t> newVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 10; iter++)
//		{
//			for (uint64_t i = 0; i < tempVec.size(); i++)
//			{
//				tempStr = std::to_string(tempVec[i]);
//
//				if (tempVec[i] == 0)
//				{
//					newVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					newVec.emplace_back(std::stoull(s1));
//					newVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					newVec.emplace_back(tempVec[i] * 2024);
//				}
//			}
//
//			tempVec = std::move(newVec);
//			newVec.reserve(tempVec.size() * 1.5);
//		}
//
//		//mtx.lock(); // Lock the resource
//		map10[setItem] = std::move(tempVec);
//		//mtx.unlock(); // Unlock the resource
//	}
//
//	std::cout << "map10 done \n" << map10.size();
//
//	for (uint64_t setItem : set)
//	{
//
//		std::vector<uint64_t> tempVec = { setItem };
//
//		std::vector<uint64_t> newVec;
//
//		std::string tempStr;
//
//		for (int iter = 0; iter < 5; iter++)
//		{
//			for (uint64_t i = 0; i < tempVec.size(); i++)
//			{
//				tempStr = std::to_string(tempVec[i]);
//
//				if (tempVec[i] == 0)
//				{
//					newVec.emplace_back(1);
//				}
//				else if (tempStr.size() % 2 == 0)
//				{
//					std::string s1 = tempStr.substr(0, tempStr.size() / 2);
//					std::string s2 = tempStr.substr(tempStr.size() / 2, tempStr.size() / 2);
//
//					newVec.emplace_back(std::stoull(s1));
//					newVec.emplace_back(std::stoull(s2));
//				}
//				else
//				{
//					newVec.emplace_back(tempVec[i] * 2024);
//				}
//			}
//
//			tempVec = std::move(newVec);
//			newVec.reserve(tempVec.size() * 1.5);
//		}
//
//		//mtx.lock(); // Lock the resource
//		map5[setItem] = std::move(tempVec);
//		//mtx.unlock(); // Unlock the resource
//	}
//
//	std::cout << "map5 done \n" << map5.size();
//	*/
//
//
//
//
//
//
//
//
//
//	//uint64_t sum = 0;
//
//	//std::cout << "map done\n";
//	///*
//	//std::vector<uint32_t> iterVec2;
//	//
//	//for (int i = 0; i < vec.size(); i++)
//	//	iterVec2.push_back(vec[i]);
//
//	//std::for_each(std::execution::par, iterVec2.begin(), iterVec2.end(), [&sum, &map35, &map25, &map10, &map5](uint32_t vecitem)
//	//	{
//	//		uint64_t temp = iterInp(vecitem, 0, map35, map25, map10, map5);
//	//		mtx.lock(); // Lock the resource
//	//		sum += temp;
//	//		std::cout << vecitem << "\n";
//	//		mtx.unlock(); // Unlock the resource
//	//	});
//	//	*/
//	//
//	//for (int i = 0; i < vec.size(); i++)
//	//{
//	//	sum += iterInp(vec[i], 0);
//	//	std::cout << i << "\n";
//	//}
//
//	//std::cout << sum;
//
//	//return 0;
//}

///14777945


//7791978 upp

//exit code -1073740791