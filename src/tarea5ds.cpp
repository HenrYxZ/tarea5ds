//============================================================================
// Name        : tarea5ds.cpp
// Author      : HenrY
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HT.h"
#include "IICMap.h"
#include <string>


using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	IICMap<const char*,int>* map = newMapObject<const char*,int>();
	/*
	map->put("hola", "mundo");
	delete map;
	map = newMapObject<string,string>();
	if (!map->contains("hello")) cout << "todo bien" << endl;
	*/


	map->put("alfa",3);
	//cout << map->find(2);
	if(map->contains("alfa"))
	{
		cout << "Encontro la key" << endl;
		cout << map->find("alfa") << endl;
	}
	else
	{
		cout << "false uno" << endl;
	}

	/*

	map->put("p","f");
	if(map->contains("a"))
	{
		cout << "Encontro la key" << endl;
		cout << map->find("a") << endl;
	}
	else
	{
		cout << "false dos" << endl;
	}


	map->remove("a");
	if(map->contains("a"))
	{
		cout << "Encontro la key" << endl;
		cout << map->find("a") << endl;
	}
	else
	{
		cout << "false tres" << endl;
	}
 */


	delete map;
	return 0;
}
