#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int decision = 1 - radius;  // Initial decision parameter

    while (x >= y)
    {
        // Drawing 8 symmetrical points in the circle
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 + y, y0 + x, WHITE);
        putpixel(x0 - y, y0 + x, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 - y, y0 - x, WHITE);
        putpixel(x0 + y, y0 - x, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);

        y++;

        // Decision parameter update
        if (decision <= 0)
        {
            decision += 2 * y + 1;
        }
        else
        {
            x--;
            decision += 2 * (y - x) + 1;
        }
    }
}

int main()
{
    int gdriver = DETECT, gmode;
    int x, y, r;

    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI"); // Initialize graphics mode

    // Get radius and center of the circle from user
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    printf("Enter the coordinates of the center (x and y): ");
    scanf("%d%d", &x, &y);

    // Draw the circle using Midpoint Circle Algorithm
    drawcircle(x, y, r);

    getch();  // Wait for key press
    closegraph();  // Close the graphics mode
    return 0;
}
