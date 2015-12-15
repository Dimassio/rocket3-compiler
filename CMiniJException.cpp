#include "CMiniJException.h"


CMiniJException::CMiniJException( std::string _str ):
	str( _str )
{
}

CMiniJException::~CMiniJException() throw ()
{
}

const char* CMiniJException::what() const throw( )
{
	return str.c_str();
}