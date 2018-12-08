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
}
