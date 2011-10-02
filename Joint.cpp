#include "Joint.h"

Joint::Joint(float t)
{
	this->offset = t * 40;
	this->factor = (MAXNUMJOINTS - t) / MAXNUMJOINTS;
	this->size = (t + 1.0) / MAXNUMJOINTS;
	if(this->size > 0.5) this->size = 0.5;
	return;
}

Joint::~Joint()
{
}

void Joint::draw(float t)
{
	glPushMatrix();
	glTranslatef( 0.5, 0, 0 );					// move pivot point
	glRotatef( SNAKEAMPLITUDE * 10 * this-> factor * sin((this->offset + t) * \
						3.141592654 / 180.0), 0, 0, 1 );
	glTranslatef( 0.5, 0, 0 );					// move to origin
	glPushMatrix();
	glScalef( 1.0, this->size, this->size );				// add scaling to matrix
	glutWireCube(1.0);
	glPopMatrix();

	return;
}
