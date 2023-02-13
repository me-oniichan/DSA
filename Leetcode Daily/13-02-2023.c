int countOdds(int low, int high){
    return ((high-low+1)&1)?(high-low+1)/2+(low&1): (high-low+1)/2; 
}