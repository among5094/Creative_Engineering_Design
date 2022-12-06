//�Ƶ��̳� sound sensor �� led

int soundSeneor = A0; 
int led[3] = {8, 9 , 10}; //led�����ϴ� ��ȣ
int threshold = 100; //�Ѱ���
int count = 0; //�ڼ� ��� ġ���� 

void setup() {
  
  Serial.begin(9600);//�ø��� ��� �ӵ� ���� 9600�� 9600bps�� ���ϰ� �ʴ� 9600bit�� �����Ѵٴ� �ǹ��Դϴ�.
  pinMode(soundSeneor, INPUT);//pin: Arduino �� ��带 �����մϴ�.mode:INPUT�Ǵ� OUTPUT�̶�� ���Դϴ�.
  
  for (int i = 0; i < 3 ;i++)//i�� 0���� 5���� 5�� led�� output�ϰڴ�. 
    pinMode(led[i], OUTPUT);
    
}

void loop()//���ѹݺ�
{

  int value = analogRead(soundSeneor); //analogRead(): ������ �Ƴ��α� �ɿ��� ���� �н��ϴ�.
  Serial.println(value);
  delay(100);//������ �и������� �Դϴ�. 1000�� 1���̱� ������ 0.1���Դϴ�.
  //Serial.print(); //�ø����� ���ؼ� �����͸� ������ ���
  Serial.println(); //print���� �ٹٲ��� �߰��Ǿ��ٴ� �ǹ� ����� �ҹ���L��. �빮�� i�ƴ�

  if (analogRead(soundSeneor) >= threshold ) //�Ѱ谪���� �Է¹޴� �Ҹ��� �� ũ�ٸ�?
  {
    for (int i = 0;i <3 ;i++)
    {
      if (i == count)
      {
        digitalWrite(led[i], HIGH); //digitalWrite(�ɹ�ȣ, ��): �־��� �� ��ȣ�� ���� ���� "���"�ϴ� ����Դϴ�. 
      }
      else
        digitalWrite(led[i], LOW);                
    }
    count = (count < 3) ? count+1 : 0; //count�� 5���� ������ count�� 1���ϰ� count�� 5�̻��̸� 0���
    delay(200);//0.2��
  }
  else //�Ѱ谪���� �Է¹޴� �Ҹ��� �� �۴ٸ�?
    delay(1);//0.001��

    
}//�׸��� void loop()�̱� ������ ���ѹݺ