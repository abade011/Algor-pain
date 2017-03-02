import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class ReverseNodeTest {
    @Test
    public void testReverseOfNIL() {
        Node n = Node.NIL.reverse();
        assertEquals("What should the reverse of NIL be?", Node.NIL, n);
    }
    @Test
    public void testReverse1() {
        Node n = new Node(1, Node.NIL);
        Node r = n.reverse();
        assertNotEquals("reverse must return a fresh list", n, r);
        assertEquals("reverse should not change the length of the list", 1, r.length());
        assertEquals("the first item of a reversed one-element list is the same as the first element of the original", 1, r.getItem());
        assertEquals("reverse of a one-element list should be a one-element list", Node.NIL, r.getNext());
    }
    @Test
    public void testReverse2() {
        Node n = new Node(1, Node.NIL);
        Node nn = new Node(2, n);
        Node r = nn.reverse();
        assertNotEquals("reverse must return a fresh list", nn, r);
        assertEquals("reverse must not change the length of the list", 2, r.length());
        assertEquals("the second item becomes the first", 1, r.getItem());
        assertNotEquals("all nodes in the reversed list must be fresh", n, r.getNext());
        assertEquals("the first item becomes the second", 2, r.getNext().getItem());
        assertEquals("reverse of a two-element list should be a two-element list", Node.NIL, r.getNext().getNext());
    }
}
