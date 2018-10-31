package pr2calc;

import org.apache.commons.math3.linear.MatrixUtils;
import org.apache.commons.math3.linear.RealMatrix;

public class Matrix
{
    public int numRow, numCol;
    public RealMatrix m;

    public Matrix()
    {
        numRow = 0;
        numCol = 0;
    }

    public Matrix(double[][] input)
    {
        m = MatrixUtils.createRealMatrix(input);
    }

    public Matrix(double[] input)
    {
        m = MatrixUtils.createRowRealMatrix(input);
    }

    public int getNumOfRow()
    {
        return m.getRowDimension();
    }

    public int getNumOfColumn()
    {
        return m.getColumnDimension();
    }

    public double showsComponentOf(int rowIndex, int columnIndex)
    {
        if ((rowIndex > m.getRowDimension()) || (columnIndex > m.getColumnDimension()))
        {
            System.out.println("Ordered component does not exist.");
            System.exit(0);
        }
        return m.getEntry(rowIndex, columnIndex);
    }

    public void display(String name)
    {
        System.out.println(new StringBuilder().append("~~~\t~~~\t").append(name));
        for (int i = 0; i < this.m.getRowDimension(); i++)
        {
            System.out.print("[");
            for (int j = 0; j < this.m.getColumnDimension(); j++)
            {
                System.out.print(this.m.getEntry(i, j));
                if (j < this.m.getColumnDimension() - 1) System.out.print(",");
            }
            System.out.println("]");
        }
        System.out.println();
    }

    // ベクトルAとBの内積 A・Bの結果を返す
    public double getInnerProduct(Matrix matrix)
    {
        double result = 0;
        if (this.m.getColumnDimension() == 1)
        {
            System.out.println("Matrix column is not enough to solve.");
            System.exit(0);
        }
        else if (this.m.getRowDimension() == 1)
        {
            if (matrix.m.getRowDimension() == 1) result = this.m.getRowVector(0).dotProduct(matrix.m.getRowVector(0));
            else if (matrix.m.getColumnDimension() == 1)
                result = this.m.getRowVector(0).dotProduct(matrix.m.getColumnVector(0));
            else
            {
                System.out.println("Matrix dimension is not even.");
                System.exit(0);
            }
        }
        return result;
    }

    // 行列同士、もしくは行列とベクトルとの積を計算する
    public Matrix multiplyMatrix(Matrix target)
    {
        Matrix ans = new Matrix();
        // 掛けられる行列の列数と掛ける行列の行数が等しいなら
        if (this.m.getColumnDimension() == target.m.getRowDimension())
            ans.m = this.m.multiply(target.m);
        else
        {
            System.out.println("Bad combination matrix.");
            System.exit(0);
        }
        return ans;
    }

    public boolean isMultipliable(Matrix y)
    {
        if (this.m.getColumnDimension() != y.m.getRowDimension())
        {
            System.out.println("Bad combination matrix.");
            return false;
        }
        return true;
    }
}
