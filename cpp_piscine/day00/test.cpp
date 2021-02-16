#include <iostream>

class A
{
	private:
		int x;
		std::string str;

	public:
		A(int a) { x = a; }
		~A() {};
		int* getP() {return &x;}
		int getX() {return x;}
		std::string &getStr() const;
};

std::string &A::getStr() const
{
	return str;
}

int main()
{
	A a(9);
	int *p = a.getP();

	*p += 1;
	std::string &s = a.getStr();
	std::cout << a.getX() << std::endl;
	s = "Hello World";
	std::cout << a.getStr() << std::endl;
	return 0;
}