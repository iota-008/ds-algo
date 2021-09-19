import java.util.HashMap;
import java.util.Scanner;

class Chegg{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int number_of_zone = sc.nextInt();
    String zone_sequence_match = sc.next();
    String zone_sequence_predicted = sc.next();

    HashMap<Character, String> map = new HashMap<>();
    map.put('Y', "Yasnaya");
    map.put('R', "Rozhok");
    map.put('S', "School");
    map.put('P', "Pochinki");
    map.put('F', "Farm");
    map.put('M', "Mylta");
    map.put('H', "Shelter");
    map.put('I', "Prison");

    int[][] L = new int[number_of_zone+1][number_of_zone+1];
    for (int i=0; i<=number_of_zone; i++)
    {
        for (int j=0; j<=number_of_zone; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (zone_sequence_match.charAt(i-1) == zone_sequence_predicted.charAt(j-1))
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = Math.max(L[i-1][j], L[i][j-1]);
        }
    }

    // Following code is used to print LCS
    int index = L[number_of_zone][number_of_zone];
    int temp = index;

    // Create a character array to store the lcs string
    char[] lcs = new char[index+1];
    lcs[index] = '\u0000'; // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = number_of_zone;
    int j = number_of_zone;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (zone_sequence_match.charAt(i-1) == zone_sequence_predicted.charAt(j-1))
        {
            // Put current character in result
            lcs[index-1] = zone_sequence_match.charAt(i-1); 
        
            // reduce values of i, j and index
            i--; 
            j--; 
            index--;     
        }
        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    // Print the answer

    for(int k=0;k<temp;k++)
      System.out.print(map.get(lcs[k]) + " ");
    System.out.println();
    int correctness = temp * 100 / number_of_zone;
    System.out.println("correctness of Prediction: " + correctness + "%");
    sc.close();   
  }
}
