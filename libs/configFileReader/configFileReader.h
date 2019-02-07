#ifndef PLESHW_CONFIGFILEREADER
#define PLESHW_CONFIGFILEREADER

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

typedef std::map< std::string, std::string > configFile;

namespace configFileReader
{
	/// Returns a map with config[keyword] and value of each config
	configFile getConfigs ( std::string _src );

} //namespace

#endif //ifndef