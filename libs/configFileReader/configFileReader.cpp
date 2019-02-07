#include "configFileReader.h"

namespace configFileReader{
configFile getConfigs ( std::string _src )
{
	configFile reader; //get the keys and values

	std::ifstream inputFile { _src }; //open the file [IT NEEDS TO EXIST]

	std::stringstream fileStream; //file stream controller
	fileStream << inputFile.rdbuf(); //get the file buffer

	std::string line; //get the line
	std::string tmpKey; //get the key in the line
	std::string tmpValue; //get the value in the line
	while( std::getline(fileStream, line) ) //get the line
	{
		std::stringstream lineStream; // line stream controller	
		lineStream << line;

		if( std::getline(lineStream, tmpKey, ':') )//get the key ( everything that is before ':' )
		{ 
			lineStream >> tmpValue;
			reader[tmpKey] = tmpValue; 
		}
	}
	inputFile.close();
	return reader;
}
}