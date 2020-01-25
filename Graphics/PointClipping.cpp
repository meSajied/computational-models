#include <stdio.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>

int X1, Y1, X2, Y2, n;

struct Point {
	int x;
	int y;
};
Point points[10];

struct Color {
	float r;
	float g;
	float b;
};

Color getPixelColor(int x, int y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(int x, int y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500, 500, -500, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	if (y1 == y2) {
		for (int i = x1; i <= x2; i++)
			draw_pixel(i, y1);
	} else {
		for (int i = y1; i <= y2; i++)
			draw_pixel(x1, i);
	}
}

void Check() {
	Color g = {0.0f, 1.0f, 0.0f};
	Color r = {1.0f, 0.0f, 0.0f};

	for (int i = 0; i < n; i++) {
		if (points[i].x >= X1 && points[i].x <= X2 && points[i].y >= Y1 && points[i].y <= Y2) {
			setPixelColor(points[i].x, points[i].y, g);
		} else {
			setPixelColor(points[i].x, points[i].y, r);
		}
	}
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	draw_line(X1, X2, Y1, Y1);
	draw_line(X1, X2, Y2, Y2);
	draw_line(X1, X1, Y1, Y2);
	draw_line(X2, X2, Y1, Y2);
	Check();
	glFlush();

}

int main(int argc, char **argv) {

	printf("Enter lower left coordinate of Rectangle : ");
	scanf("%d %d", &X1, &Y1);
	printf("Enter upper right coordinate of Rectangle : ");
	scanf("%d %d", &X2, &Y2);

	printf("How many points will you draw?\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%dth point is: ", i + 1);
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(800, 400);
	glutCreateWindow("Point Clipping");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
