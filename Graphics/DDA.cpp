#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>

void display(void) {
	double x1 = 5, x2 = 20, y1 = 5, y2 = 40;
	double dy, dx, st, x, y, inX, inY;
	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy)) {
		st = abs(dx);
	} else {
		st = abs(dy);
	}

	inX = dx / st;
	inY = dy / st;

	x = x1;
	y = y1;
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();

	for (int i = 1; i <= st; i++) {
		x = x + inX;
		y = y + inY;

		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
	}

	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA Line");
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
