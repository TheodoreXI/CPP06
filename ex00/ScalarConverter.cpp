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
	if (type == "-inff" || type == "+inff" || type == "-inf" || type == "+inf")
		return (5);
	if (type == "nanf" || type == "nan")
		return (6);
	//sstrem to convert its much better
	for (size_t i = 0; i < type.length(); i++)
	{
		if (!std::isdigit(type[i]))
		{
			check = 1;
			if ((type[i] != '-' && type[i] != 'f' && type[i] != '.') || (type[i] == 'f' && (i+1) != type.length()) || (type[i] == '-' && i != 0))
				return (0);
			if (type[i] == '.')
			{
				count_point++;
			}
			if (count_point > 1 || (i+1) == type.length())
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
	int	a = 0;
	char c = 0;
	float f = 0.0f;
	double d = 0.0;
	std::string end = "";
	std::string endf = "f";


	if (ScalarConverter::parsing(type))
	{
		if (type.find(".0") != std::string::npos)
		{
			endf = ".0f";
			end = ".0";
		}
		switch(ScalarConverter::parsing(type))
		{
			case 1:
			{
				c = type[0];
				a = static_cast<int>(c);
				f = static_cast<float>(c);
				d = static_cast<double>(c);
				if (a <= 31 || a >= 127)
				{
					std::cout << "char: " << "Non displayable" << "\n";
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
				c = static_cast<char>(a);
				f = static_cast<float>(a);
				d = static_cast<double>(a);
				if (a <= 31 || a >= 127)
				{
					std::cout << "char: " << "Non displayable" << "\n";
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
				if (a <= 31 || a >= 127)
				{
					std::cout << "char: " << "Non displayable" << "\n";
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
				d = static_cast<float>(f);
				if (a <= 31 || a >= 127)
				{
					std::cout << "char: " << "Non displayable" << "\n";
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
				std::cout << "it entere default\n";
				break;
			}
		}
	}
}
