#ifndef JOINT_H_
#define JOINT_H_
#define SNAKEAMPLITUDE 3
#define MAXNUMJOINTS 20

#include <GL/glut.h>
#include <math.h>
#define PI 3.141592654

class Joint
{
	public:
		Joint(float t);		// Use 't' as position in joint chain
		virtual ~Joint();	// Currently not used, but here just in case
		void draw(float t);	// Draw the joint
	private:
		float offset;			// Angle of this joint in relation to parent joint
		float factor;			// Angle shrinking factor based on location in body
		float size;				// Size of joint based on location in body
};

#endif
