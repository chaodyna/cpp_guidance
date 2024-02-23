#include<stdio.h>
//从12月往前数到3月，或者从1月往后数到1月，都符合这个规律(虽然定义了，但完全没用) 
const int mon[]={0,31,30,31,30,31,31,30,31,30,31};
//∑mon[n] = n*30+n*7/12 (基本上是凑出来的公式) 
 
typedef struct{
    int year;
    short month;
    short day;
}Date;
 
int daysofyear(int year){//返回周年的天数 
    return year*365+year/4-year/100+year/400;
}
 
int daysofdate(Date t){
    return 
        t.month<=2?
            //天数是周年的天数加上当年已过完的月份的天数加日 
            daysofyear(t.year-1)+(t.month-1)*30+t.month*7/12+t.day-1
        :(
            //天数是虚年的天数减去当年未过完的月份的天数加日
            daysofyear(t.year)-(13-t.month)*30-(14-t.month)*7/12+t.day-1
        );
}
 
int main(){
    Date t1,t2;
    scanf("%d%hd%hd",&t1.year,&t1.month,&t1.day);//输入日期1
    scanf("%d%hd%hd",&t2.year,&t2.month,&t2.day);//输入日期2
    printf("%d\n",daysofdate(t2)-daysofdate(t1));//输出两个日期相差天数
    return 0;
}