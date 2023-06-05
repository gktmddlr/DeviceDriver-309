#pragma once

#include <exception>

class ReadFailException : public std::exception
{
	
};

class WriteFailException : public std::exception
{
	
};