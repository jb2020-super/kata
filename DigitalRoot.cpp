/*
Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.
    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
*/
/*
best solution:
A math guy here. Let me do my best to explain this code to anybody who does not yet understands it.
The idea behind this trick is: sum of digits of a number 'n' is same as the number 'n' itself modulo 9. For example, 23 = 9*2+5 = 5 (modulo 9) = 2 + 3 (sum of digits modulo 9). If you don't believe it - try it with any number you come up with, I will leave a semiformal proof in the end.

So, after any interchanging 'n' with a sum of digits of 'n' we have the same number modulo 9. And in the end we clearly have a one-digit number. I hope you got the gist of how we can figure the final number.

//semiformal proof further
//before further reading - be sure to understand why 9, 99, 999, 9999, etc are divisible by 9.

Let us prove it for a number 7235.
First, notice that 7000 = 7 (modulo 9). Why is that? Because 7000 - 7 = 7 * (1000 - 1) = 7 * 999 = 0 (modulo 9).
Then, 200 = 2 (modulo 9). Again, 200 - 2 = 2 * (100-1) = 2 * 99 = 0(modulo 9)
Hopefully, you see how this works. Now without my annoying comments:

7000 = 7(modulo 9)
200 = 2 (modulo 9)
30 = 3 (modulo 9)
5 = 5(modulo 9)

all that is left to do is to add up these equations.
*/
int digital_root(int Z) {
    return --Z % 9 + 1;
}

int digital_root1(int n)
{
    int sum = n;
    do
    {
        n = sum;
        sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
    } while (sum >= 10);
    return sum;
}