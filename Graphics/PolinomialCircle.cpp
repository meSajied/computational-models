#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int xc = 320, yc = 240;
int radius;

void plot_point(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}

void polynomial(int r) {
	int x = 0, y = r, xend;
	plot_point(x, y);
	xend = r / sqrt(2);
	while (x < xend) {
		x = x + 1;
		y = sqrt(r * r - x * x);
		plot_point(x, y);
	}
	glFlush();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);


	polynomial(radius);

}

void Init() {

	glClearColor(1.0, 1.0, 1.0, 0);

	glColor3f(0.0, 0.0, 0.0);

	gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char **argv) {
	printf("Enter radius of the cricle : ");
	scanf("%d", &radius);

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);

	glutCreateWindow("2nd order polynomial");

	Init();

	glutDisplayFunc(display);

	glutMainLoop();
}