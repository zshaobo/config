#include "config.h"
#include <iostream>
#include <string.h>
using namespace std;


bool IsSpace(char c)
{
	if (' ' == c || '\t' == c)
		return true;
	return false;
}


bool IsCommentChar(char c)
{
	switch(c) {
		case COMMENT_CHAR:
			return true;
		default:
			return false;
	}
}



bool AnalyseLine(const string & line, string & key, string & value)
{
	if (line.empty())
		return false;
	string::size_type   pos = string::npos;
	if ((pos = line.find(COMMENT_CHAR)) != string::npos) {
		if (0 == pos) {  // 行的第一个字符就是注释字符
			return false;
		}
	}

	if ((pos = line.find('=')) == string::npos)
		return false;  // 没有=号
	if(strstr(line.data(),key.data())){
		const char *p=strstr(line.data(),"=");
		if(p){
			++p;
			value=p;
			
			}

	}
//	printf("key.data _ %s\n",key.data());
	printf("value.data _ %s\n",value.data());
	return true;
}
Config :: Config(const string filename) : m_filename(filename)
{
	///每次调用构造函数的时候就打开文件
	m_infile.open(m_filename.c_str());
}
Config :: Config(const Config& c) : m_filename(c.m_filename)
{

}
Config :: ~Config()
{
	///析构函数时候关闭文件
	if(m_infile)
	{
		m_infile.close();
	}
}
bool Config::ReadConfig(const string& key, string& keyvalue)
{


	if (!m_infile) {
		return false;
	}
	string line, key_,value;
	key_ = key;
	while (getline(m_infile, line)) {
		if (AnalyseLine(line, key_, value)) {
			keyvalue = value;
	printf("keyvalue =%s\n",keyvalue.data());
			return true;
		}
	}
	return false;


}
