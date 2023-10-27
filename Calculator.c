#include "StdTupes.h"
#include "KeyPad_Interface.h"
#include "LCD_Interface.h"
#include "Calculator_Interface.h"
//u8 Caclc_Operand[MAX_IN];
//u8 Caclc_Operator[MAX_IN];
//s16 Calc_Result[MAX_IN]={0};



void Calc_init(void)
{
	LCD_Clear();
}
void Calc_runabble(void)
{
	u16 Caclc_Operand[MAX_IN]={0};
	u16 Caclc_Operator[MAX_IN]={0};
	 u16 count=0;
	 u8 flag_operand=0;
	 u8 flag_operator=0;
	u8 j=0,first=0;
	u8 k=NO_KEY;
	s32 r=0;
	s32 Result=0,i=0;
	count=0;
	for(i=0;count<MAX_IN&&k!='=';)
	{
		
		k=KEYPAD_GetKey();
		if(k!=NO_KEY)
		{
			if((k>='0'&&k<='9')&&(count)<MAX_IN)
			{
				if(first==0)
				{
					first=1;
					LCD_Clear();
				}
				flag_operator=1;
				flag_operand=1;
				Caclc_Operand[i]=((Caclc_Operand[i])*10)+(k-'0');
				count++;
				LCD_WriteChar(k);
				
			}
			else if((count)<MAX_IN&&flag_operand==1&&flag_operator==1&&(k=='*'||k=='/'||k=='-'||k=='+'))
			{
				i++;
				count++;
				flag_operand=0;
				Caclc_Operator[j++]=k;
				LCD_WriteChar(k);
			}
			else if(k=='C')
			{
				LCD_Clear();
				break;
			}
			else if(k=='=')
			{
				
				break;
			}
			else
			{
				//
			}
			
			
			
		}
	}
		Caclc_Operand[i+1]=0x55;
		Caclc_Operator[j]=0x55;
		if(k=='='||count==MAX_IN)
		{
			u8 i=0;
			LCD_GoTo(3,0);
			LCD_WriteChar('=');
			
			
				
				for(i=0;Caclc_Operator[i]!=0x55;i++)
				{
					
						if(Caclc_Operator[i]=='/')
						{
							r=Caclc_Operand[i]/Caclc_Operand[i+1];
							//Result+=r;
							Caclc_Operand[i]=0xAA;
							Caclc_Operand[i+1]=r;
							Caclc_Operator[i]='A';
							
						}
						else if(Caclc_Operator[i]=='*')
						{
							r=Caclc_Operand[i]*Caclc_Operand[i+1];
							//Result+=r;
							Caclc_Operand[i]=0XAA;
							Caclc_Operand[i+1]=r;
							Caclc_Operator[i]='A';
						}
					
				}
					for(i=0;Caclc_Operator[i]!=0x55;i++)
					{
						
						
							
							if(Caclc_Operator[i]=='-')
							{
								if(Caclc_Operand[i+1]==0xAA)
								{
									r=Caclc_Operand[i]-Caclc_Operand[i+2];
									Caclc_Operand[i+2]=r;
									Caclc_Operand[i]=0;
									Caclc_Operand[i+1]=0;
								}
								else
								{
									r=Caclc_Operand[i]-Caclc_Operand[i+1];
									Caclc_Operand[i+1]=r;
									Caclc_Operand[i]=0;
								}
								
								//Result+=r;
								
								//Caclc_Operand[i+1]=r;
								Caclc_Operator[i]='A';
								
							}
							else if(Caclc_Operator[i]=='+')
							{
								if(Caclc_Operand[i+1]==0xAA)
								{
									r=Caclc_Operand[i]+Caclc_Operand[i+2];
									Caclc_Operand[i+2]=r;
									Caclc_Operand[i]=0;
									Caclc_Operand[i+1]=0;
								}
								else
								{
									r=Caclc_Operand[i]+Caclc_Operand[i+1];
									Caclc_Operand[i+1]=r;
									Caclc_Operand[i]=0;
								}
								//r=Caclc_Operand[i]+Caclc_Operand[i+1];
								//Result+=r;
								//Caclc_Operand[i]=0;
								//Caclc_Operand[i+1]=r;
								Caclc_Operator[i]='A';
							}
						
					}
					
				
				
				for(i=0;Caclc_Operand[i]!=0x55;i++)
				{
					if(Caclc_Operand[i]!=0xAA)
					Result=Result+Caclc_Operand[i];
				}
				
				
			}
			
		
		
		
		
		
		
		

	LCD_GoTo(3,1);
   LCD_WriteNum(Result);
}
	



