/* LaskaKit LaskaKit ESP32-C3-LPKit blink example.
 * 
 * Board:   LaskaKit ESP32-C3-LPKit  https://www.laskakit.cz/laskkit-esp-12-board
 * 
 * In Arduino IDE choose board: "ESP32C3 Dev Module"
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#define led 4           
int i, j;

void setup() {
  pinMode(led, OUTPUT);   
}

void loop() {
  for(i=0; i < 3; i++) {
    digitalWrite(led, HIGH);
    delay(100);

    digitalWrite(led, LOW);
    delay(100);
  }
  
  delay(500);
  
  for(i=0; i < 1; i++) {
	  for(j=0; j <= 256;){
		  analogWrite(led, j);
      delay(1);
		  j += 1;
	  }
	  delay(500);
	  for(j=256; j >= 0;){
		  analogWrite(led, j);
      delay(1);
		  j -= 1;
	  }
    delay(500);
  }
  delay(500);
}
