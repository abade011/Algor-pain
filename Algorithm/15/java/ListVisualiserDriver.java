public class ListVisualiserDriver {
    public static void main(String args[]) {
        Node a = new Node(1, new Node(11, new Node(23, Node.NIL)));
        ListVisualiser.visualise(a);
    }
}
