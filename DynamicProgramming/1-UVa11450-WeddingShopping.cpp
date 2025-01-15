#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int price[25][25];
int memo[210][25];

int shop(int money, int g, int M, int C) {
    cout << "Called function shop(" << money << "," << g << ")" << endl;
    if (money < 0) {
        return -10000; 
    }
    if (g == C) {
        return M - money; // Money spent successfully
    }
    if (memo[money][g] != -1) {
        return memo[money][g]; // Memoization lookup
    }

    int ans = -1;
    for (int model = 1; model <= price[g][0]; model++) {
        int a = shop(money - price[g][model], g + 1, M, C);
        printf("Value of a is %d\n", a);
        ans = max(ans, a); // Maximize spending
    }

    printf("Memo set for (%d,%d) with value %d\n", money, g, ans);
    return memo[money][g] = ans;
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int M, C;
        scanf("%d %d", &M, &C);

        for (int i = 0; i < C; i++) {
            scanf("%d", &price[i][0]); // Number of models
            for (int j = 1; j <= price[i][0]; j++) {
                scanf("%d", &price[i][j]); // Prices of models
            }
        }

        memset(memo, -1, sizeof memo);
        int ans = shop(M, 0, M, C);

        if (ans < 0) {
            printf("No solution\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
