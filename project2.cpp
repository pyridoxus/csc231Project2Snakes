#include "project2.h"

Joint *joints[MAXNUMJOINTS];

int main( int argc, char *argv[] )
{
	// Print menu
	printInstructions();

  // Initialize window system
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize( 800, 600 );
  glutCreateWindow( "Snake" );

  // Projection
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 45.0, 1.333, 0.01, 10000.0 );

	// View transformation (move scene away from camera at origin)
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glTranslatef( 0, 0, tz );

  // Hidden surface z-buffering
  glEnable( GL_DEPTH_TEST );

  // Callbacks
  glutDisplayFunc( draw );
  glutKeyboardFunc( keyboard );
	glutSpecialFunc( special );

  // Create all satellites
  createSnake();

	// Main loop
	glColor3f( 1.0, 1.0, 1.0 );
  glutMainLoop();
  return 0;
}

// Display callback
void draw()
{
	// Clear the screen
	glClearColor( 0.0, 0.0, 0.0, 1.0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Save view translation matrix
	glPushMatrix();
	// Next two lines attempt to keep the "head" moving and rotating in such a
	// way that the rest of the "body" seems to move across the ground correctly.
	glTranslatef( tx, ty - SNAKEAMPLITUDE * cos((t) * 3.141592654 / 180.0), 0.0 );
	glRotatef( SNAKEAMPLITUDE * 10 * cos(t * 3.141592654 / 180.0 + 3.0 * \
							3.141592654 / 4.0), 0, 0, 1);
	// Draw entire system
	for(int n = 0; n < MAXNUMJOINTS; n++)
		if(joints[n]) joints[n]->draw(t);
	for(int n = 0; n < MAXNUMJOINTS; n++)
		if(joints[n]) glPopMatrix();	// Remove the snake hierarchy

	// Restore view translation
	glPopMatrix();

	// Execute draw commands
	glutSwapBuffers();
	return;
}

// Keyboard callback
void keyboard( unsigned char key, int x, int y )
{
  switch( key )
    {
			case 'a':
				t += 10;
				break;
			case 'z':
				t -= 10;
				break;
			case 's':
				t += 2;
				break;
			case 'x':
				t -= 2;
				break;
			case '+':
				// View transformation (move scene away from camera at origin)
			  glMatrixMode( GL_MODELVIEW );
			  glLoadIdentity();
			  tz *= 0.95;
			  glTranslatef( 0, 0, tz );
			  break;
			case '-':
				// View transformation (move scene away from camera at origin)
			  glMatrixMode( GL_MODELVIEW );
			  glLoadIdentity();
			  tz /= 0.95;
			  glTranslatef( 0, 0, tz );
			  break;
			case 'q':
				for(int n = 0; n < MAXNUMJOINTS; n++) delete joints[n];
				exit(1);
				break;
    }

  // Redraw the scene
  glutPostRedisplay();
}

void printInstructions()
{
	cout << "Keyboard commands" << endl;
	cout << "-----------------" << endl;
	cout << "a - advance time quickly" << endl;
	cout << "z - reverse time quickly" << endl;
	cout << "s - advance time slowly" << endl;
	cout << "x - reverse time slowly" << endl;
	cout << "+ - move camera closer" << endl;
	cout << "- - move camera farther away" << endl;
	cout << "move system with arrow keys" << endl;
	cout << "q - exit" << endl;
	return;
}

// Special function callback
void special( int key, int x, int y )
{
  // Process entries */
  switch( key )
  {
		case GLUT_KEY_RIGHT:
			tx += 0.1;
			break;
		case GLUT_KEY_LEFT:
			tx -= 0.1;
			break;
		case GLUT_KEY_UP:
			ty += 0.1;
			break;
		case GLUT_KEY_DOWN:
			ty -= 0.1;
			break;
	}

	// Redraw the scene
  glutPostRedisplay();
}

void createSnake(void)
{
	// Create snake
	for(int n = 0; n < MAXNUMJOINTS; n++)
		joints[n] = new Joint(n);
	return;
}

