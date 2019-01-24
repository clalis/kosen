import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.TreeMap;


class StdUtil {
    private static final Integer fSampling = 400000;
    private static final Integer bitRate = 200;
    private static final Double ac = 1.0;
    private static final Double fc = 1000.0;
    private static final Double pc = ((-1.0) / 2.0) * Math.PI;

// --Commented out by Inspection START (2019/01/24 18:45):
//    public void exampleTest() {
//        System.out.println("Hello world!");
//
//        String[] result = StringUtils.split("hog,pio,foo,bar", ",");
//        System.out.println(Arrays.toString(result));
//    }
// --Commented out by Inspection STOP (2019/01/24 18:45)

    public void showTreeMap(TreeMap<Double, Double> treeMap) {
        treeMap.keySet().stream().map(key -> key + ", " + treeMap.get(key)).forEach(System.out::println);
    }

    public void outFileTreeMap(TreeMap<Double, Double> treeMap, String fileName) throws FileNotFoundException {
        PrintWriter printWriter = new PrintWriter(fileName);
        treeMap.keySet().stream().map(key -> key + ", " + treeMap.get(key)).forEach(printWriter::println);
    }

    public TreeMap<Double, Double> encodeBPSK(ArrayList<Boolean> booleans) {
        TreeMap<Double, Double> doubleTreeMap = new TreeMap<>();
        Integer bitCnt = 0;

        for (Boolean b : booleans) {
            if (b) for (int n = 0; n < fSampling / bitRate; n++)
                doubleTreeMap.put((double) n / fSampling + bitCnt.doubleValue() / bitRate.doubleValue(), ac * Math.cos(2 * Math.PI * fc * n / fSampling + Math.PI + pc));
            else for (int n = 0; n < fSampling / bitRate; n++)
                doubleTreeMap.put((double) n / fSampling + bitCnt.doubleValue() / bitRate.doubleValue(), ac * Math.cos(2 * Math.PI * fc * n / fSampling + pc));
            bitCnt++;
        }

        return doubleTreeMap;
    }

    public void decodeBPSK(TreeMap<Double, Double> doubleTreeMap) {
        doubleTreeMap.keySet().forEach(key -> doubleTreeMap.replace(key, doubleTreeMap.get(key) * ac * Math.cos(2 * Math.PI * fc * key + pc)));
    }

    public void applyLPF(TreeMap<Double, Double> doubleTreeMap) {
        final double factor = 0.99609375;
        double pV = 0.0;    // factor = 1 - 1 / 2 ^ 8
        for (Double key : doubleTreeMap.keySet()) {
            doubleTreeMap.replace(key, doubleTreeMap.get(key) + (pV - doubleTreeMap.get(key)) * factor);
            pV = doubleTreeMap.get(key);
        }
    }
}
