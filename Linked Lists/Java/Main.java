
public class Main {

   public static void main(String[] args) {

      IntLinkedList list1 = new IntLinkedList();

      for (int i = 1; i < 6; i++) {

         list1.add(i);
      }

      IntLinkedList list2 = new IntLinkedList();

      for (int i = 1; i < 3; i++) {
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

      IntNode test = removeNthFromEnd(list2.getHead(), 1);
      // System.out.println(list2);

   }

   /** LeetCode Problems */

   // Not working it, look into it tomorrow
   public static IntNode removeNthFromEnd(IntNode head, int n) {

      if (head == null) {
         return null;
      } // end if

      IntNode prev = head;
      IntNode stepper = head;

      int step = 0;

      while (stepper.next != null) {

         if (step == n) {

            prev = prev.next;
            step = 0;

         } // end if
         stepper = stepper.next;
         step++;

      } // end while

      if (prev == head) {

         if (head.next == null) {

            head = null;

         } else {

            head = head.next;

         } // end if
      } else if (prev.next.next == null) {

         prev.next = null;

      } else {

         prev.next = prev.next.next;

      } // end if

      return head;
   } // end of removeNthFromEnd

   public static IntNode getIntersectionNode(IntNode headA, IntNode headB) {

      if (headA == null || headB == null) {
         return null;
      }

      IntNode a = headA;
      IntNode b = headB;

      while (a != b) {

         if (a == null) {
            a = headB;
         } else {
            a = a.next;
         } // end if

         if (b == null) {
            b = headA;
         } else {
            b = b.next;
         } // end if

      } // end while

      return a;
   } // end of getIntersectionNode

}