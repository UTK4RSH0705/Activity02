# Activity02
#include <stdio.h>

int main() {
    printf("            ||MMCOE HOTEL||\n\n");
    printf("                      GSTIN:AAAPL1234C1Z5\n\n");
    
    char CustomerName[50];
    int RoomType, RoomNo, NoOfRoom, RoomTotal;
    long long TeleNo;

    printf("     Enter Customer Name: ");
    scanf(" %s", CustomerName);
    long AdharNo;
    printf("     Enter Adhaar Card Number:");
    scanf("%ld",&AdharNo);
    if(AdharNo<=99999999999||AdharNo>=1000000000000)
    {
        printf("Enter Valid Adhaar Card Number");
    }
    else{

    printf("     Enter Telephone Number: ");
    scanf("%lld", &TeleNo);
    printf("\n");

    if (TeleNo < 1000000000 || TeleNo > 9999999999){
        printf("     Enter Valid Number\n");
    } else {
        printf("     Type of Room Booked:\n");
        printf("       1. Single   2. Double\n");
        printf("     Room Type: ");
        scanf("%d", &RoomType);

        printf("     Number of Rooms Booked: ");
        scanf("%d", &NoOfRoom);

        RoomTotal = (RoomType == 2) ? 1500 * NoOfRoom : 1000 * NoOfRoom;

        for (int i = 0; i < NoOfRoom; i++){
            printf("     Room Number: ");
            scanf("%d", &RoomNo);
        }

        float GST = 0.05 * RoomTotal;
        float TotalBill = RoomTotal + GST + 150;

        printf("\n\n");
        printf("     Room Bill:        ₹%d\n", RoomTotal);
        printf("     GST:              ₹%.2f\n", GST);
        printf("     Service Tax:      ₹150\n");
        printf("----------------------------------\n");
        printf("     Total Bill:       ₹%.2f\n\n", TotalBill);

        printf("=========================================\n");
        printf("Address: 123, MG Road, Andheri, Mumbai, Maharashtra, 400058\n");
        printf("Contact:9876543210\n\n");
        printf("      THANK YOU FOR VISITING\n");
    }
}
    return 0;
}
