package Arrays;

import java.util.ArrayList;
import java.util.Scanner;

class Arrays {
  class Reverse {
    
    public static void main(String[] args) {

      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      ArrayList<Integer> arr = new ArrayList<Integer>(n);
      for (int i = 0; i < n; i++) {
        int ele = sc.nextInt();
        arr.add(ele);
      }

      int i = 0, j = n - 1;
      while (i < j) {

        swap(arr, i, j);
        i++;
        j--;
      }
      sc.close();

      System.out.println("Array : " + arr.toString());

    }
    
    static void swap(ArrayList<Integer> arr, int i, int j) {
      int temp = arr.get(i);
      arr.set(i, arr.get(j) );
      arr.set(j, temp);
    }
  }
}
