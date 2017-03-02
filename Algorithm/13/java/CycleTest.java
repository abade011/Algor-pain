import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import java.util.Random;

public class CycleTest {
    @Test
    public void testNoncyclicDetection() {
        assertTrue("Node.NIL is not cyclic by definition", !CycleDetection.isCyclic(Node.NIL));
        Node n = new Node(1, Node.NIL);
        assertTrue("A one-element list is not cyclic", !CycleDetection.isCyclic(n));
        Node nn = new Node(2, n);
        assertTrue("A two-element list is not cyclic", !CycleDetection.isCyclic(nn));
    }
    @Test
    public void testNoncyclicInfo() {
        assertEquals("Node.NIL's CycleInfo should be null by definition", null, CycleDetection.cycleInfo(Node.NIL));
        Node n = new Node(1, Node.NIL);
        assertEquals("A one-element list's CycleInfo should be null", null, CycleDetection.cycleInfo(n));
        Node nn = new Node(2, n);
        assertEquals("A two-element list's CycleInfo should be null", null, CycleDetection.cycleInfo(nn));
    }
    @Test
    public void testSmallCyclicDetection() {
        Node n = new Node(1, Node.NIL);
        n.setNext(n);
        assertTrue("A one-element cyclic list should be detected as cyclic", CycleDetection.isCyclic(n));
        Node nn = new Node(2, n);
        assertTrue("A two-element list with a cycle at the end should be detected as cyclic", CycleDetection.isCyclic(nn));
        n.setNext(nn);
        assertTrue("A two-element list cycling back to the start should be detected as cyclic", CycleDetection.isCyclic(nn));
        assertTrue("A two-element list cycling back to the start should be detected as cyclic wherever you start", CycleDetection.isCyclic(n));
    }
    @Test
    public void testSmallCyclicInfo() {
        Node n = new Node(1, Node.NIL);
        n.setNext(n);
        CycleInfo cn = CycleDetection.cycleInfo(n);
        assertTrue("A one-element cyclic list should be detected as cyclic", null != cn);
        assertEquals("A one-element cyclic list's cycle starts at 0", 0, cn.start);
        assertEquals("A one-element cyclic list's cycle's length is 1", 1, cn.length);
        Node nn = new Node(2, n);
        CycleInfo cnn = CycleDetection.cycleInfo(nn);
        assertTrue("A two-element list with a cycle at the end should be detected as cyclic", null != cnn);
        assertEquals("A two-element list with a cycle at the end's cycle starts at 1", 1, cnn.start);
        assertEquals("A two-element list with a cycle at the end's cycle' length is 1", 1, cnn.length);
        n.setNext(nn);
        cn = CycleDetection.cycleInfo(n);
        cnn = CycleDetection.cycleInfo(nn);
        assertTrue("A two-element list cycling back to the start should be detected as cyclic", null != cnn);
        assertTrue("A two-element list cycling back to the start should be detected as cyclic wherever you start", null != cn);
        assertEquals("A two-element cyclic list's cycle starts at 0", 0, cnn.start);
        assertEquals("A two-element cyclic list's cycle has length 2", 2, cnn.length);
        assertEquals("A two-element cyclic list's cycle starts at 0 wherever you start", 0, cn.start);
        assertEquals("A two-element cyclic list's cycle has length 2 wherever you start", 2, cn.length);
    }
    @Test
    public void testRandomCyclicDetection() {
        Node n = new Node(0, Node.NIL);
        Node tail = n;
        for (int i = 1; i < 100; i++) {
            n = new Node(i, n);
        }
        Random r = new Random();
        int start = r.nextInt(100);
        Node head = n;
        for (int i = 0; i < start; i++) {
            head = head.getNext();
        }
        tail.setNext(head);
        assertTrue("A randomly-made cyclic list should be detected as cyclic", CycleDetection.isCyclic(n));
    }
    @Test
    public void testRandomCyclicInfo() {
        Node n = new Node(0, Node.NIL);
        Node tail = n;
        for (int i = 1; i < 100; i++) {
            n = new Node(i, n);
        }
        Random r = new Random();
        int start = r.nextInt(100);
        Node head = n;
        for (int i = 0; i < start; i++) {
            head = head.getNext();
        }
        tail.setNext(head);
        CycleInfo cn = CycleDetection.cycleInfo(n);
        assertTrue("A randomly-made cyclic list should be detected as cyclic", null != cn);
        assertEquals("The start of a cycle in a randomly-made cyclic list should be detected correctly", start, cn.start);
        assertEquals("The length of a cycle in a randomly-made cyclic list should be detected correctly", 100-start, cn.length);
        
    }
    public static void main(String[] args) {
        JUnitCore core = new JUnitCore();
        core.run(CycleTest.class);
    }

}
