#include <cstdio>
#include <string>


/*
class c1
{
    int i = 0;
public:
    void setvalue(const int & value) { i = value; }
    int getvalue() const { return i; }
};

int main()
{
    const int i = 42;
    c1 o1; // implicit call to default constructor
    o1.setvalue(i);
    printf("value is %d\n", o1.getvalue());

    c1 o2 = o1; // implicit call to copy constructor
    printf("value is %d\n", o2.getvalue());

    o1.setvalue(0);
    o2 = o1; // implicit call to copy assignment operator
    printf("value is %d\n", o1.getvalue());
    printf("value is %d\n", o2.getvalue());

    return 0;
}
*/

const std::string unk = "unknown";
const std::string clone_prefix = "clone-";

// interface
class Animal
{
    std::string _type = "";
    std::string _name = "";
    std::string _sound = "";
public:
    Animal(); // default constructor
    Animal(const std::string & type, const std::string & name, const std::string & sound);
    Animal(const Animal &); // copy constructor
    Animal & operator=(const Animal &); // copy assignment operator
    ~Animal(); // destructor
    void print() const;
};

// implementation
Animal::Animal() : _type(unk), _name(unk), _sound(unk)
{
    puts("default constructor");
}

Animal::Animal(const std::string & type, const std::string & name, const std::string & sound) : _type(type), _name(name), _sound(sound)
{
    puts("constructor with arguments");
}

Animal::Animal(const Animal & rhs)
{
    puts("copy constructor");
    _name = clone_prefix + rhs._name;
    _type = rhs._type;
    _sound = rhs._sound;
}

Animal::~Animal()
{
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}
void Animal::print() const
{
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator=(const Animal & rhs)
{
    puts("copy assignment operator");
    if (this != &rhs)
    {
        _name = clone_prefix + rhs._name;
        _type = rhs._type;
        _sound = rhs._sound;
    }
    return *this;
}

int main()
{
    Animal a;
    a.print();

    const Animal b("goat", "bob", "baah");
    b.print();

    const Animal c = b;
    c.print();

    a = c;
    a.print();

    return 0;
}

// rules of three
// 0. if you define any of the following, define all of them
// 1. destructor
// 2. copy constructor
// 3. copy assignment operator
