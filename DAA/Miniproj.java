import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class miniproj {

    public static int[][] multiply(int[][] A, int[][] B) {
        int numRowsA = A.length;
        int numColsA = A[0].length;
        int numColsB = B[0].length;
        int[][] result = new int[numRowsA][numColsB];

        ExecutorService executor = Executors.newFixedThreadPool(numRowsA);

        try {
            for (int i = 0; i < numRowsA; i++) {
                final int row = i;
                executor.submit(() -> {
                    for (int j = 0; j < numColsB; j++) {
                        for (int k = 0; k < numColsA; k++) {
                            result[row][j] += A[row][k] * B[k][j];
                        }
                    }
                });
            }
        } finally {
            executor.shutdown();
        }

        return result;
    }

    public static void main(String[] args) {
        int[][] A = {{1, 2, 3}, {4, 5, 6}};
        int[][] B = {{7, 8}, {9, 10}, {11, 12}};

        int[][] result = multiply(A, B);

        for (int[] row : result) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}