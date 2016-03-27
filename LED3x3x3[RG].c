/*
 * LED3x3x3.c
 *
 * Created: 4/5/2015 8:01:20 PM
 *  Author: r_gujju
 * *******************************************0b0000000000000001 1 corresponds to first pin**************************************************
 *This code is provided as is without any warranty
 */ 


#include <avr/io.h>
#include <util/delay.h>

void latch(int i)
{
	if(i==1)
	PORTD |= (1<<PIND1);
	
	if(i==0)
	PORTD &= ~(1<<PIND1);
	
}

void clock(int i)
{
	if(i==1)
	PORTD |= (1<<PIND2);
	
	if(i==0)
	PORTD &= ~(1<<PIND2);
	
}

void write(unsigned short data1)
{
	unsigned short data2 =0b0000000000000000 ;
	latch(0); //make latch pin low or 0
	for(int i=15;i>=0;i--)   
	{
		
		clock(0); //make clock pin low or 0
		
		data2 = 0b0000000000000000;
		data2 |= (1<<i);
		
		if(data1 & data2)
		PORTD |= (1 << PIND0);
		
		else
		PORTD &= ~(1<<PIND0);
		
		clock(1);//make clock pin high or 1
	}
	
	latch(1); //make latch pin high or 0
}






int main(void)
{
	unsigned short data;
	
	 
	//write outputs here (start with zero)
	
	//10th == top 
	
	//pattern1
	
	unsigned short output[36]; //number of outputs
	int outputs = 36 ;
	output[0]=0b0000000000000001;
	output[1]=0b0000000000000010;
	output[2]=0b0000000000000100;
	output[3]=0b0000000000001000;
	output[4]=0b0000000000010000;
	output[5]=0b0000000000100000;
	output[6]=0b0000000001000000;
	output[7]=0b0000000010000000;
	output[8]=0b0001000000000000;
	
	//pattern 2
	output[9]=0b0000110000000001;
	output[10]=0b0000110000000010;
	output[11]=0b0000110000000100;
	output[12]=0b0000110000010000;
	output[13]=0b0000110000100000;
	output[14]=0b0000110001000000;
	output[15]=0b0000110010000000;
	output[16]=0b0000110100000000;
	output[17]=0b0001110000000000;
	output[18]=0b0000101000000001;
	output[19]=0b0000101000000010;
	output[20]=0b0000101000000100;
	output[21]=0b0000101000001000;
	output[22]=0b0000101000010000;
	output[23]=0b0000101000100000;
	output[24]=0b0000101001000000;
	output[25]=0b0000101010000000;
	output[26]=0b0001101000000000;
	output[27]=0b0000011000000001;
	output[28]=0b0000011000000010;
	output[29]=0b0000011000000100;
	output[30]=0b0000011000001000;
	output[31]=0b0000011000010000;
	output[32]=0b0000011000100000;
	output[33]=0b0000011001000000;
	output[34]=0b0000011010000000;
	output[35]=0b0001011000000000;
	
	//pattern 3
	unsigned short output3[4]; //number of outputs
	int outputs3 = 4 ;
	
	output3[0]=0b0001000011111111;
	output3[1]=0b0000111000000000;
	output3[2]=0b0001000011111111;
	output3[3]=0b0000111000000000;
	
	
	//pattern 4
	unsigned short output4[4];
	int outputs4 = 4;
	output4[0]=0b0001000001010101;
	output4[1]=0b0000000010101010;
	output4[2]=0b0001000001010101;
	output4[3]=0b0000000010101010;
	
	//pattern 5
	unsigned short output5[14];
	int outputs5 = 14;
	output5[0]=0b0000110001000001;
	output5[1]=0b0000101001000001;
	output5[2]=0b0000011001000001;
	output5[3]=0b0000110000100100;
	output5[4]=0b0000101000100100;
	output5[5]=0b0000011000100100;
	output5[6]=0b0001110001001010;
	output5[7]=0b0001101001001010;
	output5[8]=0b0001011001001010;
	output5[9]=0b0001110001010100;
	output5[10]=0b0001101001010100;
	output5[11]=0b0001011001010100;
	output5[12]=0b0001010001011101;
	output5[13]=0b0001000011111111;
	
	// pattern 6
	unsigned short output6[24];
	int outputs6 = 24;
	output6[0]=0b0000100000100101;
	output6[1]=0b0000011000011100;
	output6[2]=0b0000110010010000;
	output6[3]=0b0000101000101111;
	output6[4]=0b0000110001010011;
	output6[5]=0b0000010001010100;
	output6[6]=0b0000010000110101;
	output6[7]=0b0000011000100101;
	output6[8]=0b0000100100101010;
	output6[9]=0b0000000100000100;
	output6[10]=0b0000000100011010;
	output6[11]=0b0000011000010011;
	output6[12]=0b0000001001110010;
	output6[13]=0b0000101100100011;
	output6[14]=0b0000010110011001;
	output6[15]=0b0000101100001010;
	output6[16]=0b0000001100110011;
	output6[17]=0b0000111001001111;
	output6[18]=0b0000101000111110;
	output6[19]=0b0000000100010100;
	output6[20]=0b0000010000110011;
	output6[21]=0b0000000001001101;
	output6[22]=0b0000110001101010;
	output6[23]=0b0000010100101101;
	
	
	
	//output 7
	unsigned short output7[14]; //number of outputs
	int outputs7 = 14 ;
	output7[0]=0b0001110011111111;
	output7[1]=0b0001101011111111;
	output7[2]=0b0001011011111111;
	output7[3]=0b0001111011111111;
	output7[4]=0b0001010011111111;
	output7[5]=0b0001100011111111;
	output7[6]=0b0001110011111111;
	
	
	output7[7]=0b0000000000000111;
	output7[8]=0b0000000000111000;
	output7[9]=0b0001000011000000;
	output7[10]=0b0000111010000000;
	output7[11]=0b0001000011000000;
	output7[12]=0b0000000000111000;
	output7[13]=0b0000000000000111;
	
	
	DDRD = 0xff ;
	PORTD = 0b00000000;
	
    while(1)    {
		
		//output 1
		for (int j=0 ; j<outputs; j++)
		{
			data = output[j];
				write(data); 
				_delay_ms(150);
		}
		
		
		//output 2
		for(int k=0;k<2;k++)
		{
			for (int j=0 ; j<outputs3; j++)
				{
					data = output3[j];
					write(data);
					_delay_ms(900);
				}
		
		}		
		
		//output 3
		
		
		for(int k=0;k<2;k++)
		{
			for (int j=0 ; j<outputs4; j++)
			{
				data = output4[j];
				write(data);
				_delay_ms(900);
			}
			
		}
		
		
		//output 4
		for (int k=0 ; k<6; k++)
		{
			for (int j=0 ; j<outputs5; j++)
				{
					data = output5[j];
					write(data);
					_delay_ms(200);
				}
		}				
		
		
		
		//output 5
		for (int k=0 ; k<4; k++)
		{
			for (int j=0 ; j<outputs6; j++)
			{
				data = output6[j];
				write(data);
				_delay_ms(300);
			}
		}
		
		
		//output 6
		for (int k=0 ; k<6; k++)
		{
			for (int j=0 ; j<outputs7; j++)
			{
				data = output7[j];
				write(data);
				_delay_ms(150);
			}
		}
		
			
	}	
	
}

