#pragma once
#include <iostream>
using namespace std;

class String {
	// 1�ܰ� �ڵ�--------------------
	//friend std::ostream& operator<<(std::ostream& os, const String& str);
//private:
protected:
	char* str_;
	int len_; // ���ڿ��� ����
	int capa_; // ���� �迭�� ũ��

public:
	String();
	String(const char* s);	// "...." �Ǵ� char[]
	String(const String& str);	// string ��ü ���� �Է�
	virtual ~String();

	//void print();
	int length();
	int size();
	int capacity();


	// 2�ܰ� �ڵ�--------------------
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

	// 3�ܰ� �ڵ�--------------------
private:
	void common_func(const char* s1, bool delStorage = false, const char* s2 = "");
public:
	String operator+(const String& str);
	String operator+(const char* s);
};

// 3�ܰ� �ڵ�--------------------
std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);