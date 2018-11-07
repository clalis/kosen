//4J23 Shiina

import pr2calc.Matrix;
import pr2calc.SimultaneousEquation;

public class Main {
    public static void main(String[] args) {
        Matrix mat0, mat1, mat2;
        SimultaneousEquation sMat0;
        double[]
                v0 = {-3.0, 3.0};
        double[][]
                m0 =
                {
                        {1.0, 2.0, 3.0},
                        {3.0, 2.0, -1.0},
                        {4.0, 2.0, 6.0}
                },
                m1 =
                        {
                                {8.0, 2.0},
                                {-3.0, 2.0},
                                {1.0, 6.0}
                        },
                v1 =
                        {
                                {3.0},
                                {-2.0}
                        },
                d =
                        {
                                {2.0, 1.0, 3.0, 4.0, 2.0},
                                {3.0, 2.0, 5.0, 2.0, 12.0},
                                {3.0, 4.0, 1.0, -1.0, 4.0},
                                {-1.0, -3.0, 1.0, 3.0, -1.0},
                        };

        mat0 = new Matrix(v0);
        mat1 = new Matrix(m1);
        mat2 = new Matrix(v1);
        sMat0 = new SimultaneousEquation(d);
// 以下は、行列・ベクトル演算の実行＆結果表示の一例．不要であれば削除し，課題の条件を満たす記述を新たに追加すること

        System.out.println("v0 = ");
        mat0.namedDisplay("mat0");
        System.out.println("m1 = ");
        mat1.namedDisplay("mat1");
        System.out.println("v1 = ");
        mat2.namedDisplay("mat2");

//        pp2_ex3
//        System.out.println("例題0a");
//        System.out.println("v0 * m1 = ");
//        if (mat0.isMultipliable(mat1)) (mat0.multiplyMatrix(mat1)).display();
//
//        System.out.println("例題0b");
//        System.out.println("v0 * v1 = ");
//        if (mat0.isMultipliable(mat2)) (mat0.multiplyMatrix(mat2)).display();

//        pp2_ex4
//        mat1.display();
//        mat1.transpose().display();
//        mat0.rotate(45.0).display();
//        mat2.rotate(60.0).display();

//        pp2_ex5
        sMat0.display();
        sMat0.solveByGaussJordan();
    }
}

/*
"C:\Program Files\Java\jdk-11.0.1\bin\java.exe" -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:54313,suspend=y,server=n -javaagent:C:\Users\s_cla\.IntelliJIdea2018.2\system\captureAgent\debugger-agent.jar=file:/C:/Users/s_cla/AppData/Local/Temp/capture.props -Dfile.encoding=UTF-8 -classpath "C:\Users\s_cla\Documents\repos\kosen\Java\PracticalProgramming2\example05\out\production\example05;C:\Users\s_cla\.m2\repository\org\apache\commons\commons-math3\3.6.1\commons-math3-3.6.1.jar;C:\Program Files\JetBrains\IntelliJ IDEA 2018.2.5\lib\idea_rt.jar" Main
        Connected to the target VM, address: '127.0.0.1:54313', transport: 'socket'
        v0 =
        ~~~	~~~	mat0
        [-3.0,	3.0]

        m1 =
        ~~~	~~~	mat1
        [8.0,	2.0]
        [-3.0,	2.0]
        [1.0,	6.0]

        v1 =
        ~~~	~~~	mat2
        [3.0]
        [-2.0]

        ~~~	~~~
        [2.0,	1.0,	3.0,	4.0,	2.0]
        [3.0,	2.0,	5.0,	2.0,	12.0]
        [3.0,	4.0,	1.0,	-1.0,	4.0]
        [-1.0,	-3.0,	1.0,	3.0,	-1.0]

        ~~~	~~~
        [1.0,	0.5,	1.5,	2.0,	1.0]
        [0.0,	0.5,	0.5,	-4.0,	9.0]
        [0.0,	2.5,	-3.5,	-7.0,	1.0]
        [0.0,	-2.5,	2.5,	5.0,	0.0]

        ~~~	~~~
        [1.0,	0.0,	1.0,	6.0,	-8.0]
        [0.0,	1.0,	1.0,	-8.0,	18.0]
        [0.0,	0.0,	-6.0,	13.0,	-44.0]
        [0.0,	0.0,	5.0,	-15.0,	45.0]

        ~~~	~~~
        [1.0,	0.0,	0.0,	8.166666666666666,	-15.333333333333332]
        [0.0,	1.0,	0.0,	-5.833333333333334,	10.666666666666668]
        [-0.0,	-0.0,	1.0,	-2.1666666666666665,	7.333333333333333]
        [0.0,	0.0,	0.0,	-4.166666666666668,	8.333333333333336]

        ~~~	~~~
        [1.0,	0.0,	0.0,	0.0,	1.0]
        [0.0,	1.0,	0.0,	0.0,	-1.0]
        [-0.0,	-0.0,	1.0,	0.0,	3.0]
        [-0.0,	-0.0,	-0.0,	1.0,	-2.0]

        1.0	-1.0	3.0	-2.0
        Disconnected from the target VM, address: '127.0.0.1:54313', transport: 'socket'

        Process finished with exit code 0
*/
