#ifndef _PARAMETER_H
#define	_PARAMETER_H

#include "stm32f4xx.h"
#include "Ano_FcData.h"

__packed struct Parameter_s
{
	u16 frist_init;	//�ɿص�һ�γ�ʼ������Ҫ��һЩ���⹤�����������flash
	
	
	u8		pwmInMode;				//���ջ�ģʽ���ֱ�ΪPWM��PPM��
	u8		heatSwitch;				//

	float 	acc_offset[VEC_XYZ];  	//���ٶȼ���ƫ
	float 	gyro_offset[VEC_XYZ]; 	//��������ƫ
	
	float 	surface_vec[VEC_XYZ]; 	//ˮƽ������
	float 	center_pos_cm[VEC_XYZ]; //������Դ�����λ��ƫ����
	
	float 	mag_offset[VEC_XYZ];  	//��������ƫ
	float 	mag_gain[VEC_XYZ];    	//������У������
	
	float 	pid_att_1level[VEC_RPY][PID]; //��̬���ƽ��ٶȻ�PID����
	float 	pid_att_2level[VEC_RPY][PID]; //��̬���ƽǶȻ�PID����
	float 	pid_alt_1level[PID];          //�߶ȿ��Ƹ߶��ٶȻ�PID����
	float 	pid_alt_2level[PID];           //�߶ȿ��Ƹ߶Ȼ�PID����
	float 	pid_loc_1level[PID];          //λ�ÿ���λ���ٶȻ�PID����
	float 	pid_loc_2level[PID];           //λ�ÿ���λ�û�PID����

	float 	pid_gps_loc_1level[PID];          //λ�ÿ���λ���ٶȻ�PID����
	float 	pid_gps_loc_2level[PID];           //λ�ÿ���λ�û�PID����

	float   warn_power_voltage;
	float	return_home_power_voltage;
	float   lowest_power_voltage;
	
	float	auto_take_off_height;
	float auto_take_off_speed;
	float auto_landing_speed;
	float idle_speed_pwm;
	

};

union Parameter
{
	//����ʹ�������壬������4KByte���������ڲ���һ���ṹ�壬�ýṹ��������Ҫ����Ĳ���
	struct Parameter_s set;
	u8 byte[4096];
};
extern union Parameter Ano_Parame;

typedef struct
{
	u8 save_en;
	u8 save_trig;
	u16 time_delay;
}_parameter_state_st ;
extern _parameter_state_st para_sta;

void Ano_Parame_Read(void);
void Ano_Parame_Write_task(u16 dT_ms);
void PID_Rest(void);
void Parame_Reset(void);

#endif 

