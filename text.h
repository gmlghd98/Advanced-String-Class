#pragma once
#include "String.h"

class Text : public String
{
private:
	void CheckStringTail();
public:
	Text();
	Text(const char* s);
	Text(const String& str);
	Text(const Text& txt);
	~Text();

	int lines();

	Text& append(const char* s);
	Text& append(const String& str);
	Text& append(const Text& txt);
};
//std::ostream& operator<<(std::ostream& out, Text& txt);
