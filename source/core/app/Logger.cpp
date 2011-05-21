

#include "Logger.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "string/FilenameUtils.h"

using namespace boost::posix_time;
using namespace boost::gregorian;

//------------------------------------------------------------------------------

Logger::Logger(const std::string& sLogPath)
{
   std::string sPath = FilenameUtils::DelimitPath(sLogPath);
   ptime now = microsec_clock::local_time();
   std::string timestring = to_iso_string(now);
   sPath = sPath + timestring + ".log";

   out.open(sPath);
}

//------------------------------------------------------------------------------

Logger::~Logger()
{
   out.close();
}

//------------------------------------------------------------------------------

void Logger::Warn(const std::string& warning)
{
 ptime now = second_clock::local_time();
 std::string sNow = "[" + to_simple_string(now) + "] WARNING: ";

 out << sNow << warning.c_str() << "\n";

}

//------------------------------------------------------------------------------

void Logger::Info(const std::string& info)
{
 ptime now = second_clock::local_time();
 std::string sNow = "[" + to_simple_string(now) + "]: ";

 out << sNow << info.c_str() << "\n";
}

//------------------------------------------------------------------------------

void Logger::Error(const std::string& error)
{
 ptime now = second_clock::local_time();
 std::string sNow = "[" + to_simple_string(now) + "] ERROR: ";

 out << sNow << error.c_str() << "\n";
}

//------------------------------------------------------------------------------