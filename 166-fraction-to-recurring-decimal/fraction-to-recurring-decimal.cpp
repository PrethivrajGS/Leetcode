class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      if (numerator == 0) return "0";

    string result = "";

    if ((numerator < 0) ^ (denominator < 0))
        result += "-";
    long long n = llabs(numerator);
    long long d = llabs(denominator);

    result += to_string(n / d);

    long long remainder = n % d;
    if (remainder == 0)
        return result; // No fractional part

    result += ".";

    unordered_map<long long, int> remainderMap;
    while (remainder != 0) {
        if (remainderMap.find(remainder) != remainderMap.end()) {
            // Found a repeating remainder
            result.insert(remainderMap[remainder], "(");
            result += ")";
            break;
        }

        remainderMap[remainder] = result.size();
        remainder *= 10;
        result += to_string(remainder / d);
        remainder %= d;
    }

    return result;  
    }
};