#include "Joint.h"

Joint::Joint(float t)
{
	this->offset = t;
	return;
}

Joint::~Joint()
{
}

void Joint::draw(float t)
{
	glPushMatrix();
	glRotatef( SNAKEAMPLITUDE * 10 * sin(( this->offset + t) * \
						3.141592654 / 180.0), 0, 0, 1 );
	glTranslatef( 1.0, 0, 0 );					// move away from parent
	glPushMatrix();
	glScalef( 1.0, 0.5, 1.0 );				// add scaling to matrix
	glutWireCube(1.0);
	glPopMatrix();

	return;
}
