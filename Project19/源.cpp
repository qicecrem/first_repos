#include<iostream>
#include <string>
using namespace std;

class Printable
{
public:
    virtual ~Printable() {} // Add a virtual destructor
    virtual string GetClassName() = 0;
};

class A : public Printable
{
public:
    string GetClassName() override { return "a"; }
};

class Entity : public Printable
{
public:
    virtual string GetName() = 0;
    string GetClassName() override { return "Entity"; }
};

class Player : public Entity // Inherits directly from Entity
{
private:
    string m_Name;
public:
    Player(const string& name) : m_Name(name) {}
    string GetName() override { return m_Name; }
    string GetClassName() override { return "Player"; } // Override the function with correct signature
};

void Print(Printable* op)
{
    cout << op->GetClassName() << endl;
}

int main()
{
    Entity* e = new Entity();
    Print(e);
    Player* p = new Player("chero");
    Print(p);
    delete e; // Don't forget to delete dynamically allocated memory
    delete p;
    cin.get();
}