import java.util.Scanner;
public class SearchAlgo {

    //2D ARRAY LINEAR SEARCH
    public static byte TwoDimensionalArray(byte userInput, byte[][] arr){
        for (byte[] row : arr){//looks at how many sets in the array there are (there are 2)
            for(byte num : row){//looks at specific elements in each section of the array.
                if(num == userInput){//once user input is found, it is returned to main.
                    try {
                        Thread.sleep(1500);//pauses program for 1.5 seconds
                    } catch (InterruptedException e) {
                        
                        e.printStackTrace();
                    }
                    return num;
                }
            }
        }
        return -1;//returns -1 if number is not in array.
    }
    

    //BINARY SEARCH
    public static double binarySearch(double userInput, double[] times){//takes a user input number to check in the array, which is also included.
            int mid, start = 0, end = times.length - 1;

            //three integars used to check the beginning of the array, which will start at 0,
            //the end of the array, which will be however long it is minus 1 since the count begins at 0,
            //and a variable holding the middle value since binary search starts in the middle of the array.
            //and checks if the input value is higher or lower.
    
            while(start <= end){//the start value must be lower or equal to the end value or something is wrong.
                mid =(start + end)/ 2;//calculates the median value.
            if(times[mid] < userInput){//if input is bigger than the current middle value, the start value is changed to go to the right of the array.
                start = mid + 1;
            } else if(times[mid] > userInput){//if smaller, it goes to the left.
                end = mid - 1;}
            else if(times[mid] == userInput){//the value is then returned once it is found.
                return times[mid];}
                try {
                    Thread.sleep(1500);//pauses program for 1.5 seconds
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                }
            System.out.println("Loop!");//counts how many times the while loop is looped.
        }
                return -1;//returns the null value if the input is not in the array.
            
        }

        @SuppressWarnings("UnnecessaryContinue")
        //LINEAR SEARCH
            public static double linearSearch(double userInput, double[] times){
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                }
            System.out.println("Checking size of array: " + times.length);//checks the size of the array on console.
        for(byte i = 0; i < times.length; i++){//first example of linear search algorithm.
            if(times[i] != userInput){
                continue;
            } else {break;}//returns null value if not in array.
        }

        for(double j : times){//second example, uses less lines so more efficient.
            if(j == userInput){
                try {
                    Thread.sleep(1500);
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                }
                return j;//breaks after element is located in array.
            }
        }    

        return -1;//returns null value if number is not in array.
        }
    
        @SuppressWarnings({"resource", "ConvertToTryWithResources"})//showcase Java data types, but are not using them.
        public static void main(String[] args){
            @SuppressWarnings("unused")
            byte only127 = 2; //data type that can contain variables from -127 to 127.
            @SuppressWarnings("unused")
            short shorT = 5; //takes less data, but can hold a significant amount of numbers even still.
            @SuppressWarnings("unused")
            double decimal = 1.30d; //can store a decimal number up to 16 significant figures.
            @SuppressWarnings("unused")
            float floaT = 5.55f;//can store a decimal number up to 7 significant figures.
            @SuppressWarnings("unused")
            int integar = 14;//can store a considerably large number.
            @SuppressWarnings("unused")
            long longer = 1234567890;//useful for big data metrics, since this data type can store a beyond massive number.
    
            @SuppressWarnings("unused")
            char character = 'H';//data type holds a single character
            @SuppressWarnings("unused")
            String str = "Hello World! ";//immutable set of characters
            @SuppressWarnings("unused")
            boolean bool = true;//can only contain a true or false value.
    
    
            Scanner scan = new Scanner(System.in);//Scanner used for user input initialised.

            byte menuChoice;

            double[] times = {1.30d, 2.20d, 4.35d, 5.00d, 6.50d, 7.10d, 9.00d};//array initialised with 7 decimals.

            byte set[][] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

            do{
                System.out.println("Please select a search algorithm:\n1. Linear Search\n2. Binary Search\n3. 2D Array Linear Search\n4. Quit");
                menuChoice = scan.nextByte();
            switch (menuChoice){


            case 1 -> {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                }
                System.out.println("Enter Linear Search Number: ");//prints the string inside the brackets to console.
                double userInputLinear = scan.nextDouble();//allows user to input a decimal number.
                
                double resultLinear = linearSearch(userInputLinear, times);//calls binary search algorithm.
                
                if(resultLinear != -1){//error checking for null result.
                    System.out.println("We found " + resultLinear + " in the array.");
                    try {
                        Thread.sleep(1500);
                    } catch (InterruptedException e) {
                        
                        e.printStackTrace();
                    }}
                else {System.out.println("Not in array!");}
            }

            case 2 -> {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                }
                System.out.println("Enter Binary Search Number: ");//prints the string inside the brackets to console.
                double userInputBinary = scan.nextDouble();//allows user to input a decimal number.
                
                double resultBinary = binarySearch(userInputBinary, times);//calls binary search algorithm.
                
                if(resultBinary != -1){//error checking for null result.
                    System.out.println("We found " + resultBinary + " in the array.");
                    try {
                        Thread.sleep(1500);
                    } catch (InterruptedException e) {
                        
                        e.printStackTrace();
                    }
                }
                else {try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                } System.out.println("Not in array!");}
            }

            case 3 -> {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                }

                System.out.println("Please enter a number to be searched:");
                byte enteredNumber = scan.nextByte();
                
                byte resultTwoD = TwoDimensionalArray(enteredNumber, set);
                
                System.out.println("We found " + resultTwoD + " in the array.");
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    
                    e.printStackTrace();
                }
            }

            case 4 -> {
                break;
            }
            
            default -> throw new ArithmeticException("You have not selected a correct option! Please select an option within the menu: ");
        }
    
    System.out.println("");
    try {
        Thread.sleep(1500);
    } catch (InterruptedException e) {
        
        e.printStackTrace();
    }
    }while(menuChoice != 4);
        scan.close();
    }
}
