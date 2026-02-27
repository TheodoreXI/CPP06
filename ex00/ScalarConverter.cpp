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

int	parsing(std::string &type)
{
	int	count_point;

	count_point = 0;
	if (type.length() < 1)
		return (0);
	if (type.length() == 1 && !std::isdigit(type[0]))
	{
		return (1);
	}
	if (type == "-inff" || type == "+inff" || type == "-inf" || type == "+inf")
		return (5);
	if (type == "nanf" || type == "nan")
		return (6);
	for (size_t i = 0; i < type.length(); i++)
	{
		if (!std::isdigit(type[i]))
		{
			if (i == 0 && type[i] != '-')
				return (0);
			if (type[i] == '-' && ((i+1) == type.length() || !std::isdigit(type[i+1])))
			{
				return (0);
			}
			if (type[i] == '.')
			{
				count_point++;
			}
			else if ((!std::isdigit(type[i-1]) || (i+1) != type.length()) && type[i] == 'f')
			{
				return (0);
			}
		}
	}
	if (count_point > 1)
		return (0);
	if (!count_point)
		return (2);
	if (count_point && type.find('f') == std::string::npos)
		return (3);
	else if (count_point)
	{
		type = type.substr(0, type.length()-1);
		return (4);
	}
	return (0);
}

void	ScalarConverter::convert(std::string &type)
{
	int	a = 0;
	char c = 0;
	float f = 0.0f;
	double d = 0.0;
	std::string end = "";
	std::string endf = "f";

	if (type.find(".0") != std::string::npos)
	{
		endf = ".0f";
		end = ".0";
	}
	switch(parsing(type))
	{
		case 1:
		{
			c = type[0];
			a = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			if ((a >= 0 && a <= 31) || a == 127)
			{
				std::cout << "char: " << "Non displayable" << "\n";
			}
			else if (a > 127 || a < 0)
			{
				std::cout << "char: " << "Impossible" << "\n";
			}
			else
			{
				std::cout << "char: " << c << "\n";
			}
			std::cout << "int: " << a << "\n";
			std::cout << "float: " << f << ".0f" << "\n";
			std::cout << "double: " << d << ".0" << "\n";
			break;
		}
		case 2:
		{
			std::stringstream s(type.c_str());
			s >> a;
			if ((a == 2147483647 && type != "2147483647") || (a == -2147483648 && type != "-2147483648"))
			{
				std::cout << "char: " << "impossible" << "\n";
				std::cout << "int: " << "impossible" << "\n";
				std::cout << "float: " << "impossible" << "\n";
				std::cout << "double: " << "impossible" << "\n";
				break ;
			}
			if ((a >= 0 && a <= 31) || a == 127)
			{
				std::cout << "char: " << "Non displayable" << "\n";
			}
			else if (a > 127 || a < 0)
			{
				std::cout << "char: " << "Impossible" << "\n";
			}
			else
			{
				std::cout << "char: " << c << "\n";
			}
			c = static_cast<char>(a);
			f = static_cast<float>(a);
			d = static_cast<double>(a);
			if ((a >= 0 && a <= 31) || a == 127)
			{
				std::cout << "char: " << "Non displayable" << "\n";
			}
			else if (a > 127 || a < 0)
			{
				std::cout << "char: " << "Impossible" << "\n";
			}
			else
			{
				std::cout << "char: " << c << "\n";
			}
			std::cout << "int: " << a << "\n";
			std::cout << "float: " << f << ".0f" << "\n";
			std::cout << "double: " << d << ".0" << "\n";
			break;
		}
		case 3:
		{
			std::stringstream s(type.c_str());
			s >> d;
			a = static_cast<int>(d);
			c = static_cast<char>(d);
			f = static_cast<float>(d);
			if ((a >= 0 && a <= 31) || a == 127)
			{
				std::cout << "char: " << "Non displayable" << "\n";
			}
			else if (a > 127 || a < 0)
			{
				std::cout << "char: " << "Impossible" << "\n";
			}
			else
			{
				std::cout << "char: " << c << "\n";
			}
			std::cout << "int: " << a << "\n";
			std::cout << "float: " << f << endf << "\n";
			std::cout << "double: " << d << end << "\n";
			break;
		}
		case 4:
		{
			std::stringstream s(type.c_str());
			s >> f;
			a = static_cast<int>(f);
			c = static_cast<char>(f);
			d = static_cast<double>(f);
			if ((a >= 0 && a <= 31) || a == 127)
			{
				std::cout << "char: " << "Non displayable" << "\n";
			}
			else if (a > 127 || a < 0)
			{
				std::cout << "char: " << "Impossible" << "\n";
			}
			else
			{
				std::cout << "char: " << c << "\n";
			}
			std::cout << "int: " << a << "\n";
			std::cout << "float: " << f << endf << "\n";
			std::cout << "double: " << d << end << "\n";
			break;
		}
		case 5:
		{
			std::cout << "char: " << "impossible" << "\n";
			std::cout << "int: " << "impossible" << "\n";
			if (type.find("-") != std::string::npos)
			{
				std::cout << "float: " << "-inff" << "\n";
				std::cout << "double: " << "-inf" << "\n";
			}
			else
			{
				std::cout << "float: " << "+inff" << "\n";
				std::cout << "double: " << "+inf" << "\n";
			}
			break;
		}
		case 6:
		{
			std::cout << "char: " << "impossible" << "\n";
			std::cout << "int: " << "impossible" << "\n";
			std::cout << "float: " << "nanf" << "\n";
			std::cout << "double: " << "nan" << "\n";
			break;
		}
		default:
		{
			std::cout << "char: " << "impossible" << "\n";
			std::cout << "int: " << "impossible" << "\n";
			std::cout << "float: " << "impossible" << "\n";
			std::cout << "double: " << "impossible" << "\n";
			break;
		}
	}
}
