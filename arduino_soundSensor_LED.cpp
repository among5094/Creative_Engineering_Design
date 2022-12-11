//�Ҹ����� �����

int soundSensor = A0; // �Ҹ������� �Ƴ��α� 0���� �����ϰڴٴ� �ǹ��Դϴ�.
int led[6] = {3, 4, 5, 6, 7, 8}; // led�����ϴ� �ɹ�ȣ�Դϴ�.
int threshold = 50; //�Ѱ����Դϴ�. threshold�Ҹ��� ������ �Һ��� ���ɴϴ�.
int count = 0; //�ڼ�ġ�� Ƚ���� ���� �����Դϴ�.


void setup()
{
  Serial.begin(9600); 
  //�ø��� ��� �ӵ� ���� 9600�� 9600bps�� ���ϰ� �ʴ� 9600bit�� �����Ѵٴ� �ǹ��Դϴ�.
  
  pinMode(soundSeneor, INPUT);
  //pinMode(�����Ϸ��� ���� ��ȣ, ����̳� ��ǲ���� ����)
  //pin: Arduino �� ��带 �����մϴ�.
  //Mode: INPUT�Ǵ� OUTPUT�� �϶�� ���Դϴ�.
  
  for (int i = 0; i < 6 ;i++)
    pinMode(led[i], OUTPUT);
    //i�� 0���� 5���� 6�� led�� ����ϰڴٴ� �ǹ��Դϴ�.
}


void loop()
{
  int value = analogRead(soundSeneor);
  //analogRead(): ������ �Ƴ��α� �ɿ��� ���� �н��ϴ�.
  //�׸��� analogRead()�� value��� ������ �����ؼ� �־��ݴϴ�.
  
  Serial.println(value);
  //Serial.print(); //�ø����� ���ؼ� �����͸� ������ ���
  //Serial.println(); //print���� �ٹٲ��� �߰��Ǿ��ٴ� �ǹ��Դϴ�.

  delay(100);
  //������ �и������� �Դϴ�. 1000�� 1���̱� ������ 100�� 0.1���Դϴ�.

  //�ڼ� ġ�� Ƚ���� ���� �Ҹ��� ������ ������ �ڵ�
  
  if(value >= threshold ) //�Ѱ谪���� �Է¹޴� �Ҹ��� �� ũ�ٸ�?
  {
    for (int i = 0;i <6 ;i++)
    {
      if (i == count)
        digitalWrite(led[i], HIGH); //digitalWrite(�ɹ�ȣ, ��): �ɹ�ȣ�� �Ѵ� ����Դϴ�.
      else
        digitalWrite(led[i], LOW); //digitalWrite(�ɹ�ȣ, ��): �ɹ�ȣ�� ���� ����Դϴ�.              
    }
    count = (count < 6) ? count+1 : 0; //count�� 6���� ������ count�� 1���ϰ� count�� 6�̻��̸� 0���
    delay(200);//0.2��
    
    /*
    ���� �����ڸ� if������ ���ٸ�
    if(count < 6)
      count++;
    else
      count=0;
    */

  }
  else//�Ѱ谪���� �Է¹޴� �Ҹ��� �� �۴ٸ�?
    delay(1);//0.001��
}


/*

 ������ �ڵ� ��ũ 
 ���� ���� �ִ� �ڵ� ��ũ
 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=eduino&logNo=221182896944
  

 led�ϳ��� �� �� ������ ��ũ
 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=icbanq&logNo=220859240794
 

*/