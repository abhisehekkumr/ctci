/*
     creating hash map for user defined data types
*/

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

struct Person{
     string name;
     int age;

     Person(string name, int age){
          this->name = name;
          this->age = age;
     }

     bool operator<(const Person &obj) const {
          return this->age < obj.age;
     }

     bool operator==(const Person &obj) const {
          return this->age == obj.age;
     }

     bool operator!=(const Person &obj) const{
          return this->age != obj.age;
     }
};



int main(){
     Person p1("abhishek",23);
     Person p2("kumar",24);
     Person p3("sandeep",25);
     Person p4("arsheeep",20);
     Person p5("arsh",27);

     map<Person,int> m;
     m.insert(std :: make_pair<Person,int>(Person("abhishek",23),1));
     m.insert(std :: make_pair<Person,int>(Person("kumar",24),2));
     m.insert(std :: make_pair<Person,int>(Person("sandeep",25),3));
     m.insert(std :: make_pair<Person,int>(Person("arsheeep",20),4));
     m.insert(std :: make_pair<Person,int>(Person("arsh",27),5));

     map<Person,int> :: iterator it;
     for(it = m.begin(); it != m.end(); it++)
           std::cout << it->second << '\n';

/*
     unordered_map<Person,int> um;
     um.insert(std :: make_pair<Person,int>(Person("abhishek",23),1));
     um.insert(std :: make_pair<Person,int>(Person("kumar",24),2));
     um.insert(std :: make_pair<Person,int>(Person("sandeep",25),3));
     um.insert(std :: make_pair<Person,int>(Person("arsheeep",20),4));
     um.insert(std :: make_pair<Person,int>(Person("arsh",27),5));
*/
     //map<Person,int> :: iterator uit;
     //for(uit = um.begin(); uit != um.end(); uit++)
     //      std::cout << uit->second << '\n';

}
