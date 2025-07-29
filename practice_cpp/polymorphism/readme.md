# Polymorphism

Polymorphism means many forms, allows objects to be treated as instances of base class, even 
though they are instances of derived class.

## Types of Polymorphism in C++

1. Static binding: objects are binded at compile time: function overloading, operator overloading

2. Dyanamic binding: objects are binded at run time: function overriding. Uses virtual functions and inheritance.

## Need

- brings advantages of inheritance and overloading together
- make destructor virtual in base class if virtual functions are used
- make use of virtual keyword to make functions virtual 
- override can be used when using virtual functions in base class, its not necessary but helps catch mispelled function names, mismatched signatures
- final specfier: at class level prevents the class from being derived from, at function level: function cant be overriden
- final: prevents inheritance, prevents overriding
- abstract: class must be inherited and completed, uses pure virtual functions
