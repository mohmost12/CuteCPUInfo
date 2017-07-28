#ifndef CPUINFOPARSER_H
#define CPUINFOPARSER_H

#include "include/types.h"

///
/// \brief a singlton parser of CPU infos from /proc/cpuinfo
/// that encapsulates infos as a single instance of CPUInfoList
///
class CPUInfoParser final
{
public:
    CPUInfoParser(const CPUInfoParser&) = delete;
    CPUInfoParser(const CPUInfoParser&&) = delete;
    CPUInfoParser& operator=(const CPUInfoParser&) = delete;
    CPUInfoParser& operator=(const CPUInfoParser&&) = delete;

    ///
    /// \return a reference to a single instance of CPUInfoList managed CPUInfoParser
    ///
    static CPUInfoList& getCPUInfo();

private:
    CPUInfoParser();
    ~CPUInfoParser();
    CPUInfoList _cpuInfoList;
};

#endif // CPUINFOPARSER_H
