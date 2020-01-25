#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <GL/glut.h>

int X1, Y1, X2, Y2;

struct Color {
	float r;
	float g;
	float b;
};

//Getter for Pixel Color
Color getPixelColor(int x, int y) {
	Color clr;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &clr);
	return clr;
}

//Setter for Pixel Color
void setPixelColor(int x, int y, Color clr) {
	glColor3f(clr.r, clr.g, clr.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

//Four directional Flood-fill
void floodFill_4dir(int x, int y, Color currentColor, Color newColor) {
	Color clr;
	clr = getPixelColor(x, y);

	//Setting new color if current pixel color is white
	if (clr.r == currentColor.r && clr.g == currentColor.g && clr.b == currentColor.b) {
		setPixelColor(x, y, newColor);
		floodFill_4dir(x + 1, y, currentColor, newColor);
		floodFill_4dir(x, y + 1, currentColor, newColor);
		floodFill_4dir(x - 1, y, currentColor, newColor);
		floodFill_4dir(x, y - 1, currentColor, newColor);
	}
	return;
}

void floodfill() {
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color currentColor = {1.0f, 1.0f, 1.0f};

	floodFill_4dir(X1 + 1, Y1 + 1, currentColor, newColor);
}

//Drawing a pixel
void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

//Drawing a line
void draw_line(int x1, int x2, int y1, int y2) {
	if (y1 - y2 == 0) {
		for (int i = x1; i <= x2; i++)
			draw_pixel(i, y1);
	} else {
		for (int i = y1; i <= y2; i++)
			draw_pixel(x1, i);
	}
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	draw_line(X1, X2, Y1, Y1);
	draw_line(X1, X2, Y2, Y2);
	draw_line(X1, X1, Y1, Y2);
	draw_line(X2, X2, Y1, Y2);
	glFlush();
	floodfill();
}

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {

	printf("What's the lower left coordinate of the rectangle? : ");
	scanf("%d %d", &X1, &Y1);
	printf("What's the upper right coordinate of the rectangle? : ");
	scanf("%d %d", &X2, &Y2);

	//Initializing
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Flood-fill the rectangle using Bresenham's line drawing algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
