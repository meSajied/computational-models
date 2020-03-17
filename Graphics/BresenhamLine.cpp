#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>

void display() {

	int x0 = 5, y0 = 5, xn = 20, yn = 40, x, y;
	int dx, dy;
	int k;

	glBegin(GL_POINTS);
	glVertex2f(x0, y0);
	glEnd();

	dx = xn - x0;
	dy = yn - y0;
	k = 2 * dy - dx;
	x = x0;
	y = y0;

	for (int i = 0; i < dx - 1; i++) {

		if (k < 0)
			k = k + 2 * dy;
		else {

			k = k + 2 * dy - 2 * dx;
			y++;
		}
		x++;

		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
	}
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Bresenham Line");
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
