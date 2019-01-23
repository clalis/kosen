//4J23 Shiina

import pr2NLcalc.NonlinearEquation;

class Main {
    public static void main(String[] args) {
        NonlinearEquation eqn = new NonlinearEquation();

        if (eqn._solveNLEByNewton(1.19))
            System.out.println("X = " + eqn.answer_ + " at iteration " + eqn.iteration_ + ".");
        else {
            System.out.println("Cannot solve NLE.");
            System.exit(0);
        }
    }
}

/*
"C:\Program Files\Java\jdk-11.0.1\bin\java.exe" -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:63780,suspend=y,server=n -javaagent:C:\Users\s_cla\.IntelliJIdea2018.3\system\captureAgent\debugger-agent.jar -Dfile.encoding=UTF-8 -classpath "C:\Users\s_cla\Documents\repos\kosen\Java\PracticalProgramming2\example11\out\production\example11;C:\Users\s_cla\.m2\repository\org\apache\commons\commons-math3\3.6.1\commons-math3-3.6.1.jar;C:\Program Files\JetBrains\IntelliJ IDEA 2018.2.5\lib\idea_rt.jar" Main
        Connected to the target VM, address: '127.0.0.1:63780', transport: 'socket'
        xNext = 2.634310143332198, f(xNext) = 5.89905095598958
        xNext = 2.0923021276825864, f(xNext) = 1.7220276225179667
        xNext = 1.7515460403525986, f(xNext) = 0.42129098186919123
        xNext = 1.5962889968823843, f(xNext) = 0.06600432843821924
        xNext = 1.5612675999331678, f(xNext) = 0.0029911717097617085
        xNext = 1.5595233314042811, f(xNext) = 7.2442616163570506E-6
        xNext = 1.5595190864380264, f(xNext) = 4.285638510737044E-11
        X = 1.5595233314042811 at iteration 7.
        Disconnected from the target VM, address: '127.0.0.1:63780', transport: 'socket'

        Process finished with exit code 0
*/
