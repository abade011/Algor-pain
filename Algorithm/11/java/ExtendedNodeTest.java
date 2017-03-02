import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import java.util.Random;
import org.junit.Test;
import org.junit.Before;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class ExtendedNodeTest {
    private Node n;
    private Node ncirc;
    
    @Test
    public void testNthItem() {
        assertEquals("Not getting the right first (index 0) item from nthItem", 17, n.nthItem(0));
        assertEquals("Not getting the right second (index 1) item from nthItem", 34, n.nthItem(1));
        assertEquals("Not getting the right third (index 2) item from nthItem", 3, n.nthItem(2));
        Random r = new Random();
        for (int k = 0; k < 100; k++) {
            int i = r.nextInt(1000);
            assertEquals(ncirc.nthItem(i % 2), ncirc.nthItem(i));
        }
    }
    @Test
    public void testNthNext() {
        assertEquals("Not getting the right first (index 0) next from nthNext", n.getNext(), n.nthNext(0));
        assertEquals("Not getting the right second (index 1) next from nthNext", n.getNext().getNext(), n.nthNext(1));
        assertEquals("Not getting the right third (index 2) next from nthNext", Node.NIL, n.nthNext(2));
        Random r = new Random();
        for (int k = 0; k < 100; k++) {
            int i = r.nextInt(1000);
            assertEquals(ncirc.nthNext(i % 2), ncirc.nthNext(i));
        }
    }

    @Before
    public void setUp() {
        n = new Node(17, new Node(34, new Node(3, Node.NIL)));
        ncirc = new Node(2, new Node (3, Node.NIL));
        ncirc.getNext().setNext(ncirc);
    }

    public static void main(String[] args) {
        JUnitCore core = new JUnitCore();
        Result result = core.run(ExtendedNodeTest.class);
        System.exit(result.wasSuccessful() ? 0 : 1);
    }
}
