#include<stdio.h>
#include<conio.h>
int box[4][4];
void main()
{
    int i,j,k,m,n,t;

       for(i=0;i<4;i++)
       {
        for(j=0;j<4;j++)
        {

            k=rand()%17;
            t=compare(k);

            if(t==0)
            {

                box[i][j]=k;
            }
            else
                {
                j--;
            }

        }}
         for(i=0;i<4;i++)
       {
        for(j=0;j<4;j++)
        {
            if(box[i][j]==16)
            {
            box[i][j]=0;
            }
        }
       }

       while(1)
       {
           int temp,choice;
        printbox();
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(box[i][j]==0)
                {
                    printf("Enter the element : ");
                    scanf("%d",&choice);
                    if(j-1>=0 && box[i][j-1]==choice)
                    {
                        temp=box[i][j];
                        box[i][j]=box[i][j-1];
                        box[i][j-1]=temp;
                        printbox();
                        //check_fun();
                        i=0;j=-1;
                    }
                    else if(j+1<=3 && box[i][j+1]==choice)
                    {
                        temp=box[i][j];
                        box[i][j]=box[i][j+1];
                        box[i][j+1]=temp;
                        printbox();
                        //check_fun();
                        i=0;j=-1;
                    }
                    else if(i-1>=0 && box[i-1][j]==choice)
                    {
                        temp=box[i][j];
                        box[i][j]=box[i-1][j];
                        box[i-1][j]=temp;
                        printbox();
                        //check_fun();
                        i=0;j=-1;
                    }
                    else if(i+1<=3 && box[i+1][j]==choice)
                    {
                        temp=box[i][j];
                        box[i][j]=box[i+1][j];
                        box[i+1][j]=temp;
                        printbox();
                        //check_fun();
                        i=0;j=-1;
                    }
                    else
                    {
                        printf("\nIncorrect choice...please try again\n");
                        i=0;j=0;
                    }
                }

            }
        }
        break;
    }
       }

void printbox()
{
    int i,j;
      for(i=0;i<4;i++)
       {

        printf("|");
        for(j=0;j<4;j++)
        {
            if(box[i][j]==0)
            {
                printf("    |");
            }
            else if(box[i][j]<10)
            {
                printf(" 0");
                printf("%d |",box[i][j]);
            }
            else
            {
                printf(" %d |",box[i][j]);
            }

        }
        printf("\n\n");
    }
}
int compare(int z)
{
    int flag=0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(box[i][j]==z)
            {
                 flag =1;
                 return flag;

            }

        }

    }
return flag;
}
void check_fun()
{
    int k=1,count=0,flg=1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(box[i][j]==k)
            {
                count++;
                k++;
                if(count==15)
                {
                printf("\nCongratulation.....!!!!");
                exit(0);
                }
            }
            else if(box[i][j]!=k)
            {
                flg=0;
                break;
            }
        }
    }
}
