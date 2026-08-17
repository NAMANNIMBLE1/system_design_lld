// implementing inṭerface segregation

#include <bits/stdc++.h>
using namespace std;

class TwoDimentionShape
{
public:
    virtual double area() = 0;
};

class ThreeDimensionShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

//**************************************************** */

class square : public TwoDimentionShape{
    private:
        double side;

    public:
        square(double side){
            this->side = side;
        }

        double area() override{
            return side * side;
        }
};


class cube : public ThreeDimensionShape{
    private:
        double side;

    public:
        cube(double s){
            this->side = s;
        }

    double area() override{
        return 6*side*side;
    }

    double volume() override{
        return side*side*side;
    }
};



int main()
{
    TwoDimentionShape* Square = new square(2);
    ThreeDimensionShape* Cube = new cube(4);

    cout<<"area of square is "<<Square->area()<<endl;
    cout<<"area of cube is "<<Cube->area()<<endl;
    cout<<"volume of cube is "<<Cube->volume()<<endl;

    delete Square;
    delete Cube;
    return 0;
}