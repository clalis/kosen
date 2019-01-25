import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeMap;

class Main {
    public static void main(String[] args) {
        StdUtil stdUtil = new StdUtil();
        ArrayList<Boolean> booleans = new ArrayList<>(Arrays.asList(Boolean.FALSE, Boolean.TRUE, Boolean.FALSE, Boolean.TRUE, Boolean.TRUE, Boolean.FALSE));
        TreeMap<Double, Double> doubleTreeMapASK, doubleTreeMapBPSK;

        System.out.println("It begins.");
        try {
            doubleTreeMapASK = stdUtil.encodeASK(booleans);
            doubleTreeMapBPSK = stdUtil.encodeBPSK(booleans);
            stdUtil.outFileTreeMap(doubleTreeMapASK, "outEncoded_ASK.txt");
            stdUtil.decodeASK(doubleTreeMapASK);
            stdUtil.outFileTreeMap(doubleTreeMapASK, "outDecoded_ASK.txt");
            stdUtil.applyLPF(doubleTreeMapASK);
            stdUtil.outFileTreeMap(doubleTreeMapASK, "outLPF_ASK.txt");
            stdUtil.showTreeMap(doubleTreeMapBPSK);
            stdUtil.outFileTreeMap(doubleTreeMapBPSK, "outEncoded_BPSK.txt");
            stdUtil.decodeBPSK(doubleTreeMapBPSK);
            stdUtil.outFileTreeMap(doubleTreeMapBPSK, "outDecoded_BPSK.txt");
            stdUtil.applyLPF(doubleTreeMapBPSK);
            stdUtil.outFileTreeMap(doubleTreeMapBPSK, "outLPF_BPSK.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println("Finished.");
    }
}
