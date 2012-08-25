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
