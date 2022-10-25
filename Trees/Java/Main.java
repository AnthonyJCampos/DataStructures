package Trees.Java;

import java.util.*;

public class Main {

   /**
    * @param args
    */
   public static void main(String[] args) {

      BTS<Integer> tree1 = new BTS<>();

      // int[] arrayOfTree = new int[15];
      ArrayList<Integer> arrayOfTree = new ArrayList<>();

      randamFillTreeNum(tree1, arrayOfTree);
      // linearFillTreeNum(tree1);
      tree1.printInorder();
      System.out.println(tree1.length());
      System.out.println("Break");

   }

   // build out tree

   public static void randamFillTreeNum(BTS<Integer> tree, ArrayList<Integer> array) {

      for (int i = 0; i < 15; i++) {
         int rand = (int) Math.round(Math.random() * 1000 + 1);
         System.out.println("current random num: " + rand);
         if (tree.add(rand)) {
            array.add(rand);
         } // end if
      } // end for

   } // end randamFillTreeNum

   public static void linearFillTreeNum(BTS<Integer> tree) {

      for (int i = 0; i < 10; i++) {
         tree.add(i);
      } // end for
   } // end linearFillTreeNum

} // end main
