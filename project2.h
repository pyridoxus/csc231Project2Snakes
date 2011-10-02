#ifndef PROJECT2_H_
#define PROJECT2_H_

#include <iostream>
using namespace std;

#include "Joint.h"
#include <stdlib.h>			// Used for exit()

void draw();		// Draw everything
void keyboard( unsigned char, int, int);		// Keyboard callback
void special( int, int, int );							// Special callback
void printInstructions(void);								// Print instructions in stdout
void createSnake(void);											// Initialize the snake

float t = 0.0;															// Time (parametric variable)
float tx = -10.0;														// Initial snake position
float ty = 0.0;															// Initial snake position
float tz = -20.0;														// Initial camera depth position

#endif
