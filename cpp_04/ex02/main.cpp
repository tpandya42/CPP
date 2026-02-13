#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "TEST ROUND 1 ( FROM SUBJECT )" << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();

	std::cout << "\n\nTEST ROUND 2 ( WRONG CLASS TeSTS )" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	const WrongCat* real_wrong_cat = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_meta->makeSound();
	wrong_i->makeSound();
	real_wrong_cat->makeSound();

	std::cout << "\n\nTEST ROUND 3 (ADDitionAL TESTS)" << std::endl;
	std::cout << "\n -> COPY CONSTRUCTOR TEST" << std::endl;
	Dog basic_dog;
	{
		Dog tmp = basic_dog;
		std::cout << "tmp dog type _> " << tmp.getType() << std::endl;
		tmp.makeSound();
	}
	std::cout << std::endl;
	Cat basic_cat;
	{
		Cat tmp;
		tmp = basic_cat;
		std::cout << "tmp cat type -> " << tmp.getType() << std::endl;
		tmp.makeSound();
	}
	std::cout << "basic_dog type: " << basic_dog.getType() << std::endl;
	basic_dog.makeSound();
	std::cout << "basic_cat type: " << basic_cat.getType() << std::endl;
	basic_cat.makeSound();

	std::cout << "\n\n TEST ROUND 4 (Cleanupi )" << std::endl;
	delete (j);
	delete (i);
	delete (wrong_meta);
	delete (wrong_i);
	delete (real_wrong_cat);

	return 0;
}
