#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)) return 0;

    int minX1 = std::min(x1, x2), maxX1 = std::max(x1, x2);
    int minY1 = std::min(y1, y2), maxY1 = std::max(y1, y2);
    
    int minX2 = std::min(x3, x4), maxX2 = std::max(x3, x4);
    int minY2 = std::min(y3, y4), maxY2 = std::max(y3, y4);

    int interMinX = std::max(minX1, minX2);
    int interMaxX = std::min(maxX1, maxX2);
    int interMinY = std::max(minY1, minY2);
    int interMaxY = std::min(maxY1, maxY2);

    int interWidth = std::max(0, interMaxX - interMinX);
    int interHeight = std::max(0, interMaxY - interMinY);

    int area1 = (maxX1 - minX1) * (maxY1 - minY1);
    int area2 = (maxX2 - minX2) * (maxY2 - minY2);
    int interArea = interWidth * interHeight;

    std::cout << area1 + area2 - interArea << "\n";

    return 0;
}