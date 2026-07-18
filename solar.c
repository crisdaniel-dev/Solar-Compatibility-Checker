#include <stdio.h>

   char showMenu() {

    char productCODE;

    printf("\n=====Solar Product Code=====\n");
    printf("B - Led bulb\n");
    printf("F - Fan\n");
    printf("R - Refrigerator\n");
    printf("W - Water pump\n");

    printf("\nEnter product code: ");
    scanf(" %c", & productCODE);

    return productCODE;

   }

   void checkCompatibility(char productCODE,int deviceVOLT,int batteryVOLT,int inverterAMP,int panelWATT) {

      if (productCODE == 'B') {
        if ((deviceVOLT == 5 || deviceVOLT == 12 || deviceVOLT == 24) && deviceVOLT <= batteryVOLT) {
            printf("\n=== Solar Led bulb is compatible with this setup ===");
        } else {
            printf("\n=== Invalid Solar Led bulb for this setup ===");
        }
    }

    else if (productCODE == 'F') {
        if ((deviceVOLT == 12 || deviceVOLT == 24 || deviceVOLT == 48) && deviceVOLT <= batteryVOLT) {
            printf("\n=== Solar Fan is compatible with this setup ===");
        } else {
            printf("\n=== Invalid Solar Fan for this setup ===");
        }
    }

    else if (productCODE == 'R') {
        if ((deviceVOLT == 12 || deviceVOLT == 24 || deviceVOLT == 48) && deviceVOLT <= batteryVOLT && panelWATT >= 150) {
            printf("\n=== Solar Refrigerator is compatible with this setup ===");
        } else {
            printf("\n=== Invalid Solar Refrigerator for this setup ===");
        }
    }

    else if (productCODE == 'W') {
        if ((deviceVOLT == 24 || deviceVOLT == 48) && deviceVOLT <= batteryVOLT && panelWATT >= 200) {
            printf("\n=== Solar Water pump is compatible with this setup ===");
        } else {
            printf("\n=== Invalid Solar Water pump for this setup ===");
        }
    }

    if (inverterAMP < 10) {
        printf("\nNOTE: Insufficient inverter amps for this setup\n");
    } else {
        printf("\nNOTE: Sufficient inverter amps with this setup\n");
    }

   }

   void suggestImprovements(int panelWATT, int inverterAMP, int batteryVOLT) {

    if (panelWATT < 100) {
        printf("\nNOTE: You need upgrade your panel wattage (100 - 600)");
    }

    if (inverterAMP < 10) {
        printf("\nNOTE: You need upgrade your inverter amps at least 10");
    }

    if (batteryVOLT < 12) {
        printf("\nNOTE: You need to upgrade your battery voltage (12, 24, 48)");
    }
    
   }

   int main () {

    char code[4] = {'B','F','R','W'};
    int minWatt[4] = {0,0,150,200};
    int maxVolt[4] = {24,48,48,48};
    int minVolt[4] = {5,12,12,24};
    char productCODE;
    int deviceVOLT,batteryVOLT,inverterAMP,panelWATT;
    char choice;
	int i;
	int v,a;

    do {

        do {

        productCODE = showMenu();
        if (productCODE != code[0] && productCODE != code[1] && productCODE != code[2] && productCODE != code[3]) {
            printf("Invalid code entered! Pls try again.\n");
        } else {
            break;
        }

        } while (1);


    printf("\nEnter device voltage (5, 12, 24, 48): ");
    scanf("%d", & deviceVOLT);

    printf("\nEnter panel wattage (100 - 600): ");
    scanf("%d", & panelWATT);

    printf("\nEnter battery voltage (12, 24, 48): ");
    scanf("%d", & batteryVOLT);

    printf("\nEnter inverter amps: ");
    scanf("%d", & inverterAMP);

    checkCompatibility(productCODE,deviceVOLT,batteryVOLT,inverterAMP,panelWATT);
    suggestImprovements(panelWATT,inverterAMP,batteryVOLT);

    for (i = 0; i < 4; i++) {
        if (productCODE == code[i]) {
            
            if (panelWATT < minWatt[i]) {
                printf("\nNOTE: Minimum panel wattage for this product is: %dW.\n",minWatt[i]);
            }

            if (deviceVOLT > maxVolt[i]) {
                printf("\nNOTE: Invalid device voltage, Maximum voltage is %dV.\n",maxVolt[i]);
                break;
            } else if (deviceVOLT < minVolt[i]) {
                printf("\nNOTE: Invalid device voltage, Minimum voltage is %dV.\n",minVolt[i]);
                break;
            }

            if (batteryVOLT < deviceVOLT) {
                printf("\nNOTE: You need to upgrade your battery voltage at least: %dV.\n",deviceVOLT);
            } else {
                printf("\nGOOD!\n");
            }
            break;
        }
    }

    printf("\n");

    printf("\n===== SOLAR WATTAGE GUIDE =====\n");
    for (v = 12; v <= batteryVOLT; v += 12) {
        for (a = 1; a <= inverterAMP; a++) {
            printf("%dV x %dA = %dW || ",v,a, v * a);
        }
    }

    printf("\nDo you want to check another solar product?If yes type Y/y: ");
    scanf(" %c", & choice);
    
    } while (choice == 'Y' || choice == 'y');

    printf("\nThank you for using solar compatibility checker\n");

    return 0;
   }
