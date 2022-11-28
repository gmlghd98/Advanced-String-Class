#include <iostream>
#include "text.h"

void Text::CheckStringTail()
{
	if ((int)strlen(this->str_) > 0 &&
		this->str_[(int)strlen(this->str_) - 1] != '\n')
		this->String::append("\n");
}

Text::Text() : String("")
{
	this->CheckStringTail();
}
Text::Text(const char* s) : String(s)
{
	this->CheckStringTail();
}
Text::Text(const String& str) : String(str)
{
	this->CheckStringTail();
}
Text::Text(const Text& txt) : String(txt)
{
	this->CheckStringTail();
}
Text::~Text()
{
	// 부모 String에서 삭제할 예정
}
//std::ostream& operator<<(std::ostream& out, Text& txt)
//{	// out = cout
//	return out << txt.print(false);
//}
int Text::lines()
{
	int cntliens = 0;
	for (int i = 0; i < (int)strlen(this->str_); i++)
		if (this->str_[i] == '\n')
			cntliens++;
	return cntliens;
}
Text& Text::append(const char* s)
{
	return this->append(Text(s));
}
Text& Text::append(const String& str)
{
	return this->append(Text(str));
}
Text& Text::append(const Text& txt)
{
	this->String::append(txt);
	return *this;
}