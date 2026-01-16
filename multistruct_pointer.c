    #include<stdio.h>
    
    struct student{
        char name [20];
        int roll_no;
        float CPI;
    };
    void main()
    {
        struct student *p[3],s1,s2,s3;
        p[0]= &s1;
        p[1]=&s2;
        p[2]= &s3;
        for(int i =0;i<3;i++)
        {
            printf("enter name\n");
            scanf("%s",&p[i]->name);
            printf("enter roll no \n");
            scanf("%d",&p[i]->roll_no);
            printf("enter CPI \n");
            scanf("%f",&p[i]->CPI);
        }
        for(int i =0;i<3;i++)
        {
            printf("%s\n",p[i]->name);
            printf("%d\n",p[i]->roll_no);
            printf("%f\n",p[i]->CPI);
        }
    }