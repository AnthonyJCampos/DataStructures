public class Main {

    public static void main(String[] args) {

        IntLinkedList list1 = new IntLinkedList();

        for(int i = 1; i < 6; i++){

            list1.add(i);
        }

        IntLinkedList list2 = new IntLinkedList();

        for(int i = 10; i < 16; i++){
            list2.add(i);
        }
        System.out.println("Hello World!");

        list1.mergeInBetween(list2, 2, 4);
        System.out.println("Hello World!");
    }

}