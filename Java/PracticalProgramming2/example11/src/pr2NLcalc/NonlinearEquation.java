package pr2NLcalc;

public class NonlinearEquation {
    private static final double EPSILON = 0.001;
    private static final int MAXIMUM_IT = 100;

    public double answer_;
    public int iteration_;

    public NonlinearEquation() {
        answer_ = 0.0d;
        iteration_ = 0;
    }

    public Boolean _solveNLEByLinearIteration(double x0) {
        double value, pastValue;

        value = x0;

        for (int i = 0; i < MAXIMUM_IT; i++) {
            iteration_++;
            pastValue = value;
            value = Math.sqrt(10.0d + 3.0d + pastValue);
            System.out.println("value = " + value + ", pastValue = " + pastValue);
            if ((value - pastValue) < EPSILON) {
                answer_ = value;
                return Boolean.TRUE;
            }
        }

        return Boolean.FALSE;
    }

    public Boolean _solveNLEByBisectionMethod(double posMax, double negMax) {
        Double a = 3.0, x1 = negMax, x2 = posMax, xm = 0.0, pm, s1, sm;

        s1 = (x1 + a) == 0.0 ? 1.0 : Math.signum(Math.sin(x1 + a) / (x1 + a));

        //a = 3.0 max = 3.0
        for (int i = 0; i < MAXIMUM_IT; i++) {
            iteration_++;
            pm = xm;
            xm = (x1 + x2) / 2;
            sm = (xm + a) == 0.0 ? 1.0 : Math.signum(Math.sin(xm + a) / (xm + a));
            if (sm.equals(s1)) x1 = xm;
            else x2 = xm;
            System.out.println("xMid = " + xm + ", f(xMid) = " + (Math.sin(xm + a) / (xm + a)) + ", xPastMid = " + pm);
            if ((Math.abs((Math.sin(xm + a) / (xm + a)) - (Math.sin(pm + a) / (pm + a))) < EPSILON) || (xm == 0.0)) {
                answer_ = (Math.sin(xm + a) / (xm + a));
                return Boolean.TRUE;
            }
        }

        return Boolean.FALSE;
    }

    public Boolean _solveNLEByRegulaFalsi(double posMax, double negMax) {
        Double a = 1.0, x1 = negMax, x2 = posMax, xm = 0.0, pm, s1, sm;

        s1 = ((x1 + a) == 0.0) ? 1.0 : Math.signum(Math.sin(x1 + a) / (x1 + a));

        //a = 1.0 max = 5.0
        for (int i = 0; i < MAXIMUM_IT; i++) {
            iteration_++;
            pm = xm;
            xm = (x1 * Math.sin(x2 + a) / (x2 + a) - x2 * Math.sin(x1 + a) / (x1 + a)) / (Math.sin(x2 + a) / (x2 + a) - (Math.sin(x1 + a) / (x1 + a)));
            sm = (xm + a) == 0.0 ? 1.0 : Math.signum(Math.sin(xm + a) / (xm + a));
            if (sm.equals(s1)) x1 = xm;
            else x2 = xm;
            System.out.println("xMid = " + xm + ", f(xMid) = " + (Math.sin(xm + a) / (xm + a)) + ", xPastMid = " + pm);
            if ((Math.abs((Math.sin(xm + a) / (xm + a)) - (Math.sin(pm + a) / (pm + a))) < EPSILON) || (xm == 0.0)) {
                answer_ = xm;
                return Boolean.TRUE;
            }
        }

        return Boolean.FALSE;
    }

    public Boolean _solveNLEByNewton(double initValue) {
        Double a = 3.05, x0 = initValue, fx;

        // initValue = 1.19, a = 3.05
        for (int i = 0; i < MAXIMUM_IT; i++) {
            iteration_++;

            fx = x0 - (Math.exp(x0) - (a * x0)) / (Math.exp(x0) - a);
            System.out.println("xNext = " + fx + ", f(xNext) = " + (Math.exp(fx) - (a * fx)));
            if ((Math.abs(fx - x0)) < EPSILON) {
                answer_ = x0;
                return Boolean.TRUE;
            }

            x0 = fx;
        }

        return Boolean.FALSE;
    }
}
