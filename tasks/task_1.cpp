int choosing_cleaner(int n, int time){
    if (time/(n-1)%2){
        return n-time%(n-1);
    }
    else {
        return time%(n-1)+1;
    }
}