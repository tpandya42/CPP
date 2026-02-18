#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    const int num_animals = 4;
    Animal* animals[num_animals];

    for (int i = 0; i < num_animals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = num_animals / 2; i < num_animals; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < num_animals; ++i) {
        delete animals[i];
    }

    std::cout << "\ntest to make sure that copy is not shallow\n" << std::endl;

    std::cout << "-> Testing Dog copy" << std::endl;
    Dog* original_dog = new Dog();
    Dog* copy_dog = new Dog(*original_dog);
    delete original_dog;
	copy_dog->makeSound();
    delete copy_dog;

    std::cout << "\n-> Testing Cat copy" << std::endl;
    Cat* original_cat = new Cat();
    Cat* copy_cat = new Cat();
    *copy_cat = *original_cat;
    delete original_cat;
    copy_cat->makeSound();
    delete copy_cat;

    return 0;
}
