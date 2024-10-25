#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, depth, xOffset, yOffset;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Input: Coordinates for the top-left and bottom-right corners of the box
    printf("Enter the TOP-LEFT (x1, y1) and BOTTOM-RIGHT (x2, y2) corners of the box: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Input: Depth along z-axis (used for parallel projection)
    printf("Enter the depth for projection: ");
    scanf("%d", &depth);

    // Offset for the side and top views in parallel projection
    xOffset = depth;     // Horizontal offset
    yOffset = depth / 2; // Vertical offset (typically half of the depth)

    // Drawing the front face (2D view)
    rectangle(x1, y1, x2, y2);
    outtextxy(x1 + (x2 - x1) / 2, y1 - 10, "Front View");

    // Drawing the side face (parallel projection)
    rectangle(x1 + xOffset, y1 - yOffset, x2 + xOffset, y2 - yOffset);
    outtextxy(x1 + xOffset + (x2 - x1) / 2, y1 - yOffset - 10, "Side View");

    // Connecting the corresponding corners of front and side faces to form a 3D-like box
    line(x1, y1, x1 + xOffset, y1 - yOffset); // Top-left corner
    line(x2, y1, x2 + xOffset, y1 - yOffset); // Top-right corner
    line(x1, y2, x1 + xOffset, y2 - yOffset); // Bottom-left corner
    line(x2, y2, x2 + xOffset, y2 - yOffset); // Bottom-right corner

    getch();      // Wait for key press before closing
    closegraph(); // Close the graphics mode
    return 0;
}
