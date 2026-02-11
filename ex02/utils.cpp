#include "utils.hpp"

Base * generate(void)
{
	srand(time(NULL));
	if (!(rand() % 2))
	{
		return new A();
	}
	else if (!(rand() % 3))
	{
		return new B();
	}
	return new C();
}
void identify(Base* p)
{
	if (dynamic_cast <A*>(p))
	{
		std::cout << "the type is A.\n";
	}
	else if (dynamic_cast <B*>(p))
	{
		std::cout << "the type is A.\n";
	}
	else
	{
		std::cout << "the type is C.\n";
	}	
}

void identify(Base& p)
{
	try
	{
		
	}
}