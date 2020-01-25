#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int x = 100, y = 250;
int r;


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
void setPixelColor(int xx, int yy, Color clr) {
	glColor3f(clr.r, clr.g, clr.b);
	glBegin(GL_POINTS);
	glVertex2i(xx, yy);
	glEnd();
	glFlush();
}

//Four directional Flood-fill
void floodFill_4dir(int xx, int yy, Color currentColor, Color newColor) {
	Color clr;
	clr = getPixelColor(xx, yy);

	//Setting new color if current pixel color is white
	if (clr.r == currentColor.r && clr.g == currentColor.g && clr.b == currentColor.b) {
		setPixelColor(xx, yy, newColor);
		floodFill_4dir(xx + 1, yy, currentColor, newColor);
		floodFill_4dir(xx, yy + 1, currentColor, newColor);
		floodFill_4dir(xx - 1, yy, currentColor, newColor);
		floodFill_4dir(xx, yy - 1, currentColor, newColor);
	}
	return;
}

void floodfill() {
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color currentColor = {1.0f, 1.0f, 1.0f};

	floodFill_4dir(x, y, currentColor, newColor);
}

// Plotting eight points using circle's eight point symmetry
void plot_point(int xx, int yy) {
	glBegin(GL_POINTS);
	glVertex2i(x + xx, y + yy);
	glVertex2i(x + xx, y - yy);
	glVertex2i(x + yy, y + xx);
	glVertex2i(x + yy, y - xx);
	glVertex2i(x - xx, y - yy);
	glVertex2i(x - yy, y - xx);
	glVertex2i(x - xx, y + yy);
	glVertex2i(x - yy, y + xx);
	glEnd();
}

// Drawing a circle using Bresenham's circle drawing algorithm
void bresenham_circle(int r) {
	int xx = 0, yy = r;
	float d = 3.0 - 2.0 * r;

	plot_point(xx, yy);

	while (xx < yy) {
		xx = xx + 1;
		if (d < 0)
			d = d + 4 * xx + 6;
		else {
			yy = yy - 1;
			d = d + 4 * (xx - yy) + 10;
		}
		plot_point(xx, yy);
	}
	glFlush();
	floodfill();
}

// Function to draw two concentric circles
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	bresenham_circle(r);
	glFlush();
}

void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {
	printf("What's the radius of the circle? : ");
	scanf("%d", &r);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Flood-fill the rectangle using Bresenham's circle drawing algorithm");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
}
