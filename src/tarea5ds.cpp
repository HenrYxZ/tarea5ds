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

	IICMap<timeStamp,int>* map = newMapObject<timeStamp,int>();
	/*
	map->put("hola", "mundo");
	delete map;
	map = newMapObject<string,string>();
	if (!map->contains("hello")) cout << "todo bien" << endl;
	*/


	timeStamp st=timeStamp();

	map->put(st,3);
	//cout << map->find(2);
	if(map->contains(st))
	{
		cout << "Encontro la key" << endl;
		cout << map->find(st) << endl;
	}
	else
	{
		cout << "false uno" << endl;
	}
	cout << "Remove Key" << endl;
	map->remove(st);

	if(map->contains(st))
		{
			cout << "Encontro la key" << endl;
			cout << map->find(st) << endl;
		}
		else
		{
			cout << "NO ENCUENTRA Key" << endl;
		}
	//cout << map->find(st) << endl;


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


