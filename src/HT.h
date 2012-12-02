/*
 * HT.h
 *
 *  Created on: 01-12-2012
 *      Author: Jesús
 */

#ifndef HT_H_
#define HT_H_

#include "IICMap.h"
#include <iostream>

using namespace std;

template<typename Key, typename Value>
class Entry : public Hashable{

private:
	Value _v;
	Key _k;
	Entry* _next;

public:

	Entry (Key k, Value v){
		_k = k;
		_v = v;
		_next = NULL;
	}
	Entry(){
		this = NULL; _next = NULL;
	}
	virtual ~Entry() {};
	Entry* getNext() { return _next; }
	void setNext(Entry* e){ _next = e; }
	Value getValue(){ return _v; }
	Key getKey(){ return _k; }

	// ESTE ES EL METODO QUE SE DEBE CAMBIAR PARA FUNCION DE HASH
	int hash(const char* chars, int length)
	{
		//polinomial
			unsigned int h = 0;
			const int a = 37;
			for (int i = 0; i < length; i++) {
			h = ((unsigned int)chars[i] + a*h);
			}
			return h;
	}

	int hashCode(){

		Key aux = _k;
		int length = sizeof(_k);
		const char* p = reinterpret_cast<const char*>(&aux);
		return hash(p,length);

	}

	bool operator==(const Entry &other) const {
		 return !(&this < other) && !(other < &this);
	}

	bool equalKey(Key other)
	{
		Key a=this->getKey();
		Key b=other;
		if(  !(a < b) && !(b < a) )
			return true;
		else
			return false;

	}




};



template <typename Key, typename Value> class HT: public IICMap<Key,Value> {

private:
	int _size;
	Entry<Key,Value> ** _entries;
	// espacios[i] sera 1 cuando se encuentre alguna entry en entries[i]
	int* _espacios;
	int _length;
	int hash(const char* chars, int length)
	{
			//polinomial
				unsigned int h = 0;
				const int a = 37;
				for (int i = 0; i < length; i++) {
				h = ((unsigned int)chars[i] + a*h);
				}
				return h;
	}

	int hashCode(Key k){

			int length = sizeof(k);
			const char* p = reinterpret_cast<const char*>(&k);
			return hash(p,length);

	}

	void growIfNeed(){
		double n = (double)_size/(double)_length;
		if(n > 0.75)
		{
			//es necesario incrementar el arreglo
			int l = _length*2;
			Entry<Key, Value>* aux_table[l];
			int aux_espacios[l];

			//copiar los valores
			for(int i=0; i < _length; i++)
			{
				aux_table[i] = _entries[i];
				aux_espacios[i] = _espacios[i];
			}

			delete [] _entries;
			delete[] _espacios;

			_entries = aux_table;
			_espacios = aux_espacios;
			_length = l;

		}
	}


public:

	HT(){
		_size = 0;
		_length = 1000;
		_entries = new Entry<Key, Value>*[1000];
		_espacios = new int[1000];
	}

	// ---------------------------		 	METODOS		---------------------------------------

	int size() { return _size;}

	bool empty()
	{ if(_size == 0) return true;
	else return false;}

	Value put(Key key, Value value){

		Entry<Key,Value>* n = new Entry<Key,Value>(key,value);



			int h = n->hashCode();
			h = h % _length;

			// si la posicion h de la tabla esta vacia de en h
			if(_espacios[h] != 1)
			{
				_entries[h] = n;
				_size ++;
				_espacios[h] = 1;
				growIfNeed();
				return n->getValue();

			}

			//la posicion esta ocupada, avanzar hasta encontrar un espacio
			else
			{
				Entry<Key,Value> * aux = _entries[h];
				//buscamos el espacio vacio, mientras el siguiente no sea null
				while(aux->getNext() != NULL)
					aux = aux->getNext();

				aux->setNext(n);
				_size++;
				growIfNeed();

				return aux->getValue();

			}



	}


	bool contains(Key key){


		int h = hashCode(key);
		h = h % _length;
		if(_espacios[h] == 1)
		{

			Entry<Key,Value> * aux = _entries[h];


			if(aux->equalKey(key))
				return true;

			while(aux->getNext() != NULL)
			{
				aux = aux->getNext();
				if(aux->equalKey(key))
					return true;
			}


			return false;
		}
		else
			return false;
	}

	// retorna el valor que el mapa contiene asociado con la clave, o
	// lanza una excepcion si no posee la clave
	Value find(Key key) throw(NotFoundException<Key>){


			int h = hashCode(key);
			h = h % _length;
			Entry<Key,Value>* aux;
			aux = _entries[h];


			// HAY QUE ARREGLAR LA EXCEPCION
			if(_espacios[h] != 1 && aux == NULL)
			   throw NotFoundException<Key> ("No se encuentra ", key);

			if(aux->equalKey(key))
				return aux->getValue();

			// aun no se encuentra
			while(aux->getNext() != NULL)
			{
				aux = aux->getNext();
				// si la clave es la misma devuelve el VALOR
				if(aux->equalKey(key))
					return aux->getValue();
			}

			//se busco en toda la cadena y no existe
			Value v;
			return v;

	}


	void remove(Key key)
	{
		int h = hashCode(key);
		h = h % _length;

		if(_espacios[h] != 1)
			return;

		//TODO: se puede eliminar la cadena tambien
		if(_entries[h]->equalKey(key))
		{
			// DELETE AGREGADO AHORA SI CAUSA PROBLEMAS SACALO
			delete _entries[h];

			_entries[h] = NULL;
			_espacios[h] = 0;
			_size--;
		}

		else
		{
			Entry<Key,Value>* aux = _entries[h];
			while(aux->getNext() != NULL)
			{

				// si la clave es la misma elimina la entrada
				if(aux->getNext()->equalKey(key))
				{
					// DELETE AGREGADO SI CAUSA PROBLEMAS SACALO
					delete aux->getNext();

					aux->setNext(NULL);
					_size--;
					return;
				}
				else
				{
					aux = aux->getNext();
				}

			}
		}

	}

};

template<typename Key, typename Value>
IICMap<Key, Value>* newMapObject(){
	IICMap<Key,Value>* obj = new HT<Key,Value>();
	return obj;
}






#endif /* HT_H_ */
