#ifndef IICMAP_H_
#define IICMAP_H_

#include <stdexcept>

using namespace std;

template<typename E>
class NotFoundException;

template<typename Key, typename Value>
class IICMap {
public:
	// destructor default. No hace nada
	virtual ~IICMap() {}
	// entrega el numero de elementos en el mapa
	virtual int size() = 0;
	// retorna true si y solo si el mapa esta vacio
	virtual bool empty() = 0;
	// almacena el valor value asociandolo a la clave key y retorna el
	// elemento que anteriormente estaba asociado con la clave o el mismo 
	// objeto value si no habia ninguno
	virtual Value put(Key key, Value value) = 0;
	// retorna true si el mapa contiene algun valor asociado con la clave
	virtual bool contains(Key key) = 0;
	// retorna el valor que el mapa contiene asociado con la clave, o 
	// lanza una excepcion si no posee la clave
	virtual Value find(Key key) throw(NotFoundException<Key>) = 0;
	// si posee algun valor asociado con la clave key, elimina el par
	virtual void remove(Key key) = 0;
	
	//virtual std::auto_ptr< Iterator<Key> > keyIterator() = 0;
};

template<typename Key, typename Value>
IICMap<Key, Value>* newMapObject();


class Hashable {
public:
	virtual int hashCode()  = 0;
};

template<typename E>
class NotFoundException: public std::runtime_error {
private:
	E searchingElement;
public:
	NotFoundException(const char * reason, E searching) : std::runtime_error(std::string(reason)), searchingElement(searching) { }
	NotFoundException(std::string reason, E searching) : std::runtime_error(reason), searchingElement(searching) { }
	virtual ~NotFoundException() throw () {}
	E getNotFoundElement() const { return searchingElement; }
};


#endif
