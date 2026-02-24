#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename X>
void 	iter(T *_arrayAddress, const int size, void(*func)(X))
{
	for (int i = 0; i < size; i++)
	{
		func(_arrayAddress[i]);
	}
}

#endif
