#pragma once
#include <iostream>
using namespace std;

class String {
	// 1단계 코드--------------------
	//friend std::ostream& operator<<(std::ostream& os, const String& str);
//private:
protected:
	char* str_;
	int len_; // 문자열의 길이
	int capa_; // 동적 배열의 크기

public:
	String();
	String(const char* s);	// "...." 또는 char[]
	String(const String& str);	// string 객체 참조 입력
	virtual ~String();

	//void print();
	int length();
	int size();
	int capacity();


	// 2단계 코드--------------------
public:
	String& assign(const String& str);
	String& assign(const char* s);
	String& operator=(const String& str);
	String& operator=(const char* s);

	String& append(const String& str);
	String& append(const char* s);
	String& operator+=(const String& str);
	String& operator+=(const char* s);

	char& operator[](int index);

	void shrink_to_fit();

	const char* print(bool show = true) const;

	// 3단계 코드--------------------
private:
	void common_func(const char* s1, bool delStorage = false, const char* s2 = "");
public:
	String operator+(const String& str);
	String operator+(const char* s);
};

// 3단계 코드--------------------
std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);