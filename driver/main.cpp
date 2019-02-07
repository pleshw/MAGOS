#include <iostream>
#include <map>
#include <list>
#include <string>

int main( void )
{
	std::map< size_t, std::list<size_t>> mapa;
	mapa[0] = { 4, 1, 2, 3 };
	mapa[1] = { 4, 1, 2, 3 };

	std::string str;

	str = ( mapa[0] == mapa[1] ) ?"São iguais" : "Não são iguais" ;

	std::cout << std::endl << std::endl
			  << str
			  << std::endl << std::endl;
 
	return 0;
}