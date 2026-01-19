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

int	parsing(std::string type)
{
	int		one;
	char	c;

	one = 0;
	c = 0;
	if (type == "")
		return (0);
	for (int i = 0; i < type.length(); i++)
	{
		if (!std::isdigit(type[i]))
		{
			if (type[i] == '\'')
			{
				c = 1;
			}
			if (type.length() > 1 && type[i] != 'f' && type[i] != '.')
				return (0);
		}
		if (!std::isdigit(type[i]))
		{
			if (type[i] == '.')
			{

			}
		}
	}
}

void	ScalarConverter::convert(std::string type)
{
	int		check;
	char	c;
	int		one;

	c = 0;
	one = 0;
	check = 0;
	if (type == "-inff" || type == "+inff" || type == "nanf")
	{
		check = 3;
	}
	else if (type == "-inf" || type == "+inf" || type == "nan")
	{
		check = 4;
	}
	for (int i = 0; i < type.length(); i++)
	{
		if (type[i] == c)
		{
			if (c != 0)
				check = 1;
			break;
		}
		if (std::isdigit(type[i]))
			check = 2;
		else if (i > 0)
		{
			if ((type[i] == '.' || (type[i] == 'f' && (i+1) == type.length())) && one < 2)
			{
				one = 1;
			}
			else
			{
				check = 0;
				break;
			}
		}
	}
}
