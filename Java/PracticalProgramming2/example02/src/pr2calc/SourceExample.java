package pr2calc;

public class SourceExample
{
    public int a;
    public int[][] b;
    public String str;

    public SourceExample()
    {
        int h, i;

        this.a = -1;
        this.b = new int[2][2];

        for (h = 0; h < this.b.length; h++) for (i = 0; i < this.b[0].length; i++) this.b[h][i] = -1;

        this.str = "";
    }
    public SourceExample(int a, int[][] b, String str)
    {
        this.a = a;
        this.b = b;
        this.str = str;
    }

    public void setA(int value)
    {
        this.a = value;
    }

    public int getA()
    {
        return this.a;
    }

    public void setB(int[][] value)
    {
        this.b = value;
    }

    public int[][] getB()
    {
        return this.b;
    }

    public void setStr(String value)
    {
        this.str = value;
    }

    public String getStr()
    {
        return this.str;
    }

    public void showAllContentsOfB()
    {
        for (int i = 0; i < this.b.length; i++)
        {
            for (int j = 0; j < this.b[i].length; j++)
            {
                System.out.print(" " + this.b[i][j]);
                if (j >= (this.b[i].length - 1))   break;
                System.out.print(",");
            }
            System.out.println();
        }
    }
}
