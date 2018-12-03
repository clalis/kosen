package pr2NLcalc;

public class NonlinearEquation {
    public static final double EPSILON = 0.001;
    public static final int MAXIMUM_IT = 100;

    private double initialValue_;
    private double answer_;
    private int iteration_;

    // コンストラクタ(最低一つ用意せよ）
    public NonlinearEquation(引数は各自で決定){
        // 処理を実装せよ
    }

    private 戻り値 _solveNLEByLinearIteration(引数は各自で決定)
    {
        double value,      // x_k に対応
                pastValue;  // x_{k-1} に対応（初回のpastValue = x_0とする）

        // 初期反復解をvalueに設定し
        // |value - pastValue| が EPSILON 未満となる(近似解が見つかる)、もしくは
        // 繰り返し回数がMAXIMUM_IT 回に到達するまで繰り返し
        // 繰り返しで得られる反復解の途中経過を表示するようにすること
    }
}
