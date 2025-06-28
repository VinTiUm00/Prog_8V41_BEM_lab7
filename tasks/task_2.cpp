#include <math.h>

bool path_exist(int sx, int sy, int fx, int fy, int t){
    int vx = std::abs(fx - sx),
        vy = std::abs(fy - sy),
        diags = std::min(vx, vy),
        min_moves = diags;
    vx -= diags; vy -= diags;
    min_moves += vx + vy;
    if (min_moves <= t){
        return true;
    }
    else {
        return false;
    }
}