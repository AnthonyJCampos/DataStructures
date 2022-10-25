package Trees.Java;

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

   public void add(T value) {

      this.root = addHelper(this.root, value);
   }

   private Node addHelper(Node root, T value) {

      // if empty
      if (root == null) {
         Node newNode = new Node(value);
         root = newNode;
         size++;
         return root;
      } // end if

      if (root.value.compareTo(value) > 1) {
         root.left = addHelper(root.left, value);
      } else if (root.value.compareTo(value) < 0) {
         root.right = addHelper(root.right, value);
      } // end if

      return root;

   } // end addHelper

} // end of BTS
