#ifndef PROJECT2_H_
#define PROJECT2_H_

#include <iostream>
using namespace std;

#include "Joint.h"
#include <stdlib.h>			// Used for exit()

#define MAXNUMJOINTS 20

void draw();
void keyboard( unsigned char, int, int);
void special( int, int, int );
void printInstructions(void);
void createSnake(void);

float t = 0.0;
float tx = -10.0;
float ty = 0.0;
float tz = -20.0;

#endif
