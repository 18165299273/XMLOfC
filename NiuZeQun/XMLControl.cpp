#include "XMLControl.h"
#include <iostream>
#include "tinyxml2-master/tinyxml2.h"

using namespace tinyxml2;
void XMLControl::XmlTest()
{
	std::cout << "xml测试开始" << std::endl;

}
void XMLControl::XmlInsert(std::string path)
{
	XMLDocument doc;
	XMLDeclaration *dec = doc.NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\""); //声明汉字编码方式
	doc.InsertFirstChild(dec);
	
	//创建算法主节点
	
	std::string MesOf = "论文统计信息" ;
	XMLElement* ALgorithm = doc.NewElement(MesOf.c_str());
	doc.InsertEndChild(ALgorithm);
	for (size_t i = 0; i < 10; i++)
	{
		std::string basisautor = "作者基本信息";
		XMLElement* secondmes = doc.NewElement(basisautor.c_str());
		secondmes->SetAttribute("id", "1");

		basisautor = "姓名";
		XMLElement* secondmesd = doc.NewElement(basisautor.c_str());
		secondmesd->SetValue("name");
		secondmesd->SetText("Smith");


		XMLElement* sex = doc.NewElement(basisautor.c_str());
		sex->SetValue("abstract");
		sex->SetText("XML数据可以拷贝到任何有能力显示文本的 HTML 元素.");

		XMLElement* sexd = doc.NewElement(basisautor.c_str());
		sexd->SetValue("journal");
		sexd->SetText("《自然》");
	

		
		secondmes->InsertEndChild(secondmesd);
		secondmes->InsertEndChild(sex);
		secondmes->InsertEndChild(sexd);







		//basisautor = "年龄";
		//XMLElement* secondmesd1 = doc.NewElement(basisautor.c_str());
		//secondmesd1->SetValue("18");
		//secondmes->InsertEndChild(secondmesd1);
		ALgorithm->InsertEndChild(secondmes);
	}
	const char* path_save = path.c_str();
	doc.SaveFile(path_save, false);


}
void XMLControl::GetMess(std::string path, std::vector<MODEL> *modelofmes)
{
	const char * xmlFile = path.c_str();
	XMLDocument doc;
	if (!doc.LoadFile(xmlFile))
	{
		//doc.Print();
		for (XMLElement *elem0 = doc.FirstChildElement();elem0!=NULL; elem0= elem0->NextSiblingElement())
		{
			//std::cout << elem0->Value() << std::endl;
			std::cout << "子节点展开" << std::endl;

			for (XMLElement *elem01 = elem0->FirstChildElement(); elem01!=NULL; elem01 = elem01->NextSiblingElement())
			{
				//std::cout << elem01->Value() << std::endl;
				
				MODEL usermodel;
				for (XMLElement *elem02 = elem01->FirstChildElement(); elem02 != NULL; elem02 = elem02->NextSiblingElement())
				{
					//std::cout << elem02->Value() << std::endl;
					XMLNode *nodevalue = elem02->FirstChild();
					//std::cout << nodevalue->Value() << std::endl;
					std::string Key = elem02->Value();
					std::string Valued = nodevalue->Value();			
					if (Key=="name")
					{
						usermodel.name = Valued;
					}
					else if(Key == "abstract")
					{
						usermodel.abstract = Valued;

					}
					else if (Key == "journal")
					{

						usermodel.journal = Valued;
					}

				}

				modelofmes->push_back(usermodel);
			}

		}
	}
	else
	{
		std::cout << doc.ErrorName()<< std::endl;
		std::cout << "文件打开失败" << std::endl;
	}

	
}