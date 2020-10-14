#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


int xc = 320, yc = 240;
int radius;

void plot_point(double x, double y) {
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


void Trigonometric(int r) {
	double x = 0, y = r, cnt = 1, inc = .001;
	plot_point(x, y);
	while (cnt <= 45) {
		x = r * cos((double) cnt);
		y = sqrt(r * r - x * x);
		plot_point(x, y);
		cnt += inc;
	}
	glFlush();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);


	Trigonometric(radius);

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

	glutCreateWindow("Trigonometric method");

	Init();

	glutDisplayFunc(display);

	glutMainLoop();
}
