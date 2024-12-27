#pragma once

#include <string>

using namespace std;

class Shapes
{
public:
    virtual ~Shapes() = default;
    virtual double getArea() const = 0;
    virtual string getType() const = 0;
};

class Circle : public Shapes{
public:
    Circle(double rad);

    double  getArea() const override;

    string getType() const override;

private:
    double radius;
};

class Rectangle : public Shapes{
public:
    Rectangle(double len, double wid);

    double  getArea() const override;

    string getType() const override;
private:
    double length, width;
};

class Triangle : public Shapes{
public:
    Triangle(double base, double height);

    double  getArea() const override;

    string getType() const override;
private:
    double base_, height_;
};
