#include<stdio.h>

/* Luhn's Algorithm Implementation to check if a credit card  number  is valid*/

int validCard(long long card_number){

    long long temp = card_number;
    int count_digit = 0; 
    int digit_sum = 0;

    while(temp > 0){
        count_digit++;
        temp = temp / 10;
    }
    
    //Initialize an storedigitay to store the digits of the number
    int store_digit[count_digit];

    //Add digits of the number to the storedigitay
    for(int i = count_digit - 1; i >= 0; i--){
        store_digit[i] = card_number % 10;
        card_number = card_number / 10;
    }

    for(int i = count_digit - 1; i >= 0; i--){
        if(i % 2 == 0){
            store_digit[i] = store_digit[i] * 2;
            if(store_digit[i] > 9){
                store_digit[i] = store_digit[i] - 9;
            }
        }
    }

    for(int i = 0; i < count_digit; i++){
        digit_sum += store_digit[i];
    }


    if (digit_sum % 10 == 0) {
        printf("The card is valid \n"); 
        return 0;
    } else {
        printf("The card is not valid \n"); 
        return 1;
    }
}

int main(){
    int result = validCard(4830859599038301);
    printf("Result: %d\n", result);
    
}
