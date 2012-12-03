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

class Kangaroo : Hashable {
public:
	Kangaroo(){

	}
	int hashCode(){
		return 31;
	}
};


int main() {



	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	/*
	Hashable* e = new Entry<int,int>();
	Hashable* aux = new Entry<string,string>();

	if(typeid( *e ) == typeid( *aux ) )
		cout << "todo well" << endl;
	*/




	IICMap<int,int>* map = newMapObject<int,int>();
	/*
	map->put("hola", "mundo");
	delete map;
	map = newMapObject<string,string>();
	if (!map->contains("hello")) cout << "todo bien" << endl;
	*/


	//timeStamp st=new timeStamp();
	for(int i=0; i < 2000; i++)
	{
		//if(i == 2715)
			//cout << "lorea\n";
		map->put(i ,i*2-3);
	}

	if(map->contains(2))
	{
		cout << "Encontro la key" << endl;
		cout << map->find(2) << endl;
	}
	else
	{
		cout << "false uno" << endl;
	}
	cout << "Remove Key" << endl;
	map->remove(2);

	if(map->contains(2))
		{
			cout << "Encontro la key" << endl;
			cout << map->find(2) << endl;
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


