#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int n, i, j, k, gd, gm, dy, dx, temp;
    int x, y, a[20][2], xi[20];
    float slope[20];

    // Clear the screen
    clrscr();

    // Input number of edges
    printf("\nEnter the number of edges of the polygon: ");
    scanf("%d", &n);

    // Input the coordinates of the polygon
    printf("\nEnter the coordinates of the polygon:\n");
    for (i = 0; i < n; i++)
    {
        printf("X%d, Y%d: ", i + 1, i + 1);
        scanf("%d%d", &a[i][0], &a[i][1]);
    }

    // Close the polygon by repeating the first point at the end
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];

    // Initialize the graphics mode
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the polygon
    for (i = 0; i < n; i++)
    {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }

    // Calculate slopes of each edge
    for (i = 0; i < n; i++)
    {
        dy = a[i + 1][1] - a[i][1];
        dx = a[i + 1][0] - a[i][0];

        if (dy == 0)       // Horizontal line
            slope[i] = 1.0;
        else if (dx == 0)  // Vertical line
            slope[i] = 0.0;
        else               // General case
            slope[i] = (float)dx / dy;
    }

    // Scanline algorithm
    for (y = 0; y < getmaxy(); y++)  // Traverse each scanline (y-coordinate)
    {
        k = 0;  // Reset intersection count

        // Find the x-intersections for each edge with the current scanline
        for (i = 0; i < n; i++)
        {
            if ((a[i][1] <= y && a[i + 1][1] > y) || (a[i][1] > y && a[i + 1][1] <= y))
            {
                xi[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
                k++;
            }
        }

        // Sort the intersection points in increasing order
        for (j = 0; j < k - 1; j++)
        {
            for (i = 0; i < k - 1; i++)
            {
                if (xi[i] > xi[i + 1])
                {
                    temp = xi[i];
                    xi[i] = xi[i + 1];
                    xi[i + 1] = temp;
                }
            }
        }

        // Fill the pixels between pairs of intersections
        setcolor(35);  // Set the color for filling
        for (i = 0; i < k; i += 2)
        {
            line(xi[i], y, xi[i + 1], y);  // Draw horizontal line between intersections
        }
    }

    getch();  // Wait for key press
    closegraph();  // Close graphics mode
}
