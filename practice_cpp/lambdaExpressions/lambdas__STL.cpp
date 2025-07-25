#include<iostream>
#include<algorithm>
#include<numeric>


void test1(){

    std::cout << "Test1 executed .." << std::endl;

    std::vector<int> nums{10,20,30,40,50};

    std::for_each(nums.begin(), nums.end(), [](int num){std::cout<<num << std::endl;});

}// end test1



void test2(){


    std::cout << "Test2 executed ..." << std::endl;

    struct Point
    {
        int x;
        int y;
    };

    Point p1{1,2};
    Point p2{4,3};
    Point p3{3,5};
    Point p4{3,1};

    std::vector<Point> triangle1{p1,p2,p3};
    std::vector<Point> triangle2{p2,p3,p1};
    std::vector<Point> triangle3{p1,p2,p4};



    // triangle1 and triangle2
    if(std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [](Point lhs, Point rhs){return lhs.x==rhs.x && lhs.y==rhs.y;}))
        std::cout << "equal" << std::endl;
    
    else
        std::cout << "not equal" << std::endl;
    


    // triangle1 and trianlge3

    if(std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [](Point lhs, Point rhs){

        return lhs.x==rhs.x && lhs.y==rhs.y;
    }))
    {
        std::cout << "equal" << std::endl;
    }
    else
    {
        std::cout << "not equal" << std::endl;
    }

} // end test2


// for vector 
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    os << "[";

    for(int i=0; i<vec.size(); i++)
    {
        os<<vec[i] << " ";
    }

    os << "]";

    return os;
}



void test3()
{
    std::vector<int> num{93,77,66,21,50};

    int bonus_points = 100;

    std::transform(num.begin(), num.end(), num.begin() ,[bonus_points](int score){
        return score=score+bonus_points;
    });

    for(int i:num)
    {
        std::cout << num << std::endl; // << op gets overloaded
    }


}





void test4()
{

    std::vector<int> num{0,2,4,5,6,7,9,10,12};

    // delete all even values
    num.erase(std::remove_if(num.begin(), num.end(), [](int n){
        return n%2==0;
    }), num.end());


     for(int i:num)
    {
        std::cout << num << std::endl; // << op gets overloaded
    }
}







class Person{
    friend std::ostream& operator<<(std::ostream& os, Person& rhs);
    std::string name;
    int age;

    public:
    Person() {}
    Person(std::string new_name, int new_age) {name=new_name; age=new_age;}
    Person(const Person& p)=default;

    // getters
    std::string get_name(){return name;}
    int get_age(){return age;}

    //setters
    void set_name(std::string new_name) {this->name=new_name;}
    void set_age(int new_age) {this->age=new_age;}

    ~Person(){}

};

std::ostream& operator<<(std::ostream& os,  Person& rhs)
{
    os << rhs.name << ":"  << rhs.age;
    return os;
}

void test5()
{

    Person p1("Larry", 10);
    Person p2("Moe", 20);
    Person p3("David", 30);


    std::vector<Person> person{p1,p2,p3};

    std::sort(person.begin(), person.end(), [](Person lhs, Person rhs){return lhs.get_age()>rhs.get_age();});

    for(auto i:person)
    {
        std::cout <<i << std::endl;
    }


      std::sort(person.begin(), person.end(), [](Person& lhs, Person& rhs){return lhs.get_name()>rhs.get_name();});

    std::cout<<std::endl;

    for(auto i:person)
    {
        std::cout <<i << std::endl;
    }


}









int main(){

    //test1();
    //test2();
    //test3();
    //test4();
    //test5();

    return 0;
}