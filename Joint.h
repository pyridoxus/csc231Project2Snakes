#ifndef JOINT_H_
#define JOINT_H_
#define SNAKEAMPLITUDE 3
#define MAXNUMJOINTS 20

#include <GL/glut.h>
#include <math.h>

class Joint
{
	public:
		Joint(float t);
		virtual ~Joint();
		void draw(float t);
	private:
		float offset;			// Angle of this joint in relation to parent joint
		float factor;			// Angle shrinking factor based on location in body
		float size;				// Size of joint based on location in body
};

#endif
