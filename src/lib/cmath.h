class CalcMath {
public:
    /**
     * @brief Math addition
     * @param number_1 first number for addition
     * @param number_2 second number for addition
     */
    static double add(double number_1, double number_2);

    /**
     * @brief Math subtraction
     * @param number_1 first number for subtraction
     * @param number_2 second number for subtraction
     */
    static double sub(double number_1, double number_2);

    /**
     * @brief Math multiplication
     * @param number_1 first number for multiplication
     * @param number_2 second number for multiplication
     */
    static double mult(double number_1, double number_2);

    /**
     * @brief Math division
     * @param dividend dividend
     * @param divisor divisor
     */
    static double div(double dividend, double divisor);

    /**
     * @brief Math exponentiation
     * @param basis base for exponent
     * @param exponent exponent
     */
    static double pow(double basis, double exponent);

    /**
     * @brief Math square root
     * @param n_root n-th root
     * @param number Neviem prosim doplnit xD
     */
    static double root(double n_root, double number);

    /**
     * @brief Math logarithm
     * @param basis base of logarithm
     * @param logarithm logarithm
     */
    static double log(double basis, double logarithm);

    /**
     * @brief Math factorial
     * @param number factorial number 
     */
    static unsigned long fact(unsigned long number);
};