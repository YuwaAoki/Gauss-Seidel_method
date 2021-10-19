#include <stdio.h>

double get_x1( double x2, double x3)
{
	return( (10.0 - x2 - x3) / 5.0);
}

double get_x2( double x1, double x3)
{
	return( (12.0 - x1 - x3) / 4.0);
}

double get_x3( double x1, double x2)
{
	return( (13 - 2 * x1 - x2) / 3);
}

int main()
{
	double x1, x2, x3, X1, X2, X3, a, b, c; //X1,X2,X3は収束判定のため値を格納しておく変数
	int i;

	x1 = x2 = x3 = X1 = X2 = X3 = a = b = c = 1.0;

	for(i=0; i<20; i++)
	{

		x1 = get_x1( x2, x3);
		x2 = get_x2( x1, x3);
		x3 = get_x3( x1, x2);

		a = X1 - x1;//ひとつ前の計算との差を求める
		b = X2 - x2;
		c = X3 - x3;

		printf ("[i=%d] x1 = %0.10f, x2 = %0.10f, x3 = %0.10f\n", i+1, x1, x2, x3 );

		if( -0.00000000004 <= a && a <= 0.00000000004 && -0.00000000004 <= b && b <= 0.00000000004 &&
				-0.00000000004 <= c && c <= 0.00000000004) //小数点第１１位を四捨五入して同じなら収束
		{
			printf( "success\n");
		}
		X1 = x1;
		X2 = x2;
		X3 = x3;
	}
	return 0;
}
