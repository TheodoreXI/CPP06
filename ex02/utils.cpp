#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


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
	
}