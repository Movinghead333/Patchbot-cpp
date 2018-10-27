#ifndef __EXCEPTIONS_H_DEFINED__
#define __EXCEPTIONS_H_DEFINED__

#include <exception>
#include <string>

struct Simple_Message_Exception : public std::exception
{
	const std::string m_error_message;

public:
	Simple_Message_Exception(const std::string p_message): m_error_message(p_message)
	{}
};

#endif

