#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979

typedef struct STATE_INFO
{
	int year; //param1:year 年 2017
	int month; //param2:month 月01
	int day; //param3:day 天 01
	double lat; //param4:Lat 纬度 31.12
	int hour; //param5:hour 小时 01
	int minute; //param6:minute 分钟 01
	int sec; //param7:sec 秒 01
	double current_angle; //param8:current_angle 当前角度01.11
	int state; //param9:state 状态信息
}STATE_INFO_BUF;

STATE_INFO_BUF state_buf;

int err = 0;
char *p = NULL;
int c = 0;

static double shift_angle;//旋转角
//double current_angle; //当前角

/*
*数据解析函数，接受服务器传送的数据，解析后传递到结构体
*/
void analyze_data(char str[])
{
	int i = 1;
    char *delim = "-";
    char *p;
    int j,k;
    char str_tmp[50];
	double array_tmp[9];//7个元素year-month-day-hour-minute-lat-angle-state

    for(j=1,k=0; j < strlen(str); j++)
    {
        str_tmp[k++] = str[j];

    }
    str_tmp[k]= '\0';

    array_tmp[0] = atoi(strtok(str_tmp, delim));//整型year

    while((p = strtok(NULL, delim))){
        array_tmp[i++] = atof(p);//保存剩余的6个元素
    }

	state_buf.year = (int)array_tmp[0];
	state_buf.month = (int)array_tmp[1];
	state_buf.day = (int)array_tmp[2];
	state_buf.hour = (int)array_tmp[3];
	state_buf.minute = (int)array_tmp[4];
	state_buf.sec = (int)array_tmp[5];
	state_buf.lat = array_tmp[6];
	state_buf.current_angle = array_tmp[7];
	state_buf.state = array_tmp[8];
}

/*
*软件实现分钟自动增加
*/
void with_param_get_minute()
{

    int i;
	int hour = state_buf.hour;
	int minute = state_buf.minute;

    minute += 10;
    if(minute >= 60)
    {
        hour += 1;
        minute = 0;
        if(hour == 24)
            hour = 0;
    }
    state_buf.hour = hour;
	state_buf.minute= minute;

}
double get_rad(double angle)
{
        return 2*PI/360*angle;
}

/*日角计算函数定义*/
double days_angle_ca(int days_sum, int year)
{
	double days_angle = 0;

    double bias_days = 79.6764+0.2433 * (year-1985) - ((year-1985)/4);
    double correct_days = days_sum - bias_days;
    days_angle = 2 * PI * correct_days / 365.2422;
    return days_angle;
}
/*太阳赤纬角计算函数定义*/
double delt_sun_ca(double days_angle)
{
	double delt_sun = 0;
    delt_sun = (0.3723+23.2567*sin(days_angle)+0.1149*sin(2*days_angle)
                -0.1712*sin(3*days_angle)-0.758*cos(days_angle)+0.3656*cos(2*days_angle)
                +0.0201*cos(3*days_angle))*PI/180;
    delt_sun = delt_sun * 180 / PI;

	return delt_sun;
}
/*时差计算函数的定义*/
double et_ca(double days_angle)
{
	double et = 0;
    et= 0.0028-1.9857*sin(days_angle)+9.9059*sin(2*days_angle)
        -7.0924*cos(days_angle)-0.6882*cos(2*days_angle);


     return et;

}
/*时角计算函数定义*/
double angle_hour_ca()
{
	double angle_hour = 0;
	int hour = state_buf.hour;
	int minute = state_buf.minute;
	int sec = state_buf.sec;
	angle_hour = (hour + minute/60.0 + sec/3600.0 - 12) * 15;

	return angle_hour;
}
/*重置函数*/
double reset()
{
	shift_angle = 90 - state_buf.current_angle;
	state_buf.current_angle = 90;
	return shift_angle;
}
/*竖放函数*/
double upright()
{
	shift_angle = 90-state_buf.current_angle;
	state_buf.current_angle = 90;
	return shift_angle;
}

