

/*
    STL Priority Queue and Class
    Basic methods: .top(), .push(), .pop(), .size()

*/



#include<iostream>
#include<queue>

//---------  Person Class------------------------------------------

class Person{

    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

    std::string name;
    int age;

    public:
    Person():name{"Unknown"}, age{0}{std::cout<<"default"<<std::endl;}

    Person(std::string n, int x): name{n}, age{x}{std::cout<<"2 args constructor"<<std::endl;}

    bool operator<(const Person& rhs) const {
        return this->age<rhs.age;

    }

    bool operator==(const Person& rhs) const{
        return this->name==rhs.name;
    }

    template <typename T>
    void display(std::priority_queue<T> pq); // definition

};




// declaration of display() function
template <typename T>
void Person::display(std::priority_queue<T> pq)
{
   while(!pq.empty())
   {
    T x = pq.top();
    std::cout<<x<<" ";
    pq.pop();
   }
   std::cout<<std::endl;
}



// definition of ostream
std::ostream& operator<<(std::ostream& os, const Person& rhs)
{
    os<<rhs.name<<":"<<rhs.age;
    return os;
}


template <typename X>
void Show(std::priority_queue<X> p)
{   
    while(!p.empty())
    {
        std::cout<<p.top()<<std::endl;
        p.pop();
    }
    std::cout<<std::endl;

}


//-------------- MAIN() --------------------------------

int main()
{
    std::cout<<"/------Test1-------"<<std::endl;

    std::priority_queue<int> p;
    Person obj1;

    for(int i:{100,1,2,4,6,200,300})
    {
        p.push(i);
    }

    obj1.display(p);

    std::cout<<"/------Test2-------"<<std::endl;

    Person obj2("david",10);
    Person obj3("lola",20);
    Person obj4("lili",30);

    // a priority queue of class Person objects
    std::priority_queue<Person> person_queue;
    
    person_queue.push(obj2);
    person_queue.push(obj3);
    person_queue.push(obj4);

    // display
    Show(person_queue);

    return 0;
}
