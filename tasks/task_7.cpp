int numbers_from_range(int n){
    int count = 0;

    for (int i = 0; i <= n; i++){
        int units = 0;
        for (int j = 0; j < 16; j++){
            if (units > 1){
                break;
            }
            if (i & 1<<j){
                units++;
            }
            else {
                units = 0;
            }
        }
        if (units <= 1){
            count++;
        }
    }

    return count;
}