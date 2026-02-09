#include "Serializer.hpp"

int main()
{
	Data b = Data();
	Data *k = &b;
	uintptr_t a;
	a = Serializer::serialize(k);
	std::cout << "this is the first address " << k << "\n";
	std::cout << a << "\n";
	std::cout << "this is the check " << Serializer::deserialize(a) << "\n";

}

















