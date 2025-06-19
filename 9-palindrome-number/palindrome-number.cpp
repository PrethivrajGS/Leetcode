
class Solution {
public:
    bool isPalindrome(int x) {
       
        if (x < 0) {
            return false;
        }

        int original = x;
        double reversed = 0;

       
        while (x > 0) {
            double digit = x % 10;           
            reversed = reversed * 10 + digit;  
            x /= 10;                      
        }
        return original == reversed;
    }
};
/*
int main() {
    Solution solution;
    bool ret = solution.isPalindrome(121);  
    cout << ret << endl;  

    ret = solution.isPalindrome(-121);     
    cout << ret << endl;

    ret = solution.isPalindrome(10);       
    cout << ret << endl;

    ret = solution.isPalindrome(12321);    
    cout << ret << endl;

    return 0;
}
*/