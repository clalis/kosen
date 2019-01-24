import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {
        StdUtil stdUtil = new StdUtil();
        ArrayList<Boolean> booleans = new ArrayList<>(Arrays.asList(Boolean.FALSE, Boolean.TRUE, Boolean.FALSE, Boolean.TRUE, Boolean.TRUE, Boolean.FALSE));
        TreeMap<Double, Double> doubleTreeMap;

        System.out.println("It begins.");
        try {
            doubleTreeMap = stdUtil.encodeBPSK(booleans);
            stdUtil.showTreeMap(doubleTreeMap);
            stdUtil.outFileTreeMap(doubleTreeMap, "outEncoded.txt");
            stdUtil.decodeBPSK(doubleTreeMap);
            stdUtil.outFileTreeMap(doubleTreeMap, "outDecoded.txt");
            stdUtil.applyLPF(doubleTreeMap);
            stdUtil.outFileTreeMap(doubleTreeMap, "outLPF.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println("Finished.");
    }
}
