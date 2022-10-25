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

   public int length() {
      return size;
   } // end length()

   public boolean add(T value) {

      // store previous size to determine if add was successful
      int prevSize = size;
      this.root = addHelper(this.root, value);
      if (size > prevSize) {
         return true;
      } // end if
      return false;
   } // end add

   private Node addHelper(Node root, T value) {

      // if empty
      if (root == null) {
         Node newNode = new Node(value);
         root = newNode;
         size++;
         return root;
      } // end if

      int check = root.value.compareTo(value);
      if (check > 0) {
         root.left = addHelper(root.left, value);
      } else if (check < 0) {
         root.right = addHelper(root.right, value);
      } // end if

      return root;

   } // end addHelper

   /** Work In Progress */
   public boolean remove(T value) {

      int tempSize = size;
      root = removeHelper(root, value);
      if (tempSize > size) {
         return true;
      } // end if
      return false;
   } // end remove

   private Node removeHelper(Node root, T value) {

      // base case, empty tree
      if (root == null) {
         return null;
      } // case 1: value is equal to root value
      else if (root.value.compareTo(value) == 0) {

         // delete node
         deleteNode(root);
         size--;
      } // case 2: value is less then root value
      else if (root.value.compareTo(value) > 0) {
         root = removeHelper(root.left, value);
      } // case 3: value is greater then root value
      else {
         root = removeHelper(root.right, value);
      } // end if

      return root;

   } // end removeHelper

   private void deleteNode(Node root) {

      // case 1: root/leaf
      if (root.left == null && root.right == null) {

         root = null;
      }
      // case 2: only one child
      else if (root.left == null || root.right == null) {

         // determine which child to delete
         if (root.left == null) {
            root = root.right;
         } else {
            root = root.left;
         } // end if
      }
      // case 3 two children
      else {

         root.value = removeLeftMostNode(root.right);
      } // end if

   } // end deleteNode

   private T removeLeftMostNode(Node root) {

      if (root.left == null) {

         root = root.right;

      } else {
         return removeLeftMostNode(root.left);
      } // end if

      return root.value;
   } // end removeLeftMostNode

   public void printInorder() {
      inorder(this.root);
   } // end printIn

   private void inorder(Node root) {

      if (root != null) {
         inorder(root.left);
         System.out.printf("%s ", root.value);
         inorder(root.right);
      } // end if

   } // end inorder

   public void printPreorder() {
      preorder(this.root);
   } // end printPreorder

   private void preorder(Node root) {
      if (root != null) {
         System.out.printf("%s ", root.value);
         preorder(root.left);
         preorder(root.right);
      } // end if
   } // end preorder

   public void printPostorder() {
      postorder(this.root);
   } // end printPostOrder()

   private void postorder(Node root) {

      if (root != null) {
         postorder(root.left);
         postorder(root.right);
         System.out.printf("%s ", root.value);
      } // end if
   } // end postorder

} // end of BTS
