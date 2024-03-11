public class App {

    static void threePalindrome(){
        for(int i=100; i<1000; i++){
            int first;
            int third;
            first=i%10;
            third=i/100;
            if(first==third){
                System.out.println(i);
            }
        }
    }

    static void fourPalindrome(){
        for(int i=1000; i<10000; i++){
            int first;
            int second;
            int third;
            int fourth;
            first=i%10;
            second=(i/10)%10;
            third=(i/100)%10;
            fourth=(i/1000);
            if(first==fourth && second==third){
                System.out.println(i);
            }
        }
    }

    static void fiveDigitPrimes(){
        for(int i=10000;i<=100000;i++){
            int flag=0;
            for(int j=2;j<=i/2;j++){
                if(i%j==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                System.out.println(i+" is a prime number");
            }
        }
    }

    public static void main(String[] args){
        threePalindrome();
        fourPalindrome();
        fiveDigitPrimes();
    }
}
