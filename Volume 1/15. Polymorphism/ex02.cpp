/**
Modify Exercise 1 so draw( ) is a pure virtual function. Try creating
an object of type Shape. Try to call the pure virtual function inside
the constructor and see what happens. Leaving it as a pure virtual,
give draw( ) a definition.

Ex 1:
Create a simple "shape" hierarchy: a base class called Shape and
derived classes called Circle, Square, and Triangle. In the base
class, make a virtual function called draw( ), and override this
in the derived classes. Make an array of pointers to Shape objects
that you create on the heap (and thus perform upcasting of the
pointers), and call draw( ) through the base-class pointers, to
verify the behavior of the virtual function.
If your debugger supports it, single-step through the code.
**/

#include <iostream>

using namespace std;

class Shape {
public:
    //Shape() { draw(); }
    virtual void draw() = 0;
    virtual ~Shape() { cout << "~Shape()" << endl; }
};

//void Shape::draw() { cout << "Shape::draw()" << endl; }

class Circle : public Shape {
public:
    void draw() { cout << "Circle::draw()" << endl; }
    ~Circle() { cout << "~Circle()" << endl; }
};

class Square : public Shape {
public:
    void draw() { cout << "Square::draw()" << endl; }
    ~Square() { cout << "~Square()" << endl; }
};

class Triangle : public Shape {
public:
    void draw() { cout << "Triangle::draw()" << endl; }
    ~Triangle() { cout << "~Triangle()" << endl; }
};

int main() {

    //Shape object;
    //!error: cannot declare variable 'object' to be of abstract type 'Shape'|

    Shape* s[] = {new Circle, new Square, new Triangle};

    for (size_t i = 0; i < sizeof(s) / sizeof(*s); i++)
        s[i]->draw();

    for (size_t i = 0; i < sizeof(s) / sizeof(*s); i++) {
        delete s[i];
        s[i] = 0;
    }

return 0;
}
