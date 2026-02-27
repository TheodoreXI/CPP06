#include "Serializer.hpp"

int main()
{
	Data b = Data();
	Data *k = &b;
	uintptr_t a;
	a = Serializer::serialize(k);
	std::cout << "this is the first address " << k << " and value " << k->ft_getx() << "\n";
	std::cout << a << "\n";
	std::cout << "this is the check " << Serializer::deserialize(a) << " and value " << k->ft_getx() << "\n";
}

















