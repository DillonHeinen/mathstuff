#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//************** Function Prototypes ******************
//
//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false

bool isPrime(int number);

//
//helps isPrime by handling recursion

bool primeHelper(int number, int check);

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes(int n);

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo(int n);

//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example outputL 52=2*2*13 (or 52=1*2*13) or 13=prime

void findFactors(int number);

void factorsHelper(int number, int prime);

//**************** Function Definitions *****************

bool isPrime(int number) {      //returns true for prime, false for not prime
    if(number <= 1) {
        return false;
    }
    int check = number / 2;
    return primeHelper(number, check);
}

bool primeHelper(int number, int check) {     //assists isPrime with recursion
    if(check <= 1) {
        return true;
    }
    else if(number % check == 0) {
        return false;
    } else {
        return primeHelper(number, check - 1);
    }
}

void printPrimes(int n){       //prints primes with newline indentation
    if(isPrime(n)) {
        printf("%d ", n);
    }
    if(n != 0) {               //base condition
        printPrimes(n - 1);
    }
}

int findFibo(int n) {          //prints fibonacci sequence inline
    if(n == 0){                //base condition
        return 0;
    }
    else if(n == 1){           //base condition
        return 1;
    }
    return findFibo(n - 2) + findFibo(n - 1);
}

void findFactors(int number) {    //prints factors of a number inline
    if (isPrime(number)) {
        printf("%d=prime", number);
    } else{
        printf("%d=", number);
        factorsHelper(number, 2);

    }
}

void factorsHelper(int number, int prime) {    //assists findFactos with recursion
    if(prime <= number) {
        if (isPrime(prime) != true) {
            factorsHelper(number, prime + 1);
        } else if (number % prime == 0) {
            printf("%d*", prime);
            number = number / prime;
            factorsHelper(number, prime);
        } else {
            factorsHelper(number, prime + 1);
        }
    }printf("\b ");
}

//****************** Main Function **********************

int main () {
    
    
    int testNum;
    
    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);
    
    if (isPrime(testNum))  
       printf("%d is prime\n",testNum);
    else
       printf("%d is not prime.", testNum);
    
    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);
    
    printPrimes(testNum);
    
    printf("\n");
    
    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);
   
    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum)); 
    
    printf("\n");
    
    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    
    findFactors(testNum);
    
    return 0;
}