// RS
#define LCD_RS_PIN_SET    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#define LCD_RS_PIN_RESET    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

// RW
#define LCD_RW_PIN_SET      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
#define LCD_RW_PIN_RESET    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

// EN
#define LCD_E_PIN_SET      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
#define LCD_E_PIN_RESET    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);

// D0
#define LCD_D0_PIN_SET      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
#define LCD_D0_PIN_RESET    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);

// D1
#define LCD_D1_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
#define LCD_D1_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);


// D2
#define LCD_D2_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
#define LCD_D2_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);

// D3
#define LCD_D3_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
#define LCD_D3_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);

// D4
#define LCD_D4_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
#define LCD_D4_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);

// D5
#define LCD_D5_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
#define LCD_D5_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);

// D6
#define LCD_D6_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
#define LCD_D6_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);

// D7
#define LCD_D7_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
#define LCD_D7_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);

// V0
#define LCD_V0_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
#define LCD_V0_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);

// BL
#define LCD_BL_PIN_SET      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
#define LCD_BL_PIN_RESET    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);

void LCD_WriteCommand(uint8_t command) 
{
    LCD_RS_PIN_RESET;
    LCD_RW_PIN_RESET;
	LCD_E_PIN_RESET;
	
    if(command & 0x01) {
		LCD_D0_PIN_SET;
	}
	else {
		LCD_D0_PIN_RESET;
	}
	
	if(command &0x02) {
		LCD_D1_PIN_SET;
	}
	else {
		LCD_D1_PIN_RESET;
	}
	
	if(command &0x04) {
		LCD_D2_PIN_SET;
	}
	else {
		LCD_D2_PIN_RESET;
	}
	
	if(command &0x08) {
		LCD_D3_PIN_SET;
	}
	else {
		LCD_D3_PIN_RESET;
	}
	
	if(command &0x10) {
		LCD_D4_PIN_SET;
	}
	else {
		LCD_D4_PIN_RESET;
	}
	
	if(command &0x20) {
		LCD_D5_PIN_SET;
	}
	else {
		LCD_D5_PIN_RESET;
	}
	
	if(command &0x40) {
		LCD_D6_PIN_SET;
	}
	else {
		LCD_D6_PIN_RESET;
	}
	
	if(command &0x80) {
		LCD_D7_PIN_SET;
	}
	else {
		LCD_D7_PIN_RESET;
	}
	
    LCD_E_PIN_SET;   
    HAL_Delay(5);  
	LCD_E_PIN_RESET;   
}

void LCD_WriteData(uint8_t data) 
{
    LCD_RS_PIN_SET;  
    LCD_RW_PIN_RESET;
	LCD_E_PIN_RESET;  

	if(data &0x01) {
		LCD_D0_PIN_SET;
	}
	else {
		LCD_D0_PIN_RESET;
	}
	
	if(data &0x02) {
		LCD_D1_PIN_SET;
	}
	else {
		LCD_D1_PIN_RESET;
	}
	
	if(data &0x04) {
		LCD_D2_PIN_SET;
	}
	else {
		LCD_D2_PIN_RESET;
	}
	
	if(data &0x08) {
		LCD_D3_PIN_SET;
	}
	else {
		LCD_D3_PIN_RESET;
	}
	
	if(data &0x10) {
		LCD_D4_PIN_SET;
	}
	else {
		LCD_D4_PIN_RESET;
	}
	
	if(data &0x20) {
		LCD_D5_PIN_SET;
	}
	else {
		LCD_D5_PIN_RESET;
	}
	
	if(data &0x40) {
		LCD_D6_PIN_SET;
	}
	else {
		LCD_D6_PIN_RESET;
	}
	
	if(data &0x80) {
		LCD_D7_PIN_SET;
	}
	else {
		LCD_D7_PIN_RESET;
	}

    LCD_E_PIN_SET;   
    HAL_Delay(5);  
	LCD_E_PIN_RESET;   
}

void LCD_GPIO_Init() 
{
	LCD_BL_PIN_SET;
	LCD_V0_PIN_SET;
}

void LCD_Init() 
{
    LCD_WriteCommand(0x38);
    HAL_Delay(5);

    LCD_WriteCommand(0x0c);
    HAL_Delay(5);

    LCD_WriteCommand(0x06);
    HAL_Delay(5);
	
    LCD_WriteCommand(0x01);
    HAL_Delay(5);
}

void LCD_SetCursor(uint8_t col, uint8_t row) 
{
    uint8_t address = col;
    if (row == 1) {
        address += 0x40; 
    }
    LCD_WriteCommand(0x80 | address); 
}

void LCD_Print(char* str) 
{
    while (*str) {
        LCD_WriteData(*str++);
    }
}