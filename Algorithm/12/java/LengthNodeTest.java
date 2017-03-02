import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.runner.JUnitCore;

public class LengthNodeTest {
    @Test
    public void testLengthOfNIL() {
        assertEquals("What is the length of NIL?", 0, Node.NIL.length());
    }
    @Test
    public void testLength() {
        Node n = new Node(1, Node.NIL);
        assertEquals("What is the length of a list whose next is NIL?", 1, n.length());
        Node nn = new Node(2, n);
        assertEquals("What is the length of a list whose next is a list with length 1?", 2, nn.length());
    }
    
    public static void main(String[] args) {
        JUnitCore core = new JUnitCore();
        core.run(LengthNodeTest.class);
    }
}
