/*
   Пример эмуляции клавиатуры EasyHID
   Можно нажимать, отжимать и кликать одновременно до 5ти клавиш
   Нажатые клавиши буфферизируются, клавиши модификаторы (ALT,CTRL...) так же работают
   Список всех доступных клавиш см. в файле Codekeys.h

   Если используется активная подтяжка при помощи пина,
   обьявляем "EASYHID_SOFT_DETACH" ПЕРЕД подключением EasyHID.h
   (Раскоментируйте строку ниже)
*/
 #define EASYHID_SOFT_DETACH

#include <EasyHID.h>                    // Либа HID 
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int PinQ = 6;
int PinE = 7;
int  Q = HIGH;
int  E = HIGH;
int count = 0;
int countlast = 7;
int sensorValue = 0;  // variable to store the value coming from the sensor
void setup() {
  //Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(PinQ, INPUT_PULLUP);
  pinMode(PinE, INPUT_PULLUP);
  HID.begin();                          // Инициализация USB
}
void loop() {
   count = analogRead(sensorPin) / 10;
   count = count / 15;
   //digitalWrite(ledPin, HIGH);   // включает светодиод

    if (count != countlast){
    switch (count) {
      


      /* -------------------------------- Стандартные сценарии использования клавиатуры -------------------------------- */
      case 0:                                           // Пример #0 - печать текста
        Keyboard.click(KEY_1);                          // Нажимаем и сразу отпускаем клавишу 'A'
 //       Keyboard.println("");                           // Начнем с новой строки
 //       Keyboard.write('>');                            // Печать одного ascii символа
 //       Keyboard.print("Hello world ");                 // Стандартный print, можно печатать текст (ТОЛЬКО АНГЛ!) и численные значения
        break;

      case 1:                                           // Пример #1 - клик по обычным клавишам
        Keyboard.click(KEY_2);                          // Нажимаем и сразу отпускаем клавишу 'A'
 //       Keyboard.click(KEY_B, KEY_C);                   // Можно указывать вплоть до 5ти клавиш одновременно
        break;

      case 2: 
        Keyboard.click(KEY_3);   // Пример #2 - нажатие клавиш, без отпускания
 //       Keyboard.press(KEY_1, KEY_2, KEY_3);            // Зажимаем одну или несколько клавиш
        break;

      case 3:                                             // Пример #3 - отпускание отдельной клавиши или нескольких клавиш
        Keyboard.click(KEY_4);   
//        Keyboard.release(KEY_2, KEY_3);                 // Пару отпустим, а '1' и дальше будет зажата
        break;

      case 4:                                           // Пример #4 - отпускание всех клавиш разом
      Keyboard.click(KEY_5);   
//        Keyboard.releaseAll();                          // Все ранее нажатые клавиши теперь отпущены
        break;

      case 5:                                           // Пример #6 - Сочетания клавиш, меняем язык в системе (SHIFT + ALT)
      Keyboard.click(KEY_6);   
//        Keyboard.click(KEY_LEFT_SHIFT, KEY_LEFT_ALT);   // Кликаем сочетание, можно и CTRL + ALT + DEL сделать!
        break;
        // ---------------------------------------------------------------------------------------------------------------- 
       // digitalWrite(ledPin, LOW);   // вsключает светодиод
        digitalWrite(ledPin, HIGH);   // включает светодиод
    }
        digitalWrite(ledPin, HIGH);   // включает светодиод
    }
    countlast=count;    // ONE TIME
   HID.tick();                           // Вызываем тикер не реже чем каждые 10 мс!
  }  















/*
  //  static uint8_t count = 0;             // Направление
  static uint32_t timer = millis();     // Миллис - таймер (НЕ DELAY!!!)
  if (millis() - timer >= 50) {       // Каждые 3000 мс
  /*  Serial.print('1');*/
   /* timer = millis();
    Q = digitalRead(PinQ);
    if (Q == LOW){
    //Keyboard.click(KEY_Q);                          // Нажимаем и сразу отпускаем клавишу 'A'  
    Keyboard.press(KEY_Q);                          // Нажимаем и сразу отпускаем клавишу 'A'  
  /*  Serial.print('Q');*/
 /*   }
    if (Q == HIGH){
    Keyboard.release(KEY_Q);                          // Нажимаем и сразу отпускаем клавишу 'A'  
     
    }
    E = digitalRead(PinE);
     if (E == LOW){
   // Keyboard.click(KEY_E);                          // Нажимаем и сразу отпускаем клавишу 'A'  
    Keyboard.press(KEY_E);                          // Нажимаем и сразу отпускаем клавишу 'A'   
 /*   Serial.print('W');*/
//    }
/*    if (E == HIGH){
    Keyboard.release(KEY_E);                          // Нажимаем и сразу отпускаем клавишу 'A'   
    }
  }*/
