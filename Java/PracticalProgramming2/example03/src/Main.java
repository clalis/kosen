//4J23 Shiina
import pr2calc.Matrix;

public class Main {

    public static void main(String[] args) {
        Matrix mat0, mat1, mat2;

        double[]
                v0 = {2.0, -3.0, 7.0};
        double[][]
                m0 = {
                {1.0, 2.0, 3.0},
                {3.0, 2.0, -1.0},
                {4.0, 2.0, 6.0}},

                m1 = {
                        {8.0, 2.0},
                        {-3.0, 2.0},
                        {1.0, 6.0}},

                v1 = {
                        {3.0},
                        {-2.0}},

                d;


        mat0 = new Matrix(v0);
        mat1 = new Matrix(m1);
        mat2 = new Matrix(v1);
// 以下は、行列・ベクトル演算の実行＆結果表示の一例．不要であれば削除し，課題の条件を満たす記述を新たに追加すること

        System.out.println("v0 = ");
        mat0.display(mat0.m, mat0.toString());
        System.out.println("m1 = ");
        mat1.display(mat1.m, mat1.toString());
        System.out.println("v1 = ");
        mat2.display(mat2.m, mat2.toString());

        System.out.println("例題0a");
        System.out.println("v0 * m1 = ");
        if (mat0.multipliable(mat1) == true)
            (mat0.multiplyMatrix(mat1)).display(mat0.multiplyMatrix(mat1).m, mat0.multiplyMatrix(mat1).toString());

        System.out.println("例題0b");
        System.out.println("v0 * v1 = ");
        if (mat0.multipliable(mat2) == true)
            (mat0.multiplyMatrix(mat1)).display(mat0.multiplyMatrix(mat1).m, mat0.multiplyMatrix(mat1).toString());
    }
}
