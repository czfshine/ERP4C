/*

**************************************
11111 Lightning
**************************************
Description

There are N robots standing on the ground (Don't know why. Don't know how). 

 

Suddenly the sky turns into gray, and lightning storm comes! Unfortunately, one of the robots is stuck by the lightning!

 

So it becomes overladen. Once a robot becomes overladen, it will spread lightning to the near one. 

 

The spreading happens when: 

	Robot A is overladen but robot B not.

	The Distance between robot A and robot B is no longer than R.

	No other robots stand in a line between them.

In this condition, robot B becomes overladen. 

 

We assume that no two spreading happens at a same time and no two robots stand at a same position. 



The problem is: How many kind of lightning shape if all robots is overladen? The answer can be very large so we output the answer modulo 10007. 

If some of the robots cannot be overladen, just output -1. 


**************************************
Input

There are several cases.

The first line is an integer T (T < = 20), indicate the test cases.

For each case, the first line contains integer N ( 1 < = N < = 300 ) and R ( 0 < = R < = 20000 ), indicate there stand N robots; 

following N lines, each contains two integers ( x, y ) ( -10000 < = x, y < = 10000 ), indicate the position of the robot. 


**************************************
Output

One line for each case contains the answer.
**************************************
Sample Input

3

3 2

-1 0

0 1

1 0

3 2

-1 0

0 0

1 0

3 1

-1 0

0 1

1 0


**************************************
Sample Output

3

1

-1


**************************************
Author0*/
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}