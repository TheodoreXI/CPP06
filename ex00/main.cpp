#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	argc = 0;
	std::string type = argv[1];
	ScalarConverter::convert(type);
}