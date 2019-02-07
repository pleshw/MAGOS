#include <iostream>
#include "../include/magos.h"

int main( void )
{
	
	configFile setup = configFileReader::getConfigs("setup.txt");

	MAGOS magos { setup };

	magos.build();

	magos.solve();

	return 0;
}