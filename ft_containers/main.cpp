#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "vector.hpp"
#include <list>
#include "list.hpp"
#include <queue>
#include "queue.hpp"
#include <stack>
#include "stack.hpp"
#include <map>
#include "map.hpp"
#include <set>

#define SIZE 30

bool is_100(const int &x)
{
	return (x < 50);
}

bool is_true(const int &x, const int &y)
{
	return (x == y);
}

bool is_min(const int x, const int y)
{
	return (x < y);
}

void map_testing()
{
	std::string str;
	std::cout << "\n///// MAP TESTING \\\\\\\\\\\n";
	std::cout << "\n===== CONSTRUCTOR TEST =====\n";
	do {
		{
			std::cout << "\n----- DEFAULT CONSTRUCTOR -----\n";
			std::map<int, int> m;
			ft::map<int, int> mp;

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE CONSTRUCTOR -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- COPY CONSTRUCTOR -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> cp(vec.begin(), vec.end());
			ft::map<int, int> cpy(vec.begin(), vec.end());

			std::map<int, int> m(cp);
			ft::map<int, int> mp(cpy);

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== ITERATOR TEST =====\n";
	do {
		{
			std::cout << "\n----- BEGIN AND END -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RBEGIN AND REND -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "\nrevers std: ";
			for (std::map<int, int>::reverse_iterator k = m.rbegin(); k != m.rend(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "reverse ft: ";
			for (std::map<int, int>::reverse_iterator k = m.rbegin(); k != m.rend(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== CAPACITY TEST =====\n";
	do {
		{
			std::cout << "\n----- EMPTY -----\n";

			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> cp;
			ft::map<int, int> cpy;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "org: " << m.empty() << std::endl;
			std::cout << " ft: " << mp.empty() << std::endl;

			std::cout << "\norg: " << cp.empty() << std::endl;
			std::cout << " ft: " << cpy.empty() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
			{
			std::cout << "\n----- SIZE -----\n";

			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- MAX SIZE -----\n";
			
			std::map<int, int> cp;
			ft::map<int, int> cpy;

			std::cout << "std: " << cp.max_size() << std::endl;
			std::cout << " ft: " << cpy.max_size() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== ELEMENT ACCESS =====\n";
	do {
		{
			std::cout << "\n----- OPERATOR [] -----\n";

			std::map<int, int> m;
			ft::map<int, int> mp;

			for (int i = 0; i < SIZE; i++)
			{
				int x = std::rand() % 100;
				int y = std::rand() % 100;
				m[x] = y;
				mp[x] = y;
			}

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== MODIFIRES =====\n";
	do {
		{
			std::cout << "\n----- SINGLE INSERT -----\n";

			std::map<int, int> m;
			ft::map<int, int> mp;
			
			for (int i = 0; i < SIZE / 2; i++)
			{
				int x = std::rand() % 100, y = std::rand() % 100;
				std::pair<int, int> sp(x, y);
				ft::pair<int, int> fp(x, y);

				std::pair<std::map<int, int>::iterator, bool> sres = m.insert(sp);
				ft::pair<ft::map<int, int>::iterator, bool> fres = mp.insert(fp);
				std::cout << "std: " << (*sres.first).first << "-" << (*sres.first).second << " " << sres.second << std::endl;
				std::cout << " ft: " << (*fres.first).first << "-" << (*fres.first).second << " " << fres.second << std::endl;
			}

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- INSERT WITH HINT -----\n";

			std::map<int, int> m;
			ft::map<int, int> mp;
			
			for (int i = 0; i < SIZE / 2; i++)
			{
				int x = std::rand() % 100, y = std::rand() % 100;
				std::pair<int, int> sp(x, y);
				ft::pair<int, int> fp(x, y);

				std::map<int, int>::iterator k1 = m.insert(m.begin(), sp);
				ft::map<int, int>::iterator k2 = mp.insert(mp.begin(), fp);

				std::cout << "std: " << (*k1).first << "-" << (*k1).second << std::endl;
				std::cout << " ft: " << (*k2).first << "-" << (*k2).second << std::endl;
			}

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE INSERT -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m;
			ft::map<int, int> mp;

			m.insert(vec.begin(), vec.end());
			mp.insert(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- ITERATOR ERASE -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "\nerasing twice\n";
			
			m.erase((++(++m.begin())));
			m.erase((++(++m.begin())));

			mp.erase((++(++mp.begin())));
			mp.erase((++(++mp.begin())));

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- KEY ERASE -----\n";
			
			std::vector<std::pair<int, int> > vec;

			int x = std::rand() % SIZE;
			int save_key = 0;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";

				if (x == i)
					save_key = vec.back().first;
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "\nerasing with key " << save_key << std::endl;
			
			std::cout << "std: " << m.erase(save_key) << std::endl;
			std::cout << " ft: " << mp.erase(save_key) << std::endl;

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
			{
			std::cout << "\n----- RANGE ERASE -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "\nerasing from begin to end" << std::endl;
			
			m.erase(++m.begin(), --m.end());
			mp.erase(++mp.begin(), --mp.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SWAP -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end()), m1;
			ft::map<int, int> mp(vec.begin(), vec.end()), mp1;


			std::cout << "first ORG_SIZE: " << m.size() << "\nfirst  MY_SIZE: " << mp.size() << std::endl;
			std::cout << "fisrt output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "first output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "second ORG_SIZE: " << m1.size() << "\nsecond  MY_SIZE: " << mp1.size() << std::endl;
			std::cout << "second output std: ";
			for (std::map<int, int>::iterator k = m1.begin(); k != m1.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "second output  ft: ";
			for (ft::map<int, int>::iterator k = mp1.begin(); k != mp1.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "\nswapping first and second\n";
			m.swap(m1);
			mp.swap(mp1);

			std::cout << "first ORG_SIZE: " << m.size() << "\nfirst  MY_SIZE: " << mp.size() << std::endl;
			std::cout << "fisrt output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "first output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "second ORG_SIZE: " << m1.size() << "\nsecond  MY_SIZE: " << mp1.size() << std::endl;
			std::cout << "second output std: ";
			for (std::map<int, int>::iterator k = m1.begin(); k != m1.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "second output  ft: ";
			for (ft::map<int, int>::iterator k = mp1.begin(); k != mp1.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- CLEAR -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "\nclearing" << std::endl;
			
			m.clear();
			mp.clear();

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== OBSERVERS =====\n";
	do {
		{
			std::cout << "\n----- KEY COMPARE -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::map<int, int>::key_compare const &k = m.key_comp();
			ft::map<int, int>::key_compare const &k1 = mp.key_comp();

			int x = std::rand() % 100, y = std::rand() % 100;
			std::cout << "\ncomparing: " << x << " and " << y << std::endl;
			std::cout << "std: " << k(x, y) << std::endl;
			std::cout << " ft: " << k1(x, y) << std::endl;
			std::cout << "\ncomparing: " << y << " and " << x << std::endl;
			std::cout << "std: " << k(y, x) << std::endl;
			std::cout << " ft: " << k1(y, x) << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- VALUE COPMARE -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::map<int, int>::value_compare const &k = m.value_comp();
			ft::map<int, int>::value_compare const &k1 = mp.value_comp();

			int x = std::rand() % 100, y = std::rand() % 100;
			int x1 = std::rand() % 100, y1 = std::rand() % 100;

			std::pair<int, int> pr1(x, y), pr2(x1, y1);
			ft::pair<int, int> prt1(x, y), prt2(x1, y1);
			std::cout << "\ncomparing: " << x << "-" << y << " and " << x1 << "-" << y1 << std::endl;
			std::cout << "std: " << k(pr1, pr2) << std::endl;
			std::cout << " ft: " << k1(prt1, prt2) << std::endl;
			std::cout << "\ncomparing: " << x1 << "-" << y1 << " and " << x << "-" << y << std::endl;
			std::cout << "std: " << k(pr2, pr1) << std::endl;
			std::cout << " ft: " << k1(prt2, prt1) << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== OPERATIONS =====\n";
	do {
		{
			std::cout << "\n----- FIND -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			int x = std::rand() % 100;
			std::cout << "\nfind random key " << x << std::endl;
			if (m.find(x) != m.end())
				std::cout << "std: " << (*m.find(x)).first << "-" << (*m.find(x)).second << std::endl;
			else
				std::cout << "std: end()\n";
			if (mp.find(x) != mp.end())
				std::cout << "ft : " << (*mp.find(x)).first << "-" << (*mp.find(x)).second << std::endl;
			else
				std::cout << "ft : end()\n";
			
			x = vec[std::rand() % vec.size()].first;
			std::cout << "\nfind contained key " << x << std::endl;
			if (m.find(x) != m.end())
				std::cout << "std: " << (*m.find(x)).first << "-" << (*m.find(x)).second << std::endl;
			else
				std::cout << "std: end()\n";
			if (mp.find(x) != mp.end())
				std::cout << "ft : " << (*mp.find(x)).first << "-" << (*mp.find(x)).second << std::endl;
			else
				std::cout << "ft : end()\n";
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- COUNT -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			int x = std::rand() % 100;
			std::cout << "\ncount random key " << x << std::endl;
			std::cout << "std: " << m.count(x) << std::endl;
			std::cout << "ft : " << mp.count(x) << std::endl;
			
			x = vec[std::rand() % vec.size()].first;
			std::cout << "\ncount contained key " << x << std::endl;
			std::cout << "std: " << m.count(x) << std::endl;
			std::cout << "ft : " << mp.count(x) << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- LOWER BOUND -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			int x = std::rand() % 100;
			std::cout << "\nlower bound random key " << x << std::endl;
			std::cout << "std: " << (*m.lower_bound(x)).first << "-" << (*m.lower_bound(x)).second << std::endl;
			std::cout << "ft : " << (*mp.lower_bound(x)).first << "-" << (*mp.lower_bound(x)).second << std::endl;
			
			x = vec[std::rand() % vec.size()].first;
			std::cout << "\nlower bound contained key " << x << std::endl;
			std::cout << "std: " << (*m.lower_bound(x)).first << "-" << (*m.lower_bound(x)).second << std::endl;
			std::cout << "ft : " << (*mp.lower_bound(x)).first << "-" << (*mp.lower_bound(x)).second << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- UPPER BOUND -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			int x = std::rand() % 100;
			std::cout << "\nlower bound random key " << x << std::endl;
			std::cout << "std: " << (*m.upper_bound(x)).first << "-" << (*m.upper_bound(x)).second << std::endl;
			std::cout << "ft : " << (*mp.upper_bound(x)).first << "-" << (*mp.upper_bound(x)).second << std::endl;
			
			x = vec[std::rand() % vec.size()].first;
			std::cout << "\nlower bound contained key " << x << std::endl;
			std::cout << "std: " << (*m.upper_bound(x)).first << "-" << (*m.upper_bound(x)).second << std::endl;
			std::cout << "ft : " << (*mp.upper_bound(x)).first << "-" << (*mp.upper_bound(x)).second << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- EQUAL RANGE BOUND -----\n";
			
			std::vector<std::pair<int, int> > vec;

			std::cout << "creating random vector: ";
			for (int i = 0; i < SIZE; i++)
			{
				vec.push_back(std::pair<int, int>(std::rand() % 100, std::rand() % 100));
				std::cout << vec.back().first << "-" << vec.back().second << " ";
			}
			std::cout << std::endl;

			std::map<int, int> m(vec.begin(), vec.end());
			ft::map<int, int> mp(vec.begin(), vec.end());

			std::cout << "ORG_SIZE: " << m.size() << "\n MY_SIZE: " << mp.size() << std::endl;
			std::cout << "output std: ";
			for (std::map<int, int>::iterator k = m.begin(); k != m.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::map<int, int>::iterator k = mp.begin(); k != mp.end(); k++)
				std::cout << (*k).first << "-" << (*k).second << " ";
			std::cout << std::endl;

			int x = std::rand() % 100;
			std::cout << "\nequal range random key " << x << std::endl;
			std::cout << "std: " << (*(m.equal_range(x)).first).first << "-" << (*(m.equal_range(x)).first).second << " and " << (*(m.equal_range(x)).second).first << "-" << (*(m.equal_range(x)).second).second << std::endl;
			std::cout << "ft : " << (*(mp.equal_range(x)).first).first << "-" << (*(mp.equal_range(x)).first).second << " and " << (*(mp.equal_range(x)).second).first << "-" << (*(mp.equal_range(x)).second).second << std::endl;
			
			x = vec[std::rand() % vec.size()].first;
			std::cout << "\nlower bound contained key " << x << std::endl;
			std::cout << "std: " << (*(m.equal_range(x)).first).first << "-" << (*(m.equal_range(x)).first).second << " and " << (*(m.equal_range(x)).second).first << "-" << (*(m.equal_range(x)).second).second << std::endl;
			std::cout << "ft : " << (*(mp.equal_range(x)).first).first << "-" << (*(mp.equal_range(x)).first).second << " and " << (*(mp.equal_range(x)).second).first << "-" << (*(mp.equal_range(x)).second).second << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
}

void vector_testing()
{
	std::string str;
	std::cout << "\n///// VECTOR TESTING \\\\\\\\\\\n";
	std::cout << "\n===== CONSTRUCTOR TESTING =====\n";
	do
	{
		{
			std::cout << "\n----- DEFAULT CONSTRUCTOR -----\n";
			std::vector<int> vc;
			ft::vector<int> vec;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");	
	do
	{
		{
			std::cout << "\n----- FILL CONSTRUCTOR -----\n";
			int x = std::rand() % 100;
			std::vector<int> vc(SIZE, x);
			ft::vector<int> vec(SIZE, x);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do
	{
		{
			std::cout << "\n----- RANGE CONSTRUCTOR -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do
	{
		{
			std::cout << "\n----- COPY CONSTRUCTOR -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res);
			ft::vector<int> cp(res.begin(), res.end());
			ft::vector<int> vec(cp);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do
	{
		{
			std::cout << "\n----- OPERATOR = -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc = res;
			ft::vector<int> cp(res.begin(), res.end());
			ft::vector<int> vec = cp;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== ITERATOR TESTING =====\n";
	do {
		{
			std::cout << "\n----- REVERSE ITERATOR -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res);
			ft::vector<int> cp(res.begin(), res.end());
			ft::vector<int> vec(cp);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::reverse_iterator k = vc.rbegin(); k != vc.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::reverse_iterator k = vec.rbegin(); k != vec.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== CAPACITY TESTING =====\n";
	do {
		{
			std::cout << "\n----- SIZE -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::reverse_iterator k = vc.rbegin(); k != vc.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::reverse_iterator k = vec.rbegin(); k != vec.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- MAX SIZE -----\n";

			std::vector<int> vc;
			ft::vector<int> vec;

			std::cout << "std: " << vc.max_size() << std::endl;
			std::cout << " ft: " << vec.max_size() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RESIZE -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t size = std::rand() % 100;
			int val = std::rand() % 100;

			std::cout << "\nresizing to size " << size << " with value " << val << std::endl;
			vc.resize(size, val);
			vec.resize(size, val);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- CAPACITY -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::reverse_iterator k = vc.rbegin(); k != vc.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::reverse_iterator k = vec.rbegin(); k != vec.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- EMPTY -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::vector<int> vc1;
			ft::vector<int> vec1;

			std::cout << "\ntesting with filled vector\n";
			std::cout << "std: " << vc.empty() << std::endl;
			std::cout << " ft: " << vec.empty() << std::endl;
			std::cout << "\ntesting with non-filled vector\n";
			std::cout << "std: " << vc1.empty() << std::endl;
			std::cout << " ft: " << vec1.empty() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RESERVE -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::reverse_iterator k = vc.rbegin(); k != vc.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::reverse_iterator k = vec.rbegin(); k != vec.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t size = std::rand() % 100;

			std::cout << "\nreserve with size " << size << std::endl;
			vc.reserve(size);
			vec.reserve(size);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::reverse_iterator k = vc.rbegin(); k != vc.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::reverse_iterator k = vec.rbegin(); k != vec.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== ELEMENT ACCESS TESTING =====\n";
	do {
		{
			std::cout << "\n----- OPERATOR [] -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (size_t i = 0; i < vc.size(); i++)
				std::cout << vc[i] << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (size_t i = 0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- AT -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (size_t i = 0; i < vc.size(); i++)
				std::cout << vc.at(i) << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (size_t i = 0; i < vec.size(); i++)
				std::cout << vec.at(i) << " ";
			std::cout << std::endl;

			std::cout << "\ntrying to out of range access\n";
			try
			{
				std::cout << vc.at(100) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				std::cout << vec.at(100) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
			{
			std::cout << "\n----- FRONT -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "std: " << vc.front() << std::endl;
			std::cout << " ft: " << vc.front() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- BACK -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "std: " << vc.back() << std::endl;
			std::cout << " ft: " << vc.back() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== MODIFIERS =====\n";
	do {
		{
			std::cout << "\n----- FILL ASSIGN -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t size = std::rand() % 100;
			int val = std::rand() % 100;

			std::cout << "\nassign with size " << size << " and value " << val << std::endl;
			vc.assign(size, val);
			vec.assign(size, val);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE ASSIGN -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::vector<int> vc(res.begin(), res.end());
			ft::vector<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			res.clear();
			size_t size = std::rand() % 100;

			std::cout << "\ncreating new vector with size " << size << std::endl;
			for (size_t i = 0; i < size; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}

			std::cout << "\nassign" << std::endl;
			vc.assign(res.begin(), res.end());
			vec.assign(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PUSH BACK -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;


			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "ORG_CAP: " << vc.capacity() << "\n MY_CAP: " << vec.capacity() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- POP BACK -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "poping " << SIZE / 2 << " elements from back\n";

			for (int i = 0; i < SIZE / 2; i++)
			{
				vc.pop_back();
				vec.pop_back();
			}

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SINGLE INSERT -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			int x = std::rand();
			size_t offset = std::rand() % SIZE;
			
			std::cout << "inserting " << x << " to begin + " << offset << std::endl;

			std::cout << "std: " << *vc.insert(vc.begin() + offset, x) << std::endl;
			std::cout << " ft: " << *vec.insert(vec.begin() + offset, x) << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- FILL INSERT -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			int x = std::rand();
			size_t size = rand() % (SIZE / 2);
			size_t offset = std::rand() % SIZE;
			
			std::cout << "inserting " << x << " to begin + " << offset << " for size " <<  size << std::endl;

			vc.insert(vc.begin() + offset, size, x);
			vec.insert(vec.begin() + offset, size, x);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE INSERT -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> res;
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\ncreating random vector for inserting\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t offset = std::rand() % SIZE;
			
			std::cout << "inserting new vector to begin + " << offset << std::endl;

			vc.insert(vc.begin() + offset, res.begin(), res.end());
			vec.insert(vec.begin() + offset, res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SINGLE ERASE -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t offset = std::rand() % SIZE;
			
			std::cout << "Erasing from begin + " << offset << " element " << *(vc.begin() + offset) << std::endl;

			std::cout << "std: " << *vc.erase(vc.begin() + offset) << std::endl;
			std::cout << "ft : " << *vec.erase(vec.begin() + offset) << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE ERASE -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t offset = 5;
			size_t offset1 = 4;
			
			std::cout << "Erasing from begin + " << offset << " to end - " << offset1 << std::endl;

			std::cout << "std: " << *vc.erase(vc.begin() + offset, vc.end() -  offset1) << std::endl;
			std::cout << "ft : " << *vec.erase(vec.begin() + offset, vec.end() -  offset1) << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SWAP -----\n";

			std::cout << "creating first random vector\n";
			std::vector<int> res;
			std::vector<int> vc;
			ft::vector<int> vec;
			ft::vector<int> ret;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "creating second random vector\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
				ret.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;		
		
			std::cout << "\nSwapping\n";

			vc.swap(res);
			vec.swap(ret);

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- CLEAR -----\n";

			std::cout << "creating random vector\n";
			std::vector<int> vc;
			ft::vector<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nclearing\n";
			vc.clear();
			vec.clear();

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::vector<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::vector<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
}

void list_testing()
{
	std::string str;
	std::cout << "\n///// LIST TESTING \\\\\\\\\\\n";
	std::cout << "\n===== CONSTRUCTOR TESTING =====\n";
	do {
		{
			std::cout << "\n----- DEFAULT CONSTRUCTOR -----\n";
			std::list<int> vc;
			ft::list<int> vec;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- FILL CONSTRUCTOR -----\n";
			int x = std::rand() % 100;
			std::list<int> vc(SIZE, x);
			ft::list<int> vec(SIZE, x);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE CONSTRUCTOR -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- COPY CONSTRUCTOR -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res);
			ft::list<int> cp(res.begin(), res.end());
			ft::list<int> vec(cp);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- OPERATOR = -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc = res;
			ft::list<int> cp(res.begin(), res.end());
			ft::list<int> vec = cp;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== ITERATOR TESTING =====\n";
	do {
		{
			std::cout << "\n----- REVERSE ITERATOR -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res);
			ft::list<int> cp(res.begin(), res.end());
			ft::list<int> vec(cp);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::reverse_iterator k = vc.rbegin(); k != vc.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::reverse_iterator k = vec.rbegin(); k != vec.rend(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== CAPACITY TESTING =====\n";
	do {
		{
			std::cout << "\n----- SIZE -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- MAX SIZE -----\n";

			std::list<int> vc;
			ft::list<int> vec;

			std::cout << "std: " << vc.max_size() << std::endl;
			std::cout << " ft: " << vec.max_size() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- EMPTY -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::list<int> vc1;
			ft::list<int> vec1;

			std::cout << "\ntesting with filled list\n";
			std::cout << "std: " << vc.empty() << std::endl;
			std::cout << " ft: " << vec.empty() << std::endl;
			std::cout << "\ntesting with non-filled list\n";
			std::cout << "std: " << vc1.empty() << std::endl;
			std::cout << " ft: " << vec1.empty() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== ELEMENT ACCESS TESTING =====\n";
	do {
		{
			std::cout << "\n----- FRONT -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::cout << "std: " << vc.front() << std::endl;
			std::cout << " ft: " << vc.front() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- BACK -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::cout << "std: " << vc.back() << std::endl;
			std::cout << " ft: " << vc.back() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== MODIFIERS TESTING =====\n";
	do {
		{
			std::cout << "\n----- FILL ASSIGN -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t size = std::rand() % 100;
			int val = std::rand() % 100;

			std::cout << "\nassign with size " << size << " and value " << val << std::endl;
			vc.assign(size, val);
			vec.assign(size, val);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE ASSIGN -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			res.clear();
			size_t size = std::rand() % 100;

			std::cout << "\ncreating new list with size " << size << std::endl;
			for (size_t i = 0; i < size; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}

			std::cout << "\nassign" << std::endl;
			vc.assign(res.begin(), res.end());
			vec.assign(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PUSH BACK -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- POP BACK -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "poping " << SIZE / 2 << " elements from back\n";

			for (int i = 0; i < SIZE / 2; i++)
			{
				vc.pop_back();
				vec.pop_back();
			}

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PUSH FRONT -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_front(x);
				vec.push_front(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- POP FRONT -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_front(x);
				vec.push_front(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\npoping " << SIZE / 2 << " elements from front\n";

			for (int i = 0; i < SIZE / 2; i++)
			{
				vc.pop_front();
				vec.pop_front();
			}

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SINGLE INSERT -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			int x = std::rand();
			size_t offset = std::rand() % SIZE;		
			std::cout << "inserting " << x << " to begin + " << offset << std::endl;

			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}

			std::cout << "std: " << *vc.insert(its, x) << std::endl;
			std::cout << " ft: " << *vec.insert(itf, x) << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- FILL INSERT -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			int x = std::rand();
			size_t size = rand() % (SIZE / 2);
			size_t offset = std::rand() % SIZE;
			
			std::cout << "inserting " << x << " to begin + " << offset << " for size " <<  size << std::endl;
			
			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}

			vc.insert(its, size, x);
			vec.insert(itf, size, x);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE INSERT -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\ncreating random list for inserting\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t offset = std::rand() % SIZE;
			
			std::cout << "inserting new list to begin + " << offset << std::endl;

			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}

			vc.insert(its, res.begin(), res.end());
			vec.insert(itf, res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
			{
			std::cout << "\n----- SINGLE ERASE -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t offset = std::rand() % SIZE;

			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}
			
			std::cout << "Erasing from begin + " << offset << " element " << *(its) << std::endl;

			std::cout << "std: " << *vc.erase(its) << std::endl;
			std::cout << "ft : " << *vec.erase(itf) << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE ERASE -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t offset = 5;
			size_t offset1 = 4;

			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			std::list<int>::iterator its1 = vc.end();
			ft::list<int>::iterator itf1 = vec.end();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}
			for(size_t i = 0; i < offset1; i++)
			{
				its1--;
				itf1--;
			}
			
			std::cout << "Erasing from begin + " << offset << " to end - " << offset1 << std::endl;

			std::cout << "std: " << *vc.erase(its, its1) << std::endl;
			std::cout << "ft : " << *vec.erase(itf, itf1) << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SWAP -----\n";

			std::cout << "creating first random list\n";
			std::list<int> res;
			std::list<int> vc;
			ft::list<int> vec;
			ft::list<int> ret;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "creating second random list\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
				ret.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\nFirst\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;		
		
			std::cout << "\nSwapping\n";

			vc.swap(res);
			vec.swap(ret);

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RESIZE -----\n";

			std::cout << "creating random list\n";
			std::list<int> res;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
			}
			std::cout << std::endl;

			std::list<int> vc(res.begin(), res.end());
			ft::list<int> vec(res.begin(), res.end());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			size_t size = std::rand() % 100;
			int val = std::rand() % 100;

			std::cout << "\nresizing to size " << size << " with value " << val << std::endl;
			vc.resize(size, val);
			vec.resize(size, val);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- CLEAR -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nclearing\n";
			vc.clear();
			vec.clear();

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== OPERATIONS TESTING =====\n";
	do {
		{
			std::cout << "\n----- ENTRY LIST SPLICE -----\n";

			std::cout << "creating first random list\n";
			std::list<int> res;
			std::list<int> vc;
			ft::list<int> vec;
			ft::list<int> ret;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "creating second random list\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
				ret.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\nFirst\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;		
		
			size_t offset = rand() % SIZE;

			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}

			std::cout << "\nSplicing\n";
			vc.splice(its, res);
			vec.splice(itf, ret);

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SINGLE SPLICE -----\n";

			std::cout << "creating first random list\n";
			std::list<int> res;
			std::list<int> vc;
			ft::list<int> vec;
			ft::list<int> ret;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "creating second random list\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
				ret.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\nFirst\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;		
		
			size_t offset = rand() % SIZE;
			size_t offset1 = rand() % SIZE;

			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			std::list<int>::iterator its1 = res.end();
			ft::list<int>::iterator itf1 = ret.end();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}
			for(size_t i = 0; i < offset1; i++)
			{
				its1--;
				itf1--;
			}

			std::cout << "\nSplicing element " << *its1 << " from second list\n";
			vc.splice(its, res, its1);
			vec.splice(itf, ret, itf1);

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- RANGE SPLICE -----\n";

			std::cout << "creating first random list\n";
			std::list<int> res;
			std::list<int> vc;
			ft::list<int> vec;
			ft::list<int> ret;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "creating second random list\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
				ret.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\nFirst\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;		
		
			size_t offset = rand() % SIZE;
			size_t offset1 = rand() % (SIZE / 2);
			size_t offset2 = rand() % (SIZE / 2);

			std::list<int>::iterator its = vc.begin();
			ft::list<int>::iterator itf = vec.begin();

			std::list<int>::iterator its1 = res.begin();
			ft::list<int>::iterator itf1 = ret.begin();

			std::list<int>::iterator its2 = res.end();
			ft::list<int>::iterator itf2 = ret.end();

			for(size_t i = 0; i < offset; i++)
			{
				its++;
				itf++;
			}
			for(size_t i = 0; i < offset1; i++)
			{
				its1++;
				itf1++;
			}
			for(size_t i = 0; i < offset2; i++)
			{
				its2--;
				itf2--;
			}

			std::cout << "\nSplicing range from " << offset1 << " to " << SIZE - offset2 << " from second list\n";
			vc.splice(its, res, its1, its2);
			vec.splice(itf, ret, itf1, itf2);

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- REMOVE -----\n";

			std::cout << "creating random list\n";
			int elem;
			int con = rand() % SIZE;
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
				if (i == con)
					elem = x;
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nRemoving element " << elem << std::endl;
			vc.remove(elem);
			vec.remove(elem);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- REMOVE IF -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nRemoving element less 50\n";
			vc.remove_if(is_100);
			vec.remove_if(is_100);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- STANDART UNIQUE -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			int save = 5;
			int x = rand() % 10;
			for (int i = 0, j = 0; i < SIZE; i++)
			{
				if (j++ >= save)
				{
					j = 0;
					x = rand() % 10;
				}
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSaving only unique elements\n";
			vc.unique();
			vec.unique();

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PREDICATE UNIQUE -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			int save = 5;
			int x = rand() % 10;
			for (int i = 0, j = 0; i < SIZE; i++)
			{
				if (j++ >= save)
				{
					j = 0;
					x = rand() % 10;
				}
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSaving only unique elements, using binary predicate\n";
			vc.unique(is_true);
			vec.unique(is_true);

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- STANDART SORT -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSorting\n";
			vc.sort();
			vec.sort();

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PREDICATE SORT -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSorting\n";
			vc.sort(ft::less<int>());
			vec.sort(ft::less<int>());

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- STANDART MERGE -----\n";

			std::cout << "creating first random list\n";
			std::list<int> res;
			std::list<int> vc;
			ft::list<int> vec;
			ft::list<int> ret;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "creating second random list\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
				ret.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\nFirst\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;		
		
			std::cout << "\nSorting\n";

			vc.sort();
			vec.sort();
			res.sort();
			ret.sort();

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nMerging second in first\n";
			vc.merge(res);
			vec.merge(ret);

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PREDICATE MERGE -----\n";

			std::cout << "creating first random list\n";
			std::list<int> res;
			std::list<int> vc;
			ft::list<int> vec;
			ft::list<int> ret;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "creating second random list\n";
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				res.push_back(x);
				ret.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "\nFirst\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;		
		
			std::cout << "\nSorting\n";

			vc.sort();
			vec.sort();
			res.sort();
			ret.sort();

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nMerging second in first\n";
			vc.merge(res, ft::less<int>());
			vec.merge(ret, ft::less<int>());

			std::cout << "First\n";
			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nSecond\n";
			std::cout << "ORG_SIZE: " << res.size() << "\n MY_SIZE: " << ret.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = res.begin(); k != res.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = ret.begin(); k != ret.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- REVERSE -----\n";

			std::cout << "creating random list\n";
			std::list<int> vc;
			ft::list<int> vec;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				vc.push_back(x);
				vec.push_back(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "\nReversing\n";
			vc.reverse();
			vec.reverse();

			std::cout << "ORG_SIZE: " << vc.size() << "\n MY_SIZE: " << vec.size() << std::endl;
			std::cout << "output std: ";
			for (std::list<int>::iterator k = vc.begin(); k != vc.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;

			std::cout << "output  ft: ";
			for (ft::list<int>::iterator k = vec.begin(); k != vec.end(); k++)
				std::cout << *k << " ";
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
}

void queue_testing()
{
	std::string str;
	std::cout << "\n///// QUEUE TESTING \\\\\\\\\\\n";
	std::cout << "\n===== CONSTRUCTOR TEST =====\n";
	do {
		{
			std::cout << "\n----- DEFAULT CONSTRUCTOR -----\n";
			std::queue<int> qu;
			ft::queue<int> que;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.front() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.front() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== OPERATIONS TEST =====\n";
	do {
		{
			std::cout << "\n----- EMPTY -----\n";

			std::cout << "creating random queue\n";
			std::queue<int> qu;
			ft::queue<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::queue<int> vc1;
			ft::queue<int> vec1;

			std::cout << "\ntesting with filled list\n";
			std::cout << "std: " << qu.empty() << std::endl;
			std::cout << " ft: " << que.empty() << std::endl;
			std::cout << "\ntesting with non-filled list\n";
			std::cout << "std: " << vc1.empty() << std::endl;
			std::cout << " ft: " << vec1.empty() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SIZE -----\n";

			std::cout << "creating random queue\n";
			std::queue<int> qu;
			ft::queue<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.front() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.front() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- FRONT -----\n";

			std::cout << "creating random queue\n";
			std::queue<int> qu;
			ft::queue<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.front() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.front() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- BACK -----\n";

			std::cout << "creating random queue\n";
			std::queue<int> qu;
			ft::queue<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "\nBack\nstd: " << qu.back() << std::endl << " ft: " << que.back() << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.front() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.front() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PUSH -----\n";

			std::cout << "creating random queue\n";
			std::queue<int> qu;
			ft::queue<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.front() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.front() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- POP -----\n";

			std::cout << "creating random queue\n";
			std::queue<int> qu;
			ft::queue<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.front() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.front() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
}

void stack_testing()
{
	std::string str;
	std::cout << "\n///// STACK TESTING \\\\\\\\\\\n";
	std::cout << "\n===== CONSTRUCTOR TEST =====\n";
	do {
		{
			std::cout << "\n----- DEFAULT CONSTRUCTOR -----\n";
			std::stack<int> qu;
			ft::stack<int> que;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.top() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.top() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	std::cout << "\n===== OPERATIONS TEST =====\n";
	do {
		{
			std::cout << "\n----- EMPTY -----\n";

			std::cout << "creating random stack\n";
			std::stack<int> qu;
			ft::stack<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::stack<int> vc1;
			ft::stack<int> vec1;

			std::cout << "\ntesting with filled list\n";
			std::cout << "std: " << qu.empty() << std::endl;
			std::cout << " ft: " << que.empty() << std::endl;
			std::cout << "\ntesting with non-filled list\n";
			std::cout << "std: " << vc1.empty() << std::endl;
			std::cout << " ft: " << vec1.empty() << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- SIZE -----\n";

			std::cout << "creating random stack\n";
			std::stack<int> qu;
			ft::stack<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.top() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.top() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- TOP -----\n";

			std::cout << "creating random stack\n";
			std::stack<int> qu;
			ft::stack<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.top() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.top() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- PUSH -----\n";

			std::cout << "creating random stack\n";
			std::stack<int> qu;
			ft::stack<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.top() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.top() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
	do {
		{
			std::cout << "\n----- POP -----\n";

			std::cout << "creating random stack\n";
			std::stack<int> qu;
			ft::stack<int> que;
			for (int i = 0; i < SIZE; i++)
			{
				int x = rand() % 100;
				std::cout << x << " ";
				qu.push(x);
				que.push(x);
			}
			std::cout << std::endl;

			std::cout << "ORG_SIZE: " << qu.size() << "\n MY_SIZE: " << que.size() << std::endl;
			std::cout << "output std: ";
			while (!qu.empty())
			{
				std::cout << qu.top() << " ";
				qu.pop();
			}
			std::cout << std::endl;

			std::cout << "output  ft: ";
			while (!que.empty())
			{
				std::cout << que.top() << " ";
				que.pop();
			}
			std::cout << std::endl;
		}
		std::cout << "\nTo continue press ENTER\nFor restart test press any key\n";
		std::getline(std::cin, str);
	} while (str != "");
}

int main()
{
	std::srand(std::time(nullptr));
	std::string str;

	do
	{
		std::cout << "\nPlease enter what you want to test\n";
		std::cout << "1 - Vector\n2 - List\n3 - Queue\n4 - Stack\n5 - Map\nFor exit press ENTER\n";
		std::cout << "input: ";
		std::getline(std::cin, str);
		if (str == "1")
			vector_testing();
		if (str == "2")
			list_testing();
		if (str == "3")
			queue_testing();
		if (str == "4")
			stack_testing();
		if (str == "5")
			map_testing();
	} while (str != "");
	return 0;
}