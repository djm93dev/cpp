#include <iostream>
#include <string>

// Animal class (base)
class Animal {
    std::string _name;
    std::string _type;
    std::string _sound;
    // private constructor prevents construction of base class
    Animal(){}
    Animal ( const std::string & n, const std::string & t, const std::string & s )
    : _name(n), _type(t), _sound(s) {}

    friend const std::string & get_animal_name(const Animal &); // get_animal_name() is a friend of Animal (so it can access the private members of Animal)
    friend class Dog; // Dog is a friend of Animal (so it can access the private members of Animal)
    friend class Cat; // Cat is a friend of Animal (so it can access the private members of Animal)
    friend class Pig; // Pig is a friend of Animal (so it can access the private members of Animal)

    // generally, you should avoid using friend classes and use protected members instead

public:
    void speak() const;
    const std::string & name() const { return _name; }
    const std::string & type() const { return _type; }
    const std::string & sound() const { return _sound; }
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
    int _walked;
public:
    Dog( std::string n ) : Animal(n, "dog", "woof"), _walked(0) {};
    int walk() { return ++_walked; }
};

// Cat class - derived from Animal
class Cat : public Animal {
    int _petted;
public:
    Cat( std::string n ) : Animal(n, "cat", "meow"), _petted(0) {};
    int pet() { return ++_petted; }
};

// Pig class - derived from Animal
class Pig : public Animal {
    int _fed;
public:
    Pig( std::string n) : Animal(n, "pig", "oink"), _fed(0) {};
    int feed() { return ++_fed; }
};

const std::string & get_animal_name(const Animal & a) {
    return a._name;
}

int main() {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    
    d.speak();
    c.speak();
    p.speak();
    
    std::cout << "the " << d.type() << " has been walked " << d.walk() << " times" << std::endl;
    std::cout << "the " << c.type() << " has been petted " << c.pet() << " times" << std::endl;
    std::cout << "the " << p.type() << " has been fed " << p.feed() << " times" << std::endl;

    std::cout << "the " << d.type() << " is named " << get_animal_name(d) << std::endl; // has access to the private members of Animal but undermines encapsulation
}