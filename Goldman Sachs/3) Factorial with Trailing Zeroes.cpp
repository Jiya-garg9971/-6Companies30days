/*
Q) Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int D=5;int cnt=0;
        while(n/D>0){
            cnt+=(n/D);
            D*=5;
        }
        return cnt;
    }
};
