package pr2SLcalc;

import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

public class SimultaneousEquation extends Matrix {
    private final RealMatrix matrix;
    private double[] answers;

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

        this.matrix.setRowVector(to, toVector.subtract(fromVector.mapMultiply(toVector.getEntry(from) / fromVector.getEntry(from))));
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
        for (double answer : answers) System.out.print(answer + "\t");
        System.out.println();
    }

    public void solveByGauss() {
        int rowDimension = this.matrix.getRowDimension();
        int colDimension = this.matrix.getColumnDimension();
        answers = new double[rowDimension];

        for (int i = 0; i < rowDimension; i++) {
            for (int j = i; j < rowDimension; j++) {
                if (i == j) continue;
                this.subtractRowFrom(i, j);
            }
            this.display();
        }

        answers[rowDimension - 1] = this.matrix.getEntry(rowDimension - 1, colDimension - 1) / this.matrix.getEntry(rowDimension - 1, colDimension - 2);
        backSubstitution(rowDimension, colDimension);

        for (double answer : answers) System.out.print(answer + "\t");
        System.out.println();
    }

    public void solveByGaussWithPartialSelection() {
        int rowDimension = this.matrix.getRowDimension();
        int colDimension = this.matrix.getColumnDimension();
        answers = new double[rowDimension];

        for (int i = 0; i < rowDimension; i++) {
            this.exchangeRows(selectPivotFromRow(i), i);
            for (int j = i; j < rowDimension; j++) {
                if (i == j) continue;
                this.subtractRowFrom(i, j);
            }
            this.display();
        }

        answers[rowDimension - 1] = this.matrix.getEntry(rowDimension - 1, colDimension - 1) / this.matrix.getEntry(rowDimension - 1, colDimension - 2);
        backSubstitution(rowDimension, colDimension);

        for (double answer : answers) System.out.print(answer + "\t");
        System.out.println();
    }

    protected void backSubstitution(int rowDimension, int colDimension) {
        for (int i = rowDimension - 2; i >= 0; --i) {
            double vd = 0.0d;
            for (int j = i + 1; j < rowDimension; ++j) vd += this.matrix.getEntry(i, j) * answers[j];
            answers[i] = (this.matrix.getEntry(i, colDimension - 1) - vd) / this.matrix.getEntry(i, i);
        }
    }

    protected void exchangeRows(int r1, int r2) {
        RealVector tempVector = this.matrix.getRowVector(r1);
        this.matrix.setRowVector(r1, this.matrix.getRowVector(r2));
        this.matrix.setRowVector(r2, tempVector);
    }

    protected int selectPivotFromRow(int cN) {
        int max = 0;

        for (int i = 0; i < this.matrix.getRowDimension(); i++)
            if (Math.abs(this.matrix.getEntry(i, cN)) > max) max = i;

        return max;
    }
}
