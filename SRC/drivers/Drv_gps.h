#ifndef _DRV_GPS_H_
#define _DRV_GPS_H_

#include "include.h"

typedef struct{
	unsigned char satellite_num;
	unsigned char Location_stu;			//��λ״̬
	double latitude;						//γ��		
	double longitude;						//����		
	int N_vel;							//�ϱ����ٶ�
	int E_vel;							//�������ٶ�
	
	float last_N_vel;							//�ϴ��ϱ����ٶ�
	float last_E_vel;							//�ϴζ������ٶ�
	
	float real_N_vel;
	float real_E_vel;
	
	unsigned char run_heart;			//��������
	double start_latitude;					//��ʼγ��		
	double start_longitude;					//��ʼ����		
	int latitude_offset;
	int longitude_offset;
	float hope_latitude;
	float hope_longitude;
	float hope_latitude_err;
	float hope_longitude_err;
	unsigned char new_pos_get;
	unsigned char Back_home_f;
	float home_latitude;
	float home_longitude;
	
}GPS_INF;

extern GPS_INF Gps_information;
extern short Gps_send_Temp[10];
extern float wcx_acc_use;		
extern float wcy_acc_use;


void Uart1_GPS_IRQ(void);
void Drv_GpsPin_Init(void);
void ANO_DT_Send_Gps_data(void);
void WCXY_Acc_Get_Task(void);
void GPS_Data_Processing_Task(u8 dT_ms);

#endif
