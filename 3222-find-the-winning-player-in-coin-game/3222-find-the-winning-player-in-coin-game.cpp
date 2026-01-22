class Solution {
public:
    string winningPlayer(int x, int y) {
        int moves = min(x, y / 4);

        if (moves == 0) return "Bob";

        return (moves % 2 == 1) ? "Alice" : "Bob";
    }
};
