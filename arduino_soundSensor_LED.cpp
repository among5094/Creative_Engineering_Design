//소리감지 무드등

int soundSensor = A0; // 소리센서를 아날로그 0번에 연결하겠다는 의미입니다.
int led[6] = {3, 4, 5, 6, 7, 8}; // led연결하는 핀번호입니다.
int threshold = 50; //한계점입니다. threshold소리가 넘으면 불빛이 나옵니다.
int count = 0; //박수치는 횟수를 세는 변수입니다.


void setup()
{
  Serial.begin(9600); 
  //시리얼 통신 속도 지정 9600은 9600bps를 뜻하고 초당 9600bit를 전송한다는 의미입니다.
  
  pinMode(soundSeneor, INPUT);
  //pinMode(설정하려는 핀의 번호, 출력이나 인풋모드로 설정)
  //pin: Arduino 핀 모드를 설정합니다.
  //Mode: INPUT또는 OUTPUT을 하라는 뜻입니다.
  
  for (int i = 0; i < 6 ;i++)
    pinMode(led[i], OUTPUT);
    //i를 0부터 5까지 6번 led를 출력하겠다는 의미입니다.
}


void loop()
{
  int value = analogRead(soundSeneor);
  //analogRead(): 지정한 아날로그 핀에서 값을 읽습니다.
  //그리고 analogRead()를 value라는 변수로 선언해서 넣어줍니다.
  
  Serial.println(value);
  //Serial.print(); //시리얼을 통해서 데이터를 보낼때 사용
  //Serial.println(); //print에서 줄바꿈이 추가되었다는 의미입니다.

  delay(100);
  //단위는 밀리세컨드 입니다. 1000이 1초이기 때문에 100은 0.1초입니다.

  //박수 치는 횟수에 따라서 소리가 켜지고 꺼지는 코드
  
  if(value >= threshold ) //한계값보다 입력받는 소리가 더 크다면?
  {
    for (int i = 0;i <6 ;i++)
    {
      if (i == count)
        digitalWrite(led[i], HIGH); //digitalWrite(핀번호, 값): 핀번호를 켜는 기능입니다.
      else
        digitalWrite(led[i], LOW); //digitalWrite(핀번호, 값): 핀번호를 끄는 기능입니다.              
    }
    count = (count < 6) ? count+1 : 0; //count가 6보다 작으면 count에 1더하고 count가 6이상이면 0출력
    delay(200);//0.2초
    
    /*
    삼항 연산자를 if문으로 쓴다면
    if(count < 6)
      count++;
    else
      count=0;
    */

  }
  else//한계값보다 입력받는 소리가 더 작다면?
    delay(1);//0.001초
}


/*

 참고한 코드 링크 
 지금 쓰고 있는 코드 링크
 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=eduino&logNo=221182896944
  

 led하나만 쓸 때 참고할 링크
 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=icbanq&logNo=220859240794
 

*/