#pragma once
#include <string>
#include <vector>
struct MODEL
{
	std::string name;
	std::string abstract;
	std::string journal;
};

class XMLControl
{
public:
	XMLControl() {};
	~XMLControl() {};

	void XmlTest();
	void XmlInsert(std::string path);
	void GetMess(std::string path, std::vector<MODEL> *);


};

