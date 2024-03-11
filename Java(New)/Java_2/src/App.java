import java.math.BigInteger;
import java.util.Scanner;

public class App {

    //alıştırma 1
    static void calcSum(){
        int totalsum=0;
        for(int i=19;i<=202;i+=3){
            totalsum+=i;
        }
        System.out.println("The total sum is: "+totalsum);
    }

    //alıştırma 2
    static void eulerPi(){
        double totalsum=0;
        for(double i=1;i<=10000;i++){
            totalsum+=6/(i*i);
        }
        double pi=Math.sqrt(totalsum);
        System.out.println(pi);
    }

    //alıştırma 3
    static int factorial(int n){
        int totalfactorial=1;
        if(n==1 || n==0){
            return 1;
        }else{
            for(int i=2;i<=n;i++){
                totalfactorial=totalfactorial*i;
            }
            return totalfactorial;
        }
    }

    static void eulerE(){
        double totalsum=0;
        for(int i=0;i<=20;i++){
            totalsum+=1.0/factorial(i);
        }
        System.out.println("The value of e is: "+totalsum);
    }

    //alıştırma 4
    static void threePalindrome(){
        int firstDigit=0;
        int thirdDigit=0;
        for(int i=100;i<1000;i++){
            firstDigit=i%10;
            thirdDigit=i/100;
            if(firstDigit==thirdDigit){
                System.out.println(+i+" is a palindrome number");
            }
        }
    }

    //alıştırma 5
    static void fourPalindrome(){
        int firstDigit=0;
        int secondDigit=0;
        int thirdDigit=0;
        int fourthDigit=0;

        for(int i=1000;i<10000;i++){
            firstDigit=i%10;
            secondDigit=(i/10)%10;
            thirdDigit=(i/100)%10;
            fourthDigit=i/1000;

            if(firstDigit==fourthDigit && secondDigit==thirdDigit){
                System.out.println(+i+" is a palindrome number");
            }
        }
    }

    //alıştırma 6
    static void firstDigitBiggerFourthDigit(){
        int firstDigit=0;
        int fourthDigit=0;

        for(int i=1000;i<10000;i++){
            firstDigit=i/1000;
            fourthDigit=i%10;

            if(firstDigit>fourthDigit){
                System.out.println(+i+"'s first digit is bigger than it's fourth one");
            }
        }
    }

    //alıştırma 7
    static void firstTwoDigitsAddedEqualLast(){
        int firstDigit=0;
        int secondDigit=0;
        int thirdDigit=0;

        for(int i=100;i<1000;i++){
            firstDigit=i/100;
            secondDigit=(i/10)%10;
            thirdDigit=i%10;
            if((firstDigit+secondDigit)==thirdDigit){
                System.out.println(i+"s first two digits when added together equal it's third one");
            }
        }
    }

    //alıştırma 8
    static void atLeastTwoDigitsEqual(){
        int firstDigit=0;
        int secondDigit=0;
        int thirdDigit=0;

        for(int i=100;i<1000;i+=2){
            firstDigit=i/100;
            secondDigit=(i/10)%10;
            thirdDigit=i%10;
            if(firstDigit==thirdDigit || firstDigit==secondDigit || secondDigit==thirdDigit ){
                System.out.println("The even number of "+i+" has at least two digits that are identical");
            }
        }
    }

    //alıştırma 9
    static void digitSumLessthanNine(){
        int firstDigit=0;
        int secondDigit=0;
        int thirdDigit=0;

        for(int i=1;i<1000;i++){
            firstDigit=i/100;
            secondDigit=(i/10)%10;
            thirdDigit=i%10;
            if((firstDigit+secondDigit+thirdDigit)<9){
                System.out.print(i+" ");
            }
        }
    }

    //alıştırma 10
    static void firstAndLastTwoDigitsIdentical(){
        int firstDigit=0;
        int secondDigit=0;
        int thirdDigit=0;
        int fourthDigit=0;
        int fifthDigit=0;

        int firstTwoDigits=0;
        int lastTwoDigits=0;
        int counter=0;

        for(int i=10000;i<100000;i++){
            firstDigit=(i/10000);
            secondDigit=(i/1000)%10;
            thirdDigit=(i/100)%10;
            fourthDigit=(i/10)%10;
            fifthDigit=i%10;

            firstTwoDigits=10*firstDigit+secondDigit;
            lastTwoDigits=10*fourthDigit+fifthDigit;

            if(firstTwoDigits==lastTwoDigits){
                counter++;
                System.out.println(+i+"'s first and last two digits are the same");
            }
        }
        System.out.println("There are "+counter+" numbers in total that satisfy this requirement");
    }

    //alıştırma 11
    static void biggestCommonModulus(int num1, int num2, int num3){
        int biggestDivisor=0;
        int smallestNum=Math.min(Math.min(num1, num2), num3);
        int modulo1;
        int modulo2;
        int modulo3;
        for(int i=2;i<smallestNum;i++){
            modulo1=num1%i;
            modulo2=num2%i;
            modulo3=num3%i;
            if(modulo1==modulo2 && modulo1==modulo3 && modulo2==modulo3  && modulo1>biggestDivisor){
                biggestDivisor=i;
            }
        }
        System.out.println(biggestDivisor);
    }

    //alıştırma 12
    static void findBirthYear(){
        int firstDigit=0;
        int secondDigit=0;
        int thirdDigit=0;
        int fourthDigit=0;

        for(int i=2005;i>=1977;i--){
            firstDigit=(i/1000);
            secondDigit=(i/100)%10;
            thirdDigit=(i/10)%10;
            fourthDigit=i%10;

            if((firstDigit+secondDigit+thirdDigit+fourthDigit)==2005-i){
                System.out.println(i+" is this person's birthyear");
            }
        }
    }
    
    //alıştırma 13
    static void findWeirdNumber(){
        int firstDigitA=0;
        int secondDigitA=0;
        int firstDigitB=0;
        int secondDigitB=0;

        for(int a=10;a<100;a++){
            firstDigitA=a/10;
            secondDigitA=a%10;
            for(int b=10;b<100;b++){
                if(((firstDigitA*1000)+(secondDigitB*100)+b)==11*(a+b)){
                    System.out.println("("+a+"+"+b+")*11=="+a+b);
                }
            }
        }
    }

    //alıştırma 14
    static void smallestDifference(double num) {
        int factor1 = 0;
        int factor2 = 0;
    
        // Find the integer square root of the number
        int sqrt = (int) Math.sqrt(num);
    
        // Initialize the minimum difference to a large value
        int minDifference = Integer.MAX_VALUE;
    
        for (int i = 1; i <= sqrt; i++) {
            if (num % i == 0) {
                int tempFactor1 = i;
                int tempFactor2 = (int) (num / i);
                int difference = Math.abs(tempFactor1 - tempFactor2); // Define the variable difference here
    
                // Update factors if the new difference is smaller
                if (difference < minDifference) {
                    factor1 = tempFactor1;
                    factor2 = tempFactor2;
                    minDifference = difference;
                }
            }
        }
    
        // Output the factors with the smallest difference
        System.out.println("The 2 factors of this number with the smallest difference are: " + factor1 + " and " + factor2);
        System.out.println("Their difference is: " + minDifference);
    }

    //alıştırma 15
    /* 
    static void fiveDigitPrimes(int n){
        boolean[] nums= new boolean[100000];
        for(int i=2;i<n+1;)
    }
    */

    //alıştırma 16
    
    //alıştırma17

    static int askForInput(){
        Scanner number = new Scanner(System.in);
        System.out.println("Please enter a 3 or 4 digit number: ");
        int num=number.nextInt();
        return num;
    }

    static void threeOrFourDigitPalindromeCheck(){
        int number=askForInput();
        while ((number>=10000 || number<100)){
            number=askForInput();
        }
        
        int firstDigit=0;
        int secondDigit=0;
        int thirdDigit=0;
        int fourthDigit=0;
        if ((number/1000)>0) {
            firstDigit=number/1000;
            secondDigit=(number/100)%10;
            thirdDigit=(number/10)%10;
            fourthDigit=number%10;
            if(fourthDigit==firstDigit && secondDigit==thirdDigit){
                System.out.println(number+" is a 4 digit palindrome number");
            }else{
                System.out.println(number+" is NOT a 4 digit palindrome number");
            }
        }else{
            firstDigit=number/100;
            secondDigit=(number/10)%10;
            thirdDigit=number%10;
            if(thirdDigit==firstDigit){
                System.out.println(number+" is a 3 digit palindrome number");
            }else{
                System.out.println(number+" is NOT a 3 digit palindrome number");
            }
        }
    }

    static void findIfPrime(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Type in a number: ");
        String numtxt=scanner.nextLine();
        int num=Integer.valueOf(numtxt);
        for(int i=2;i<=num;i++){
            if(num%i==0){
                System.out.println("The number is not a prime");
                break;
            }else{
                System.out.println("The number is a prime");
            }
        }
    }

    
    public static void main(String[] args) {
        int num1=125;
        int num2=200;
        int num3=350;
        double product=121212;

        /* 
        calcSum();
        eulerPi();
        eulerE();
        threePalindrome();
        fourPalindrome();
        firstDigitBiggerFourthDigit();
        firstTwoDigitsAddedEqualLast();
        atLeastTwoDigitsEqual();
        digitSumLessthanNine();
        firstAndLastTwoDigitsIdentical();
        biggestCommonModulus(num1, num2, num3);
        findBirthYear();
        findWeirdNumber();
        smallestDifference(product);
        */
        threeOrFourDigitPalindromeCheck();
    }
}




