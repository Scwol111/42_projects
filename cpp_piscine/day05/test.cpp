#include <iostream>

using namespace std;

int main()
{
	//char x[] =  "5.344";
	double x = 346.456;
	//char d = static_cast<char>(x);
	std::cout << static_cast<char>(x) << std::endl;
	cout << static_cast<int>(x) << endl;
	cout << static_cast<float>(x) << endl;
	cout << static_cast<double>(x) << endl;
}