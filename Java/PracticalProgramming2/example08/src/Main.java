//4J23 Shiina

import pr2NLcalc.NonlinearEquation;

class Main {
    public static void main(String[] args) {
        NonlinearEquation eqn = new NonlinearEquation();

        if (eqn._solveNLEByLinearIteration(4.0d))
            System.out.println("X = " + eqn.answer_ + " at iteration " + eqn.iteration_ + ".");
        else {
            System.out.println("Cannot solve NLE.");
            System.exit(0);
        }
    }
}


/*
"C:\Program Files\Java\jdk-11.0.1\bin\java.exe" -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:62453,suspend=y,server=n -javaagent:C:\Users\s_cla\.IntelliJIdea2018.2\system\captureAgent\debugger-agent.jar=file:/C:/Users/s_cla/AppData/Local/Temp/capture.props -Dfile.encoding=UTF-8 -classpath "C:\Users\s_cla\Documents\repos\kosen\Java\PracticalProgramming2\example08\out\production\example08;C:\Users\s_cla\.m2\repository\org\apache\commons\commons-math3\3.6.1\commons-math3-3.6.1.jar;C:\Program Files\JetBrains\IntelliJ IDEA 2018.2.5\lib\idea_rt.jar" Main
        Connected to the target VM, address: '127.0.0.1:62453', transport: 'socket'
        value = 4.123105625617661, pastValue = 4.0
        value = 4.138007446297996, pastValue = 4.123105625617661
        value = 4.139807658128333, pastValue = 4.138007446297996
        value = 4.140025079408135, pastValue = 4.139807658128333
        Disconnected from the target VM, address: '127.0.0.1:62453', transport: 'socket'
        X = 4.140025079408135 at iteration 4.

        Process finished with exit code 0
*/
