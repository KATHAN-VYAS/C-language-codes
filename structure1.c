#include<stdio.h>
struct Employee
{
    char name[20];
    int EID;
    float exp;
};
void main() 
{
    struct Employee e; // or {"kathan",22,2.5}
    printf("name:");
    scanf("%s",&e.name); //we can exclude & for array because it array it self is a location 
    printf("eid:");
    scanf("%d",&e.EID); //"."is used where there is no pointers for pointers "->" is used
    printf("exp:");
    scanf("%f",&e.exp);
    printf("printing data");
    printf("%s\n",e.name);
    printf("%d\n",e.EID);
    printf("%f\n",e.exp);

}
