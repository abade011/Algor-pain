import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import org.junit.Test;
import org.junit.Before;
import org.junit.After;
import org.junit.runner.JUnitCore;

public class Timing12Test {
    private int NCASES = 20;
    private Node[] nodes2 = new Node[NCASES];

    @Before
    public void setUp() {
        for (int i = 0; i < NCASES; i++)
            nodes2[i] = Node.NIL;
        for (int i = 0; i < NCASES; i++) {
            int n = (int) Math.pow(2, i);
            for(int j = 0; j < n; j++) {
                nodes2[i] = new Node(j, nodes2[i]);
            }
        }
    }

    @Test
    public void testLengthTiming() {
        int i;
        long diff = 0;
        for (i = 0; i < NCASES - 1; i++) {
            long start = System.nanoTime();
            int result = nodes2[i].length();
            long end = System.nanoTime();

            diff = end - start;
            if (diff/1000000 > 250) {
                i++;
                break;
            }
        }
        long start = System.nanoTime();
        int result = nodes2[i].length();
        long end = System.nanoTime();
        long diff2 = end - start;
        double ratio = (double) diff2 / (double) diff;
        assertTrue("length should scale linearly with list size", ratio > 1.2);
        assertTrue("length should scale linearly with list size", ratio < 2.5);
    }
    
    @Test
    public void testRemoveTiming() {
        int i;
        long diff = 0;
        for (i = 0; i < NCASES - 1; i++) {
            long start = System.nanoTime();
            Node result = nodes2[i].remove(0);
            long end = System.nanoTime();
            diff = end - start;
            if (diff/1000000 > 250) {
                i++;
                break;
            }
        }
        long start = System.nanoTime();
        Node result = nodes2[i].remove(0);
        long end = System.nanoTime();
        long diff2 = end - start;
        double ratio = (double) diff2 / (double) diff;
        assertTrue("remove should scale linearly with list size", ratio > 1.2);
        assertTrue("remove should scale linearly with list size", ratio < 2.5);
    }
    
    @Test
    public void testReverseTiming() {
        int i;
        long diff = 0;
        for (i = 0; i < NCASES - 1; i++) {
            long start = System.nanoTime();
            Node result = nodes2[i].reverse();
            long end = System.nanoTime();
            diff = end - start;
            if (diff/1000000 > 250) {
                i++;
                break;
            }
        }
        long start = System.nanoTime();
        Node result = nodes2[i].reverse();
        long end = System.nanoTime();
        long diff2 = end - start;
        double ratio = (double) diff2 / (double) diff;
        assertTrue("reverse should scale linearly with list size", ratio > 1.2);
        assertTrue("reverse should scale linearly with list size", ratio < 2.5);
    }
    
    public static void main(String[] args) {
        JUnitCore core = new JUnitCore();
        core.run(Timing12Test.class);
    }
}
