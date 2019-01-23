//4J23 Shiina

import pr2NLcalc.NonlinearEquation;

class Main {
    public static void main(String[] args) {
        NonlinearEquation eqn = new NonlinearEquation();

        if (eqn._solveNLEByRegulaFalsi(5.0, 0.0))
            System.out.println("X = " + eqn.answer_ + " at iteration " + eqn.iteration_ + ".");
        else {
            System.out.println("Cannot solve NLE.");
            System.exit(0);
        }
    }
}

/*
"C:\Program Files\Java\jdk-11.0.1\bin\java.exe" -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:63245,suspend=y,server=n -javaagent:C:\Users\s_cla\.IntelliJIdea2018.3\system\captureAgent\debugger-agent.jar -Dfile.encoding=UTF-8 -classpath "C:\Users\s_cla\Documents\repos\kosen\Java\PracticalProgramming2\example10\out\production\example10;C:\Users\s_cla\.m2\repository\org\apache\commons\commons-math3\3.6.1\commons-math3-3.6.1.jar;C:\Program Files\JetBrains\IntelliJ IDEA 2018.2.5\lib\idea_rt.jar" Main
        Connected to the target VM, address: '127.0.0.1:63245', transport: 'socket'
        xMid = 4.737797636355764, f(xMid) = -0.09040917653742735, xPastMid = 0.0
        xMid = 4.278145847776519, f(xMid) = -0.15993933175130398, xPastMid = 4.737797636355764
        xMid = 3.594865701054022, f(xMid) = -0.21613299470460137, xPastMid = 4.278145847776519
        xMid = 2.8602153928282474, f(xMid) = -0.1705471191102443, xPastMid = 3.594865701054022
        xMid = 2.3782067277726964, f(xMid) = -0.0693895935643059, xPastMid = 2.8602153928282474
        xMid = 2.197034326452006, f(xMid) = -0.017332711817567747, xPastMid = 2.3782067277726964
        xMid = 2.1526929210955448, f(xMid) = -0.0035208121532872352, xPastMid = 2.197034326452006
        xMid = 2.143723334140801, f(xMid) = -6.77756504755059E-4, xPastMid = 2.1526929210955448
        xMid = 2.1419980778258125, f(xMid) = -1.2903388699502918E-4, xPastMid = 2.143723334140801
        X = 2.1419980778258125 at iteration 9.
        Disconnected from the target VM, address: '127.0.0.1:63245', transport: 'socket'

        Process finished with exit code 0
*/
