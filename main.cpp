#include <iostream>
//#include "string.h"
#include "text.h"

void step1() {
	const char* s = "apple";
	String s1(s);
	s1.print();
	std::cout << s1.length() << std::endl;
	std::cout << s1.capacity() << std::endl;
	String s2(s1);
	s2.print();
	std::cout << s1.length() << std::endl;
	std::cout << s1.capacity() << std::endl;
}

void step2() {
	String s1("aaa");
	String s2("bbb");
	s1.append("cccc");
	s2 += "ddddd";
	std::cout << s1.length() << std::endl;
	std::cout << s1.capacity() << std::endl;
	std::cout << s1.print(false) << std::endl;
	std::cout << s2.length() << std::endl;
	std::cout << s2.capacity() << std::endl;
	std::cout << s2.print(false) << std::endl;
}

void step3() {
	String s1("apple ");
	String s2("is red");
	String s3 = s1 + s2;
	std::cout << s3.print(false) << std::endl;
	std::cout << s3.length() << std::endl;
	std::cout << s3.capacity() << std::endl;
}

void step_cincout() {
	String str("apple");
	std::cin >> str;
	std::cout << str << std::endl;
}

void step4()
{
	Text t1("apple");
	Text t2("banana");
	String s1("banana");
	t1.append(s1);
	std::cout << t1 << std::endl;
	std::cout << t1.lines() << std::endl;
}

int main() {
	
	// step1();
	// step2();
	// step3();
	//step_cincout();
	step4();
	return 0;
}