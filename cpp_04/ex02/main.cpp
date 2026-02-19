#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {



	//Animal new_animal;



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

	std::cout <<std::endl <<std::endl;

    std::cout << "-> Creating a Dog and its copy" << std::endl;
    Dog dog_a;
    dog_a.getBrain()->ideas[0] = "Original Dog Idea";

    Dog dog_b = dog_a;

    std::cout << "Original Dog's Idea: " << dog_a.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Dog's Idea:   " << dog_b.getBrain()->ideas[0] << std::endl;

    std::cout << "\n-> Changing original Dog's idea" << std::endl;
    dog_a.getBrain()->ideas[0] = "New Dog Idea";

    std::cout << "Original Dog's Idea: " << dog_a.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Dog's Idea:   " << dog_b.getBrain()->ideas[0] << std::endl;

    std::cout << "\n-> Creating a Cat and its copy" << std::endl;
    Cat cat_a;
    cat_a.getBrain()->ideas[0] = "Original Cat Idea";

    Cat cat_b = cat_a;

    std::cout << "Original Cat's Idea: " << cat_a.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Cat's Idea:   " << cat_b.getBrain()->ideas[0] << std::endl;

    std::cout << "\n-> Changing original Cat's idea" << std::endl;
    cat_a.getBrain()->ideas[0] = "New Cat Idea";

    std::cout << "Original Cat's Idea: " << cat_a.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Cat's Idea:   " << cat_b.getBrain()->ideas[0] << std::endl;



    return 0;
}
