#include <iostream>
#include "String.h"
using namespace std;

// 1단계 코드--------------------
String::String() {
	//this->len_ = strlen("");
	//this->capa_ = this->len_ + 1;
	//this->str_ = new char[this->capa_];
	//strcpy_s(this->str_, this->capa_, "");
	this->common_func("");
}
String::String(const char* s) {
	//this->len_ = strlen(s);
	//this->capa_ = this->len_ + 1;
	//this->str_ = new char[this->capa_];
	//strcpy_s(this->str_, this->capa_, s);
	this->common_func(s);
}
String::String(const String& str) {
	//this->len_ = strlen(str.str_);
	//this->capa_ = this->len_ + 1;
	//this->str_ = new char[this->capa_];
	//strcpy_s(this->str_, this->capa_, str.str_);
	this->common_func(str.str_);
}
String::~String() {
	delete[] this->str_;
}

/*
void String::print() {		// 2단계에서 수정
	cout << this->str_ << endl;
}
*/			
int String::length() {
	return strlen(this->str_);
}
int String::size() {
	return this->length();
}
int String::capacity() {
	return this->capa_;
}

// 2단계 코드--------------------
String& String::assign(const String& str)
{
	return this->assign(str.str_);
}
String& String::assign(const char* s)
{
	//delete[] this->str_;
	//this->len_ = strlen(s);
	//this->capa_ = this->len_ + 1;
	//this->str_ = new char[this->capa_];
	//strcpy_s(this->str_, this->capa_, s);
	this->common_func(s, true);
	return *this;
}
String& String::operator=(const String& str)
{
	return this->assign(str.str_);
}
String& String::operator=(const char* s)
{
	return this->assign(s);
}

String& String::append(const String& str)
{
	return this->append(str.str_);
}
String& String::append(const char* s)
{
	//int tlen = strlen(this->str_) + strlen(s);
	//this->capa_ = tlen + 1;
	//char* temp = new char[this->capa_];
	//strcpy_s(temp, tlen + 1, this->str_);
	//strcat_s(temp, tlen + 1, s);
	//delete[] this->str_;
	//this->str_ = temp;
	this->common_func(this->str_, true, s);
	return *this;
}
String& String::operator+=(const String& str)
{
	return this->append(str.str_);
}
String& String::operator+=(const char* s)
{
	return this->append(s);
}

char& String::operator[](int index)
{
	if (index < 0) index = 0;
	if (index >= this->length()) index = this->length() - 1;
	return this->str_[index];
}

void String::shrink_to_fit()
{
	String temp(this->str_);
	this->assign(temp);
}

const char* String::print(bool show) const 
{
	if(show)
		cout << this->str_ << endl;
	return this->str_;
}

// 3단계 코드--------------------
void String::common_func(const char* s1, bool delStorage, const char* s2)
{
	int len = (int)strlen(s1) + (int)strlen(s2);
	int capa = len + 1;
	char* buf = new char[capa];
	strcpy_s(buf, capa, s1);
	strcat_s(buf, capa, s2);
	if (delStorage)
		delete[] this->str_;
	this->len_ = len;
	this->capa_ = capa;
	this->str_ = buf;
}

String String::operator+(const String& str)
{
	return this->operator+(str.str_);
	//return String(this->str_).append(str);
}
String String::operator+(const char* s)
{
	return String(*this).append(s);
	//return String(this->str_).append(s);
	// 
	//String ret_val;
	//ret_val = this->str_;
	//ret_val.assign(this->str_);
	//ret_val = *this;
	//ret_val.assign(*this);
	//ret_val.append(s);
	//return ret_val;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	return os << str.print(false);
}
std::istream& operator>>(std::istream& is, String& str)
{
	char buf[1024];
	is >> buf;
	str.assign(buf);
	return is;
}
