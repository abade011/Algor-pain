import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.Before;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class BinarySearchTest {
    private int NARRAYS = 20;
    private int[][] arrays2 = new int[NARRAYS][];
    @Before
    public void setUp() {
        for (int i = 0; i < NARRAYS; i++) {
            int n = (int) Math.pow(2, i);
            arrays2[i] = new int[n];
            for (int j = 0; j < n; j++) {
                arrays2[i][j] = j;
            }
        }
    }
    @Test
    public void testZeroLengthSearch() {
        int[] x = {};
        assertTrue("nothing is in an empty array", !BinarySearch.search(x, 0, 0, 0));
        assertTrue("nothing is in an empty array", !BinarySearch.search(x, 1, 0, 0));
        assertTrue("nothing is in an empty array", !BinarySearch.search(x, 2, 0, 0));
        int[] y = {0,2,3,4};
        assertTrue("nothing is in an empty search", !BinarySearch.search(y, 0, 0, 0));
        assertTrue("nothing is in an empty search", !BinarySearch.search(y, 1, 1, 1));
        assertTrue("nothing is in an empty search", !BinarySearch.search(y, 2, 2, 2));
        assertTrue("nothing is in an empty search", !BinarySearch.search(y, 4, 3, 3));

    };
    @Test
    public void testSmallSearch() {
        int[] x = {0,2,4,6};
        assertTrue("-2 is not in {0,2,4,6}", !BinarySearch.search(x, -2, 0, 4));
        assertTrue("-1 is not in {0,2,4,6}", !BinarySearch.search(x, -1, 0, 4));
        assertTrue("0 is in {0,2,4,6}", BinarySearch.search(x, 0, 0, 4));
        assertTrue("1 is not in {0,2,4,6}", !BinarySearch.search(x, 1, 0, 4));
        assertTrue("2 is in {0,2,4,6}", BinarySearch.search(x, 2, 0, 4));
        assertTrue("3 is not in {0,2,4,6}", !BinarySearch.search(x, 3, 0, 4));
        assertTrue("4 is in {0,2,4,6}", BinarySearch.search(x, 4, 0, 4));
        assertTrue("5 is not in {0,2,4,6}", !BinarySearch.search(x, 5, 0, 4));
        assertTrue("6 is in {0,2,4,6}", BinarySearch.search(x, 6, 0, 4));
        assertTrue("7 is not in {0,2,4,6}", !BinarySearch.search(x, 7, 0, 4));
        assertTrue("8 is not in {0,2,4,6}", !BinarySearch.search(x, 8, 0, 4));
        assertTrue("4 is not in the first half of {0,2,4,6}", !BinarySearch.search(x, 4, 0, 2));
        assertTrue("2 is not in the second half of {0,2,4,6}", !BinarySearch.search(x, 2, 2, 4));
    };
    @Test
    public void testSearchScaling() {
        int i;
        int count = 10000;
        long diff = 0;
        for (i = 0; i < NARRAYS - 1; i++) {
            int n = (int) Math.pow(2, i);
            long start = System.nanoTime();
            for (int j = 0; j < count; j++) {
                boolean result = BinarySearch.search(arrays2[i], 0, 0, n);
                result = BinarySearch.search(arrays2[i], n-1, 0, n);
            }
            long end = System.nanoTime();
            diff = end - start;
            if (diff/1000000 > 250) {
                i++; break;
            }
        }
        int n = (int) Math.pow(2, i);
        long start = System.nanoTime();
        for (int j = 0; j < count; j++) {
            boolean result = BinarySearch.search(arrays2[i], 0, 0, n);
            result = BinarySearch.search(arrays2[i], n-1, 0, n);
        }
        long end = System.nanoTime();
        long diff2 = end - start;
        double ratio = (double) diff2 / (double) diff;
        assertTrue("binary search should scale logarithmically", ratio > 0.95);
        assertTrue("binary search should scale logarithmically", ratio < 1.2);
        
    };

    public static void main(String args[]) {
        JUnitCore core = new JUnitCore();
        core.run(BinarySearchTest.class);
    }
}
