#include "Serializer.hpp"


int main(void) {
	Data data1;
	data1.str = "test_subject";
	data1.i = 42;

	Data *dataptr;
	uintptr_t uintptr;

	std::cout << "data1: " << data1.str << " & " << data1.i << std::endl << std::endl;

	uintptr = Serializer::serialize(&data1);
	std::cout << "serialize &data1 in uintptr" << std::endl;
	std::cout << "data1: " << data1.str << " & " << data1.i << std::endl << std::endl;

	std::cout << "now dataptr get info from deserialize uintptr..." << std::endl;
	dataptr = Serializer::deserialize(uintptr);
	std::cout << "data1:   " << data1.str << " & " << data1.i << std::endl;
	std::cout << "dataptr: " << dataptr->str << " & " << dataptr->i << std::endl;

	std::cout << "\n LAST TEST: verifying pointer addresses..." << std::endl;
	std::cout << "Address of original data1: " << &data1 << std::endl;
	std::cout << "Address from deserialized ptr: " << dataptr << std::endl;

	if (dataptr == &data1) {
		std::cout << "\npointers are the same...." << std::endl;
	} else {
		std::cout << "\npointers are different...." << std::endl;
	}

	return (0);
}
