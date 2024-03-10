#include <stdio.h>
#include <stdlib.h>

#define MAX_SALES 12


void read_sales(const char *file_path, float sales[], int *num_sales) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *num_sales = 0;
    while (fscanf(file, "%f", &sales[*num_sales]) != EOF && *num_sales < MAX_SALES) {
        (*num_sales)++;
    }

    fclose(file);
}

void generate_report(const float sales[], int num_sales) {
    const char *months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    printf("Monthly sales report (Just for you:D ):\n");
    printf("Month       Sales\n");
    for (int i = 0; i < num_sales; i++) {
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }
}

void sales_summary(const float sales[], int num_sales) {
    float min = sales[0], max = sales[0], sum = 0, avg;
    int min_index = 0, max_index = 0;

    for (int i = 0; i < num_sales; i++) {
        if (sales[i] < min) {
            min = sales[i];
            min_index = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            max_index = i;
        }
        sum += sales[i];
    }
    avg = sum / num_sales;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f\n", min);
    printf("Maximum sales: $%.2f\n", max);
    printf("Average sales: $%.2f\n", avg);
}


void six_month_moving_avg(const float sales[], int num_sales) {
    const char *months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= num_sales - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%-9s - %-9s $%.2f\n", months[i], months[i + 5], sum / 6);
    }
}


int compare_sales(const void *a, const void *b) {
    float diff = *(const float *)a - *(const float *)b;
    return (diff > 0) - (diff < 0);
}


void sales_high_to_low(const float sales[], int num_sales) {
    const char *months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    float sorted_sales[MAX_SALES];
    for (int i = 0; i < num_sales; i++) {
        sorted_sales[i] = sales[i];
    }

    qsort(sorted_sales, num_sales, sizeof(float), compare_sales);

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month       Sales\n");
    for (int i = num_sales - 1; i >= 0; i--) {
        printf("%-9s $%.2f\n", months[i], sorted_sales[i]);
    }
}

int main() {
    char file_name[256];
    float sales[MAX_SALES];
    int num_sales = 0;

    printf("Hello There! UwU\nPlease enter the file name with monthly sales data (EG path/sales.txt): ");
    scanf("%255s", file_name);

    read_sales(file_name, sales, &num_sales);
    generate_report(sales, num_sales);
    sales_summary(sales, num_sales);
    six_month_moving_avg(sales, num_sales);
    sales_high_to_low(sales, num_sales);

    printf("\nThanks for grading this. I hope you're having a great day!\n");

    return 0;

}