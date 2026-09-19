class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x;
        if (x1 > xc) x = x1; // circle on left
        else if (x2 < xc) x = x2; // cirlce on right
        else x = xc;  // rect is inside circle
        
        int y;
        if (y1 > yc) y = y1; // circle on bottom
        else if (y2 < yc) y = y2; // circle on top
        else y = yc; // rect is inside cicle

        int dx = x - xc;
        int dy = y - yc;

        return dx * dx + dy * dy <= r * r;
    }
};
