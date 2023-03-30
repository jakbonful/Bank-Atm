#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


float balance = 100.0;

int userPin = 1234;

int authenticate(int enteredPin) {
	if (enteredPin == userPin) {
		return enteredPin;
	}
	else {
		int tries = 4;
		printf("Incorrect pin  please try again\n");
		while (tries > 0) {
			printf("%d tries remaining, please enter your correct pin\n", tries);
			scanf("%d", &enteredPin);
			if (enteredPin == userPin) {
				return enteredPin;
				break;
			}
			tries--;
			if (tries == 0) {
				printf("Too many attempts. Your card has been blocked.\n");
				exit(0);
			}

		}
	}
}

int requestAmount() {
	int amount;
	printf("How much would you like to take\n");
	scanf("%d", &amount);
	return amount;
}

int withDraw(int x) {
	if (x <= balance) {
		balance -= x;
		printf("%dcedis was debited from your account.\nYour remaining balance is %fcedis\n", x, balance);
	}
	else {
		printf("Insufficient funds to perform this transaction\n");
		return balance;
	}
}

void deposit() {
	int amountToDep;
	printf("Enter an amount to deposit: ");
	scanf("%d", &amountToDep);
	balance += amountToDep;
	printf("Your new balance is %f", balance);
}

void transfer() {
	int userTrans;
	int amountToTrans;
	printf("Enter 16 digit account number to transfer to, e.g (12XXXXXXXXXXX01): ");
	scanf("%d", &userTrans);
	printf("Enter amount to transfer: ");
	scanf("%d", &amountToTrans);
	if (amountToTrans <= balance) {
		balance -= amountToTrans;
		printf("Your new balance is %f", balance);
	}
	else {
		printf("Insufficient funds. Your current balance is %f cedis.\n", balance);
	}
}






int main() {

start:
	printf("Welcome to ABC BANK\nEnter your four digit pin\n");
	static int tries = 0, pin = 0;
	scanf("%d", &pin);

menu:
    if (authenticate(pin) && tries < 4) {
		int menu_item;
		printf("\nSelect an option\n1. Check Balance\n2. Withdrawal\n3. Deposit\n4.Transfer\n");
		scanf("%d", &menu_item);

		switch (menu_item) {
		case 1:
			printf("%g\n", balance);
			break;
		case 2:
			withDraw(requestAmount());
			break;
		case 3:
			deposit();
			break;
		case 4:
			transfer();
			break;
		}
	}
	 else {
		++tries;
		printf("Invalid pin after %d tries\n", tries);
		goto start;
	}
	


	int response;
	printf("\nWould you like to perfrom another transaction?\n1.Yes\n2.No\n");
	scanf("%d", &response);
	if (response == 1) {
		goto menu;
	}
	else {
		printf("Thank you for banking with us\n");
		return 0;
	}

	return 0;
}

