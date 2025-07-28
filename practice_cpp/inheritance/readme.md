
> Inheritance in C++

# Why use inheritance?
-  reuse existing classes.
-  create new classes from existing classes.
-  create new behaviours in the inherited classes.
-  types: private, protected, public
-  abstract classes as base templates
-  single inheritance , we derive from a single base class 
-  mutiple inheritance, we derive from multiple base classes
-  protected members are inherited and are protected in the derived class  (not Is-A)
-  protected members cant be accessed using objects of base or derived class
-  public members are inherited and are public in derived class
-  derived classes do not inherit base class constructors, destructors, base class friend    functions, overloaded assignment operators.



**Class A {}** // base class, or super class or parent class
*Class B: private  A {}*
*Class C: protected A {}*
*Class D: public  A {}*

If one doesnt use the access-specifier, then by default private is used.


## Relationships

### Is-A relationship aka Public Inheritance
-  in public inheritance
-  ex: a circle is shape, an accountant is an employee

### Has-A relatioship aka Composition
-  a car has an engine
-  person has an account

