public class IntLinkedList {

   // attributes
   IntNode head;

   IntLinkedList() {
      head = null;
   } // end of default constructor

   public boolean add(int newData) {

      // base case
      if (head == null) {

         head = new IntNode(newData);
         return true;
      } // end if

      IntNode currNode = head;

      while (currNode != null) {

         if (currNode.next == null) {

            currNode.next = new IntNode(newData);
            return true;

         } // end if
         currNode = currNode.next;
      } // end while

      return false;
   } // end add

   public boolean remove(int target) {

      // base case
      if (head == null) {
         return false;
      } // end if

      // check if head is target to remove
      if (head.data == target) {

         if (head.next != null) {

            head = head.next;

         } else {

            head = null;

         } // end if

         return true;

      } // end if

      IntNode currNode = head;

      while (currNode != null) {

         if (currNode.next != null) {

            if (currNode.next.data == target) {

               // check if last node
               if (currNode.next.next == null) {

                  currNode.next = null;

               } else { // node is in between

                  IntNode nodeToRemove = currNode.next;
                  currNode.next = nodeToRemove.next;
                  nodeToRemove.next = null; // break connection

               } // end if

               return true;

            } // end if

         } // end if

         currNode = currNode.next;

      } // end while

      return false;
   } // end remove

   public boolean find(int target) {

      // base case
      if (head == null) {

         return false;

      } // end if

      return false;

   }

   @Override
   public String toString() {
      String str = "[ ";

      IntNode currNode = head;

      while (currNode != null) {

         str += String.valueOf(currNode.data) + " ";
         currNode = currNode.next;

      } // end while

      return str += "]";
   } // toString

   public boolean mergeInBetween(IntLinkedList listToMerge, int start, int end) {

      IntNode currNode = head;
      IntNode startPosition = null;
      IntNode endPosition = null;
      // get start position
      while (currNode.next != null) {

         if (currNode.next.data == start) {

            startPosition = currNode;
            break;
         } // end if

         currNode = currNode.next;
      } // end while

      if (startPosition == null) {
         return false;
      } // end if

      // get end position

      while (currNode != null) {

         if (currNode.data == end) {

            endPosition = currNode;
            break;
         } // end if
         currNode = currNode.next;
      }

      if (endPosition == null) {

         return false;
      } // end if

      // connect end node of listToMerge to this list

      // get to end of listToMerge
      currNode = listToMerge.head;
      while (currNode.next != null) {

         currNode = currNode.next;
      }

      currNode.next = endPosition.next;
      // connect start position to head of listToMerge
      startPosition.next = listToMerge.head;

      // release old list control
      listToMerge.head = null;
      return true;

   } // end of mergeInBetween

}
