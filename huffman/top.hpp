#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct pine tree;
struct pine
{
    int data;
    struct pine *up;
    struct pine *left;
    struct pine *right;
};

int tam = 0;
