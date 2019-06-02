#include "string.h"

myString::myString(char c)
{
	content_ = new char[1];
	content_[0] = c;
	len_ = 1;
}

myString::myString(const char* str)
{
	len_ = strlen(str);
	content_ = new char[len_];
	
	for (int i = 0; i != len_ ; i++)
		content_[i] = str[i];
}

myString::myString(const myString& c)
{
	
}