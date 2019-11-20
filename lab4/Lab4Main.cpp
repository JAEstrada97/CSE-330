//Phillip Pascual
//4.24.2018
//Lab4Main.cpp
//Main function for CSE 330 Lab 4

#include <iostream>
#include <string>

#include "list.h"

using namespace std;

class Apple
{
private:
    string color;
public:
    Apple(): color{"red"} {}
    Apple(string col): color{col} {}
    Apple(const Apple & x): color{x.color} {}
    Apple(Apple && x): color{x.color} {}

    Apple &operator= (const Apple & x)
    {
        if(this != &x)
        {
            color = x.color;
        }
        return *this;
    }

    Apple &operator= (Apple && x)
    {
        std::swap(color,x.color);
        return *this;
    }

    bool operator==(const Apple & x)
    {
        return x.color==color;
    }

    string getColor() const
    {
        return color;
    }
};

int main()
{
    List<int> mylst;
    for (int i = 1; i <= 10; ++i)
    {
        mylst.push_back(i*i);
    }

    List<int>::iterator itr = mylst.begin();

    for (; itr != mylst.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    List<int>::iterator third = mylst.begin();
    ++third;
    ++third;

    mylst.insert(third,123);

    List<int>::iterator fifth = third;
    fifth++;
    fifth++;

    mylst.erase(fifth);

    itr = mylst.begin();
    for (; itr != mylst.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    List<int> another(mylst);

    itr = another.begin();
    for (; itr != another.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    cout << endl;
    List<Apple> myapps;

    Apple ap1;
    Apple ap2("green");
    Apple ap3(ap2);
    Apple ap4(Apple("yellow"));

    myapps.push_back(ap1);
    myapps.push_front(ap2);
    myapps.insert(myapps.begin(),ap3);
    myapps.insert(myapps.end(),ap4);

    List<Apple>::iterator aitr = myapps.begin();

    for (; aitr != myapps.end(); ++aitr)
    {
        cout << (*aitr).getColor() << " ";
    }
    cout << endl << endl;

    //-----Uncomment for Lab4 Exercise 2
    Apple green("green");
    Apple blue("blue");

    if(myapps.find(green) != myapps.end())
    {
        cout << "Green apple found" << endl;
    } else {
        cout << "There is no green apple" << endl;
    }
    if(myapps.find(blue) != myapps.end())
    {
        cout << "Blue apple found" << endl;
    } else {
        cout << "There is no blue apple" << endl << endl;
    }
    

    //-----Uncomment for Lab4 Exercise 3
    cout << "Now soFinding yellow, red, yellow, yellow apple..."
        << endl << endl;

    myapps.soFind(ap4);
    myapps.soFind(ap1);
    myapps.soFind(ap4);
    myapps.soFind(Apple("yellow"));

    aitr = myapps.begin();
    for (; aitr != myapps.end(); ++aitr)
    {
        cout << (*aitr).getColor() << endl;
    }
    cout << endl << endl;

    cout << "And soFinding green apple..." << endl << endl;

    myapps.soFind(Apple("green"));

    aitr = myapps.begin();
    for (; aitr != myapps.end(); ++aitr)
    {
        cout << (*aitr).getColor() << endl;
    }
    cout << endl << endl;
    
    return 0;
} 
