package tsp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

public class TSPController {
    private static final Integer MAX_DATA = 5000;
    private final ArrayList<ArrayList<Integer>> map;    // map[y][x]
    private Integer minDistance;

    public TSPController() {
        map = new ArrayList<>();
        minDistance = Integer.MAX_VALUE;
    }

    public void fileRead() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("out/production/resources/table.dat"));

        reader.lines().forEach(line -> map.add(Arrays.stream(Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray()).boxed().collect(Collectors.toCollection(ArrayList::new))));

        reader.close();
    }

    //デバックのため一回しかやらない
    public void searchRoot() {
        for (int start = 0; start < 1; start++) {
            ArrayList<Integer> gone = new ArrayList<>();    // 移動履歴
            int dist = 0;                                   // 現在の距離
            int step = 0;                                   // 移動回数
            int y = start;                                  // 現在の場所

            //最短経路の探索
            while ((step + 1) != MAX_DATA) {
                int min = Integer.MAX_VALUE;                // 最短距離
                int minx = 0;                               // 最短距離の対象
                gone.add(y);

                //現在の場所から最短の場所の探索
                for (int x = 0; x < MAX_DATA; x++) {
                    if (!gone.contains(x) && (map.get(y).get(x) < min)) {
                        min = map.get(y).get(x);
                        minx = x;
                    }
                }
//                 System.out.println(y + " minx:" + minx + " min:" + min + " dist:" + dist);
                step++;
                y = minx;
                dist += min;
            }

            //全体の最短経路かの判別
            System.out.println("start:" + start + " dist:" + dist + " minDist:" + minDistance);
            if (dist < minDistance) minDistance = dist;
        }
    }

    public void printResult() {
        System.out.println("dist: " + minDistance);
    }
}
