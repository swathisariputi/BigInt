#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Bigint_type
{
	char string[100];
}Big_int;
Big_int addition(Big_int str ,Big_int str1)
{
	Big_int res;
	res.string[500];
	int len,len1,n,k,s;
	len = strlen(str.string)-1;
	len1 = strlen(str1.string)-1;
	k=strlen(str.string)>strlen(str1.string) ? strlen(str.string):strlen(str1.string) ;
	res.string[k]='\0';
	k--;
   //	printf("%d%d",len,len1);
   int carry = 0;
   while(len!= -1 && len1!= -1)
   {
   	  s = (str.string[len]-48)+(str1.string[len1]-48)+carry;
   	  res.string[k] = s%10+48;
   	  carry=s/10;
   	  len--;
   	  len1--;
   	  k--;
   }
   if(len!=-1)
   {
   	    while(len!=-1)
   	     {
   	        s= (str.string[len]-48)+carry;
   	        res.string[k]=s%10+48;
   	        carry=s/10;
   	        len--;
   	        k--;	
		 }
   }
   if(len1!=-1)
   {
   	while(len1!=-1)
   	  {
     	    s= (str1.string[len]-48)+carry;
   	        res.string[k]=s%10+48;
   	        carry=s/10;
   	        len1--;
   	        k--;
	  }
   }
   int x;
   if(carry > 0)
   {
   	for(x=strlen(res.string);x>=0;x--)
   	{
   		res.string[x+1]=res.string[x];
	}
	res.string[0]=carry+48;
   }
   if(str.string[0]=='-' && str1.string[0]=='-')
   {
   	res.string[0]='-';
   }
   	return res;
}
Big_int subtraction(Big_int str,Big_int str1)
{
	int diff;
	Big_int sub;
	sub.string[500];
	int len,len1;
	len = strlen(str.string)-1;
	len1 = strlen(str1.string)-1;
	int val;
	int i = 0;
	if(len>len1)
	{
		val = 1;
	}
	else
	{
		if(len1>len)
		 {
		 	val = -1;
		 }
		 else
		 {
		 	val = strcmp(str.string,str1.string);
		 }
	}
	if(val == 1)
	{
		while(len!=-1 && len1!=-1)
		  {
		  	diff = (str.string[len]-48)-(str1.string[len1]-48);
		  	if(diff<0)
		  	{
		  	 diff = diff+10;
			 str.string[len-1]= str.string[len-1]-1; 	
			}
			len--;
			len1--;
			sub.string[i]=diff+48;
			i++;
		  }
		  while(len!=-1)
		  {
		  	sub.string[i]= (str.string[len]);
		  	len--;
		  	i++;
		  }
		  i=i-1;
		  return sub;
	}
	else if(val == -1)
	 {
	   	while(len!=-1 && len1!=-1)
		  {
		  	diff = (str1.string[len1]-48)-(str.string[len]-48);
		  	if(diff<0)
		  	{
		  	 diff = diff+10;
			 str1.string[len1-1]= str1.string[len1-1]-1; 	
			}
			len--;
			len1--;
			sub.string[i]=diff+48;
			i++;
		  }
		  while(len1!=-1)
		  {
		  	sub.string[i]= (str1.string[len1]);
		  	i++;
		  	len1--;
		  }
		  i=i-1;
		  return sub;
	 }
	 else if(val==0)
	 {
	 	while(len!=-1 && len1!=-1)
	 	{
	 	diff = (str1.string[len1]-48)-(str.string[len]-48);
	 	len--;
	 	len1--;
	 	sub.string[i]=diff+48;
	 	i++;
	    }
	 	return sub;
	 }
}
void multiply(Big_int str,Big_int str1)
{
	int a[100],b[100];
	int result[200]={0};
	int len1 = strlen(str.string);
	int len2 = strlen(str1.string);
	int i,j=0,temp;
	for(i=len1-1;i>=0;i--,j++)
	{
		a[j] = (str.string[i])-'0';

	}
	for(i=len2-1,j=0;i>=0;i--,j++)
	{
		b[j] = (str1.string[i])-'0';
	}
	for(i=0;i<len2;i++)
	{
		for(j=0;j<len1;j++)
		{
			result[i+j] += b[i]*a[j];
		}
	}
	for(i=0;i< len1+len2 ; i++)
	{
		temp = result[i]/10;
		result[i] = result[i]%10;
		result[i+1] = result[i+1] + temp;
	}
	for(i= len1+len2; i>=0;i--)
	{
		if(result[i] > 0)
		{
			break;
		}
	}
	printf("Product of %s and %s is:",str.string,str1.string);
	for(;i>=0;i--)
	{
		printf("%d",result[i]);
	}
	printf("\n");
}
 int main()
{
	
	Big_int B1,B2,sum,subtract;
    printf("enter two big integers B1,B2\n");
    scanf("%s %s",B1.string,B2.string);
    int choice;
    do
    {
    	printf("enter 1 for addition\n");
    	printf("enter 2 for subtration\n");
    	printf("enter 3 for multiplication\n");
    	printf("enter 4 for exit\n");
    	scanf("%d",&choice);
    	if(choice==1)
    	{
    		sum=addition(B1,B2);
	        printf("%s is sum\n",sum.string);
		}
		if(choice==2)
		{
		    subtract=subtraction(B1,B2);
            int i;
            int m = strlen(subtract.string);
            char temp;
	        for(i=m-1;i>=m/2;i--)
	        {
		        temp=subtract.string[m-i-1];
		        subtract.string[m-i-1]=subtract.string[i];
		        subtract.string[i]=temp;
	        }
	        if(strcmp(B1.string,B2.string)>0)
	        {
		        if(B1.string[0]=='-' && B2.string[0]=='-')
		        {
			        printf("-%s is sub value\n",subtract.string);
		        }
		        else
		        {
                    printf("%s is sub value\n",subtract.string);
                }
            }
            else
            {
    	        if(B1.string[0]=='-' && B2.string[0]=='-')
    	        {
    	            printf("-%s is sub value\n",subtract.string);
    	        }
    	        else
    	        {
    		        printf("%s is sub value\n",subtract.string);
		        }
	        } 	
		}
		if(choice ==3)
		{
			multiply(B1,B2);
		}
	}while(choice!=4);
	    return 0;
	
}
