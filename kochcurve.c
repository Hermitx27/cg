#include <graphics.h>
#include <conio.h> // For getch()
#include <math.h>  // For math functions

// Function to draw a single iteration of the Koch curve
void koch(int x1, int y1, int x5, int y5, int it)
{
    int x2, y2, x3, y3, x4, y4;
    int dx, dy;

    if (it == 0)
    {
        // Draw line if no iterations are left
        line(x1, y1, x5, y5);
    }
    else
    {
        dx = (x5 - x1) / 3;
        dy = (y5 - y1) / 3;

        x2 = x1 + dx; // First division point
        y2 = y1 + dy;

        x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6); // Peak point
        y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);

        x4 = 2 * dx + x1; // Second division point
        y4 = 2 * dy + y1;

        // Recursively draw the four sides
        koch(x1, y1, x2, y2, it - 1);
        koch(x2, y2, x3, y3, it - 1);
        koch(x3, y3, x4, y4, it - 1);
        koch(x4, y4, x5, y5, it - 1);
    }
}

int main()
{
    int gd = DETECT, gm;
    int iterations;

    // Initialize graphics
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Input number of iterations
    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    // Draw three sides of the Koch snowflake
    koch(100, 100, 300, 100, iterations); // Top side
    koch(300, 100, 200, 250, iterations); // Right side
    koch(200, 250, 100, 100, iterations); // Left side

    getch();      // Wait for user input
    closegraph(); // Close graphics mode
    return 0;
}
