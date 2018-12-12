//4J23 Shiina

import pr2NLcalc.NonlinearEquation;

class Main {
    public static void main(String[] args) {
        NonlinearEquation eqn = new NonlinearEquation();

        if (eqn._solveNLEByBisectionMethod(3.0, 0.0))
            System.out.println("X = " + eqn.answer_ + " at iteration " + eqn.iteration_ + ".");
        else {
            System.out.println("Cannot solve NLE.");
            System.exit(0);
        }
    }
}


/*
"C:\Program Files\Java\jdk-11.0.1\bin\java.exe" -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:51636,suspend=y,server=n -javaagent:C:\Users\s_cla\.IntelliJIdea2018.2\system\captureAgent\debugger-agent.jar=file:/C:/Users/s_cla/AppData/Local/Temp/capture.props -Dfile.encoding=UTF-8 -classpath "C:\Users\s_cla\Documents\repos\kosen\Java\PracticalProgramming2\example08\out\production\example08;C:\Users\s_cla\.m2\repository\org\apache\commons\commons-math3\3.6.1\commons-math3-3.6.1.jar;C:\Program Files\JetBrains\IntelliJ IDEA 2018.2.5\lib\idea_rt.jar" Main
        Connected to the target VM, address: '127.0.0.1:51636', transport: 'socket'
        xMid = 1.5, f(xMid) = -0.21722891503668823, xPastMid = 0.0
        xMid = 0.75, f(xMid) = -0.152416351664625, xPastMid = 1.5
        xMid = 0.375, f(xMid) = -0.06853149997096943, xPastMid = 0.75
        xMid = 0.1875, f(xMid) = -0.014397246516950494, xPastMid = 0.375
        xMid = 0.09375, f(xMid) = 0.015458393324604481, xPastMid = 0.1875
        xMid = 0.140625, f(xMid) = 3.0810855762221834E-4, xPastMid = 0.09375
        xMid = 0.1640625, f(xMid) = -0.007100983511811885, xPastMid = 0.140625
        xMid = 0.15234375, f(xMid) = -0.0034104431975624946, xPastMid = 0.1640625
        xMid = 0.146484375, f(xMid) = -0.001554656346030668, xPastMid = 0.15234375
        xMid = 0.1435546875, f(xMid) = -6.241445899367854E-4, xPastMid = 0.146484375
        X = -6.241445899367854E-4 at iteration 10.
        Disconnected from the target VM, address: '127.0.0.1:51636', transport: 'socket'

        Process finished with exit code 0
*/
