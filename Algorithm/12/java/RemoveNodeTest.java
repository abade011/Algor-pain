import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class RemoveNodeTest {
    @Test
    public void testRemoveOfNIL() {
        Node n = Node.NIL.remove(1);
        assertEquals("What can you remove from NIL?", Node.NIL, n);
        n = Node.NIL.remove(0);
        assertEquals("What can you remove from NIL?", Node.NIL, n);
    }
    @Test
    public void testRemove1() {
        Node n = new Node(1, Node.NIL);
        Node r = n.remove(0);
        assertNotEquals("remove must return a fresh list", n, r);
        assertEquals("removing an object not present doesn't change the length", 1, r.length());
        assertEquals("removing an object not present doesn't change any item", 1, r.getItem());
        assertEquals("removing an object not present doesn't change the next field", Node.NIL, r.getNext());
        r = n.remove(1);
        assertEquals("removing the only item present gives a length zero list", 0, r.length());
        assertEquals("the only length zero list is NIL", Node.NIL, r);
    }
    @Test
    public void testRemove2() {
        Node n = new Node(1, Node.NIL);
        Node nn = new Node(2, n);
        Node r = nn.remove(0);
        assertNotEquals("remove must return a fresh list", nn, r);
        assertEquals("removing an object not present doesn't change the length", 2, r.length());
        assertEquals("removing an object not present doesn't change any item", 2, r.getItem());
        assertNotEquals("remove must return a completely fresh list", n, r.getNext());
        assertEquals("removing an object not present doesn't change any item", 1, r.getNext().getItem());
        assertEquals("removing an object not present doesn't change the next fields", Node.NIL, r.getNext().getNext());
        r = nn.remove(1);
        assertNotEquals("remove must return a fresh list", nn, r);
        assertEquals("remove of an object present will change the length", 1, r.length());
        assertEquals("remove of an object present can change which item is first", 2, r.getItem());
        assertEquals("remove of an object present will change the list structure", Node.NIL, r.getNext());
    }
}
