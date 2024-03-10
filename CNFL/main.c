#include <stdio.h>

int printScores(int n) {
    /*
     * For safety in 2:
     * For FG in 3s
     * For TD in 6s
     * For 7 points
     * For 8 Points in
     */

    for (int two = 0; two <= n; two += 8) {
        for (int tdF = 0; tdF <= n; tdF += 7) {
            for (int t = 0; t <= n; t += 6) {
                for (int f = 0; f <= n; f += 3) {
                    for (int s = 0; s <= n; s += 2) {

                        if ((two + tdF+ t + f + s) == n) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", two/8, tdF/7, t / 6, f / 3, s/2);
                        }

                    }//S End
                }//F End
            }//T End
        }//TD END
    }//8 End


}

int main() {

    int score;
    printf("Hello There!\nPlease Enter a Score (1 and 0 End Code):\n");
    scanf("%d", &score);
    while (score > 1) {
        printScores(score);
        printf("Hello There! Please Enter a Score: (1 and 0 End Program)");
        scanf("%d", &score);
    }

}
