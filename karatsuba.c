#include<stdio.h>
#include<stdlib.h>

int num_bit(long long int x)
{	
	int s=0;
	long long t=1;
	while(t<=x)
	{
		s++;
		t=t<<1;
	}
	
	return s;
}


long long int multi(long long int x,long long int y)
{

	if(x==0|| y==0)
		return 0;

	if(x==1)
		return y;
	if(y==1)
		return x;

	int n;
	long long int k;
	int num1=num_bit(x);
	int num2=num_bit(y);
	//printf("num1=%d\n",num1);
	//printf("num2=%d\n",num2);
	if(num1>num2)
		n=num1;
	else
		n=num2;
//	printf("n=%d\n",n);
	int t=n/2;
	long long int m1=(x>>t);
	long long int m2=(m1<<t) ^ x;
//	printf("m1=%lld\tm2=%lld\n",m1,m2);

	long long int n1=(y>>t);
	long long int n2=(n1<<t) ^y;
//	printf("n1=%lld\tn2=%lld\n",n1,n2);

	long long int p=multi(m1,n1);
//	printf("p=%lld\n",p);
		
	long long int q=multi(m2,n2);
//	printf("q=%lld\n",q);

	long long int r=multi(m1+m2,n1+n2);
//	printf("r=%lld\n",r);

	long long int s=r-(p+q);
//	printf("s=%lld\n",s);

	k=(p<<(2*t))+(s<<t)+q;
//	printf("k=%lld\n",k);

	return (k);
}


int main()
{
	int p,q;
	long long int r;
	printf("ENTER THE TWO NUMBERS:\n");
	scanf("%d%d",&p,&q);
	r=multi(p,q);
	printf("The required multiplication is:\t%lld\n",r);
}
