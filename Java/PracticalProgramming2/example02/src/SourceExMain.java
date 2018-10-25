//4J23 Shina
import pr2calc.SourceExample;

import java.io.IOException;
import java.util.Scanner;

class SourceExMain
{
    public static void main(String[] args)
    {
        SourceExample ex;
//        int[][] value = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//
//        ex = new SourceExample();
//        ex.setA(10);

        ex = new SourceExample();
        try
        {
            ex.saveData("savedSample");
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

/*
        if (args.length == 1) ex = new SourceExample(args[0]);
        else
        {
            System.out.println("File name is incorrect. Please retry.");
            String fn;
            fn = new Scanner(System.in).next();
            if (fn.endsWith("sample.dat")) ex = new SourceExample(fn);
            else
            {
                ex = null;
                System.exit(1);
            }
        }

        System.out.println("Object's a is " + ex.getA() + ".");
        ex.showAllContentsOfB();
        System.out.println(ex.getStr());
*/
    }
}
