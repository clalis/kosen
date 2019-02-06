// PP2_ex12 4J23_Shina

import tsp.TSPController;

import java.io.IOException;

class tspMain {
    public static void main(String[] args) {
        long start = System.currentTimeMillis();

        TSPController test = new TSPController();
        try {
            test.fileRead();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
        test.searchRoot();
        test.printResult();

        long end = System.currentTimeMillis();
        System.out.println("Processing duration is " + ((end - start) / 1000) + " sec.");
    }
}

/*
"C:\Program Files\Java\jdk-11.0.1\bin\java.exe" -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:52173,suspend=y,server=n -javaagent:C:\Users\s_cla\.IntelliJIdea2018.3\system\groovyHotSwap\gragent.jar -javaagent:C:\Users\s_cla\.IntelliJIdea2018.3\system\captureAgent\debugger-agent.jar -Dfile.encoding=UTF-8 -classpath "C:\Users\s_cla\Documents\repos\kosen\Java\PracticalProgramming2\example12\out\production\classes;C:\Users\s_cla\Documents\repos\kosen\Java\PracticalProgramming2\example12\out\production\resources;C:\Program Files\JetBrains\IntelliJ IDEA 2018.2.5\lib\idea_rt.jar" tspMain
        Connected to the target VM, address: '127.0.0.1:52173', transport: 'socket'
        start:0 dist:447 minDist:2147483647
        start:1 dist:300 minDist:447
        start:2 dist:366 minDist:300
        start:3 dist:359 minDist:300
        start:4 dist:513 minDist:300
        start:5 dist:453 minDist:300
        start:6 dist:325 minDist:300
        start:7 dist:454 minDist:300
        dist: 300
        Processing duration is 552 sec.
        Disconnected from the target VM, address: '127.0.0.1:52173', transport: 'socket'

        Process finished with exit code 0
*/
