#include "shapeClasses.hpp"
#include <string>
#include <cmath>

using namespace std;

Circle::Circle(double rad) : radius(rad) {}

double  Circle::getArea() const{
    return M_PI * radius * radius;
}
string Circle::getType() const{
    return "Circle";
} 


Rectangle::Rectangle(double len, double wid) : length(len), width(wid) {}

double  Rectangle::getArea() const{
    return length * width;
}

string Rectangle::getType() const {
    return "Rectangle";
} 


Triangle::Triangle(double base, double height) : base_(base), height_(height) {}

double  Triangle::getArea() const {
    return height_ * base_ * 0.5;
}
string Triangle::getType() const {
    return "Triangle";
} 
