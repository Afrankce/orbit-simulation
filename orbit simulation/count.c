#include"stdio.h"
#include <math.h>
/*  代入初始条件x=3,y=4,z=0.25
Z(actual)=V0sinθt-1/2gt^2(1式)
s=1/k1 *In(k1Vx0t+1)（2式）
代入数据解得12.96=68sinθcosθ+/- sqrt(68^2*sinθ^2-78.4)cosθ
利用暴力计算得到两个解，即缓慢增大θ
或者用更加简单的方式：忽略水平阻力，构建抛物线方程
{V0cosθ*t=s
V0sinθt-0.5*g*t*t=z
也可判断有两个解
}

*/
void count1()
{
    double theta1;
    for (theta1 = 0; theta1 < 1.5708; theta1 += 0.000001) {
        double expr1 = 68 * sin(theta1) * cos(theta1);
        double expr2 = sqrt(68 * 68 * pow(sin(theta1), 2) - 78.4) * cos(theta1);
        if (fabs(12.96 - (expr1 + expr2)) < 0.001) {
            printf("theta1 = %lf\n", theta1);
            theta1+=0.01;//保证解不会重复输出
            //这个有解
        }
    }
    
}
void count2()
{
    double theta2;
    for (theta2 = 0; theta2 < 1.5708; theta2 += 0.000001) {
        double expr1 = 68 * sin(theta2) * cos(theta2);
        double expr2 = sqrt(68 * 68 * pow(sin(theta2), 2) - 78.4) * cos(theta2);
        if (fabs(12.96 - (expr1 - expr2)) < 0.001) {
            printf("theta2 = %lf\n", theta2);
            theta2+=0.01;
            //这个没解
        }
    }
    
}
int main(void)
{ 
    count1();
    count2();
     double s=5.0,targetPoint=0.25,V0=17.0,k=0.038,g=9.8;
     double sina,cosa,t,deltaZ,tempPoint,i,Zactual;
tempPoint=targetPoint;
for(i=0;i<10;i++)
{  cosa=s/sqrt(s*s + tempPoint*tempPoint);
sina=sqrt(1-cosa*cosa);
t=(exp(k*s)-1)/(k*V0*cosa);
Zactual=V0*t*sina-0.5*g*t*t;
deltaZ=targetPoint-Zactual;
tempPoint+=deltaZ;
printf("theta  = %f\n",asin(sina));
}






  











}