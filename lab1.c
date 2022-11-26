#include<conio.h>
#include<stdio.h>
#include<math.h>


float calcEqn(float x){
	float result = pow(x, 3) - 6*x + 2;
	
	return result;
}

int main(){
	int sn = 0;
	float x0, x1, xr, fx0, fx1, fxr, tol;
	
	lbl:
		printf("\nEnter two initial guesses: ");
		scanf("%f%f", &x0, &x1);
		
		fx0 = calcEqn(x0);
		fx1 = calcEqn(x1);
		
		if(fx0 * fx1 > 0){
			printf("\nInvalid initial guesses. Try again");
			goto lbl;
		}
		
		printf("\nEnter tolerance error: ");
		scanf("%f", &tol);
		
		printf("\nS.N.\tX0\t\tX1\t\tXr\t\tf(x0)\t\tf(x1)\t\tf(xr)\t\tReplace");
		
		do{
			sn++;
			xr = (x0 + x1)/2;
			fxr = calcEqn(xr);
			printf("\n%d\t%f\t%f\t%f\t%f\t%f\t%f\t", sn, x0, x1, xr, fx0, fx1, fxr);
//			printf("x0 = %d, x1 = %d", x0, x1);
			
			if(fx0 * fxr > 0){
				printf("x0 = xr");
				x0 = xr;
			}else{
				printf("x1 = xr");
				x1 = xr;
			}
//			printf("\t%f", fabs(x0 - x1));
//			printf("x0 = %f, x1 = %f", x0, x1);
		}while(fabs(x0 - x1) > tol);
	
	return 0;
}
