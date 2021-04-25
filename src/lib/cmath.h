class CalcMath {
public:
    /**
     * @brief Math addition
     * @param number_1 first number for addition
     * @param number_2 second number for addition
     * @return Sum of number_1 and number_2
     */
    static double add(double number_1, double number_2);

    /**
     * @brief Math subtraction
     * @param number_1 first number for subtraction
     * @param number_2 second number for subtraction
     * @return Substraction of number_1 and number_2
     */
    static double sub(double number_1, double number_2);

    /**
     * @brief Math multiplication
     * @param number_1 first number for multiplication
     * @param number_2 second number for multiplication
     * @return Multiplication of number_1 and number_2
     */
    static double mult(double number_1, double number_2);

    /**
     * @brief Math division
     * @param dividend dividend
     * @param divisor divisor
     * @return Divident divided by divisor
     * @throw invalid_argument Division by zero!
     */
    static double div(double dividend, double divisor);

    /**
     * @brief Math exponentiation
     * @param basis base for exponent
     * @param exponent exponent
     * @return Basis to the power of exponent
     */
    static double pow(double basis, double exponent);

    /**
     * @brief Math square root
     * @param degree degree of the root
     * @param number number from which n-th root is calculated
     * @return N-th root of number
     * @throw invalid_argument nth root, n is not an integer!
     * @throw invalid_argument nth root, n is lower than 1!
     * @throw invalid_argument nth root, number cannot be negative if root is even!
     */
    static double root(double degree, double number);

    /**
     * @brief Math logarithm
     * @param basis base of logarithm
     * @param logarithm logarithm
     * @return Logarithm from number with base basis
     * @throw invalid_argument basis cannot be lower or equal to zero!
     * @throw invalid_argument basis cannot be 1!
     * @throw invalid_argument number cannot be lower or equal to zero!
     */
    static double log(double basis, double number);

    /**
     * @brief Math factorial
     * @param number factorial number
     * @retuern Factorial of number
     * @throw invalid_argument number must be positive integer!
     */
    static unsigned long fact(double number);
};