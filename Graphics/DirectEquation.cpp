#include <GL/glut.h>
#include <GL/glu.h>

float equation(float x) {
	//y=4x+5
	return (40 * x + 5) / 100;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);

	glVertex2d(1, equation(1));
	glVertex2d(-1, equation(-1));

	glEnd();
	glutSwapBuffers();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Points & Lines");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
