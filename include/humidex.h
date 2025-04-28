// TABELLA INDICE HUMIDEX
// Righe temperatura - Colonne umidita relativa
unsigned char HUMIDEX[23][17] = {
  {00,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100},
  {42,48,50,52,55,57,59,62,64,66,68,71,73,75,77,80,82},
  {41,46,48,51,53,55,57,59,61,64,66,68,70,72,74,76,79},
  {40,45,47,49,51,53,55,57,59,61,63,65,67,69,71,73,75},
  {39,43,45,47,49,51,53,55,57,59,61,63,65,66,68,70,72},
  {38,42,44,45,47,49,51,53,55,56,58,60,62,64,66,67,69},
  {37,40,42,44,45,47,49,51,52,54,56,58,59,61,63,65,66},
  {36,39,40,42,44,45,47,49,50,52,54,55,57,59,60,62,63},
  {35,37,39,40,42,44,45,47,48,50,51,53,54,56,58,59,61},
  {34,36,37,39,40,42,43,45,46,48,49,51,52,54,55,57,58},
  {33,34,36,37,39,40,41,43,44,46,47,48,50,51,53,54,55},
  {32,33,34,36,37,38,40,41,42,44,45,46,48,49,50,52,53},
  {31,32,33,34,35,37,38,39,40,42,43,44,45,47,48,49,50},
  {30,30,32,33,34,35,36,37,39,40,41,42,43,45,46,47,48},
  {29,29,30,31,32,33,35,36,37,38,39,40,41,42,43,45,46},
  {28,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43},
  {27,27,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41},
  {26,26,26,27,28,29,30,31,32,33,34,34,35,36,37,38,39},
  {25,25,25,26,27,27,28,29,30,31,32,33,34,34,35,36,37},
  {24,24,24,24,25,26,27,28,28,29,30,31,32,33,33,34,35},
  {23,23,23,23,24,25,25,26,27,28,28,29,30,31,32,32,33},
  {22,22,22,22,22,23,24,25,25,26,27,27,28,29,30,30,31},
  {21,21,21,21,21,22,22,23,24,24,25,26,27,27,28,29,29}
};
//
// funzione per il calcolo della temperatura percepita
float temp_humidex(float temp, float umid){
	if(temp < 21 || temp > 42 || umid < 25)
		return temp;
	if (temp == 21)
		temp == 21.01;
	if (temp == 42)
		temp == 41.99;
	if (umid == 25)
		umid = 25.01;
	if (umid == 100)
		umid = 99.99; 
	int int_temp = (int)(temp);
	int flt_temp = (int)((temp - int_temp)*100);
	int int_umid = (int)(umid);
	int flt_umid = (int)((umid - int_umid)*100);
	uint col, row;
	col = (int)((int_umid - 25) / 5)  + 1;
	//Serial.print("col = ");
	//Serial.println(col);
	row = (int)(42 - int_temp);
	//Serial.print("row = ");
	//Serial.println(row);
	//
	float Q11 = (float)HUMIDEX[row][col];
	//Serial.print("Q11 = ");
	//Serial.println(Q11);
	float Q12 = (float)HUMIDEX[row][col+1]; 
	//Serial.print("Q12 = ");
	//Serial.println(Q12);
	float Q21 = (float)HUMIDEX[row+1][col];
	//Serial.print("Q21 = ");
	//Serial.println(Q21);
	float Q22 = (float)HUMIDEX[row+1][col+1];
	//Serial.print("Q22 = ");
	//Serial.println(Q22);
	float U1  = (float)HUMIDEX[0][col];
	float U2  = (float)HUMIDEX[0][col+1];
	float T1  = (float)HUMIDEX[row][0];
	float T2  = (float)HUMIDEX[row+1][0];
	//
	float T1112 = Q11 * (U2 - umid)/(U2 - U1) + Q12 * (umid - U1)/(U2 - U1);
	float T2122 = Q21 * (U2 - umid)/(U2 - U1) + Q22 * (umid - U1)/(U2 - U1);
	float temp_humidex = T1112 * (T2 - temp)/(T2 - T1) + T2122 * (temp - T1)/(T2 - T1);
	return temp_humidex;
}
