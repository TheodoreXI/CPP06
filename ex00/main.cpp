#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "must enter two parameters.\n";
		return (1);
	}
	std::string type = argv[1];
	ScalarConverter::convert(type);
}