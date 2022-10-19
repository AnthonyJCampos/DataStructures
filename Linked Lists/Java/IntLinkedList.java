public class IntLinkedList {

   // attributes
   private IntNode head;
   private int size;

   IntLinkedList() {
      head = null;
      size = 0;
   } // end of default constructor

   public int length() {

      return size;

   } // end length

   /**
    * @brief addes a int data type to the array list and increments the size by one
    *        on successful add
    * @param newData
    * @return true on successful add and false of unsucessful add
    */
   public boolean add(int newData) {

      // base case
      if (head == null) {

         head = new IntNode(newData);
         size++;
         return true;
      } // end if

      IntNode currNode = head;

      while (currNode != null) {

         if (currNode.next == null) {

            currNode.next = new IntNode(newData);
            size++;
            return true;

         } // end if
         currNode = currNode.next;
      } // end while

      return false;
   } // end add

   /**
    * @brief remove removes a requested integer from the linked list
    * @param target
    * @return true on successful removal, false otherwise
    */
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
         size--;
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
               size--;
               return true;

            } // end if

         } // end if

         currNode = currNode.next;

      } // end while

      return false;
   } // end remove

   /**
    * @brief clear clears the Linked List and resets the size to 0
    */
   public void clear() {

      head = null;
      size = 0;

   } // end of clear

   /**
    * @brief find finds the target if within the linked list
    * @param target
    * @return true on successful find, false otherwise
    */
   public boolean find(int target) {

      IntNode currNode = head;

      while (currNode != null) {

         if (currNode.data == target) {

            return true;
         } // end if
         currNode = currNode.next;
      }

      return false;

   } // end of find

   /**
    * @brief overrriden toString method to represent a Linked List
    *        return a string representation of the Linked List
    */
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

   /**
    * @brief gets the middle element of the Link list
    * @return the middle data memeber of the node, throws an exception otherwise
    */
   public int getMiddleElement() {

      if (size < 1) {

         throw new RuntimeException("list empty");
      }

      // use fast a slow approach
      IntNode slow = head;
      IntNode fast = head.next;

      while (fast != null && fast.next != null) {
         slow = slow.next;
         fast = fast.next.next;
      } // end while

      return slow.data;
   }

   /**
    * Below Are Random Problems from LeetCode, possibly modifiedto work with this
    * Linked List
    */

   /**
    * @bief mergInBetween merges the input Linklist into the provided start and end
    *       position
    * @param listToMerge
    * @param start
    * @param end
    * @return true if succesful merge of link list, false otherwise
    */
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

   /** haven't decided if I'm going to use this yet */
   private IntNode getMiddleNode() {

      IntNode slow = head;
      IntNode fast = head.next;

      while (fast != null && fast.next != null) {

         slow = slow.next;
         fast = fast.next.next;

      } // end while

      return slow;
   }

   public int getIndex(int index) {

      if (head == null) {
         throw new RuntimeException("list empty");
      } // end if

      if (index >= size) {
         throw new RuntimeException("Out of Bounds. Size: " + size + ", index: " + index);
      } // end if

      IntNode currNode = head;

      int currIndex = 0;
      while (currNode != null && currIndex < index) {

         currNode = currNode.next;
         currIndex++;

      } // end while

      return currNode.data;
   } // end getIndex

   public void addAtIndex(int index, int value) {

      if (index >= size) {
         throw new RuntimeException("Out of Bounds. Size: " + size + ", index: " + index);
      } // end if

      if (index == 0) {

         addAtHead(value);

      } else if (index == size - 1) {

         addAtTail(value);

      } else { // insert in the middle of the Linked List

         IntNode currNode = head;
         int currIndex = 0;

         // get the node before the index to insert at
         while (currNode != null && currIndex < index - 1) {

            currIndex++;
            currNode = currNode.next;

         } // end while
         IntNode newNode = new IntNode(value);

         newNode.next = currNode.next;
         currNode.next = newNode;

      } // end if
      size++;

   } // end of addAtIndex

   public void deleteAtIndex(int index) {

      if (head == null) {
         throw new RuntimeException("list empty");
      } // end if

      if (index >= size) {
         throw new RuntimeException("Out of Bounds. Size: " + size + ", index: " + index);
      } // end if

      if (index == 0) {

         removeAtHead();

      } else if (index == size - 1) {// remove last node

         removeAtTail();

      } else { // remove between nodes

         IntNode currNode = head;
         int currIndex = 0;
         // get the node before the index to remove
         while (currNode.next != null && currIndex < index - 1) {

            currIndex++;
            currNode = currNode.next;

         } // end while

         currNode.next = currNode.next.next;

      } // end if

      size--;

   } // end deleteAtIndex

   private void addAtHead(int value) {

      IntNode newNode = new IntNode(value);
      if (head.next != null) {

         newNode.next = head;
         head = newNode;

      } else { // only node

         head = newNode;

      } // end if

   } // end addAtHead

   private void addAtTail(int value) {

      if (head == null) {

         addAtHead(value);

      } else {

         IntNode newNode = new IntNode(value);
         IntNode currNode = head;
         while (currNode.next != null) {

            currNode = currNode.next;

         } // end while

         currNode.next = newNode;

      } // end if

   } // end addAtTail

   private void removeAtHead() {

      if (head.next != null) {

         head = head.next;

      } else { // only node

         head = null;

      } // end if

   } // end of removeAtHead

   private void removeAtTail() {

      IntNode currNode = head;

      while (currNode.next.next != null) {

         currNode = currNode.next;

      } // end while

      currNode.next = null;

   } // end of removeAtTail

} // end of IntLinkedList
