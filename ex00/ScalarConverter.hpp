#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
// #include <cctype>
#include <sstream>


class ScalarConverter
{
	public:
		static void	convert(std::string &type);
		static int			parsing(std::string &type);
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		
};




#endif