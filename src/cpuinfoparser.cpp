#include "include/cpuinfoparser.h"
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

CPUInfoList& CPUInfoParser::getCPUInfo()
{
    //a singleton instance of CPUInfoParser is lazily initialized
    //which in turn will populate a single instance of CPUInfoList
    static CPUInfoParser parser;

    return parser._cpuInfoList;
}

CPUInfoParser::CPUInfoParser()
{
    //this constructor will parse /proc/cpuinfo
    //and populate information about all CPUS in _cpuInfoList

    CPUInfo cpuInfo;
    
    ifstream fs("/proc/cpuinfo");
    if(fs.is_open())
    {
        //regular expression for parsing name and value from a single cpu information delimited by ':'
        //and trimming leading and trailing whitespaces
        //e.g "bogomips	: 5183.99" --> name "bogomips" , value "5183.99"
        regex pattern{"(\\w.*\\w)\\s*:\\s?(\\w?.*\\w?)\\s*"};

        smatch matches;
        string line;

        while(getline(fs, line))
        {
			if(line == "")
			{
                _cpuInfoList.push_back(cpuInfo);
                cpuInfo.clear();
			}
			else
			{
				if(regex_match(line, matches, pattern))
				{	
                    cpuInfo.append(new CPUInfoElement{matches[1], matches[2]});
                }
			}
        }

        fs.close();
    }
}

CPUInfoParser::~CPUInfoParser()
{
    //release the CPUInfoElement instances allocated in the constructor
    for(auto& cpuInfo: _cpuInfoList)
    {
        for(auto& ptrCPUInfoElement: cpuInfo)
        {
            delete ptrCPUInfoElement;
            ptrCPUInfoElement = nullptr;
        }
    }
}
