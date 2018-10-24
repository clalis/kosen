package pr2calc;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SourceExample
{
//    private int a;
//    private int[][] b;
//    private String str;
//
//    public SourceExample()
//    {
//        int h, i;
//
//        this.a = -1;
//        this.b = new int[2][2];
//
//        for (h = 0; h < this.b.length; h++) for (i = 0; i < this.b[0].length; i++) this.b[h][i] = -1;
//
//        this.str = "";
//    }
//
//    public SourceExample(int a, int[][] b, String str)
//    {
//        this.a = a;
//        this.b = b;
//        this.str = str;
//    }
//
//
//    public SourceExample(String fileName)
//    {
//        try
//        {
//            loadData(fileName);
//        }
//        catch (IOException e)
//        {
//            System.out.println("Failed to open files.");
//            System.exit(1);
////            e.printStackTrace();
//        }
//    }
//
//    public void setA(int value)
//    {
//        this.a = value;
//    }
//
//    public int getA()
//    {
//        return this.a;
//    }
//
//    public void setB(int[][] value)
//    {
//        this.b = value;
//    }
//
//    public int[][] getB()
//    {
//        return this.b;
//    }
//
//    public void setStr(String value)
//    {
//        this.str = value;
//    }
//
//    public String getStr()
//    {
//        return this.str;
//    }
//
//    public void showAllContentsOfB()
//    {
//        for (int[] aB : this.b)
//        {
//            for (int j = 0; j < aB.length; j++)
//            {
//                System.out.print(" " + aB[j]);
//                if (j >= (aB.length - 1)) break;
//                System.out.print(",");
//            }
//            System.out.println();
//        }
//    }
//
//    private void loadData(String fileName) throws IOException
//    {
//        int row, column;
//        BufferedReader reader = new BufferedReader(new FileReader(fileName));
//        String buf;
//        String inputData;
//        String[] inputValue;
//
//        inputData = reader.readLine();
//        inputValue = inputData.split("\\s");
//
//        if (inputValue.length != 1) return;
//        else
//        {
//            this.a = Integer.parseInt(inputValue[0]);
//            inputData = reader.readLine();
//            inputValue = inputData.split("\\s");
//            if (inputValue.length != 2) return;
//            else
//            {
//                row = Integer.parseInt(inputValue[0]);
//                column = Integer.parseInt(inputValue[1]);
//                this.b = new int[row][column];
//                for (int h = 0; h < this.b.length; h++)
//                {
//                    inputData = reader.readLine();
//                    inputValue = inputData.split("\\s");
//                    for (int i = 0; i < this.b[h].length; i++) this.b[h][i] = Integer.parseInt(inputValue[i]);
//                }
//                inputData = reader.readLine();
//                inputValue = inputData.split("\\s");
//                buf = Arrays.stream(inputValue).map(anInputValue -> anInputValue + " ").collect(Collectors.joining());
//                this.str = buf;
//            }
//        }
//        reader.close();
//    }

    public void saveData(String saveFileName) throws IOException
    {
        int n = 37;
        Integer[] sizeIntegers = {3, 3};
        String s = "Hello world!";
        List<ArrayList<Object>> lists = new ArrayList<>();
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(saveFileName + ".dat")));

        lists.add(new ArrayList<>(Arrays.asList(n)));
        lists.add(new ArrayList<>(Arrays.asList(sizeIntegers)));
        for (int i = 0; i < sizeIntegers[0]; i++)
        {
            List<Object> objects = new ArrayList<>();
            for (int j = 0; j < sizeIntegers[1]; j++) objects.add(i * j);
            lists.add((ArrayList<Object>) objects);
        }
        lists.add(new ArrayList<>(Collections.singleton(s)));

        lists.forEach(objects ->
        {
            objects.stream().map(s1 -> String.valueOf(new StringBuilder().append(s1).append(" "))).forEachOrdered(writer::print);
            writer.println();
        });

        writer.close();
    }
}
