import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FrequencyCounter {

    public static void main(String[] args){
        FrequencyCounter freq = new FrequencyCounter();
    }

    public FrequencyCounter(){
        System.out.print("scanning file...");
        try {
            File file = new File("list.txt");
            if (!file.exists()){
                throw new FileNotFoundException("Lol no.");
            }
            Scanner input = new Scanner(file);
            int total = 0;
            while (input.hasNextLine()){
                String line = input.nextLine();
                try{
                    int num = Integer.parseInt(line);
                    total += num;
                    System.out.println(total);
                } catch (NumberFormatException e) {
                    System.out.println(e.getMessage());
                }
                // System.out.println(line);
            }
            input.close();
        } catch (FileNotFoundException fnfe){
            System.out.println(fnfe.getMessage());
        }
   } //end FrequencyCounter()

} //end 
