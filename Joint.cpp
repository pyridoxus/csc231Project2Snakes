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
#include "Joint.h"

Joint::Joint(float t)
{
	// Each joint has an angular offset dependent upon its position in the chain
	// of the body. The parameter 't' is used to determine the angular offset.
	this->offset = t * 40;			// Joint angular offset.

	// To somewhat simulate the angular differences between the head portion and
	// tail portion of the snake, the angular factor is added to accentuate the
	// whipping of the tail and to subdue the motion of the head.
	this->factor = (MAXNUMJOINTS - t) / MAXNUMJOINTS;

	// The 'size' member helps to define a more snake-like appearance.
	this->size = (t + 1.0) / MAXNUMJOINTS;
	if(this->size > 0.5) this->size = 0.5;	// Restrict size change
	return;
}

Joint::~Joint()
{
}

void Joint::draw(float t)
{
	glPushMatrix();
	glTranslatef( 0.5, 0, 0 );					// move pivot point

	// SNAKEAMPLITUDE was added to experiment with the amplitude of the wave.
	glRotatef( SNAKEAMPLITUDE * 10 * this-> factor * sin((this->offset + t) * \
						PI / 180.0), 0, 0, 1 );
	glTranslatef( 0.5, 0, 0 );					// move to origin of joint
	glPushMatrix();											// Add scaling due to joint position
	glScalef( 1.0, this->size, this->size );				// add scaling to matrix
	glutWireCube(1.0);
	glPopMatrix();											// Disregard this particular scaling

	return;
}
