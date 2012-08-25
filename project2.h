//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
