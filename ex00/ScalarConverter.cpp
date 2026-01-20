#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default ScalarConverter Constructor.\n";
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter Destructor.\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

int	ScalarConverter::parsing(std::string &type)
{
	int	check;
	int	count_point;

	check = 0;
	count_point = 0;
	if (type.length() < 1)
		return (0);
	if (type.length() == 1 && std::isalpha(type[0]))
	{
		return (1);
	}
	if (type == "-inff" || type == "+inff" || type == "-inf" || type == "+inf" || type == "nanf" || type == "nan")
		return (5);
	for (size_t i = 0; i < type.length(); i++)
	{
		if (!std::isdigit(type[i]))
		{
			check = 1;
			if ((type[i] != '-' && type[i] != 'f' && type[i] != '.') || (type[i] == 'f' && (i+1) != type.length()) || (type[i] == '-' && i != 0))
				return (0);
			if (type[i] == '.')
				count_point++;
			if (count_point > 1)
				return (0);
			if (type[i] == '-' && (i+1) != type.length())
				check = 0;
		}
	}
	if (!check)
		return (2);
	if (count_point && type.find('f') == std::string::npos)
		return (3);
	else if (count_point)
		return (4);
	return (0);
}

void	ScalarConverter::convert(std::string &type)
{
	// std::cout << ScalarConverter::parsing(type) << "\n"; //must be deleted after
	int	a = 0;

	if (ScalarConverter::parsing(type))
	{
		switch(ScalarConverter::parsing(type))
		{
			case 1:
			{
				a = std::atoi(type.c_str());
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				break;
			}
			case 5:
			{
				break;
			}
			default:
			{
				break;
			}
		}
	}
}
