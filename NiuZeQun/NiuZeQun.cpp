// NiuZeQun.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "XMLControl.h"

XMLControl xml;
int main()
{
    std::cout << "Hello World!\n";
	
	
	xml.XmlTest();
	xml.XmlInsert("Niuxmlfile.xml");

	std::vector<MODEL> mess;
	xml.GetMess("niuxmlfile.xml", &mess);
	std::cout<< mess .size()<<std::endl;
	int long_mes = mess.size();
	for (size_t i = 0; i < long_mes; i++)
	{
		std::cout << mess[i].name <<std::endl;
		std::cout << mess[i].abstract <<std::endl;
		std::cout << mess[i].journal <<std::endl;
	}


	getchar();
}


