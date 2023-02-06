#include <iostream>
#include <string>

// Animal class (base)
class Animal {
    std::string _name;
    std::string _type;
    std::string _sound;
    // private constructor prevents construction of base class
    Animal(){}
protected:
    // protected constructor for use by derived classes
    Animal ( const std::string & n, const std::string & t, const std::string & s )
    : _name(n), _type(t), _sound(s) {}
public:
    virtual void speak() const; // tell the compiler that this is a virtual function and it maybe overridden in a derived class
    const std::string & name() const { return _name; }
    const std::string & type() const { return _type; }
    const std::string & sound() const { return _sound; }
    virtual ~Animal() {} // virtual destructor to ensure that the correct destructor is called when deleting a pointer to a derived class
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
    void speak() const { Animal::speak(); puts("meow");}
};

// Pig class - derived from Animal
class Pig : public Animal {
    int _fed;
public:
    Pig( std::string n) : Animal(n, "pig", "oink"), _fed(0) {};
    int feed() { return ++_fed; }
};

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

    Animal *ap[3] = {&d, &c, &p};
    for(auto p : ap) {
        p->speak();
    }
}