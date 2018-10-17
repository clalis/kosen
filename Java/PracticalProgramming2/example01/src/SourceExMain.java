//4J23 pp2ex1
import pr2calc.SourceExample;

class SourceExMain
{
    public static void main(String[] args)
    {
        SourceExample ex;
        int[][] value = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

//        ex = new SourceExample();
//        ex.setA(10);
        ex = new SourceExample(3, value, "Hello world!");

        System.out.println("Object's a is " + ex.getA() + ".");
        ex.showAllContentsOfB();
        System.out.println(ex.getStr());
    }
}
