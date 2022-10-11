
public class IntNode {

    int data;
    IntNode next = null;

    public IntNode(){};

    public IntNode(int data){
        this(data, null);
    }

    public IntNode(int data, IntNode next){
        this.data = data;
        this.next = next;
    }

} // end of node
