package pr2SLcalc;

import org.apache.commons.math3.geometry.euclidean.threed.Rotation;
import org.apache.commons.math3.geometry.euclidean.threed.RotationConvention;
import org.apache.commons.math3.geometry.euclidean.threed.Vector3D;
import org.apache.commons.math3.linear.MatrixUtils;
import org.apache.commons.math3.linear.RealMatrix;

public class Matrix {
    public int numRow, numCol;
    public RealMatrix m;

    public Matrix() {
        numRow = 0;
        numCol = 0;
    }

    public Matrix(double[][] input) {
        m = MatrixUtils.createRealMatrix(input);
    }

    public Matrix(double[] input) {
        m = MatrixUtils.createRowRealMatrix(input);
    }

    private void internalDisplay() {
        for (int i = 0; i < this.m.getRowDimension(); i++) {
            System.out.print("[");
            for (int j = 0; j < this.m.getColumnDimension(); j++) {
                System.out.print(this.m.getEntry(i, j));
                if (j < this.m.getColumnDimension() - 1) System.out.print(",\t");
            }
            System.out.println("]");
        }
    }

    public void display() {
        System.out.println(new StringBuilder().append("~~~\t~~~\t"));
        internalDisplay();
        System.out.println();
    }

    public void namedDisplay(String name) {
        System.out.println(new StringBuilder().append("~~~\t~~~\t").append(name));
        internalDisplay();
        System.out.println();
    }

    public boolean isMultipliable(Matrix y) {
        if (this.m.getColumnDimension() != y.m.getRowDimension()) {
            System.out.println("Bad combination matrix.");
            return false;
        }
        return true;
    }

    public int getNumOfRow() {
        return m.getRowDimension();
    }

    public int getNumOfColumn() {
        return m.getColumnDimension();
    }

    public double showsComponentOf(int rowIndex, int columnIndex) {
        if ((rowIndex > m.getRowDimension()) || (columnIndex > m.getColumnDimension())) {
            System.out.println("Ordered component does not exist.");
            System.exit(0);
        }
        return m.getEntry(rowIndex, columnIndex);
    }

    public double getInnerProduct(Matrix matrix)    // ベクトルAとBの内積 A・Bの結果を返す
    {
        double result = 0;
        if (this.m.getColumnDimension() == 1) {
            System.out.println("Matrix column is not enough to solve.");
            System.exit(0);
        } else if (this.m.getRowDimension() == 1) {
            if (matrix.m.getRowDimension() == 1) result = this.m.getRowVector(0).dotProduct(matrix.m.getRowVector(0));
            else if (matrix.m.getColumnDimension() == 1)
                result = this.m.getRowVector(0).dotProduct(matrix.m.getColumnVector(0));
            else {
                System.out.println("Matrix dimension is not even.");
                System.exit(0);
            }
        }
        return result;
    }

    public Matrix multiplyMatrix(Matrix target) // 行列同士、もしくは行列とベクトルとの積を計算する
    {
        Matrix ans = new Matrix();
        // 掛けられる行列の列数と掛ける行列の行数が等しいなら
        if (this.m.getColumnDimension() == target.m.getRowDimension())
            ans.m = this.m.multiply(target.m);
        else {
            System.out.println("Bad combination matrix.");
            System.exit(0);
        }
        return ans;
    }

    public Matrix transpose() {
        Matrix matrix = new Matrix();
        matrix.m = this.m.transpose();

        return matrix;
    }

    public Matrix rotate(double deg)    // Thanks for "https://www.programcreek.com/java-api-examples/index.php?api=org.apache.commons.math3.geometry.euclidean.threed.Rotation"
    {
        RealMatrix matrix = this.m;
        double[] ans;
        double rad = deg / 180 * Math.PI;

        if (matrix.getRowDimension() <= 1)
            matrix = MatrixUtils.createColumnRealMatrix(new double[]{this.m.getEntry(0, 0), this.m.getEntry(0, 1)});
        if (matrix.getRowDimension() <= 1) {
            System.out.println("Not enough dimensions.");
            System.exit(0);
        }
        Vector3D vector3D = new Vector3D(matrix.getEntry(0, 0), matrix.getEntry(1, 0), 0.0);
        Rotation rotation = new Rotation(Vector3D.PLUS_K, rad, RotationConvention.VECTOR_OPERATOR);
        Vector3D answer = rotation.applyTo(vector3D);

        ans = new double[]{answer.getX(), answer.getY()};
        Matrix result = new Matrix(ans);

        return result.transpose();
    }
}
