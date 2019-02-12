import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;

public class DuplicateChecker {

    private ArrayList<Integer> listOfTotals;

    public static void main(String[] args){
        DuplicateChecker freq = new DuplicateChecker();
    } //end main()
    
    public DuplicateChecker(){
        System.out.print("scanning file...");
        boolean found = false;
        try {
            File file = new File("list.txt");
            if (!file.exists()){
                throw new FileNotFoundException("Lol no.");
            }
            HashSet<Integer> listOfTotals = new HashSet<Integer>();
            int total = 0;
            while (!found){
                Scanner input = new Scanner(file);
                while (input.hasNextLine()){
                    String line = input.nextLine();
                    try{
                        int num = Integer.parseInt(line);
                        total += num;
                        if (listOfTotals.add(total) == false){
                            found = true;
                            System.out.println(total);
                            break;
                        }
                    } catch (NumberFormatException e) {
                        System.out.println(e.getMessage());
                    }
                }
            }
        } catch (FileNotFoundException fnfe){
            System.out.println(fnfe.getMessage());
        }
   } //end DuplicateChecker()

} //end 
