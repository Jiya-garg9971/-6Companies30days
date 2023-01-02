/*
n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly.
But after that, the rest of the passengers will:

Take their own seat if it is still available, and
Pick other seats randomly when they find their seat occupied
Return the probability that the nth person gets his own seat.
*/
//DONE USING BASIC LOGIC THAT IF only one seat is available nth person will only sit on that seat but if n seat are available then there are two possibilities either 
// he get his allocated seat or not.

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n==1?1:.5;
    }
};
