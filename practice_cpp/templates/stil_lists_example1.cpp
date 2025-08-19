
#include<iostream>
#include<list>
#include<algorithm>


class Person {

    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

    std::string name;
    int age;
    
    public:
        
        Person(): name{"None"}, age{0}{std::cout<<"default"<<std::endl;}

        Person(std::string name, int age): name(name), age(age) {std::cout<<"2 arg constructor"<<std::endl;}
        
        // copy constructor
        Person(const Person& rhs)
        {
          std::cout<<"copy constructor"<<std::endl;
          age=rhs.age;
          name=rhs.name;

        }

        // move constructor
        Person(Person&& rhs) noexcept: name(std::move(rhs.name)), age(rhs.age)
        {
            std::cout<<"move constructor"<<std::endl;
            // release 
            rhs.age=0;
            rhs.name=" ";
        }


        // copy assignment 
        Person& operator=(const Person& rhs)
        {   
            std::cout<<"copy assignment"<<std::endl;
            name=rhs.name;
            age=rhs.age;
            return *this;
        }
        
        // move assignment
        Person& operator=(Person&& rhs) noexcept
        {
            std::cout<<"move assignment"<<std::endl;
            age=std::move(rhs.age);
            name=std::move(rhs.name);
            rhs.name=" ";
            rhs.age=0;   

            return *this;
        }

        // overloading bool operator==
        bool operator==(const Person& rhs) const
        {
            return (this->age == rhs.age && this->name == rhs.name);
        }


        // overloading bool operator<
        bool operator<(const Person& rhs) const
        {
            return this->age<rhs.age;
        }

        // setter method
        void set_Name(std::pair<std::string, int> P)
        {
            name = P.first;
            age = P.second;
        }

        ~Person(){std::cout<<"destructor"<<std::endl;}


};



// overloaded insertion operator<<
std::ostream& operator<<(std::ostream& os, const Person& rhs)
{
    os<<rhs.name<<":"<<rhs.age<<std::endl;
    return os;
}


// generic display
template <std::ranges::range T>
void display(const T& obj)
{

    for(auto& i:obj)
    {
        std::cout<<i<<" "; // for a class object , this will call the operator<< above!
    }
    std::cout<<std::endl;
}





int main()
{
    
    std::list<int> l1 {1,2,3,4,5};
    std::cout<<"list1: ";
    display(l1);

    // using initializer
    std::list<int> l2(5,10);
    std::cout<<"list2: ";
    display(l2);

    std::list<int> l3;
   



    // using std::pair
    std::pair<std::string, int> p1 ("lola", 20);
    std::cout<<p1.first<<":"<<p1.second<<std::endl;

    Person obj1;
    obj1.set_Name(p1); // passing a std::pair

    Person obj2;
    obj2=obj1; // assignment constructor call

    Person obj3(obj2); // copy constructor

    Person obj4(std::move(obj3)); // move contructor

    Person obj5;
    obj5=std::move(obj4);  // move assignment

   

    //--- List operations --------

    // transform: adding 2 lists into a third
    std::transform(l1.begin(), l1.end(), l2.begin(), std::back_inserter(l3), [](int x, int y){return x+y;});
    std::cout<<"adding two lists:";
    display(l3);

    // find and insert

    auto it = std::find(l1.begin(), l1.end(), 3);
    l1.insert(it,10); 
    

    // for_each
    std::cout<<"for_each:";
    std::for_each(l1.begin(),l1.end(), [](int x){std::cout<<x<<" ";} );
    std::cout<<std::endl;



    // copy_if e.g:1
    std::list<int> l4;
    std::copy_if(l1.begin(), l1.end(), std::back_inserter(l4), [](int x){return x%2==0; }); // shall return a bool in copy_if
    std::cout<<"after copy_if:";
    display(l4);
    std::cout<<std::endl;


    // copy_if e.g:2

    std::list<int> l5;
    l5.resize(l1.size());
    std::cout<<"l5: ";
    display(l5);

    std::copy_if(l1.begin(), l1.end(), l5.begin(), [](int x){return x%2==0; }); // shall return a bool in copy_if
    std::cout<<"after copy_if:";
    display(l5);
    std::cout<<"after erasing 0s: ";
    //l5.remove(0); // .remove() optimized for lists
    //display(l5);


    /* removes 0's from the list l5
    auto i = l5.begin();

    while(i!=l5.end())
    {
        if(*i==0)
        {
            i=erase(i);
        }
        i++;
    }

    */


    // OR
    l5.erase(std::remove(l5.begin(), l5.end(), 0),l5.end());
    display(l5);
    
    
    //----- Class operations -------

    Person p_obj1("david", 30);
    Person p_obj2("moe", 40);
    Person p_obj3("claire", 50);

    // creating a list of Person objects
    std::list<Person> lP {p_obj1, p_obj2, p_obj3};
    std::cout<<"printing list of class objects: "<<std::endl;
    display(lP);

    Person p_obj4("mimi", 100);
    std::cout<<std::endl;

    // emplace_back
    lP.emplace_back(p_obj4); // uses a copy constructor
    display(lP);


    return 0;
}