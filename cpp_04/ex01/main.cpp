#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    const int num_animals = 4;
    Animal* animals[num_animals];

    // Create half Dogs and half Cats
    for (int i = 0; i < num_animals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = num_animals / 2; i < num_animals; ++i) {
        animals[i] = new Cat();
    }

    // Delete all animals
    for (int i = 0; i < num_animals; ++i) {
        delete animals[i];
    }

    std::cout << "\n--- Deep Copy Test ---\n" << std::endl;

    // Test deep copy for Dog
    std::cout << "-> Testing Dog copy" << std::endl;
    Dog* original_dog = new Dog();
    Dog* copy_dog = new Dog(*original_dog);
    delete original_dog; // Delete original, copy should still be fine
    copy_dog->makeSound();
    delete copy_dog;

    std::cout << "\n-> Testing Cat copy" << std::endl;
    // Test deep copy for Cat
    Cat* original_cat = new Cat();
    Cat* copy_cat = new Cat();
    *copy_cat = *original_cat;
    delete original_cat; // Delete original, copy should still be fine
    copy_cat->makeSound();
    delete copy_cat;

    return 0;
}