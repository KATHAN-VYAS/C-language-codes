#include<stdio.h>
struct employee
{
    int id ;
    char name[20];
    float exp;
};
void main()
{
    struct employee *e,k; // or {"kathan",22,2.5}
   
    e = &k;
    printf("name:");
    scanf("%s",&e->name); //we can exclude "&" for array because it array it self is a location 
    printf("eid:");
    scanf("%d",&e->id);
    printf("exp:");
    scanf("%f",&e->exp);
    printf("%s\n",e->name);
    printf("%d\n",e->id);
    printf("%f\n",e->exp);

   

}