#ifndef JOINT_H_
#define JOINT_H_
#define SNAKEAMPLITUDE 1
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
};

#endif
