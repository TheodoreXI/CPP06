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