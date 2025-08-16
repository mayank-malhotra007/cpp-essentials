
/*

STL Vectors and some algorithms.

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>




//---- Class -------------

class Person{
    friend std::ostream& operator<<(std::ostream&, const Person& rhs);

    std::string name;
    int age;

    public:
        Person(){std::cout<<"default"<<std::endl;}

        Person(std::string n, int a):name{n}, age{a}{}

        bool operator<(const Person& rhs) const
        {
            return this->age<rhs.age;
        }

        bool operator==(const Person& rhs) const
        {
            return (this->age==rhs.age && this->name==rhs.name);
        }

};



// this will be called in display funtions when using class objects
std::ostream& operator<<(std::ostream& os, const Person& rhs)
{
    os<<rhs.name<<":"<<rhs.age;
    return os;
}



void display(std::vector<int>& vec )
{
    
    for(int i:vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}



template <typename T>
void display2(T& vec)
{
    for(auto& i:vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}



template <typename T1>
void display3(std::vector<T1>& vec)
{
    for(auto& i:vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}


void display4(std::vector<int>& vec)
{
    std::for_each(vec.begin(), vec.end(), [](int x){std::cout<<x<<" ";});
}


//-----MAIN-----------------

int main()
{

    std::cout<<"-----------test case1---------------"<<std::endl;
    // using different display methods
    std::vector<int> x {1,2,3,4,5};
    display(x);
    display2(x);
    display3(x);
    display4(x);

    std::cout<<std::endl;
    std::cout<<"-----------test case2---------------"<<std::endl;
    // creating a vector using ()
    std::vector<int> y (5,10);  // creates a vector of 5 integers each with value 10
    display(y);

    std::cout<<std::endl;
    std::cout<<"-----------test case3---------------"<<std::endl;

    // using size, max_size, capacity, push_back, shrink_to_fit, reserve
    std::vector<int> z {10,20,30,40};
    std::cout<< z.size() <<std::endl;
    std::cout << z.max_size() << std::endl;
    std::cout << z.capacity() << std::endl;

    z.push_back(50);
    std::cout<< z.size() <<std::endl;
    std::cout << z.max_size() << std::endl;
    std::cout << z.capacity() << std::endl;

    // reduces the size to exactly fit
    z.shrink_to_fit();
    std::cout<< z.size() <<std::endl;
    std::cout << z.max_size() << std::endl;
    std::cout << z.capacity() << std::endl;

    // reserve the capacity
    z.reserve(20);
    std::cout<< z.size() <<std::endl;
    std::cout << z.max_size() << std::endl;
    std::cout << z.capacity() << std::endl;


    std::cout<<std::endl;
    std::cout<<"-----------test case4---------------"<<std::endl;
    // using emplace_back
    std::vector<Person> vec_person;

    Person p1("David", 100);
    Person p2("Lilly", 90);

    vec_person.push_back(p1);
    display2(vec_person);

    vec_person.emplace_back(p2);
    display3(vec_person);

    std::cout<<std::endl;
    std::cout<<"-----------test case5---------------"<<std::endl;

    std::vector<Person> vp {
        {"Emily",10},
        {"Lolly",20},
        {"Ioo",30}
    };

    display2(vp);
    std::cout<<std::endl;
    vp.pop_back();
    display3(vp);

    std::cout<<std::endl;
    std::cout<<"-----------test case6---------------"<<std::endl;
    // using erase
    vp.clear();
    display2(vp);

    std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
    display3(v);

    auto i = v.begin();
    while(i!=v.end())
    {
        if(*i%2==0)
        {
            i=v.erase(i); // needs a lvalue
        }
        else{
            i++;
        }
    }

    display2(v);


    std::cout<<std::endl;
    std::cout<<"-----------test case7---------------"<<std::endl;
    // using sort and swap

    std::vector<char> s1 {'b', 'c', 'd', 'a'};
    std::vector<char> s2 {'M', 'N', 'O'};

    std::sort(s1.begin(), s1.end());
    display2(s1);

    s1.swap(s2);
    display2(s1);
    display3(s2);



    std::cout<<std::endl;
    std::cout<<"-----------test case8---------------"<<std::endl;
    // using back_inserter and copy and copy_if

    std::vector<int> num1 {10,20,30,31,33,36,37};
    std::vector<int> num2 {100,200};
    std::vector<int> num3;

    std::copy(num1.begin(), num1.end(), std::back_inserter(num2));
    display(num2);

    std::copy_if(num1.begin(), num1.end(), std::back_inserter(num3), [](int x){return x%2==0; });
    display2(num3);

    std::cout<<std::endl;
    std::cout<<"-----------test case9---------------"<<std::endl;
    // using transform

    std::vector<int> v1{1,2,3,4,5};
    std::vector<int> v2{100,200,300,400,500};
    std::vector<int> v3;
    v3.resize(v1.size());
    std::vector<int> v4;

    std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int x, int y){return x+y;} );
    display2(v3);

    std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(v4), [](int x, int y){return x+y;} );
    display2(v4);

    return 0;
}