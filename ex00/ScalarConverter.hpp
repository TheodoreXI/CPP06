#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>


class ScalarConverter
{
	public:
		static void	convert(std::string type);
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &obj);
		
};




#endif