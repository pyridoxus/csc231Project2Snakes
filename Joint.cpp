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
