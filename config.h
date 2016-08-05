#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <fstream>

#define COMMENT_CHAR '#'
#define CONFIG_NAME "test.cfg"
/**
* @brief Config类
* 读取配置文件的操作
*/
class Config
{
public:
Config(const std::string  filename);

Config(const Config& c);

~Config();

bool ReadConfig(const std::string& key, std::string& keyvalue);

private:
///文件名称
    std::string m_filename; 


    std::ifstream m_infile;
};

#endif



