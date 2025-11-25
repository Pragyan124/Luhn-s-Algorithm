#include<stdio.h>

/* Luhn's Algorithm Implementation to check if a credit card  number  is valid*/

int validCard(long long cardNumber){

    long long temp = cardNumber;
    int countdigit = 0; 
    int digit_sum = 0;

    while(temp > 0){
        countdigit++;
        temp = temp / 10;
    }
    
    //Initialize an storedigitay to store the digits of the number
    int storedigit[countdigit];

    //Add digits of the number to the storedigitay
    for(int i = countdigit - 1; i >= 0; i--){
        storedigit[i] = cardNumber % 10;
        cardNumber = cardNumber / 10;
    }

    for(int i = countdigit - 1; i >= 0; i--){
        if(i % 2 == 0){
            storedigit[i] = storedigit[i] * 2;
            if(storedigit[i] > 9){
                storedigit[i] = storedigit[i] - 9;
            }
        }
    }

    for(int i = 0; i < countdigit; i++){
        digit_sum += storedigit[i];
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