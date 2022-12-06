//아두이노 sound sensor 랑 led

int soundSeneor = A0; 
int led[3] = {8, 9 , 10}; //led연결하는 번호
int threshold = 100; //한계점
int count = 0; //박수 몇번 치는지 

void setup() {
  
  Serial.begin(9600);//시리얼 통신 속도 지정 9600은 9600bps를 뜻하고 초당 9600bit를 전송한다는 의미입니다.
  pinMode(soundSeneor, INPUT);//pin: Arduino 핀 모드를 설정합니다.mode:INPUT또는 OUTPUT이라는 뜻입니다.
  
  for (int i = 0; i < 3 ;i++)//i를 0부터 5까지 5번 led를 output하겠다. 
    pinMode(led[i], OUTPUT);
    
}

void loop()//무한반복
{

  int value = analogRead(soundSeneor); //analogRead(): 지정한 아날로그 핀에서 값을 읽습니다.
  Serial.println(value);
  delay(100);//단위는 밀리세컨드 입니다. 1000이 1초이기 때문에 0.1초입니다.
  //Serial.print(); //시리얼을 통해서 데이터를 보낼때 사용
  Serial.println(); //print에서 줄바꿈이 추가되었다는 의미 참고로 소문자L임. 대문자 i아님

  if (analogRead(soundSeneor) >= threshold ) //한계값보다 입력받는 소리가 더 크다면?
  {
    for (int i = 0;i <3 ;i++)
    {
      if (i == count)
      {
        digitalWrite(led[i], HIGH); //digitalWrite(핀번호, 값): 주어진 핀 번호에 대한 값을 "기록"하는 기능입니다. 
      }
      else
        digitalWrite(led[i], LOW);                
    }
    count = (count < 3) ? count+1 : 0; //count가 5보다 작으면 count에 1더하고 count가 5이상이면 0출력
    delay(200);//0.2초
  }
  else //한계값보다 입력받는 소리가 더 작다면?
    delay(1);//0.001초

    
}//그리고 void loop()이기 때문에 무한반복