//计算积日
unsigned int days_sum_ca(unsigned int a,unsigned int b)
{
    int n=0;
    switch(a)
    {
        case 1:
            n=b;
            break;
        case 2:
            n=31+b;
            break;
        case 3:
            n=31+28+b;
            break;
        case 4:
            n=31+28+31+b;
            break;
        case 5:
            n=31+28+31+30+b;
            break;
        case 6:
            n=31+28+31+30+31+b;
            break;
        case 7:
            n=31+28+31+30+31+30+b;
            break;
        case 8:
            n=31+28+31+30+31+30+31+b;
            break;
        case 9:
            n=31+28+31+30+31+30+31+31+b;
            break;
        case 10:
            n=31+28+31+30+31+30+31+31+30+b;
            break;
        case 11:
            n=31+28+31+30+31+30+31+31+30+31+b;
            break;
        case 12:
            n=31+28+31+30+31+30+31+31+30+31+30+b;
            break;
        default:
            break;
    }
    return n;
}

/*得到时角*/
double get_angle_hour()
{

	double angle_hour = angle_hour_ca();

	return angle_hour;
}
/*计算积日、日角、得到需要的赤纬角*/
double get_delt_sun()
{
	int year = state_buf.year;
	int month = state_buf.month;
	int day = state_buf.day;

	int days_sum = days_sum_ca(month,day);

	double days_angle = days_angle_ca(days_sum, year);
	double delt_sun = delt_sun_ca(days_angle);

	return delt_sun;
}
/*得到高度角*/
double get_elevation_angle()
{
	double sin_h,h_sun,elevation_angle;
	double LAT = state_buf.lat;
	double delt_sun = get_delt_sun();
	sin_h = sin(get_rad(LAT)) * sin(get_rad(delt_sun)) + cos(get_rad(LAT))
        *cos(get_rad(delt_sun)) * cos(get_rad(get_angle_hour()) );


	h_sun = asin(sin_h);

	elevation_angle = h_sun*180/PI;
    /*
    if((state_buf.hour >= 18) || (state_buf.hour <6))
    {
        elevation_angle = 90;//处于傍晚18:00-凌晨6:00, 电池板平放
    }
    */
    printf("curr elevation_angle is %0.4f\n", elevation_angle);
    
	return elevation_angle;
}

/*计算目标角度、得到旋转角度*/
double shift_angle_ca()
{
	double target_angle;
    if((state_buf.hour >= 18) || (state_buf.hour <6))
    {
        state_buf.state = 1;//处于傍晚18:00-凌晨6:00, 电池板平放
    } 
    else
    {
        state_buf.state = 0;//复位
    }

    if(state_buf.state == 1)
	{
		shift_angle = reset();
	}else if(state_buf.state == 2)
	{
		shift_angle = upright();
	}else if(state_buf.state == 0)
	{
        if(state_buf.current_angle > 90)//下午旋转角计算
        {
            
            target_angle = 180 - get_elevation_angle();
            shift_angle = target_angle - state_buf.current_angle;
            state_buf.current_angle = target_angle;
        }
        else//上午旋转角计算
        {
            double elevation_angle_tmp = get_elevation_angle();

            if((elevation_angle_tmp <= state_buf.current_angle) && (shift_angle != 0))//是否达到临界转换条件
            {
                //临界转换条件处理
                target_angle = 180 - get_elevation_angle();
                shift_angle = target_angle - state_buf.current_angle;
                state_buf.current_angle = target_angle;

            }else//未达到转换条件
            {
                target_angle = get_elevation_angle();
                shift_angle = target_angle - state_buf.current_angle;
                state_buf.current_angle = target_angle;
            }
        }
	}
    printf("this target_angle  is %0.4f\n", target_angle);
	return shift_angle;
}

int main()
{
    int i;
    char str[40] = "#2017-3-21-18-50-20-00-0-0";
    analyze_data(str);
    shift_angle = shift_angle_ca();
    printf("this shift_angle is %0.4f\n", shift_angle);
    for(i = 0; i < 10; i++)
    {
        with_param_get_minute();
        shift_angle = shift_angle_ca();
        printf("this time is %d-%d-%d\n", state_buf.hour, state_buf.minute, state_buf.sec);
        printf("this shift_angle is %0.4f\n", shift_angle);
    }
    return 0;
}
