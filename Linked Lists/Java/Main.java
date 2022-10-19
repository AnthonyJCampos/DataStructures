
public class Main {

   public static void main(String[] args) {

      IntLinkedList list1 = new IntLinkedList();

      for (int i = 1; i < 6; i++) {

         list1.add(i);
      }

      IntLinkedList list2 = new IntLinkedList();

      for (int i = 10; i < 16; i++) {
         list2.add(i);
      }

      /* Some Test Code */

      // comment out shortcut CTRL + K and then CTRL + C
      // to uncomment CTRL + K then CTRL + U

      // System.out.println(list1);
      // System.out.println(list1.length());

      // System.out.println("********************");

      // list1.addAtIndex(0, 100);
      // System.out.println(list1.length());
      // list1.addAtIndex(5, 500);
      // list1.addAtIndex(3, 200);
      // System.out.println(list1.length());
      // System.out.println(list1);

      // System.out.println("********************");

      // list1.deleteAtIndex(0);
      // list1.deleteAtIndex(6);
      // System.out.println(list1.length());
      // list1.deleteAtIndex(2);
      // System.out.println(list1);
      // System.out.println(list1.length());

   }

}