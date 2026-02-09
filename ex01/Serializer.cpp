#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called.\n";
}

Serializer::Serializer(const Serializer &obj)
{
	*this = obj;
	std::cout << "Copy constructor called.\n";
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called.\n";
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	t;
	t = reinterpret_cast <uintptr_t>(ptr);
	return (t);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *p;
	p = reinterpret_cast <Data *>(raw);
	return (p);
}