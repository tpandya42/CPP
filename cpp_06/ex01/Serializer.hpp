#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct Data 
{
	int 	i;
	std::string str;
} Data;

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const & other);
		~Serializer(void);
		Serializer & operator=(Serializer const & other);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif
