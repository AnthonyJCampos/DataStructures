package Trees;

public class BTS<T extends Comparable<T>> {

   // fields
   private Node root = null;
   private int size = 0;

   private class Node {

      // fields
      private T value;
      private Node left = null;
      private Node right = null;

      public Node(T value) {
         this.value = value;
      } // end constructor

   } // end of Node

   public BTS() {
   } // end defualt constructor

   public boolean add(T value) {

      // if empty
      if (root == null) {
         Node newNode = new Node(value);
         root = newNode;
         size++;
         return true;
      } // end if

      // decide if it needs to go down the left side or right side
      // so compareTo


   } // end add

   return false;
} // end of BTS
