bool path_finder(unsigned int x, unsigned int y){
    while (x > 1 and y > 1){
        if (x == y and x % 2 == 1){
            return false;
        }
        else if (x % 2 == 0){
            x /= 2;
        }
        else if (y % 2 == 0){
            y /= 2;
        }
        else if (x > y){
            x += y;
        }
        else {
            y += x;
        }
    }
    return true;
}