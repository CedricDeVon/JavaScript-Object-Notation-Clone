
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <typeinfo>
#include <memory>
#include <fstream>
#include <sstream>

#include "../JSONC/genericObject.h"
#include "../JSONC/genericArray.h"


/*
* ISSUES
* - Renamings /
* - Testings
* - Performance Optimization
* - Structure Optimization
* - Return Types vs Exception Throws
*/

void AB_demo(std::unique_ptr<GenericObject>& a)
{
    GenericObject b{}, c{};
    
    c.set<std::string>("a", "C");
    /*c.set<int>("b", 1);
    c.set<double>("c", 1.2345);
    c.set<bool>("d", true);
    c.set<nullptr_t>("e", nullptr);*/

    b.set<GenericObject>("a", b);
    std::string m = "B";
    b.set<std::string>("b", m);
    
    a->set<GenericObject>("a", b);

    //a->clear();
    //a->remove("a");

    std::cout << a->get<GenericObject>("a").get<std::string>("b") << '\n';
    //std::cout << '\n';
}

int main()
{
    std::unique_ptr<GenericObject> a = std::make_unique<GenericObject>(GenericObject{});

    //AB_demo(a);
  
    return 0;
}
