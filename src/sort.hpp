#pragma once

#include <vector>
#include <string>
#include "shapeClasses.hpp"

using namespace std;


void printArray(const vector<Shapes*>& arr);

void quick_sort(vector<Shapes*>&  arr);
void bubble_sort(vector<Shapes*>&  arr);
void merge_sort(vector<Shapes*>& arr);
