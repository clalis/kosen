package pr2calc;

import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

import java.util.Arrays;

public class SimultaneousEquation extends Matrix {
    RealMatrix matrix;
    double[] answers;

    public SimultaneousEquation() {
        super();
        this.matrix = m;
    }

    public SimultaneousEquation(double[][] input) {
        super(input);
        this.matrix = m;
    }

    public SimultaneousEquation(double[] input) {
        super(input);
        this.matrix = m;
    }

    public void normalize(int rowVar) {
        RealVector vector = matrix.getRowVector(rowVar);
        double val = 1 / vector.getEntry(rowVar);

        this.matrix.setRowVector(rowVar, vector.mapMultiplyToSelf(val));
    }

    public void subtractRowFrom(int from, int to) {
        RealVector fromVector = this.matrix.getRowVector(from);
        RealVector toVector = this.matrix.getRowVector(to);

        this.matrix.setRowVector(to, toVector.subtract(fromVector.mapMultiply(toVector.getEntry(from))));
    }

    public void solveByGaussJordan() {
        int rowDimension = this.matrix.getRowDimension();

        for (int i = 0; i < rowDimension; i++) {
            this.normalize(i);
            for (int j = 0; j < rowDimension; j++) {
                if (i == j) continue;
                this.subtractRowFrom(i, j);
            }
            this.display();
        }

        answers = this.matrix.getColumn(this.matrix.getColumnDimension() - 1);
        for (double answer : answers) System.out.print(new StringBuilder().append(answer).append("\t").toString());
        System.out.println();
    }
}
