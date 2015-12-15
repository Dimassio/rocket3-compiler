#pragma once
#include <exception>
#include <string>


class CMiniJException: public std::exception {
public:
	CMiniJException( std::string _str );
	~CMiniJException() throw ();

	const char* what() const throw( );
private:
	std::string str;
};