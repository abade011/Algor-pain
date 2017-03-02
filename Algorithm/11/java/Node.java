class Node {
    public Node(Object o, Node n) { }
    public static final Node NIL = new Node(Node.NIL, Node.NIL);

    public Object getItem() {
        return null;
    }
    public Node getNext() {
        return null;
    }
    public void setItem(Object o) {
    }
    public void setNext(Node n) {
    }

    public Object nthItem(int i) {
        return null;
    }
    public Node nthNext(int i) {
        return null;
    }

    // no such thing as `unsigned' in Java
    public int length() {
        return -1;
    }
    public Node remove(Object o) {
        return null;
    }
    public Node reverse() {
        return null;
    }
}
